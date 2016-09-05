%module(directors="1")  mlclientcs

%include <exception.i>

%include <typemaps.i>

%include std_except.i
%include std_string.i
%include std_vector.i
%include std_map.i
%include std_pair.i

%exceptionclass InvalidFormatException;
%exceptionclass NoCredentialsException;



/*
TODO add STL support
TODO figure out how to support DocumentSet given it's a typedef of std::vector, not a real C++ class in our library!
*/


%apply int { size_t };
%apply int { uint };

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

%{
/* Includes the header in the wrapper code */
#include "mlclient/mlclient.hpp"
#include "mlclient/Connection.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/Document.hpp"
#include "mlclient/Permission.hpp"
%}

SWIG_STD_VECTOR_ENHANCED(mlclient::Document)
SWIG_STD_VECTOR_ENHANCED(mlclient::Collection)
SWIG_STD_VECTOR_ENHANCED(mlclient::DocumentUri)

%apply int { std::vector<mlclient::Collection>::size_type };
%apply int { std::vector<mlclient::DocumentUri>::size_type };
%apply int { std::vector<mlclient::Document>::size_type };
%apply int { std::vector<mlclient::Permission>::size_type };

using namespace std;
namespace std {
  %template(DocumentSet) std::vector<mlclient::Document>;
  %template(PermissionSet) std::vector<mlclient::Permission>;
  %template(CollectionSet) std::vector<mlclient::Collection>;
  %template(DocumentUriSet) std::vector<mlclient::DocumentUri>;
}


%{
#include "mlclient/DocumentSet.hpp"
#include "mlclient/HttpHeaders.hpp"
#include "mlclient/Response.hpp"
#include "mlclient/SearchDescription.hpp"
#include "mlclient/logging.hpp"
#include "mlclient/InvalidFormatException.hpp"
#include "mlclient/NoCredentialsException.hpp"
#include "mlclient/SearchResult.hpp"
#include "mlclient/SearchResultSet.hpp"
#include "mlclient/ValuesResult.hpp"
#include "mlclient/ValuesResultSet.hpp"
%}

%feature("director") IBatchNotifiable;

/*
%nspace mlclient::utilities::CppRestJsonDocumentContent;
%nspace mlclient::utilities::CppRestJsonHelper;
%nspace mlclient::utilities::DocumentBatchHelper;
%nspace mlclient::utilities::DocumentHelper;
%nspace mlclient::utilities::ResponseHelper;
%nspace mlclient::utilities::DocumentBatchWriter;
%nspace mlclient::utilities::PugiXmlDocumentContent;
%nspace mlclient::utilities::PugiXmlHelper;
%nspace mlclient::utilities::SearchBuilder;
%nspace mlclient::utilities::AggregateInfo;
%nspace mlclient::utilities::CppRestJsonArrayNode;
%nspace mlclient::utilities::CppRestJsonContainerNode;
%nspace mlclient::utilities::CppRestJsonDocumentNavigator;
%nspace mlclient::utilities::CppRestJsonDocumentNode;
%nspace mlclient::utilities::CppRestJsonObjectNode;
%nspace mlclient::utilities::FacetOption;
%nspace mlclient::utilities::FragmentScope;
%nspace mlclient::utilities::GenericQuery;
%nspace mlclient::utilities::IBatchNotifiable;
%nspace mlclient::utilities::IContainerRef;
%nspace mlclient::utilities::ILexiconRef;
%nspace mlclient::utilities::IQuery;
%nspace mlclient::utilities::ITypedValue;
%nspace mlclient::utilities::JsonPropertyQuery;
%nspace mlclient::utilities::JsonPropertyRef;
%nspace mlclient::utilities::LexiconType;
%nspace mlclient::utilities::ITypedValue;
%nspace mlclient::utilities::PugiXmlArrayNode;
%nspace mlclient::utilities::PugiXmlContainerNode;
%nspace mlclient::utilities::PugiXmlDocumentNavigator;
%nspace mlclient::utilities::PugiXmlDocumentNode;
%nspace mlclient::utilities::PugiXmlObjectNode;
%nspace mlclient::utilities::QueryBuilderMode;
%nspace mlclient::utilities::RangeIndexType;
%nspace mlclient::utilities::RangeLexiconRef;
%nspace mlclient::utilities::RangeOperation;
%nspace mlclient::utilities::RangeOption;
%nspace mlclient::utilities::RangeOptions;
%nspace mlclient::utilities::TransactionMode;
%nspace mlclient::utilities::ValuesInfo;
%nspace mlclient::utilities::ValuesOption;
*/

%{
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
