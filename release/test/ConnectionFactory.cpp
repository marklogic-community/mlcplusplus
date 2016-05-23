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
 */
//
//  ConnectionFactory.cpp
//  Created by Adam Fowler on 27 Nov 2015.
//

#include "Connection.hpp"
#include "ConnectionFactory.hpp"
#include "internals/FakeConnection.hpp"

using namespace mlclient;

IConnection* ConnectionFactory::getConnection() {
  //Connection* conn = new Connection;
  // ALTER THE BELOW FOR YOUR OWN SYSTEM DURING TESTING
  //conn->configure("192.168.123.4","8122","admin","admin",false);
  // TODO change this based on a setting or compiler flag
  //static mlclient::internals::FakeConnection* conn = new mlclient::internals::FakeConnection;
  static mlclient::Connection* conn = new mlclient::Connection;
  static bool configured = false;
  if (!configured) {
    conn->configure("192.168.123.4","8122","admin","admin",false);
    configured = true;
  }
  return conn;
}

void ConnectionFactory::releaseConnection(IConnection* conn) {
  // do nothing for a fake connection
  // release back to 'pool' (i.e. for tests, do nothing, do NOT deallocate)
}
