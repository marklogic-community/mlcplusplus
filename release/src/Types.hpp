//
//  Types.h
//  Scratch
//
//  Created by Paul Hoehne on 6/4/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#ifndef Scratch_Types_h
#define Scratch_Types_h

#include <map>
#include <string>

#include "MLCPlusPlus.hpp"

namespace mlclient {

typedef std::map<std::string, std::string> header_t;
typedef std::multimap<std::string, std::string> params_t;

}

#endif
