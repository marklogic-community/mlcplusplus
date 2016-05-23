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
 *
 * A header file to provide a C wrapping of the ConnectionFactory C++ class
 */
#include "ResponseWrapper.h"
#include "Response.hpp"
#include "CWrapper.hpp"

#ifdef __cplusplus
extern "C" {
#endif

// constructor/destructor
void ml_response_delete(CResponse *resp) {
  using namespace mlclient;
  CWrapper<Response>* wrapper = (CWrapper<Response>*)resp;
  delete wrapper;
}

// member functions

const int ml_response_length(CResponse *resp) {
  using namespace mlclient;
  CWrapper<Response>* wrapper = (CWrapper<Response>*)resp;
  return wrapper->get().getContent().length();
}

const char* const ml_response_String(CResponse *resp) {
  using namespace mlclient;
  CWrapper<Response>* wrapper = (CWrapper<Response>*)resp;
  return wrapper->get().getContent().c_str();
}

const int ml_response_GetResponseType(CResponse *resp) {
  using namespace mlclient;
  CWrapper<Response>* wrapper = (CWrapper<Response>*)resp;
  return (int)(wrapper->get().getResponseType());
}

const int ml_response_GetResponseCode(CResponse *resp) {
  using namespace mlclient;
  CWrapper<Response>* wrapper = (CWrapper<Response>*)resp;
  return (int)(wrapper->get().getResponseCode());
}

const char* const ml_responsecodes_translate(int code) {
  using namespace mlclient;
  static const char* cd = mlclient::translate((ResponseCode)code).c_str();
  return cd;
}

#ifdef __cplusplus
} // end extern C
#endif
