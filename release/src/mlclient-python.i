%module mlclientpython


%ignore operator=;
%ignore operator*;
%ignore operator->;
%ignore operator--;
%ignore operator++;
%ignore operator-;
%ignore operator+;
%ignore *::operator+;
%ignore operator<<;
%ignore *::operator<<;
%ignore operator>>;
%ignore *::operator>>;

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

%feature("autodoc", "3");

%{
/* Includes the header in the wrapper code */
#include "mlclient/mlclient.hpp"
#include "mlclient/Connection.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/Document.hpp"
#include "mlclient/DocumentSet.hpp"
#include "mlclient/HttpHeaders.hpp"
#include "mlclient/Response.hpp"
#include "mlclient/SearchDescription.hpp"
#include "mlclient/logging.hpp"
#include "mlclient/InvalidFormatException.hpp"
#include "mlclient/NoCredentialsException.hpp"
#include "mlclient/Permission.hpp"
#include "mlclient/SearchResult.hpp"
#include "mlclient/SearchResultSet.hpp"
#include "mlclient/ValuesResult.hpp"
#include "mlclient/ValuesResultSet.hpp"
#include "mlclient/utilities/CppRestJsonDocumentContent.hpp"
#include "mlclient/utilities/CppRestJsonHelper.hpp"
#include "mlclient/utilities/DocumentBatchHelper.hpp"
#include "mlclient/utilities/DocumentHelper.hpp"
#include "mlclient/utilities/ResponseHelper.hpp"
#include "mlclient/utilities/DocumentBatchWriter.hpp"
#include "mlclient/utilities/PugiXmlDocumentContent.hpp"
#include "mlclient/utilities/PugiXmlHelper.hpp"
#include "mlclient/utilities/SearchBuilder.hpp"
#include "mlclient/utilities/SearchOptionsBuilder.hpp"
%}

/* Parse the header file to generate wrappers */
/* WARNING - THESE MUST BE IN DEPENDENCY ORDER!!! ORDER IS VERY VERY IMPORTANT!!! */
%include "mlclient/mlclient.hpp"
%include "mlclient/logging.hpp"
%include "mlclient/DocumentContent.hpp"
%include "mlclient/Permission.hpp"
%include "mlclient/Document.hpp"
%include "mlclient/DocumentSet.hpp"
%include "mlclient/HttpHeaders.hpp"
%include "mlclient/Response.hpp"
%include "mlclient/SearchDescription.hpp"
%include "mlclient/SearchResult.hpp"
%include "mlclient/ValuesResult.hpp"
%include "mlclient/Connection.hpp"
%include "mlclient/SearchResultSet.hpp"
%include "mlclient/ValuesResultSet.hpp"
%include "mlclient/utilities/PugiXmlDocumentContent.hpp"
%include "mlclient/utilities/PugiXmlHelper.hpp"
%include "mlclient/utilities/CppRestJsonDocumentContent.hpp"
%include "mlclient/utilities/CppRestJsonHelper.hpp"
%include "mlclient/utilities/ResponseHelper.hpp"
%include "mlclient/utilities/DocumentHelper.hpp"
%include "mlclient/utilities/DocumentBatchWriter.hpp"
%include "mlclient/utilities/DocumentBatchHelper.hpp"
%include "mlclient/utilities/SearchBuilder.hpp"
%include "mlclient/utilities/SearchOptionsBuilder.hpp"
