/* File : mlclient-go.i */
%module mlclient

%feature("director:except") {
  throw Swig::DirectorMethodException($error);
}

%include std_except.i
%include std_string.i

%exceptionclass InvalidFormatException;
%exceptionclass NoCredentialsException;



%{
/* Includes the header in the wrapper code */
#include "Connection.hpp"
#include "DocumentContent.hpp"
#include "Response.hpp"
#include "SearchDescription.hpp"
%}
 
/* Parse the header file to generate wrappers */
%include "Connection.hpp"
%include "DocumentContent.hpp"
%include "Response.hpp"
%include "SearchDescription.hpp"