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
#include <activemq/connector/openwire/commands/NetworkBridgeFilter.h>
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
 *  Command and marshaling code for OpenWire format for NetworkBridgeFilter
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
NetworkBridgeFilter::NetworkBridgeFilter()
{
    this->networkTTL = 0;
    this->networkBrokerId = NULL;
}

////////////////////////////////////////////////////////////////////////////////
NetworkBridgeFilter::~NetworkBridgeFilter()
{
    delete this->networkBrokerId;
}

////////////////////////////////////////////////////////////////////////////////
NetworkBridgeFilter* NetworkBridgeFilter::cloneDataStructure() const {
    NetworkBridgeFilter* networkBridgeFilter = new NetworkBridgeFilter();

    // Copy the data from the base class or classes
    networkBridgeFilter->copyDataStructure( this );

    return networkBridgeFilter;
}

////////////////////////////////////////////////////////////////////////////////
void NetworkBridgeFilter::copyDataStructure( const DataStructure* src ) {

    // Copy the data of the base class or classes
    BaseDataStructure::copyDataStructure( src );

    const NetworkBridgeFilter* srcPtr = dynamic_cast<const NetworkBridgeFilter*>( src );

    if( srcPtr == NULL || src == NULL ) {

        throw decaf::lang::exceptions::NullPointerException(
            __FILE__, __LINE__,
            "NetworkBridgeFilter::copyDataStructure - src is NULL or invalid" );
    }
    this->setNetworkTTL( srcPtr->getNetworkTTL() );
    if( srcPtr->getNetworkBrokerId() != NULL ) {
        this->setNetworkBrokerId(
            dynamic_cast<BrokerId*>(
                srcPtr->getNetworkBrokerId()->cloneDataStructure() ) );
    }
}

////////////////////////////////////////////////////////////////////////////////
unsigned char NetworkBridgeFilter::getDataStructureType() const {
    return NetworkBridgeFilter::ID_NETWORKBRIDGEFILTER;
}

////////////////////////////////////////////////////////////////////////////////
std::string NetworkBridgeFilter::toString() const {

    ostringstream stream;

    stream << "Begin Class = NetworkBridgeFilter" << std::endl;
    stream << " Value of NetworkBridgeFilter::ID_NETWORKBRIDGEFILTER = 91" << std::endl;
    stream << " Value of NetworkTTL = " << this->getNetworkTTL() << std::endl;
    stream << " Value of NetworkBrokerId is Below:" << std::endl;
    if( this->getNetworkBrokerId() != NULL ) {
        stream << this->getNetworkBrokerId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << BaseDataStructure::toString();
    stream << "End Class = NetworkBridgeFilter" << std::endl;

    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
bool NetworkBridgeFilter::equals( const DataStructure* value ) const {
    const NetworkBridgeFilter* valuePtr = dynamic_cast<const NetworkBridgeFilter*>( value );

    if( valuePtr == NULL || value == NULL ) {
        return false;
    }
    if( this->getNetworkTTL() != valuePtr->getNetworkTTL() ) {
        return false;
    }
    if( this->getNetworkBrokerId() != NULL ) {
        if( !this->getNetworkBrokerId()->equals( valuePtr->getNetworkBrokerId() ) ) {
            return false;
        }
    } else if( valuePtr->getNetworkBrokerId() != NULL ) {
        return false;
    }
    if( !BaseDataStructure::equals( value ) ) {
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
int NetworkBridgeFilter::getNetworkTTL() const {
    return networkTTL;
}

////////////////////////////////////////////////////////////////////////////////
void NetworkBridgeFilter::setNetworkTTL(int networkTTL ) {
    this->networkTTL = networkTTL;
}

////////////////////////////////////////////////////////////////////////////////
const BrokerId* NetworkBridgeFilter::getNetworkBrokerId() const {
    return networkBrokerId;
}

////////////////////////////////////////////////////////////////////////////////
BrokerId* NetworkBridgeFilter::getNetworkBrokerId() {
    return networkBrokerId;
}

////////////////////////////////////////////////////////////////////////////////
void NetworkBridgeFilter::setNetworkBrokerId(BrokerId* networkBrokerId ) {
    this->networkBrokerId = networkBrokerId;
}

