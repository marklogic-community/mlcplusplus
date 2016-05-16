//
//  ConnectionFactory.hpp
//  Scratch
//
//  Created by Adam Fowler on 27 Nov 2015.
//  Copyright (c) 2015 Adam Fowler. All rights reserved.
//

#ifndef __Scratch__ConnectionFactory__
#define __Scratch__ConnectionFactory__

#include <mlclient.hpp>
#include "Connection.hpp"

using namespace mlclient;

class ConnectionFactory {
public:
  static IConnection* getConnection(void);
private:
  ConnectionFactory();
  virtual ~ConnectionFactory();
};

#endif /* define __Scratch__ConnectionFactory__ */
