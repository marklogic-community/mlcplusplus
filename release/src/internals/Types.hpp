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

#include "../MLCPlusPlus.hpp"

namespace mlclient {

namespace internals {

typedef std::map<std::string, std::string> header_t; // TODO what is this for???
typedef std::multimap<std::string, std::string> params_t; // TODO what is this for???

}

}

#endif
