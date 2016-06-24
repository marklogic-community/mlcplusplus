%module mlclientcsharp



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
#include "mlclient/Connection.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/HttpHeaders.hpp"
#include "mlclient/Response.hpp"
#include "mlclient/SearchDescription.hpp"
#include "mlclient/InvalidFormatException.hpp"
#include "mlclient/NoCredentialsException.hpp"
%}

/* Parse the header file to generate wrappers */
/* WARNING - THESE MUST BE IN DEPENDENCY ORDER!!! ORDER IS VERY VERY IMPORTANT!!! */
%include "mlclient/DocumentContent.hpp"
%include "mlclient/HttpHeaders.hpp"
%include "mlclient/Response.hpp"
%include "mlclient/SearchDescription.hpp"
%include "mlclient/Connection.hpp"
