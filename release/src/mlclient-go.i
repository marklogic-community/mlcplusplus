/* File : mlclient-go.i */
%module mlclient-go
%{
/* Includes the header in the wrapper code */
#include "Connection.hpp"
#include "DocumentContent.hpp"
#include "InvalidFormatException.hpp"
#include "NoCredentialsException.hpp"
#include "Response.hpp"
#include "SearchDescription.hpp"
%}
 
/* Parse the header file to generate wrappers */
%include "header.h"
%include "DocumentContent.hpp"
%include "InvalidFormatException.hpp"
%include "NoCredentialsException.hpp"
%include "Response.hpp"
%include "SearchDescription.hpp"