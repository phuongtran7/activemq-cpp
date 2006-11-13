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

#include <activemq/connector/openwire/marshal/v2/DiscoveryEventMarshaller.h>

#include <activemq/connector/openwire/commands/DiscoveryEvent.h>

//
//     NOTE!: This file is autogenerated - do not modify!
//            if you need to make a change, please see the Java Classes in the
//            activemq-core module
//

using namespace std;
using namespace activemq;
using namespace activemq::io;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;
using namespace activemq::connector::openwire::marshal;
using namespace activemq::connector::openwire::utils;
using namespace activemq::connector::openwire::marshal::v2;

///////////////////////////////////////////////////////////////////////////////
DataStructure* DiscoveryEventMarshaller::createObject() const {
    return new DiscoveryEvent();
}

///////////////////////////////////////////////////////////////////////////////
unsigned char DiscoveryEventMarshaller::getDataStructureType() const {
    return DiscoveryEvent::ID_DISCOVERYEVENT;
}

///////////////////////////////////////////////////////////////////////////////
void DiscoveryEventMarshaller::tightUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn, BooleanStream* bs ) throw( io::IOException ){
   BaseDataStreamMarshaller::tightUnmarshal( wireFormat, dataStructure, dataIn, bs );

    DiscoveryEvent* info =
        dynamic_cast<DiscoveryEvent*>( dataStructure );
    info->setServiceName( tightUnmarshalString( dataIn, bs ) );
    info->setBrokerName( tightUnmarshalString( dataIn, bs ) );
}

///////////////////////////////////////////////////////////////////////////////
int DiscoveryEventMarshaller::tightMarshal1( OpenWireFormat* wireFormat, DataStructure* dataStructure, BooleanStream* bs ) throw( io::IOException ){

    DiscoveryEvent* info =
        dynamic_cast<DiscoveryEvent*>( dataStructure );

    int rc = BaseDataStreamMarshaller::tightMarshal1( wireFormat, dataStructure, bs );
    rc += tightMarshalString1( info->getServiceName(), bs );
    rc += tightMarshalString1( info->getBrokerName(), bs );

    return rc + 0;
}

///////////////////////////////////////////////////////////////////////////////
void DiscoveryEventMarshaller::tightMarshal2( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut, BooleanStream* bs ) throw( io::IOException ){

    BaseDataStreamMarshaller::tightMarshal2( wireFormat, dataStructure, dataOut, bs );

    DiscoveryEvent* info =
        dynamic_cast<DiscoveryEvent*>( dataStructure );
    tightMarshalString2( info->getServiceName(), dataOut, bs );
    tightMarshalString2( info->getBrokerName(), dataOut, bs );
}

///////////////////////////////////////////////////////////////////////////////
void DiscoveryEventMarshaller::looseUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn ) throw( io::IOException ){
    BaseDataStreamMarshaller::looseUnmarshal( wireFormat, dataStructure, dataIn );
    DiscoveryEvent* info = 
        dynamic_cast<DiscoveryEvent*>( dataStructure );
    info->setServiceName( looseUnmarshalString( dataIn ) );
    info->setBrokerName( looseUnmarshalString( dataIn ) );
}

///////////////////////////////////////////////////////////////////////////////
void DiscoveryEventMarshaller::looseMarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut ) throw( io::IOException ){
    DiscoveryEvent* info =
        dynamic_cast<DiscoveryEvent*>( dataStructure );
    BaseDataStreamMarshaller::looseMarshal( wireFormat, dataStructure, dataOut );

    looseMarshalString( info->getServiceName(), dataOut );
    looseMarshalString( info->getBrokerName(), dataOut );
}

