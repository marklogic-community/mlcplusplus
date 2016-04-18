#include "CStructWrapper.h"
#include "CStruct.h"
#include "ResponseWrapper.h"
#include "Response.hpp"
#include <cpprest/json.h>

extern "C" {

void cstruct_unpack(CResponse* resp,struct sampledoc* obj) {
	using namespace mlclient;

	Response *t = (Response *)resp; // now have the C++ object

	// custom unpacking C++ code - as JSON and XML wrappers are C++, not C
	// This code has to be custom as C and C++ DO NOT do introspection of a struct
	const web::json::value& jsonValue = t->Json();
	//std::cout << "Web JSON value&: " << jsonValue << std::endl;
	const web::json::object& jsonObject = jsonValue.as_object();
	static const std::string firstString = jsonObject.at("first").as_string(); // COPY VALUE
	//std::cout << "first value string: " << firstString << std::endl;
	static const char* first = firstString.c_str();
	//std::cout << "first value char*: " << first << std::endl;
	obj->first = const_cast<char*>(first);
	static const std::string secondString = jsonObject.at("second").as_string(); // keeps parent string around
	static const char* second = secondString.c_str(); // creates pointer to contained c string
	obj->second = const_cast<char*>(second); // no longer a hanging pointer
}


}
