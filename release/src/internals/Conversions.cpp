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
/**
 * \file Conversions.cpp
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \date 2016-06-20
 * \since 8.0.2
 */
#include "mlclient/internals/Conversions.hpp"

#include <string>
#include <iostream>

// JSON and HTTP includes
#include <cpprest/json.h>

// NOTE Deliberately in the global namespace

/**
 * Converts a web::json::value to a string
 * @param os Output Stream (E.g. std::cout)
 * @param rt web::json::value const reference
 * @return
 */
/*
std::ostream& operator << (std::ostream& os, const web::json::value& rt) {
	os << rt.serialize();
	return os;
}
*/