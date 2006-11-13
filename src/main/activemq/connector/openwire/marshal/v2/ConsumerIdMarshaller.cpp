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

#include <activemq/connector/openwire/marshal/v2/ConsumerIdMarshaller.h>

#include <activemq/connector/openwire/commands/ConsumerId.h>

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
DataStructure* ConsumerIdMarshaller::createObject() const {
    return new ConsumerId();
}

///////////////////////////////////////////////////////////////////////////////
unsigned char ConsumerIdMarshaller::getDataStructureType() const {
    return ConsumerId::ID_CONSUMERID;
}

///////////////////////////////////////////////////////////////////////////////
void ConsumerIdMarshaller::tightUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn, BooleanStream* bs ) throw( io::IOException ){
   BaseDataStreamMarshaller::tightUnmarshal( wireFormat, dataStructure, dataIn, bs );

    ConsumerId* info =
        dynamic_cast<ConsumerId*>( dataStructure );
    info->setConnectionId( tightUnmarshalString( dataIn, bs ) );
    info->setSessionId( tightUnmarshalLong( wireFormat, dataIn, bs ) );
    info->setValue( tightUnmarshalLong( wireFormat, dataIn, bs ) );
}

///////////////////////////////////////////////////////////////////////////////
int ConsumerIdMarshaller::tightMarshal1( OpenWireFormat* wireFormat, DataStructure* dataStructure, BooleanStream* bs ) throw( io::IOException ){

    ConsumerId* info =
        dynamic_cast<ConsumerId*>( dataStructure );

    int rc = BaseDataStreamMarshaller::tightMarshal1( wireFormat, dataStructure, bs );
    rc += tightMarshalString1( info->getConnectionId(), bs );
    rc += tightMarshalLong1( wireFormat, info->getSessionId(), bs );
    rc += tightMarshalLong1( wireFormat, info->getValue(), bs );

    return rc + 0;
}

///////////////////////////////////////////////////////////////////////////////
void ConsumerIdMarshaller::tightMarshal2( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut, BooleanStream* bs ) throw( io::IOException ){

    BaseDataStreamMarshaller::tightMarshal2( wireFormat, dataStructure, dataOut, bs );

    ConsumerId* info =
        dynamic_cast<ConsumerId*>( dataStructure );
    tightMarshalString2( info->getConnectionId(), dataOut, bs );
    tightMarshalLong2( wireFormat, info->getSessionId(), dataOut, bs );
    tightMarshalLong2( wireFormat, info->getValue(), dataOut, bs );
}

///////////////////////////////////////////////////////////////////////////////
void ConsumerIdMarshaller::looseUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn ) throw( io::IOException ){
    BaseDataStreamMarshaller::looseUnmarshal( wireFormat, dataStructure, dataIn );
    ConsumerId* info = 
        dynamic_cast<ConsumerId*>( dataStructure );
    info->setConnectionId( looseUnmarshalString( dataIn ) );
    info->setSessionId( looseUnmarshalLong( wireFormat, dataIn ) );
    info->setValue( looseUnmarshalLong( wireFormat, dataIn ) );
}

///////////////////////////////////////////////////////////////////////////////
void ConsumerIdMarshaller::looseMarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut ) throw( io::IOException ){
    ConsumerId* info =
        dynamic_cast<ConsumerId*>( dataStructure );
    BaseDataStreamMarshaller::looseMarshal( wireFormat, dataStructure, dataOut );

    looseMarshalString( info->getConnectionId(), dataOut );
    looseMarshalLong( wireFormat, info->getSessionId(), dataOut );
    looseMarshalLong( wireFormat, info->getValue(), dataOut );
}

