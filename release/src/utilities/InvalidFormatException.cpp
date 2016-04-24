//
//  InvalidFormatException.cpp
//
//  Created by Adam Fowler on 18 Apr 2016
//  Copyright (c) 2016 Adam Fowler. All rights reserved.
//

#include "../mlclient.hpp"
#include "InvalidFormatException.hpp"


namespace mlclient {

namespace utilities {

const char* InvalidFormatException::what(void) const throw() {
  return "Response is not of the required type for requested function/operation to be carried out";
}

}
}
