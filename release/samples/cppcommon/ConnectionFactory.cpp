/*
 * Copyright (c) MarkLogic Corporation. All rights reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *  ConnectionFactory.cpp
 *  Created by Adam Fowler on 27 Nov 2015.
 */

#include "mlclient/Connection.hpp"
#include "ConnectionFactory.hpp"

using namespace mlclient;

Connection* ConnectionFactory::getConnection() {
  Connection* conn = new Connection;
  // ALTER THE BELOW FOR YOUR OWN SYSTEM DURING TESTING
  conn->configure("192.168.123.4","6697","admin","admin",false);
  return conn;
}
