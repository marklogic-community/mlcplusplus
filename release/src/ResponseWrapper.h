///
/// \file ResponseWrapper.h
/// \brief A header file to provide a C wrapping of the Response C++ class
/// \since 8.0.0
/// \author Adam Fowler <adam.fowler@marklogic.com>
/// \date 2016-04-18
///

#ifndef RESPONSEWRAPPER_H
#define RESPONSEWRAPPER_H


typedef void CResponse;


#ifdef __cplusplus

extern "C" {
#endif

// constants
// from ResponseCodes.h
/// \brief Unknown response type. Equivalent to C++ ResponseType::UNKNOWN_TYPE
#define RESPONSETYPE_UNKNOWN	0
/// \brief XML Response type. Equivalent to C++ ResponseType::XML
#define RESPONSETYPE_XML		1
/// \brief JSON Response type. Equivalent to C++ ResponseType::JSON
#define RESPONSETYPE_JSON		2
/// \brief Text Response type. Equivalent to C++ ResponseType::TEXT
#define RESPONSETYPE_TEXT		3
/// \brief Binary Response type. Equivalent to C++ ResponseType::BINARY
#define RESPONSETYPE_BINARY		4

// destructor (constructed via CConnection)
/// \brief Safely deletes a CResponse pointer (Response C++ instance)
void ml_response_delete(CResponse *t);

// member functions
/// \brief Returns the response length (string length) of the response object in character count. Equivalent to Response::getLength
const int ml_response_length(CResponse *t);
/// \brief Returns the response as a string. Equivalent to Response::getString
const char* const ml_response_String(CResponse *t);
/// \brief Returns the Response Type enum value for this response
const int ml_response_GetResponseType(CResponse *t);
/// \brief Returns the HTTP response code for this response
const int ml_response_GetResponseCode(CResponse *t);

/// Returns the textual description for the specified response HTTP code
const char* const ml_responsecodes_translate(int code);

#ifdef __cplusplus
}
#endif





#endif
