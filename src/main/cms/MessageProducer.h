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
 
#ifndef _CMS_MESSAGEPRODUCER_H_
#define _CMS_MESSAGEPRODUCER_H_

#include <cms/Config.h>
#include <cms/Message.h>
#include <cms/Destination.h>
#include <cms/Closeable.h>
#include <cms/CMSException.h>
#include <cms/DeliveryMode.h>

namespace cms
{
    /** 
     * defines the <code>MessageProducer</code> interface that is used
     * by all MessageProducer derivations.  This class defines the JMS
     * spec'd interface for a MessageProducer.
     */
    class CMS_API MessageProducer : public Closeable
    {
    public:

        virtual ~MessageProducer() {}
      
        /**
         * Sends the message to the default producer destination, but does
         * not take ownership of the message, caller must still destroy it.
         * Uses default values for deliveryMode, priority, and time to live.
         * @param message - a Message Object Pointer
         * @throws CMSException
         */
        virtual void send( Message* message ) throw ( CMSException ) = 0;             

        /**
         * Sends the message to the default producer destination, but does
         * not take ownership of the message, caller must still destroy it.
         * @param message - a Message Object Pointer
         * @param deliverMode The delivery mode to be used.
         * @param priority The priority for this message.
         * @param timeToLive The time to live value for this message in
         * milliseconds.
         * @throws CMSException
         */
        virtual void send( Message* message, int deliveryMode, int priority, 
            long long timeToLive) throw ( CMSException ) = 0;
            
        /**
         * Sends the message to the designated destination, but does
         * not take ownership of the message, caller must still destroy it.
         * Uses default values for deliveryMode, priority, and time to live.
         * @param destination - a Message Object Pointer
         * @param message - the message to send to the destination
         * @throws CMSException
         */
        virtual void send( const Destination* destination,
                           Message* message ) throw ( CMSException ) = 0;
                           
        /**
         * Sends the message to the designated destination, but does
         * not take ownership of the message, caller must still destroy it.
         * @param destination - a Message Object Pointer
         * @param message - a Message Object Pointer
         * @param deliverMode The delivery mode to be used.
         * @param priority The priority for this message.
         * @param timeToLive The time to live value for this message in
         * milliseconds.
         * @throws CMSException
         */     
        virtual void send( const Destination* destination,
            Message* message, int deliveryMode, int priority, 
            long long timeToLive) throw ( CMSException ) = 0;
            
        /** 
         * Sets the delivery mode for this Producer
         * @param mode - The DeliveryMode
         */
        virtual void setDeliveryMode( int mode ) = 0;
      
        /** 
         * Gets the delivery mode for this Producer
         * @return The DeliveryMode
         */
        virtual int getDeliveryMode() const = 0;
      
        /**
         * Sets if Message Ids are disbled for this Producer
         * @param value - boolean indicating enable / disable (true / false)
         */
        virtual void setDisableMessageID( bool value ) = 0;
      
        /**
         * Gets if Message Ids are disbled for this Producer
         * @return boolean indicating enable / disable (true / false)
         */
        virtual bool getDisableMessageID() const = 0;

        /**
         * Sets if Message Time Stamps are disbled for this Producer
         * @param value - boolean indicating enable / disable (true / false)
         */
        virtual void setDisableMessageTimeStamp( bool value ) = 0;
      
        /**
         * Gets if Message Time Stamps are disbled for this Producer
         * @return boolean indicating enable / disable (true / false)
         */
        virtual bool getDisableMessageTimeStamp() const = 0;
      
        /**
         * Sets the Priority that this Producers sends messages at
         * @param priority - int value for Priority level
         */
        virtual void setPriority( int priority ) = 0;
      
        /**
         * Gets the Priority level that this producer sends messages at
         * @return int based priority level
         */
        virtual int getPriority() const = 0;
      
        /**
         * Sets the Time to Live that this Producers sends messages with.  This
         * value will be used if the time to live is not specified via the
         * send method.
         * @param time - default time to live value in milliseconds
         */
        virtual void setTimeToLive( long long time ) = 0;
      
        /**
         * Gets the Time to Live that this producer sends messages with
         * @return Time to live value in milliseconds
         */
        virtual long long getTimeToLive() const = 0;
      
    };

}

#endif /*_CMS_MESSAGEPRODUCER_H_*/
