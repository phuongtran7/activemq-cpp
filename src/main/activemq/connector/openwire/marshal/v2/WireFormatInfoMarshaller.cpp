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

#include <activemq/connector/openwire/marshal/v2/WireFormatInfoMarshaller.h>

#include <activemq/connector/openwire/commands/WireFormatInfo.h>

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
DataStructure* WireFormatInfoMarshaller::createObject() const {
    return new WireFormatInfo();
}

///////////////////////////////////////////////////////////////////////////////
unsigned char WireFormatInfoMarshaller::getDataStructureType() const {
    return WireFormatInfo::ID_WIREFORMATINFO;
}

///////////////////////////////////////////////////////////////////////////////
void WireFormatInfoMarshaller::tightUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn, BooleanStream* bs ) throw( io::IOException ){
   BaseDataStreamMarshaller::tightUnmarshal( wireFormat, dataStructure, dataIn, bs );

    WireFormatInfo* info =
        dynamic_cast<WireFormatInfo*>( dataStructure );
    info->beforeUnmarshall( wireFormat );

    info->setMagic( tightUnmarshalConstByteArray( dataIn, bs, 8 ) );
    info->setVersion( dataIn->readInt() );
    info->setMarshalledProperties( tightUnmarshalByteArray( dataIn, bs ) );

    info->afterUnmarshall( wireFormat );
}

///////////////////////////////////////////////////////////////////////////////
int WireFormatInfoMarshaller::tightMarshal1( OpenWireFormat* wireFormat, DataStructure* dataStructure, BooleanStream* bs ) throw( io::IOException ){

    WireFormatInfo* info =
        dynamic_cast<WireFormatInfo*>( dataStructure );

    info->beforeMarshall( wireFormat );
    int rc = BaseDataStreamMarshaller::tightMarshal1( wireFormat, dataStructure, bs );
    bs->writeBoolean( info->getMarshalledProperties() != NULL );
    rc += info->getMarshalledProperties()() == NULL ? 0 : info->getMarshalledProperties().Length + 4;

    return rc + 12;
}

///////////////////////////////////////////////////////////////////////////////
void WireFormatInfoMarshaller::tightMarshal2( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut, BooleanStream* bs ) throw( io::IOException ){

    BaseDataStreamMarshaller::tightMarshal2( wireFormat, dataStructure, dataOut, bs );

    WireFormatInfo* info =
        dynamic_cast<WireFormatInfo*>( dataStructure );
    dataOut->write( info->getMagic(), 0, 8 );
    dataOut->write( info->getVersion() );
    if( bs->readBoolean() ) {
        dataOut->write( info->getMarshalledProperties().Length );
        dataOut->write( info->getMarshalledProperties() );
    }
    info->afterMarshall( wireFormat );
}

///////////////////////////////////////////////////////////////////////////////
void WireFormatInfoMarshaller::looseUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn ) throw( io::IOException ){
    BaseDataStreamMarshaller::looseUnmarshal( wireFormat, dataStructure, dataIn );
    WireFormatInfo* info = 
        dynamic_cast<WireFormatInfo*>( dataStructure );
    info->beforeUnmarshall( wireFormat );
    info->setMagic( looseUnmarshalConstByteArray( dataIn, 8 ) );
    info->setVersion( dataIn->readInt() );
    info->setMarshalledProperties( looseUnmarshalByteArray( dataIn ) );
    info->afterUnmarshall( wireFormat );
}

///////////////////////////////////////////////////////////////////////////////
void WireFormatInfoMarshaller::looseMarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut ) throw( io::IOException ){
    WireFormatInfo* info =
        dynamic_cast<WireFormatInfo*>( dataStructure );
    info->beforeMarshall( wireFormat );
    BaseDataStreamMarshaller::looseMarshal( wireFormat, dataStructure, dataOut );

    dataOut->write( info->getMagic(), 0, 8 );
    dataOut->write( info->getVersion() );
    dataOut->write( info->getMarshalledProperties() != NULL );
    if( info->getMarshalledProperties() != NULL ) {
        dataOut->write( info->getMarshalledProperties().Length );
        dataOut->write( info->getMarshalledProperties() );
    }
    info->afterMarshall( wireFormat );
}

