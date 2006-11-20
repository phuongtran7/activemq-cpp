/**
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

#include <activemq/connector/openwire/marshal/BaseDataStreamMarshaller.h>
#include <activemq/connector/openwire/commands/MessageId.h>
#include <activemq/connector/openwire/commands/ProducerId.h>
#include <activemq/connector/openwire/commands/TransactionId.h>
#include <activemq/connector/openwire/commands/LocalTransactionId.h>
#include <activemq/connector/openwire/commands/XATransactionId.h>
#include <activemq/connector/openwire/commands/BrokerError.h>
#include <activemq/connector/openwire/utils/HexTable.h>
#include <activemq/exceptions/ActiveMQException.h>
#include <activemq/util/Long.h>
#include <activemq/util/Integer.h>

using namespace std;
using namespace activemq;
using namespace activemq::io;
using namespace activemq::util;
using namespace activemq::exceptions;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::marshal;
using namespace activemq::connector::openwire::commands;
using namespace activemq::connector::openwire::utils;

////////////////////////////////////////////////////////////////////////////////
commands::DataStructure* BaseDataStreamMarshaller::tightUnmarshalCachedObject(
    OpenWireFormat* wireFormat, 
    io::DataInputStream* dataIn,
    utils::BooleanStream* bs ) throw ( io::IOException ) {
    
    try{
        return wireFormat->tightUnmarshalNestedObject( dataIn, bs );
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
int BaseDataStreamMarshaller::tightMarshalCachedObject1( 
    OpenWireFormat* wireFormat, 
    commands::DataStructure* data, 
    utils::BooleanStream* bs ) 
        throw ( io::IOException ) {
             
    try{
        return wireFormat->tightMarshalNestedObject1( data, bs ); 
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
void BaseDataStreamMarshaller::tightMarshalCachedObject2( 
    OpenWireFormat* wireFormat, 
    commands::DataStructure* data, 
    io::DataOutputStream* dataOut, 
    utils::BooleanStream* bs ) 
        throw ( io::IOException ) {
            
    try{
        wireFormat->tightMarshalNestedObject2( data, dataOut, bs );
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
void BaseDataStreamMarshaller::looseMarshalCachedObject( 
    OpenWireFormat* wireFormat, 
    commands::DataStructure* data, 
    io::DataOutputStream* dataOut ) 
        throw ( io::IOException ) {
            
    try{
        wireFormat->looseMarshalNestedObject( data, dataOut );
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
commands::DataStructure* BaseDataStreamMarshaller::looseUnmarshalCachedObject( 
    OpenWireFormat* wireFormat, 
    io::DataInputStream* dataIn ) throw ( io::IOException ) {
        
    try{
        return wireFormat->looseUnmarshalNestedObject( dataIn ); 
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
int BaseDataStreamMarshaller::tightMarshalNestedObject1( 
    OpenWireFormat* wireFormat, 
    commands::DataStructure* object, 
    utils::BooleanStream* bs ) 
        throw ( io::IOException ) {
             
    try{
        return wireFormat->tightMarshalNestedObject1( object, bs ); 
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
} 

////////////////////////////////////////////////////////////////////////////////
void BaseDataStreamMarshaller::tightMarshalNestedObject2( 
    OpenWireFormat* wireFormat, 
    commands::DataStructure* object, 
    io::DataOutputStream* dataOut, 
    utils::BooleanStream* bs ) 
        throw ( io::IOException ) {

    try{
        wireFormat->tightMarshalNestedObject2( object, dataOut, bs );
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
commands::DataStructure* BaseDataStreamMarshaller::tightUnmarshalNestedObject(
    OpenWireFormat* wireFormat,
    io::DataInputStream* dataIn,
    utils::BooleanStream* bs ) 
        throw ( io::IOException ) {
         
    try{
        return wireFormat->tightUnmarshalNestedObject( dataIn, bs ); 
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
commands::DataStructure* BaseDataStreamMarshaller::looseUnmarshalNestedObject( 
    OpenWireFormat* wireFormat,
    io::DataInputStream* dataIn ) 
        throw ( io::IOException ) { 
    
    try{
        return wireFormat->looseUnmarshalNestedObject( dataIn ); 
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
void BaseDataStreamMarshaller::looseMarshalNestedObject( 
    OpenWireFormat* wireFormat, 
    commands::DataStructure* object, 
    io::DataOutputStream* dataOut ) 
        throw ( io::IOException ) {
            
    try{
        wireFormat->looseMarshalNestedObject( object, dataOut );
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
std::string BaseDataStreamMarshaller::tightUnmarshalString( 
    io::DataInputStream* dataIn, 
    utils::BooleanStream* bs ) throw ( io::IOException ) {

    try{
        
        if( bs->readBoolean() ) {

            if (bs->readBoolean() ) {
                return this->readAsciiString( dataIn );
            } else {
                return dataIn->readUTF();
            }
        } else {
            return "";
        }
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
int BaseDataStreamMarshaller::tightMarshalString1( const std::string& value, 
                                                   utils::BooleanStream* bs ) 
                                                    throw ( io::IOException ) {
    try{
        
        bs->writeBoolean( value == "" );
        if( value != "" )
        {
            int strlen = value.length();
            
            int utflen = 0;
            int c = 0;
            bool isOnlyAscii = true;
            
            for( int i = 0; i < strlen; ++i ) {
                
                c = value[i];
                if( (c >= 0x0001) && (c <= 0x007F) )  // ASCII char
                {
                    utflen++;
                }
                else if( c > 0x07FF )
                {
                    utflen += 3;
                    isOnlyAscii = false;
                }
                else
                {
                    isOnlyAscii = false;
                    utflen += 2;
                }
            }
            
            if( utflen >= 0x10000 ) {
                throw IOException(
                    __FILE__, __LINE__,
                    "BaseDataStreamMarshaller::tightMarshalString1 - "
                    "Encountered a String value that is too long to encode." );
            }
            
            bs->writeBoolean( isOnlyAscii );
            return utflen + 2;
        }
        else
        {
            return 0;
        }
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
void BaseDataStreamMarshaller::tightMarshalString2( 
    const std::string& value, 
    io::DataOutputStream* dataOut, 
    utils::BooleanStream* bs ) throw ( io::IOException ) {

    try{

        if( bs->readBoolean() ) {

            // If we verified it only holds ascii values
            if( bs->readBoolean() ) {

                dataOut->writeShort( (short)value.length() );
                dataOut->writeBytes( value );

            } else {
                dataOut->writeChars( value );
            }
        }
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
void BaseDataStreamMarshaller::looseMarshalString( 
    const std::string value, 
    io::DataOutputStream* dataOut ) throw ( io::IOException ) {
        
    try{
        
        dataOut->writeBoolean( value != "" );
        if( value != "" )
        {
            dataOut->writeBytes( value );
        }
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}
                                 
////////////////////////////////////////////////////////////////////////////////
std::string BaseDataStreamMarshaller::looseUnmarshalString( 
    io::DataInputStream* dataIn ) throw ( io::IOException ) {
        
    try{
        if( dataIn->readBoolean() ) {
            return dataIn->readUTF();   // TODO
        } else {
            return "";
        }
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
int BaseDataStreamMarshaller::tightMarshalLong1( OpenWireFormat* wireFormat, 
                                                 long long value,
                                                 utils::BooleanStream* bs ) 
                                                    throw ( io::IOException ) {

    try{
        
        if( value == 0L )
        {
            bs->writeBoolean( false );
            bs->writeBoolean( false );
            return 0;
        }
        else
        {
            unsigned long long ul = (unsigned long long)value;
            if( (ul & 0xFFFFFFFFFFFF0000LL) == 0LL )
            {
                bs->writeBoolean(false);
                bs->writeBoolean(true);
                return 2;
            }
            else if( (ul & 0xFFFFFFFF00000000LL) == 0LL )
            {
                bs->writeBoolean(true);
                bs->writeBoolean(false);
                return 4;
            }
            else
            {
                bs->writeBoolean(true);
                bs->writeBoolean(true);
                return 8;
            }
        }
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
void BaseDataStreamMarshaller::tightMarshalLong2( OpenWireFormat* wireFormat, 
                                                  long long value, 
                                                  io::DataOutputStream* dataOut, 
                                                  utils::BooleanStream* bs ) 
                                                    throw ( io::IOException ) {
    try{
        
        if( bs->readBoolean() ) {

            if( bs->readBoolean() ) {
                dataOut->writeLong( value );
            } else {
                dataOut->writeInt( (int)value );
            }
            
        } else {
            
            if( bs->readBoolean() ) {
                dataOut->writeShort( (short)value );
            }
        }
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
long long BaseDataStreamMarshaller::tightUnmarshalLong( 
    OpenWireFormat* wireFormat, 
    io::DataInputStream* dataIn, 
    utils::BooleanStream* bs ) 
        throw ( io::IOException ) {

    try{
        if( bs->readBoolean() ) {
            
            if( bs->readBoolean() ) {
                return dataIn->readLong();
            } else {
                return dataIn->readInt();
            }
            
        } else {
            
            if( bs->readBoolean()) {
                return dataIn->readShort();
            } else {
                return 0;
            }
        }
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
void BaseDataStreamMarshaller::looseMarshalLong( OpenWireFormat* wireFormat, 
                                                 long long value, 
                                                 io::DataOutputStream* dataOut ) 
                                                    throw ( io::IOException ) {

    try{
        dataOut->writeLong( value );
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
long long BaseDataStreamMarshaller::looseUnmarshalLong( 
    OpenWireFormat* wireFormat, 
    io::DataInputStream* dataIn ) 
        throw ( io::IOException ) { 

    try{
        
        return dataIn->readLong();
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
commands::DataStructure* BaseDataStreamMarshaller::tightUnmarshalBrokerError( 
    OpenWireFormat* wireFormat, 
    io::DataInputStream* dataIn, 
    utils::BooleanStream* bs ) throw ( io::IOException ) {

    try{

        if( bs->readBoolean() )
        {
            BrokerError* answer = new BrokerError();
            
            answer->setExceptionClass( tightUnmarshalString( dataIn, bs ) );
            answer->setMessage( tightUnmarshalString( dataIn, bs ) );
            
            if( wireFormat->isStackTraceEnabled() )
            {
                short length = dataIn->readShort();
                std::vector< BrokerError::StackTraceElement* > stackTrace;
                
                for( int i = 0; i < length; ++i )
                {
                    BrokerError::StackTraceElement* element = 
                        new BrokerError::StackTraceElement;
                    
                    element->ClassName = tightUnmarshalString( dataIn, bs );
                    element->MethodName = tightUnmarshalString( dataIn, bs );
                    element->FileName = tightUnmarshalString( dataIn, bs );
                    element->LineNumber = dataIn->readInt();
                    stackTrace.push_back( element );
                }
                answer->setStackTraceElements( stackTrace );
                answer->setCause( dynamic_cast<BrokerError*>( 
                    tightUnmarshalBrokerError( wireFormat, dataIn, bs ) ) );
            }
            return answer;
        }
        else
        {
            return NULL;
        }
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}
    
////////////////////////////////////////////////////////////////////////////////
int BaseDataStreamMarshaller::tightMarshalBrokerError1( 
    OpenWireFormat* wireFormat, 
    commands::DataStructure* data, 
    utils::BooleanStream* bs ) 
        throw ( io::IOException ) 
{
    try{

        BrokerError* error = dynamic_cast<BrokerError*>( data );

        if( error == NULL ) {
            
            bs->writeBoolean( false );
            return 0;
            
        } else {
            
            int rc = 0;
            bs->writeBoolean( true );
            rc += tightMarshalString1( error->getExceptionClass(), bs );
            rc += tightMarshalString1( error->getMessage(), bs );
            
            if( wireFormat->isStackTraceEnabled() ) {

                rc += 2;
                
                for( int i = 0; i < error->getStackTraceElements().size(); ++i ) {
                    
                    const BrokerError::StackTraceElement* element = 
                        error->getStackTraceElements()[i];
                    rc += tightMarshalString1( element->ClassName, bs );
                    rc += tightMarshalString1( element->MethodName, bs );
                    rc += tightMarshalString1( element->FileName, bs );
                    rc += 4;
                }
                rc += tightMarshalBrokerError1( wireFormat, error->getCause(), bs );
            }
            
            return rc;
        }
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}
                                      
////////////////////////////////////////////////////////////////////////////////
void BaseDataStreamMarshaller::tightMarshalBrokerError2( 
    OpenWireFormat* wireFormat, 
    commands::DataStructure* data, 
    io::DataOutputStream* dataOut, 
    utils::BooleanStream* bs )
        throw ( io::IOException ) {

    try{

        if( bs->readBoolean() ) {
            
            BrokerError* error = dynamic_cast<BrokerError*>( data );
            
            tightMarshalString2( error->getExceptionClass(), dataOut, bs );
            tightMarshalString2( error->getMessage(), dataOut, bs );
            
            if( wireFormat->isStackTraceEnabled() ) {
                
                int length = (short)error->getStackTraceElements().size();
                dataOut->writeShort( (short)length );
                
                for( int i = 0; i < length; ++i ) {
                    
                    BrokerError::StackTraceElement* element = 
                        error->getStackTraceElements()[i];
                        
                    tightMarshalString2( element->ClassName, dataOut, bs );
                    tightMarshalString2( element->MethodName, dataOut, bs );
                    tightMarshalString2( element->FileName, dataOut, bs );
                    dataOut->writeInt( element->LineNumber );
                }
                
                tightMarshalBrokerError2( 
                    wireFormat, error->getCause(), dataOut, bs );
            }
        }        
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}
                                       
////////////////////////////////////////////////////////////////////////////////
commands::DataStructure* BaseDataStreamMarshaller::looseUnmarshalBrokerError( 
    OpenWireFormat* wireFormat, 
    io::DataInputStream* dataIn ) 
        throw ( io::IOException ) { 

    try{
        
        if( dataIn->readBoolean() ) {
            
            BrokerError* answer = new BrokerError();
            
            answer->setExceptionClass( looseUnmarshalString( dataIn ) );
            answer->setMessage( looseUnmarshalString( dataIn ) );
            
            if( wireFormat->isStackTraceEnabled() ) {
                
                short length = dataIn->readShort();
                std::vector< BrokerError::StackTraceElement* > stackTrace;
                
                for( int i = 0; i < length; ++i ) {
                    
                    BrokerError::StackTraceElement* element = 
                        new BrokerError::StackTraceElement;
                    
                    element->ClassName = looseUnmarshalString( dataIn );
                    element->MethodName = looseUnmarshalString( dataIn );
                    element->FileName = looseUnmarshalString( dataIn );
                    element->LineNumber = dataIn->readInt();
                    
                    stackTrace.push_back( element );
                }
                answer->setStackTraceElements( stackTrace );
                answer->setCause( dynamic_cast<BrokerError*>(
                    looseUnmarshalBrokerError( wireFormat, dataIn ) ) );
            }
            
            return answer;
            
        } else {
            return NULL;
        }
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}
    
////////////////////////////////////////////////////////////////////////////////
void BaseDataStreamMarshaller::looseMarshalBrokerError( 
    OpenWireFormat* wireFormat, 
    commands::DataStructure* data, 
    io::DataOutputStream* dataOut ) 
        throw ( io::IOException ) {

    try{
        
        BrokerError* error = dynamic_cast<BrokerError*>( data );
        
        dataOut->write( error != NULL );
        
        if( error != NULL ){
            
            looseMarshalString( error->getExceptionClass(), dataOut );
            looseMarshalString( error->getMessage(), dataOut );
            
            if( wireFormat->isStackTraceEnabled() ) {
                
                int length = error->getStackTraceElements().size();
                
                dataOut->writeShort( (short)length );
                
                for( int i = 0; i < length; ++i ) {
                    
                    BrokerError::StackTraceElement* element = 
                        error->getStackTraceElements()[i];
                        
                    looseMarshalString( element->ClassName, dataOut );
                    looseMarshalString( element->MethodName, dataOut );
                    looseMarshalString( element->FileName, dataOut );
                    
                    dataOut->writeInt( element->LineNumber );
                }
                
                looseMarshalBrokerError( wireFormat, error->getCause(), dataOut );
            }
        }
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
std::vector<unsigned char> BaseDataStreamMarshaller::tightUnmarshalByteArray( 
    io::DataInputStream* dataIn, 
    utils::BooleanStream* bs ) 
        throw ( io::IOException ) {

    try{
        
        std::vector<unsigned char> data;
                
        if( bs->readBoolean() ) {
            int size = dataIn->readInt();
            data.resize( size );
            dataIn->readFully( data );
        }
        
        return data;
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
std::vector<unsigned char> BaseDataStreamMarshaller::looseUnmarshalByteArray( 
    io::DataInputStream* dataIn ) 
        throw ( io::IOException ) {  

    try{
        int size = dataIn->readInt();
        std::vector<unsigned char> data;
        data.resize( size );
        dataIn->readFully( data );
        return data;
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
std::vector<unsigned char> BaseDataStreamMarshaller::tightUnmarshalConstByteArray( 
    io::DataInputStream* dataIn, 
    utils::BooleanStream* bs, 
    int size ) 
        throw ( io::IOException ) {
         
    try{
        std::vector<unsigned char> data;
        data.resize( size );
        dataIn->readFully( data );
        return data;
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
std::vector<unsigned char> BaseDataStreamMarshaller::looseUnmarshalConstByteArray( 
    io::DataInputStream* dataIn, 
    int size ) 
        throw ( io::IOException ) { 

    try{
        std::vector<unsigned char> data;
        data.resize( size );
        dataIn->readFully( data );
        return data;
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
std::string BaseDataStreamMarshaller::toString( const commands::MessageId* id )
{
    if( id == NULL ) return "";
    
    return toString( id->getProducerId() ) + ":" + 
           Long::toString( id->getProducerSequenceId() );
}

////////////////////////////////////////////////////////////////////////////////
std::string BaseDataStreamMarshaller::toString( const commands::ProducerId* id )
{
    return id->getConnectionId() + ":" + 
           Long::toString( id->getSessionId() ) + ":" + 
           Long::toString( id->getValue() );
}

////////////////////////////////////////////////////////////////////////////////
std::string BaseDataStreamMarshaller::toString( const commands::TransactionId* txnId )
{
    const LocalTransactionId* ltxnId = 
        dynamic_cast<const LocalTransactionId*>( txnId );
    const XATransactionId* xaTxnId = 
        dynamic_cast<const XATransactionId*>( txnId );
        
    if( ltxnId != NULL )
    {
        return Long::toString( ltxnId->getValue() );
    }
    else if( xaTxnId != NULL )
    {
        return string("XID:") + Integer::toString( xaTxnId->getFormatId() ) + ":" + 
               toHexFromBytes( xaTxnId->getGlobalTransactionId() ) + ":" + 
               toHexFromBytes( xaTxnId->getBranchQualifier() );        
    }

    return "";
}

////////////////////////////////////////////////////////////////////////////////
std::string BaseDataStreamMarshaller::toHexFromBytes( 
    const std::vector<unsigned char>& data )
{
    std::string buffer = "";
    
    for( int i = 0; i < data.size(); i++ )
    {
        buffer.append( hexTable[ data[i] ] );
    }
    
    return buffer;
}

////////////////////////////////////////////////////////////////////////////////
std::string BaseDataStreamMarshaller::readAsciiString( 
    io::DataInputStream* dataIn )
        throw ( io::IOException )
{
    try{
        
        int size = dataIn->readShort() + 1; // add space c++ NULL
        unsigned char* data = new unsigned char[size];        
        dataIn->readFully( data, 0, size-1 );
        data[size] = 0;  // enforce NULL
        
        // Now build a string and copy data into it.
        std::string text;
        text.resize( size );
        text.copy( (char*)data, size );
        delete data;
        
        return text; 
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, IOException )
    AMQ_CATCHALL_THROW( IOException )    
}
