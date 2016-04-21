/*
 * A header file to provide a C wrapping of the Response C++ class
 */

#ifndef RESPONSEWRAPPER_H
#define RESPONSEWRAPPER_H


typedef void CResponse;


#ifdef __cplusplus

extern "C" {
#endif

// constants
// from ResponseCodes.h
#define RESPONSETYPE_UNKNOWN	0
#define RESPONSETYPE_XML		1
#define RESPONSETYPE_JSON		2
#define RESPONSETYPE_TEXT		3
#define RESPONSETYPE_BINARY		4

// destructor
void response_delete(CResponse *t);

// member functions

const int response_length(CResponse *t);
//void response_Json(CResponse *t,char* buffer);
// TODO member function for converting JSON (or XML) response to a provided c struct type
const char* const response_String(CResponse *t);
//const char* const response_Xml(CResponse *t);
const int response_GetResponseType(CResponse *t);
const int response_GetResponseCode(CResponse *t);

const char* const responsecodes_translate(int code);

#ifdef __cplusplus
}
#endif





#endif
