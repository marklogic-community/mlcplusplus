#include "CStructWrapper.h"
#include "CStruct.h"
#include "ResponseWrapper.h"
#include "Response.hpp"
#include <cpprest/json.h>
#include <pugixml.hpp>
#include "CWrapper.hpp"

extern "C" {

void cstruct_unpack(CResponse* resp,struct sampledoc* obj) {
  using namespace mlclient;

  //Response *t = (Response *)resp; // now have the C++ object
  CWrapper<Response>* wrapper = (CWrapper<Response>*)resp;
  Response& t = wrapper->get();

  std::string& fs = t.asString();
  //std::string& fsr = fs; // hold a reference to the string
  //return fs.c_str();
  std::cout << "raw content: " << fs << std::endl;

  const int rt = response_GetResponseType(resp);
  if (rt == RESPONSETYPE_JSON) {
    // custom unpacking C++ code - as JSON and XML wrappers are C++, not C
    // This code has to be custom as C and C++ DO NOT do introspection of a struct
    //std::cout << "Web JSON string value: " << t->String() << std::endl;
    const web::json::value& jsonValue = t.asJson();
    std::cout << "Web JSON value&: " << jsonValue << std::endl;
    const web::json::object& jsonObject = jsonValue.as_object();
    static const std::string firstString = jsonObject.at("first").as_string(); // COPY VALUE
    std::cout << "first value string: " << firstString << std::endl;
    static const char* first = firstString.c_str();
    std::cout << "first value char*: " << first << std::endl;
    obj->first = const_cast<char*>(first);
    static const std::string secondString = jsonObject.at("second").as_string(); // keeps parent string around
    static const char* second = secondString.c_str(); // creates pointer to contained c string
    obj->second = const_cast<char*>(second); // no longer a hanging pointer
  } else {
    // assume XML
    const pugi::xml_document& doc = t.asXml();
    const pugi::xml_node& root = doc.root();
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
