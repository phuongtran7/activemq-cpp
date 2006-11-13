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
#include <activemq/connector/openwire/commands/TransactionInfo.h>
#include <activemq/exceptions/NullPointerException.h>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;

/*
 *
 *  Command and marshalling code for OpenWire format for TransactionInfo
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
TransactionInfo::TransactionInfo()
{
    this->connectionId = NULL;
    this->transactionId = NULL;
    this->type = 0;
}

////////////////////////////////////////////////////////////////////////////////
TransactionInfo::~TransactionInfo()
{
    delete this->connectionId;
    delete this->transactionId;
}

////////////////////////////////////////////////////////////////////////////////
DataStructure* TransactionInfo::cloneDataStructure() const {
    TransactionInfo* transactionInfo = new TransactionInfo();

    // Copy the data from the base class or classes
    transactionInfo->copyDataStructure( this );

    return transactionInfo;
}

////////////////////////////////////////////////////////////////////////////////
void TransactionInfo::copyDataStructure( const DataStructure* src ) {

    // Copy the data of the base class or classes
    BaseCommand::copyDataStructure( src );

    const TransactionInfo* srcPtr = dynamic_cast<const TransactionInfo*>( src );

    if( srcPtr == NULL || src == NULL ) {
    
        throw exceptions::NullPointerException(
            __FILE__, __LINE__,
            "TransactionInfo::copyDataStructure - src is NULL or invalid" );
    }
    this->setConnectionId( 
        dynamic_cast<ConnectionId*>( 
            srcPtr->getConnectionId()->cloneDataStructure() ) );
    this->setTransactionId( 
        dynamic_cast<TransactionId*>( 
            srcPtr->getTransactionId()->cloneDataStructure() ) );
    this->setType( srcPtr->getType() );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char TransactionInfo::getDataStructureType() const {
    return TransactionInfo::ID_TRANSACTIONINFO; 
}

////////////////////////////////////////////////////////////////////////////////
const ConnectionId* TransactionInfo::getConnectionId() const {
    return connectionId;
}

////////////////////////////////////////////////////////////////////////////////
ConnectionId* TransactionInfo::getConnectionId() {
    return connectionId;
}

////////////////////////////////////////////////////////////////////////////////
void TransactionInfo::setConnectionId(ConnectionId* connectionId ) {
    this->connectionId = connectionId;
}

////////////////////////////////////////////////////////////////////////////////
const TransactionId* TransactionInfo::getTransactionId() const {
    return transactionId;
}

////////////////////////////////////////////////////////////////////////////////
TransactionId* TransactionInfo::getTransactionId() {
    return transactionId;
}

////////////////////////////////////////////////////////////////////////////////
void TransactionInfo::setTransactionId(TransactionId* transactionId ) {
    this->transactionId = transactionId;
}

////////////////////////////////////////////////////////////////////////////////
const char TransactionInfo::getType() const {
    return type;
}

////////////////////////////////////////////////////////////////////////////////
char TransactionInfo::getType() {
    return type;
}

////////////////////////////////////////////////////////////////////////////////
void TransactionInfo::setType(char type ) {
    this->type = type;
}

