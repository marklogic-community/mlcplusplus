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
//  ConnectionFactory.hpp
//  Created by Adam Fowler on 27 Nov 2015.
//

#ifndef __Scratch__ConnectionFactory__
#define __Scratch__ConnectionFactory__

#include <mlclient/Connection.hpp>

using namespace mlclient;

class ConnectionFactory {
public:
  static IConnection* getConnection();
  static void releaseConnection(IConnection* conn);
private:
  ConnectionFactory();
  virtual ~ConnectionFactory();
};

#endif /* define __Scratch__ConnectionFactory__ */
