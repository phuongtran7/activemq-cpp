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
#include <activemq/connector/openwire/commands/DestinationInfo.h>
#include <activemq/exceptions/NullPointerException.h>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;

/*
 *
 *  Command and marshalling code for OpenWire format for DestinationInfo
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
DestinationInfo::DestinationInfo()
{
    this->connectionId = NULL;
    this->destination = NULL;
    this->operationType = 0;
    this->timeout = 0;
}

////////////////////////////////////////////////////////////////////////////////
DestinationInfo::~DestinationInfo()
{
    delete this->connectionId;
    delete this->destination;
    for( size_t ibrokerPath = 0; ibrokerPath < brokerPath.size(); ++ibrokerPath ) {
        delete brokerPath[ibrokerPath];
    }
}

////////////////////////////////////////////////////////////////////////////////
DataStructure* DestinationInfo::cloneDataStructure() const {
    DestinationInfo* destinationInfo = new DestinationInfo();

    // Copy the data from the base class or classes
    destinationInfo->copyDataStructure( this );

    return destinationInfo;
}

////////////////////////////////////////////////////////////////////////////////
void DestinationInfo::copyDataStructure( const DataStructure* src ) {

    // Copy the data of the base class or classes
    BaseCommand::copyDataStructure( src );

    const DestinationInfo* srcPtr = dynamic_cast<const DestinationInfo*>( src );

    if( srcPtr == NULL || src == NULL ) {
    
        throw exceptions::NullPointerException(
            __FILE__, __LINE__,
            "DestinationInfo::copyDataStructure - src is NULL or invalid" );
    }
    this->setConnectionId( 
        dynamic_cast<ConnectionId*>( 
            srcPtr->getConnectionId()->cloneDataStructure() ) );
    this->setDestination( 
        dynamic_cast<ActiveMQDestination*>( 
            srcPtr->getDestination()->cloneDataStructure() ) );
    this->setOperationType( srcPtr->getOperationType() );
    this->setTimeout( srcPtr->getTimeout() );
    for( size_t ibrokerPath = 0; ibrokerPath < srcPtr->getBrokerPath().size(); ++ibrokerPath ) {
        this->getBrokerPath().push_back( 
            srcPtr->getBrokerPath()[ibrokerPath]->cloneDataStructure() );
    }
}

////////////////////////////////////////////////////////////////////////////////
unsigned char DestinationInfo::getDataStructureType() const {
    return DestinationInfo::ID_DESTINATIONINFO; 
}

////////////////////////////////////////////////////////////////////////////////
const ConnectionId* DestinationInfo::getConnectionId() const {
    return connectionId;
}

////////////////////////////////////////////////////////////////////////////////
ConnectionId* DestinationInfo::getConnectionId() {
    return connectionId;
}

////////////////////////////////////////////////////////////////////////////////
void DestinationInfo::setConnectionId(ConnectionId* connectionId ) {
    this->connectionId = connectionId;
}

////////////////////////////////////////////////////////////////////////////////
const ActiveMQDestination* DestinationInfo::getDestination() const {
    return destination;
}

////////////////////////////////////////////////////////////////////////////////
ActiveMQDestination* DestinationInfo::getDestination() {
    return destination;
}

////////////////////////////////////////////////////////////////////////////////
void DestinationInfo::setDestination(ActiveMQDestination* destination ) {
    this->destination = destination;
}

////////////////////////////////////////////////////////////////////////////////
const char DestinationInfo::getOperationType() const {
    return operationType;
}

////////////////////////////////////////////////////////////////////////////////
char DestinationInfo::getOperationType() {
    return operationType;
}

////////////////////////////////////////////////////////////////////////////////
void DestinationInfo::setOperationType(char operationType ) {
    this->operationType = operationType;
}

////////////////////////////////////////////////////////////////////////////////
const long long DestinationInfo::getTimeout() const {
    return timeout;
}

////////////////////////////////////////////////////////////////////////////////
long long DestinationInfo::getTimeout() {
    return timeout;
}

////////////////////////////////////////////////////////////////////////////////
void DestinationInfo::setTimeout(long long timeout ) {
    this->timeout = timeout;
}

////////////////////////////////////////////////////////////////////////////////
const std::vector<BrokerId*> DestinationInfo::getBrokerPath() const {
    return brokerPath;
}

////////////////////////////////////////////////////////////////////////////////
std::vector<BrokerId*> DestinationInfo::getBrokerPath() {
    return brokerPath;
}

////////////////////////////////////////////////////////////////////////////////
void DestinationInfo::setBrokerPath(std::vector<BrokerId*> brokerPath ) {
    this->brokerPath = brokerPath;
}

