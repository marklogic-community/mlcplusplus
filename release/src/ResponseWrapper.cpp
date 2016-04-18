/*
 * A header file to provide a C wrapping of the ConnectionFactory C++ class
 */
#include "ResponseWrapper.h"
#include "Response.hpp"
#include "ResponseCodes.hpp"

#ifdef __cplusplus
extern "C" {
#endif

// constructor/destructor
void response_delete(CResponse *resp) {
	using namespace mlclient;
	Response *t = (Response*)resp;
	delete t;
}

// member functions

const char* const response_Json(CResponse *resp) {
	using namespace mlclient;
	Response *t = (Response*)resp;
	const web::json::value& json = t->Json(); // NOTE: Json() can ONLY be called ONCE
	//std::cout << "JSON raw returned: " << json << std::endl;
	std::ostringstream stream;
	stream << json; // REQUIRED to get raw JSON as text, as serialize(void) does NOT work
	//t->Json().serialize(stream); // Doesn't work - blank result
	std::string asstr = stream.str();
	//std::cout << "JSON returned asstr: " << asstr << std::endl;
	static const std::string& statref = stream.str(); // REQUIRED to ensure reference to string, and thus contained c_str, is not destroyed
	//std::cout << "JSON returned statref: " << statref << std::endl;
	static const char* pref = statref.c_str(); // REQUIRED so we have a local char pointer that is not temporary, and thus destroyed at function's exit
	//std::cout << "JSON returned pref: " << pref << std::endl;
	//static const char* cstr = asstr.c_str();
	return pref;
}
const char* const response_Xml(CResponse *resp) {
	using namespace mlclient;
	Response *t = (Response*)resp;
	std::ostringstream os;
	t->Xml().save(os);
	static const char* cstr = os.str().c_str();
	return cstr;
}
const char* const response_String(CResponse *resp) {
	using namespace mlclient;
	Response *t = (Response*)resp;
	static const char* cstr = t->String().c_str(); // TODO fix this
	return cstr;
}
const int response_GetResponseType(CResponse *resp) {
	using namespace mlclient;
	Response *t = (Response*)resp;
	return (int)(t->GetResponseType());
}
const int response_GetResponseCode(CResponse *resp) {
	using namespace mlclient;
	Response *t = (Response*)resp;
	return (int)(t->GetResponseCode());
}

const char* const responsecodes_translate(int code) {
	using namespace mlclient;
	static const char* cd = ResponseCode::Translate((ResponseCodes)code).c_str();
	return cd;
}

#ifdef __cplusplus
}
#endif
