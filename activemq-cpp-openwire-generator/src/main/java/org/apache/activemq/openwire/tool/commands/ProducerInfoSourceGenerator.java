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
package org.apache.activemq.openwire.tool.commands;

import java.io.PrintWriter;

public class ProducerInfoSourceGenerator extends CommandSourceGenerator {

    protected void generateAdditionalMethods( PrintWriter out ) {
        out.println("////////////////////////////////////////////////////////////////////////////////");
        out.println("Pointer<RemoveInfo> ProducerInfo::createRemoveCommand() const {");
        out.println("    Pointer<RemoveInfo> info(new RemoveInfo());");
        out.println("    info->setResponseRequired(this->isResponseRequired());");
        out.println("    info->setObjectId(this->getProducerId());");
        out.println("    return info;");
        out.println("}");
        out.println("");

        super.generateAdditionalMethods(out);
    }
}
