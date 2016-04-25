/*
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
