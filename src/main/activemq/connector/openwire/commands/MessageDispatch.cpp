/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <activemq/connector/openwire/commands/MessageDispatch.h>
#include <activemq/exceptions/ActiveMQException.h>
#include <decaf/lang/exceptions/NullPointerException.h>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;
using namespace decaf::lang::exceptions;

/*
 *
 *  Command and marshaling code for OpenWire format for MessageDispatch
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
MessageDispatch::MessageDispatch()
{
    this->consumerId = NULL;
    this->destination = NULL;
    this->message = NULL;
    this->redeliveryCounter = 0;
}

////////////////////////////////////////////////////////////////////////////////
MessageDispatch::~MessageDispatch()
{
    delete this->consumerId;
    delete this->destination;
    delete this->message;
}

////////////////////////////////////////////////////////////////////////////////
MessageDispatch* MessageDispatch::cloneDataStructure() const {
    MessageDispatch* messageDispatch = new MessageDispatch();

    // Copy the data from the base class or classes
    messageDispatch->copyDataStructure( this );

    return messageDispatch;
}

////////////////////////////////////////////////////////////////////////////////
void MessageDispatch::copyDataStructure( const DataStructure* src ) {

    // Copy the data of the base class or classes
    BaseCommand<transport::Command>::copyDataStructure( src );

    const MessageDispatch* srcPtr = dynamic_cast<const MessageDispatch*>( src );

    if( srcPtr == NULL || src == NULL ) {

        throw decaf::lang::exceptions::NullPointerException(
            __FILE__, __LINE__,
            "MessageDispatch::copyDataStructure - src is NULL or invalid" );
    }
    if( srcPtr->getConsumerId() != NULL ) {
        this->setConsumerId(
            dynamic_cast<ConsumerId*>(
                srcPtr->getConsumerId()->cloneDataStructure() ) );
    }
    if( srcPtr->getDestination() != NULL ) {
        this->setDestination(
            dynamic_cast<ActiveMQDestination*>(
                srcPtr->getDestination()->cloneDataStructure() ) );
    }
    if( srcPtr->getMessage() != NULL ) {
        this->setMessage(
            dynamic_cast<Message*>(
                srcPtr->getMessage()->cloneDataStructure() ) );
    }
    this->setRedeliveryCounter( srcPtr->getRedeliveryCounter() );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char MessageDispatch::getDataStructureType() const {
    return MessageDispatch::ID_MESSAGEDISPATCH;
}

////////////////////////////////////////////////////////////////////////////////
std::string MessageDispatch::toString() const {

    ostringstream stream;

    stream << "Begin Class = MessageDispatch" << std::endl;
    stream << " Value of MessageDispatch::ID_MESSAGEDISPATCH = 21" << std::endl;
    stream << " Value of ConsumerId is Below:" << std::endl;
    if( this->getConsumerId() != NULL ) {
        stream << this->getConsumerId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of Destination is Below:" << std::endl;
    if( this->getDestination() != NULL ) {
        stream << this->getDestination()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of Message is Below:" << std::endl;
    if( this->getMessage() != NULL ) {
        stream << this->getMessage()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of RedeliveryCounter = " << this->getRedeliveryCounter() << std::endl;
    stream << BaseCommand<transport::Command>::toString();
    stream << "End Class = MessageDispatch" << std::endl;

    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
bool MessageDispatch::equals( const DataStructure* value ) const {
    const MessageDispatch* valuePtr = dynamic_cast<const MessageDispatch*>( value );

    if( valuePtr == NULL || value == NULL ) {
        return false;
    }
    if( this->getConsumerId() != NULL ) {
        if( !this->getConsumerId()->equals( valuePtr->getConsumerId() ) ) {
            return false;
        }
    } else if( valuePtr->getConsumerId() != NULL ) {
        return false;
    }
    if( this->getDestination() != NULL ) {
        if( !this->getDestination()->equals( valuePtr->getDestination() ) ) {
            return false;
        }
    } else if( valuePtr->getDestination() != NULL ) {
        return false;
    }
    if( this->getMessage() != NULL ) {
        if( !this->getMessage()->equals( valuePtr->getMessage() ) ) {
            return false;
        }
    } else if( valuePtr->getMessage() != NULL ) {
        return false;
    }
    if( this->getRedeliveryCounter() != valuePtr->getRedeliveryCounter() ) {
        return false;
    }
    if( !BaseCommand<transport::Command>::equals( value ) ) {
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
const ConsumerId* MessageDispatch::getConsumerId() const {
    return consumerId;
}

////////////////////////////////////////////////////////////////////////////////
ConsumerId* MessageDispatch::getConsumerId() {
    return consumerId;
}

////////////////////////////////////////////////////////////////////////////////
void MessageDispatch::setConsumerId(ConsumerId* consumerId ) {
    this->consumerId = consumerId;
}

////////////////////////////////////////////////////////////////////////////////
const ActiveMQDestination* MessageDispatch::getDestination() const {
    return destination;
}

////////////////////////////////////////////////////////////////////////////////
ActiveMQDestination* MessageDispatch::getDestination() {
    return destination;
}

////////////////////////////////////////////////////////////////////////////////
void MessageDispatch::setDestination(ActiveMQDestination* destination ) {
    this->destination = destination;
}

////////////////////////////////////////////////////////////////////////////////
const Message* MessageDispatch::getMessage() const {
    return message;
}

////////////////////////////////////////////////////////////////////////////////
Message* MessageDispatch::getMessage() {
    return message;
}

////////////////////////////////////////////////////////////////////////////////
void MessageDispatch::setMessage(Message* message ) {
    this->message = message;
}

////////////////////////////////////////////////////////////////////////////////
int MessageDispatch::getRedeliveryCounter() const {
    return redeliveryCounter;
}

////////////////////////////////////////////////////////////////////////////////
void MessageDispatch::setRedeliveryCounter(int redeliveryCounter ) {
    this->redeliveryCounter = redeliveryCounter;
}

