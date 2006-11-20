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
#include <activemq/connector/openwire/commands/ActiveMQTextMessage.h>

using namespace std;
using namespace activemq;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;

////////////////////////////////////////////////////////////////////////////////
ActiveMQTextMessage::ActiveMQTextMessage()
{
}

////////////////////////////////////////////////////////////////////////////////
ActiveMQTextMessage::~ActiveMQTextMessage()
{
}

////////////////////////////////////////////////////////////////////////////////
unsigned char ActiveMQTextMessage::getDataStructureType() const
{
    return ActiveMQTextMessage::ID_ACTIVEMQTEXTMESSAGE; 
}

////////////////////////////////////////////////////////////////////////////////
void ActiveMQTextMessage::acknowledge(void) const throw( cms::CMSException ) {

    try{
        this->getAckHandler()->acknowledgeMessage( this );
    }
    AMQ_CATCH_RETHROW( exceptions::ActiveMQException )
    AMQ_CATCHALL_THROW( exceptions::ActiveMQException )
}
