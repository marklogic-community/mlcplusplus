// nugettest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <mlclient/Connection.hpp>

int main()
{
  mlclient::IConnection* conn = new mlclient::Connection();
  std::cout << "Successfully got mlclient Connection instance" << std::endl;
  return 0;
}

