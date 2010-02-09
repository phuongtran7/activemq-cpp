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

#include "ReaderTest.h"

#include <decaf/io/Reader.h>
#include <decaf/nio/CharBuffer.h>
#include <decaf/lang/Math.h>
#include <decaf/lang/exceptions/IndexOutOfBoundsException.h>

#include <vector>

using namespace decaf;
using namespace decaf::io;
using namespace decaf::nio;
using namespace decaf::lang;
using namespace decaf::lang::exceptions;

////////////////////////////////////////////////////////////////////////////////
namespace decaf{
namespace io{

    class MockReader : public decaf::io::Reader {
    private:

        std::vector<char> contents;

        std::size_t current_offset;
        std::size_t length;

    public:

        MockReader() : Reader() {
            this->current_offset = 0;
            this->length = 0;
        }

        MockReader( std::vector<char>& data ) : Reader() {
            this->contents = data;
            this->length = contents.size();
            this->current_offset = 0;
        }

        virtual void close() throw( decaf::io::IOException ) {
            contents.clear();
        }

        virtual int read( char* buffer, std::size_t offset, std::size_t length )
            throw( decaf::io::IOException,
                   decaf::lang::exceptions::NullPointerException ) {

            if( contents.empty() ) {
                return -1;
            }
            if( this->length <= current_offset ) {
                return -1;
            }

            length = Math::min( (long long)length, (long long)( this->length - current_offset ) );
            for( std::size_t i = 0; i < length; i++ ) {
                buffer[offset + i] = contents[current_offset + i];
            }

            current_offset += length;
            return length;
        }

        virtual int read( decaf::nio::CharBuffer* charBuffer )
                 throw( decaf::io::IOException,
                        decaf::lang::exceptions::NullPointerException,
                        decaf::nio::ReadOnlyBufferException ) {

            return Reader::read( charBuffer );
        }

        virtual int read() throw( decaf::io::IOException ) {
            return Reader::read();
        }

        virtual int read( std::vector<char>& buffer )
            throw( decaf::io::IOException ) {

            return Reader::read( buffer );
        }

    };

}}

////////////////////////////////////////////////////////////////////////////////
ReaderTest::ReaderTest() {
}

////////////////////////////////////////////////////////////////////////////////
ReaderTest::~ReaderTest() {
}

////////////////////////////////////////////////////////////////////////////////
void ReaderTest::testReaderCharBufferNull() {

    std::string s = "MY TEST STRING";
    std::vector<char> srcBuffer( s.begin(), s.end() );
    MockReader mockReader( srcBuffer );

    CharBuffer* charBuffer = NULL;

    CPPUNIT_ASSERT_THROW_MESSAGE(
        "Should throw an NullPointerException",
        mockReader.read( charBuffer ),
        NullPointerException );
}

////////////////////////////////////////////////////////////////////////////////
void ReaderTest::testReaderCharBufferZeroChar() {

    // the charBuffer has the capacity of 0, then there the number of char read
    // to the CharBuffer is 0. Furthermore, the MockReader is intact in its content.
    std::string s = "MY TEST STRING";
    std::vector<char> srcBuffer( s.begin(), s.end() );

    MockReader mockReader( srcBuffer );
    CharBuffer* charBuffer = CharBuffer::allocate( 0 );

    int result = mockReader.read( charBuffer );
    CPPUNIT_ASSERT_EQUAL( 0, result );
    std::vector<char> destBuffer( srcBuffer.size() );
    mockReader.read( destBuffer );
    CPPUNIT_ASSERT_EQUAL( s, std::string( destBuffer.begin(), destBuffer.end() ) );

    delete charBuffer;
}

////////////////////////////////////////////////////////////////////////////////
void ReaderTest::testReaderCharBufferChar() {

    std::string s = "MY TEST STRING";
    std::vector<char> srcBuffer( s.begin(), s.end() );
    const int CHARBUFFER_SIZE = 10;
    MockReader mockReader( srcBuffer );
    CharBuffer* charBuffer = CharBuffer::allocate( CHARBUFFER_SIZE );
    charBuffer->append( 'A' );
    const int CHARBUFFER_REMAINING = charBuffer->remaining();
    int result = mockReader.read( charBuffer );

    CPPUNIT_ASSERT_EQUAL( CHARBUFFER_REMAINING, result );
    charBuffer->rewind();

    CharSequence* subseq =
        charBuffer->subSequence( CHARBUFFER_SIZE - CHARBUFFER_REMAINING, CHARBUFFER_SIZE );

    CPPUNIT_ASSERT_EQUAL( s.substr( 0, CHARBUFFER_REMAINING ),
                          subseq->toString() );

    delete subseq;

    std::vector<char> destBuffer( srcBuffer.size() - CHARBUFFER_REMAINING );

    mockReader.read( destBuffer );
    CPPUNIT_ASSERT_EQUAL( s.substr( CHARBUFFER_REMAINING ),
                          std::string( destBuffer.begin(), destBuffer.end() ) );

    delete charBuffer;
}

////////////////////////////////////////////////////////////////////////////////
void ReaderTest::testMark() {

    MockReader mockReader;
    CPPUNIT_ASSERT_THROW_MESSAGE(
        "Should throw IOException for Reader do not support mark",
        mockReader.mark(0),
        IOException );
}

////////////////////////////////////////////////////////////////////////////////
void ReaderTest::testRead() {

    MockReader reader;

    // return -1 when the stream is null;
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Should be equal to -1", -1, reader.read());

    std::string s = "MY TEST STRING";
    std::vector<char> srcBuffer( s.begin(), s.end() );
    MockReader mockReader(srcBuffer);

    // normal read
    for( std::size_t ix = 0; ix < srcBuffer.size(); ++ix ) {

        char c = srcBuffer[ix];
        CPPUNIT_ASSERT_EQUAL_MESSAGE(
            std::string( "Should be equal to \'" ) + c + "\'",
            (int)c, mockReader.read() );
    }

    // return -1 when read Out of Index
    mockReader.read();
    CPPUNIT_ASSERT_EQUAL_MESSAGE( "Should be equal to -1", -1, reader.read() );
}

////////////////////////////////////////////////////////////////////////////////
void ReaderTest::testReady() {
    MockReader mockReader;
    CPPUNIT_ASSERT_MESSAGE( "Should always return false", !mockReader.ready() );
}

////////////////////////////////////////////////////////////////////////////////
void ReaderTest::testReset() {

    MockReader mockReader;
    CPPUNIT_ASSERT_THROW_MESSAGE(
        "Should throw an IOException",
        mockReader.reset(),
        IOException );
}

////////////////////////////////////////////////////////////////////////////////
void ReaderTest::testSkip() {
    std::string s = "MY TEST STRING";
    std::vector<char> srcBuffer( s.begin(), s.end() );
    int length = srcBuffer.size();
    MockReader mockReader( srcBuffer );
    CPPUNIT_ASSERT_EQUAL_MESSAGE( "Should be equal to \'M\'", (int)'M', mockReader.read() );

    // normal skip
    mockReader.skip( length / 2 );
    CPPUNIT_ASSERT_EQUAL_MESSAGE( "Should be equal to \'S\'", (int)'S', mockReader.read() );

    // try to skip a bigger number of characters than the total
    // Should do nothing
    mockReader.skip( length );
}