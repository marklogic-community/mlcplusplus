//
//  ConnectionFactory.hpp
//  Scratch
//
//  Created by Adam Fowler on 27 Nov 2015.
//  Copyright (c) 2015 Adam Fowler. All rights reserved.
//

#include "MLCPlusPlus.hpp"
#include "Connection.hpp"

using namespace mlclient;

class ConnectionFactory {
public:
  static Connection* getConnection(void);
private:
  ConnectionFactory();
  virtual ~ConnectionFactory();
};
