%module(directors="1")  mlclientcs

%include <exception.i>
%include <typemaps.i>

%include std_except.i
%include stl.i

%exceptionclass InvalidFormatException;
%exceptionclass NoCredentialsException;

%apply int { uint };
%apply int { int32_t };

/*
%exception {
  try {
    $action
  } catch (const std::exception& e) {
    SWIG_exception(SWIG_RuntimeError, e.what());
  }
}
*/

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

%feature("director") IDocumentContent;

%ignore mlclient::reconfigureLogging(int argc,const char *argv[]);
//%rename(FacetOptionMap) SWIGTYPE_p_FacetOptionMap;
//%rename(FacetOptionMap) SWIGTYPE_p_std__mapT_mlclient__utilities__FacetOption_std__string_std__lessT_mlclient__utilities__FacetOption_t_t;
//%rename(FacetOption) SWIGTYPE_p_std__mapT_mlclient__utilities__FacetOption_std__string_std__lessT_mlclient__utilities__FacetOption_t_t__key_type;
//%rename(string) SWIGTYPE_p_std__mapT_mlclient__utilities__FacetOption_std__string_std__lessT_mlclient__utilities__FacetOption_t_t__mapped_type;


%{
/* Includes the header in the wrapper code */
#include "mlclient/mlclient.hpp"
%}

%template(StringMap) std::map<std::string,std::string>;
%template(SearchSuggestionSet) std::vector<std::string>;


%{
#include "mlclient/Connection.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/Document.hpp"
#include "mlclient/Permission.hpp"
%}


SWIG_STD_VECTOR_ENHANCED(mlclient::Document)
SWIG_STD_VECTOR_ENHANCED(mlclient::Collection)
SWIG_STD_VECTOR_ENHANCED(mlclient::DocumentUri)

%apply size_t { std::vector<mlclient::Collection>::size_type };
%apply size_t { std::vector<mlclient::DocumentUri>::size_type };
%apply size_t { std::vector<mlclient::Document>::size_type };
%apply size_t { std::vector<mlclient::Permission>::size_type };

%template(DocumentSet) std::vector<mlclient::Document>;
%template(PermissionSet) std::vector<mlclient::Permission>;
%template(CollectionSet) std::vector<mlclient::Collection>;
%template(DocumentUriSet) std::vector<mlclient::DocumentUri>;


%{
#include "mlclient/DocumentSet.hpp"
#include "mlclient/HttpHeaders.hpp"
%}

%apply std::string *INPUT { std::string *content };
%apply std::string &&INPUT { std::string&& content };

%ignore mlclient::Response::setContent(std::string &&);

%{
#include "mlclient/Response.hpp"
#include "mlclient/SearchDescription.hpp"
#include "mlclient/logging.hpp"
#include "mlclient/InvalidFormatException.hpp"
#include "mlclient/NoCredentialsException.hpp"
#include "mlclient/SearchResult.hpp"
#include "mlclient/SearchResultSet.hpp"
//#include "mlclient/ValuesResult.hpp"
%}
/*
SWIG_STD_VECTOR_ENHANCED(mlclient::ValuesResultAggregate)
%apply size_t { std::vector<mlclient::ValuesResultAggregate>::size_type };
%template(ValuesResultAggregateSet) std::vector<mlclient::ValuesResultAggregate>;

SWIG_STD_VECTOR_ENHANCED(mlclient::ValuesResultValue)
%apply size_t { std::vector<mlclient::ValuesResultValue>::size_type };
%template(ValuesResultValueSet) std::vector<mlclient::ValuesResultValue>;
*/
%{
//#include "mlclient/ValuesResultSet.hpp"
%}


%feature("director") IBatchNotifiable;
//%feature("director") ILexiconRef; // throws ostream private constructor error
//%feature("director") IQuery; // throws ostream private constructor error


%{
// #include "mlclient/utilities/CppRestJsonDocumentContent.hpp"
%}
/*
SWIG_STD_VECTOR_ENHANCED(mlclient::utilities::IQuery*)
%apply size_t { std::vector<mlclient::utilities::IQuery*>::size_type };
%template(IQuerySet) std::vector<mlclient::utilities::IQuery*>;
*/
%{
// #include "mlclient/utilities/CppRestJsonHelper.hpp"
#include "mlclient/utilities/DocumentBatchHelper.hpp"
#include "mlclient/utilities/DocumentHelper.hpp"
//#include "mlclient/utilities/ResponseHelper.hpp"
#include "mlclient/utilities/DocumentBatchWriter.hpp"
// #include "mlclient/utilities/PugiXmlDocumentContent.hpp"
// #include "mlclient/utilities/PugiXmlHelper.hpp"
//#include "mlclient/utilities/SearchBuilder.hpp"
//#include "mlclient/utilities/SearchOptionsBuilder.hpp"
%}

%apply size_t { mlclient::utilities::FacetOption }
/*
%template(FacetOptionMap) std::map<mlclient::utilities::FacetOption,std::string,std::less<mlclient::utilities::FacetOption>>;


%apply size_t { std::map<mlclient::utilities::FacetOption,std::string,std::less<mlclient::utilities::FacetOption>>::size_type };
%apply mlclient::utilities::FacetOption { std::map<mlclient::utilities::FacetOption,std::string,std::less<mlclient::utilities::FacetOption>>::key_type };
%apply std::string { std::map<mlclient::utilities::FacetOption,std::string,std::less<mlclient::utilities::FacetOption>>::mapped_type };


//%apply size_t { std::map<mlclient::utilities::RangeOption,std::string,std::less<mlclient::utilities::RangeOption>>::size_type };
//%apply size_t { std::map<mlclient::utilities::ValuesOption,std::string,std::less<mlclient::utilities::ValuesOption>>::size_type };

//%template(FacetOptionMap) std::map<mlclient::utilities::FacetOption,std::string>;

%template(RangeOptionMap) std::map<mlclient::utilities::RangeOption,std::string,std::less<mlclient::utilities::RangeOption>>;
%template(ValuesOptionMap) std::map<mlclient::utilities::ValuesOption,std::string,std::less<mlclient::utilities::ValuesOption>>;

*/



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
//%include "mlclient/ValuesResult.hpp"
%include "mlclient/Connection.hpp"
%include "mlclient/SearchResultSet.hpp"
//%include "mlclient/ValuesResultSet.hpp"
// %include "mlclient/utilities/PugiXmlDocumentContent.hpp"
// %include "mlclient/utilities/PugiXmlHelper.hpp"
// %include "mlclient/utilities/CppRestJsonDocumentContent.hpp"
// %include "mlclient/utilities/CppRestJsonHelper.hpp"
//%include "mlclient/utilities/ResponseHelper.hpp"
%include "mlclient/utilities/DocumentHelper.hpp"
%include "mlclient/utilities/DocumentBatchWriter.hpp"
%include "mlclient/utilities/DocumentBatchHelper.hpp"
//%include "mlclient/utilities/SearchBuilder.hpp"
//%include "mlclient/utilities/SearchOptionsBuilder.hpp"
