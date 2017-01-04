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
 */
#include "CStructWrapper.h"
#include "CStruct.h"
#include <mlclient/ResponseWrapper.h>
#include <mlclient/Response.hpp>
#include <mlclient/utilities/CppRestJsonHelper.hpp>
#include <mlclient/utilities/PugiXmlHelper.hpp>
#include <cpprest/json.h>
#include <mlclient/CWrapper.hpp>

extern "C" {

void ml_samples_cstruct_unpack(CResponse* resp,struct ml_samples_sampledoc* obj) {
  using namespace mlclient;
  using namespace mlclient::utilities;

  //Response *t = (Response *)resp; // now have the C++ object
  CWrapper<Response>* wrapper = (CWrapper<Response>*)resp;
  Response& t = wrapper->get();

  const std::string& fs = t.getContent();
  //std::string& fsr = fs; // hold a reference to the string
  //return fs.c_str();
  std::cout << "raw content: " << fs << std::endl;

  const int rt = ml_response_GetResponseType(resp);
  if (rt == RESPONSETYPE_JSON) {
    // custom unpacking C++ code - as JSON and XML wrappers are C++, not C
    // This code has to be custom as C and C++ DO NOT do introspection of a struct
    //std::cout << "Web JSON string value: " << t->String() << std::endl;
    const web::json::value& jsonValue = CppRestJsonHelper::fromResponse(t);
    std::cout << "Web JSON value&: "; jsonValue.serialize(std::cout);std::cout << std::endl;
    const web::json::object& jsonObject = jsonValue.as_object();
    static const std::string firstString = utility::conversions::to_utf8string(jsonObject.at(U("first")).as_string()); // COPY VALUE
    std::cout << "first value string: " << firstString << std::endl;
    static const char* first = firstString.c_str();
    std::cout << "first value char*: " << first << std::endl;
    obj->first = const_cast<char*>(first);
    static const std::string secondString = utility::conversions::to_utf8string(jsonObject.at(U("second")).as_string()); // keeps parent string around
    static const char* second = secondString.c_str(); // creates pointer to contained c string
    obj->second = const_cast<char*>(second); // no longer a hanging pointer
  } else {
    // assume XML
    const std::unique_ptr<pugi::xml_document> doc = PugiXmlHelper::fromResponse(t);
    const pugi::xml_node& root = doc->root();
    //std::cout << "root node name: " << root.name() << std::endl;
    const pugi::xml_node& docroot = root.child("docroot");
    //std::cout << "docroot node name: " << docroot.name() << std::endl;
    static const char* firstChar = docroot.child("first").text().get();
    static const char* secondChar = docroot.child("second").text().get();
    //std::cout << "first char: " << firstChar << std::endl;
    //std::cout << "second char: " << secondChar << std::endl;
    obj->first = const_cast<char *>(firstChar);
    obj->second = const_cast<char *>(secondChar);
  }
}


}
