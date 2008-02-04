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

#include "CmsTemplateTest.h"
#include <activemq/cmsutil/DynamicDestinationResolver.h>
#include <activemq/cmsutil/ResourceLifecycleManager.h>
#include "DummyConnectionFactory.h"

CPPUNIT_TEST_SUITE_REGISTRATION( activemq::cmsutil::CmsTemplateTest );

using namespace activemq;
using namespace activemq::cmsutil;

////////////////////////////////////////////////////////////////////////////////
void CmsTemplateTest::setUp() {
    cf = new DummyConnectionFactory();
    cmsTemplate = new CmsTemplate(cf);
    cmsTemplate->setDefaultDestinationName("test");
    cmsTemplate->init();
}

////////////////////////////////////////////////////////////////////////////////
void CmsTemplateTest::tearDown() {
    cmsTemplate->destroy();
    delete cmsTemplate;
    delete cf;
}

////////////////////////////////////////////////////////////////////////////////
void CmsTemplateTest::testExecuteSession() {

    try {
        cmsTemplate->setSessionAcknowledgeMode(cms::Session::CLIENT_ACKNOWLEDGE);
        
        // Test basics.
        MySessionCallback sessionCallback;    
        cmsTemplate->execute(&sessionCallback);    
        CPPUNIT_ASSERT(sessionCallback.session != NULL);
        CPPUNIT_ASSERT(sessionCallback.ackMode == cms::Session::CLIENT_ACKNOWLEDGE);
        
        // Try again and make sure we get the same session
        MySessionCallback sessionCallback2;
        cmsTemplate->execute(&sessionCallback2);    
        CPPUNIT_ASSERT(sessionCallback2.session == sessionCallback.session);
        CPPUNIT_ASSERT(sessionCallback2.ackMode == cms::Session::CLIENT_ACKNOWLEDGE);
        
        // Now try different ack mode and make sure we have a different session.
        cmsTemplate->setSessionAcknowledgeMode(cms::Session::AUTO_ACKNOWLEDGE);
        MySessionCallback sessionCallback3;
        cmsTemplate->execute(&sessionCallback3);  
        CPPUNIT_ASSERT(sessionCallback3.session != NULL);
        CPPUNIT_ASSERT(sessionCallback3.session != sessionCallback.session);
        CPPUNIT_ASSERT(sessionCallback3.ackMode == cms::Session::AUTO_ACKNOWLEDGE);
        
    } catch( cms::CMSException& e) {
        e.printStackTrace();
    }
}

////////////////////////////////////////////////////////////////////////////////
void CmsTemplateTest::testExecuteProducer() {
    
    try {
        
        cmsTemplate->setPubSubDomain(false);
        
        // Set the pass-thru values that will be applied to the producer.
        cmsTemplate->setDeliveryMode(1);
        cmsTemplate->setTimeToLive(100);
        cmsTemplate->setPriority(5);
        cmsTemplate->setMessageTimestampEnabled(true);
        cmsTemplate->setMessageIdEnabled(true);
       
        // Test basics.
        MyProducerCallback callback;    
        cmsTemplate->execute(&callback);    
        CPPUNIT_ASSERT(callback.session != NULL);
        CPPUNIT_ASSERT(callback.producer != NULL);
        
        // Check the pass-thru values from CmsTemplate
        CPPUNIT_ASSERT_EQUAL(1, callback.producer->getDeliveryMode());
        CPPUNIT_ASSERT_EQUAL(100LL, callback.producer->getTimeToLive());
        CPPUNIT_ASSERT_EQUAL(5, callback.producer->getPriority());
        CPPUNIT_ASSERT_EQUAL(false, callback.producer->getDisableMessageID());
        CPPUNIT_ASSERT_EQUAL(false, callback.producer->getDisableMessageTimeStamp());
    
        // Try again and make sure we have the same producer
        MyProducerCallback callback2;    
        cmsTemplate->execute(&callback2);    
        CPPUNIT_ASSERT(callback2.session == callback.session);
        CPPUNIT_ASSERT(callback2.producer == callback.producer);
        
        // Change to topics and make sure it's a different producer.
        cmsTemplate->setPubSubDomain(true);
        MyProducerCallback callback3;    
        cmsTemplate->execute(&callback3);    
        CPPUNIT_ASSERT(callback3.session == callback.session);
        CPPUNIT_ASSERT(callback3.producer != callback.producer);
        
        // Now change destination name and make sure it's different yet again.
        cmsTemplate->setDefaultDestinationName("fred");
        MyProducerCallback callback4;    
        cmsTemplate->execute(&callback4);    
        CPPUNIT_ASSERT(callback4.session == callback.session);
        CPPUNIT_ASSERT(callback4.producer != callback3.producer);
        
        // Change the pass-thru values
        cmsTemplate->setDeliveryMode(0);
        cmsTemplate->setTimeToLive(1000);
        cmsTemplate->setPriority(7);
        cmsTemplate->setMessageTimestampEnabled(false);
        cmsTemplate->setMessageIdEnabled(false);
        
        // Now with the producer from the test 4, verify that the pass-thru
        // values are changed.
        MyProducerCallback callback5;    
        cmsTemplate->execute(&callback5);    
        CPPUNIT_ASSERT(callback5.session == callback.session);
        CPPUNIT_ASSERT(callback5.producer == callback4.producer);
        CPPUNIT_ASSERT_EQUAL(0, callback5.producer->getDeliveryMode());
        CPPUNIT_ASSERT_EQUAL(1000LL, callback5.producer->getTimeToLive());
        CPPUNIT_ASSERT_EQUAL(7, callback5.producer->getPriority());
        CPPUNIT_ASSERT_EQUAL(true, callback5.producer->getDisableMessageID());
        CPPUNIT_ASSERT_EQUAL(true, callback5.producer->getDisableMessageTimeStamp());
                
    } catch( cms::CMSException& e) {
        e.printStackTrace();
    }
}

