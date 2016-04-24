/*
 * A header file to provide a C wrapping of the ConnectionFactory C++ class
 */
#include "ResponseWrapper.h"
#include "Response.hpp"
#include "ResponseCodes.hpp"
#include "CWrapper.hpp"

#ifdef __cplusplus
extern "C" {
#endif

// constructor/destructor
void ml_response_delete(CResponse *resp) {
  using namespace mlclient;
  //CResponseWrapper* wrapper = (CResponseWrapper*)resp;
  CWrapper<Response>* wrapper = (CWrapper<Response>*)resp;

  //Response *t = (Response*)(wrapper->get());
  //delete t;
  delete wrapper;
}

// member functions

const int ml_response_length(CResponse *resp) {
  using namespace mlclient;
  CWrapper<Response>* wrapper = (CWrapper<Response>*)resp;
  //Response *t = (Response*)(wrapper->get());
  return wrapper->get().getContent().length();
}
/*
void response_Json(CResponse *resp,char* buffer) {
	using namespace mlclient;
	//Response *t = (Response*)resp;
	CWrapper<Response>* wrapper = (CWrapper<Response>*)resp;
	std::cout << "Calling get" << std::endl;
	Response *t = (Response*)(wrapper->get());
	std::cout << "fetching json" << std::endl;

	std::string str = t->String();
	std::cout << "raw string: " << str << std::endl;
	const char* cstr = str.c_str();
	std::cout << "c string: " << cstr << std::endl;
	int length = strlen(cstr);
	std::cout << "length: " << length << std::endl;
	strncpy(buffer,cstr,length);
 */

// ISSUE STARTS AFTER HERE
//web::json::value json = t->Json(); // NOTE: Json() can ONLY be called ONCE
// BYPASS JSON AND GET THE STRING ITSELF

/*
	std::string str = t->String();
	const char* cstr = str.c_str();
	static char *argv;
		int length = strlen(cstr);
		argv = new char[length + 1]();
		strncpy(argv, cstr, length);
	return argv;
 */

/*
	std::cout << "JSON raw returned: " << json << std::endl;
	std::ostringstream stream;
	stream << json; // REQUIRED to get raw JSON as text, as serialize(void) does NOT work
	//t->Json().serialize(stream); // Doesn't work - blank result
	std::string asstr = stream.str();
	std::cout << "JSON returned asstr: " << asstr << std::endl;
	static const std::string& statref = stream.str(); // REQUIRED to ensure reference to string, and thus contained c_str, is not destroyed
	std::cout << "JSON returned statref: " << statref << std::endl;
	static const char* pref = statref.c_str(); // REQUIRED so we have a local char pointer that is not temporary, and thus destroyed at function's exit
	std::cout << "JSON returned pref: " << pref << std::endl;
	//static const char* cstr = asstr.c_str();
	/
 * char *argv;
	int length = strlen(pref);
	argv = new char[length + 1]();
	strncpy(argv, pref, length);
	/
	return pref;
 */
//}
/*
const char* const response_Xml(CResponse *resp) {
	using namespace mlclient;
	Response *t = (Response*)resp;
	std::ostringstream os;
	t->Xml().save(os);
	static const char* cstr = os.str().c_str();
	return cstr;
}*/
const char* const ml_response_String(CResponse *resp) {
  using namespace mlclient;
  //Response *t = (Response*)resp;
  CWrapper<Response>* wrapper = (CWrapper<Response>*)resp;
  //std::cout << "Calling get" << std::endl;
  //Response *t = (Response*)();
  //static const char* cstr = ; // TODO fix this
  //std::string& fs = t->String();
  //std::cout << "response_String: " << wrapper->get().String() << std::endl;
  return wrapper->get().getContent().c_str();
}
const int ml_response_GetResponseType(CResponse *resp) {
  using namespace mlclient;
  //Response *t = (Response*)resp;
  CWrapper<Response>* wrapper = (CWrapper<Response>*)resp;
  //Response *t = (Response*)();
  return (int)(wrapper->get().getResponseType());
}
const int ml_response_GetResponseCode(CResponse *resp) {
  using namespace mlclient;
  //Response *t = (Response*)resp;
  CWrapper<Response>* wrapper = (CWrapper<Response>*)resp;
  //Response *t = (Response*)(wrapper->get());
  return (int)(wrapper->get().getResponseCode());
}

const char* const ml_responsecodes_translate(int code) {
  using namespace mlclient;
  static const char* cd = mlclient::translate((ResponseCode)code).c_str();
  return cd;
}

#ifdef __cplusplus
}
#endif
