%module mlclient_python



%feature("director:except") {
  throw Swig::DirectorMethodException($error);
}

%include std_except.i
%include std_string.i

%exceptionclass InvalidFormatException;
%exceptionclass NoCredentialsException;

/*
%exception { 
    try {
        $action
    } catch (mlclient::InvalidFormatException &e) {
        std::string s("InvalidFormatException: "), s2(e.what());
        s = s + s2;
        SWIG_exception(SWIG_RuntimeError, s.c_str());
    } catch (mlclient::NoCredentialsException &e) {
        std::string s("NoCredentialsException: "), s2(e.what());
        s = s + s2;
        SWIG_exception(SWIG_RuntimeError, s.c_str());
    } catch (...) {
        SWIG_exception(SWIG_RuntimeError, "unknown exception");
    }
}
*/

%{
/* Includes the header in the wrapper code */
#include "Connection.hpp"
#include "DocumentContent.hpp"
#include "HttpHeaders.hpp"
#include "Response.hpp"
#include "SearchDescription.hpp"
#include "InvalidFormatException.hpp"
#include "NoCredentialsException.hpp"
%}

/* Parse the header file to generate wrappers */
%include "DocumentContent.hpp"
%include "HttpHeaders.hpp"
%include "Response.hpp"
%include "SearchDescription.hpp"
