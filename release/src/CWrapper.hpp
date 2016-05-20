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
 * Creates a generic template for a wrapper holding a unique_ptr to an instance of an mlclient
 * object that needs to be held and casted to and from a C wrapper class.
 * Examples are CResponse -> std::unique_ptr<Response>
 * and CConnection -> std:unique_ptr<Connection>
 */

using namespace mlclient;

/**
 * \brief A template container allowing the holding of any C++ object within a wrapper accessible from C.
 *
 * See the ConnectionWrapper.h file for connecting to MarkLogic and making requests, the ResponseWrapper.h file for working
 * with the results from those calls.
 */
template <typename T>
class CWrapper {
public:
  CWrapper(T* obj) : ptr(obj) {
    ;
  }
  ~CWrapper() {
    ;
  }

  T& get() {
    return *ptr;
  }

private:
  T* ptr;
};
