/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "ActiveMQProducer.h"

#include <activemq/core/ActiveMQSession.h>
#include <activemq/core/ActiveMQConnection.h>
#include <activemq/commands/RemoveInfo.h>
#include <activemq/util/CMSExceptionSupport.h>
#include <decaf/lang/exceptions/NullPointerException.h>
#include <decaf/lang/exceptions/InvalidStateException.h>
#include <decaf/lang/exceptions/IllegalArgumentException.h>
#include <decaf/lang/System.h>

using namespace std;
using namespace activemq;
using namespace activemq::core;
using namespace activemq::commands;
using namespace activemq::exceptions;
using namespace decaf::util;
using namespace decaf::lang;
using namespace decaf::lang::exceptions;

////////////////////////////////////////////////////////////////////////////////
ActiveMQProducer::ActiveMQProducer( const Pointer<commands::ProducerInfo>& producerInfo,
                                    const Pointer<cms::Destination>& destination,
                                    ActiveMQSession* session ) {

    if( session == NULL || producerInfo == NULL ) {
        throw ActiveMQException(
            __FILE__, __LINE__,
            "ActiveMQProducer::ActiveMQProducer - Init with NULL Session" );
    }

    // Init Producer Data
    this->session = session;
    this->producerInfo = producerInfo;
    this->destination = destination;
    this->closed = false;

    // Default the Delivery options
    this->defaultDeliveryMode = cms::DeliveryMode::PERSISTENT;
    this->disableTimestamps = false;
    this->disableMessageId = false;
    this->defaultPriority = 4;
    this->defaultTimeToLive = 0;
}

////////////////////////////////////////////////////////////////////////////////
ActiveMQProducer::~ActiveMQProducer() {
    try {
        close();
    }
    AMQ_CATCH_NOTHROW( ActiveMQException )
    AMQ_CATCHALL_NOTHROW( )
}

////////////////////////////////////////////////////////////////////////////////
void ActiveMQProducer::close() throw ( cms::CMSException ) {

    try{

        if( !this->isClosed() ) {

            this->session->disposeOf( this->producerInfo->getProducerId() );
            this->closed = true;

            // Remove at the Broker Side, if this fails the producer has already
            // been removed from the session and connection objects so its safe
            // for an exception to be thrown.
            Pointer<RemoveInfo> info( new RemoveInfo );
            info->setObjectId( this->producerInfo->getProducerId() );
            this->session->oneway( info );
        }
    }
    AMQ_CATCH_ALL_THROW_CMSEXCEPTION()
}

////////////////////////////////////////////////////////////////////////////////
void ActiveMQProducer::send( cms::Message* message ) throw ( cms::CMSException,
                                                             cms::MessageFormatException,
                                                             cms::InvalidDestinationException,
                                                             cms::UnsupportedOperationException ) {

    try {

        this->checkClosed();

        this->send( this->destination.get(), message );
    }
    AMQ_CATCH_ALL_THROW_CMSEXCEPTION()
}

////////////////////////////////////////////////////////////////////////////////
void ActiveMQProducer::send( cms::Message* message, int deliveryMode, int priority, long long timeToLive )
    throw ( cms::CMSException,
            cms::MessageFormatException,
            cms::InvalidDestinationException,
            cms::UnsupportedOperationException ) {

    try {

        this->checkClosed();

        this->send( this->destination.get(), message, deliveryMode, priority, timeToLive );
    }
    AMQ_CATCH_ALL_THROW_CMSEXCEPTION()
}

////////////////////////////////////////////////////////////////////////////////
void ActiveMQProducer::send( const cms::Destination* destination, cms::Message* message )
    throw ( cms::CMSException,
            cms::MessageFormatException,
            cms::InvalidDestinationException,
            cms::UnsupportedOperationException ) {

    try {

        this->checkClosed();

        this->send( destination, message, defaultDeliveryMode, defaultPriority, defaultTimeToLive );
    }
    AMQ_CATCH_ALL_THROW_CMSEXCEPTION()
}

////////////////////////////////////////////////////////////////////////////////
void ActiveMQProducer::send( const cms::Destination* destination, cms::Message* message,
                             int deliveryMode, int priority, long long timeToLive )
    throw ( cms::CMSException,
            cms::MessageFormatException,
            cms::InvalidDestinationException,
            cms::UnsupportedOperationException ) {

    try {

        this->checkClosed();

        if( destination == NULL ) {

            if( this->producerInfo->getDestination() == NULL ) {
                throw cms::UnsupportedOperationException( "A destination must be specified.", NULL );
            }

            throw cms::InvalidDestinationException( "Don't understand null destinations", NULL );
        }

        const cms::Destination* dest;
        if( destination == dynamic_cast<cms::Destination*>( this->producerInfo->getDestination().get() ) ) {
            dest = destination;
        } else if( this->producerInfo->getDestination() == NULL ) {

            // TODO - We should apply a Transform so ensure the user hasn't create some
            //        external cms::Destination implementation.
            dest = destination;
        } else {
            throw cms::UnsupportedOperationException( string( "This producer can only send messages to: " ) +
                                                              this->producerInfo->getDestination()->getPhysicalName(), NULL );
        }

        if( dest == NULL ) {
            throw cms::CMSException( "No destination specified", NULL );
        }

        // configure the message
        message->setCMSDestination( dest );
        message->setCMSDeliveryMode( deliveryMode );
        message->setCMSPriority( priority );

        long long expiration = 0LL;

        if( !disableTimestamps ) {

            long long timeStamp = System::currentTimeMillis();
            message->setCMSTimestamp( timeStamp );
            if( timeToLive > 0LL ) {
                expiration = timeToLive + timeStamp;
            }
        }

        message->setCMSExpiration( expiration );

        // Delegate send to the session so that it can choose how to
        // send the message.
        this->session->send( message, this, this->memoryUsage.get() );
    }
    AMQ_CATCH_ALL_THROW_CMSEXCEPTION()
}

////////////////////////////////////////////////////////////////////////////////
void ActiveMQProducer::onProducerAck( const commands::ProducerAck& ack ) {

    try{

        if( this->memoryUsage.get() != NULL ) {
            this->memoryUsage->decreaseUsage( ack.getSize() );
        }
    }
    AMQ_CATCH_RETHROW( ActiveMQException )
    AMQ_CATCH_EXCEPTION_CONVERT( Exception, ActiveMQException )
    AMQ_CATCHALL_THROW( ActiveMQException )
}

////////////////////////////////////////////////////////////////////////////////
void ActiveMQProducer::checkClosed() const throw( activemq::exceptions::ActiveMQException ) {
    if( closed ) {
        throw ActiveMQException(
            __FILE__, __LINE__,
            "ActiveMQProducer - Producer Already Closed" );
    }
}
