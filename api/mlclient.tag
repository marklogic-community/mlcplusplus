<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile>
  <compound kind="file">
    <name>Connection.hpp</name>
    <path>/Users/adamfowler/Documents/marklogic/git/mlcplusplus/release/src/</path>
    <filename>_connection_8hpp</filename>
    <includes id="_document_content_8hpp" name="DocumentContent.hpp" local="yes" imported="no">DocumentContent.hpp</includes>
    <includes id="_search_description_8hpp" name="SearchDescription.hpp" local="yes" imported="no">SearchDescription.hpp</includes>
    <class kind="class">mlclient::Connection</class>
    <namespace>mlclient</namespace>
  </compound>
  <compound kind="file">
    <name>ConnectionWrapper.h</name>
    <path>/Users/adamfowler/Documents/marklogic/git/mlcplusplus/release/src/</path>
    <filename>_connection_wrapper_8h</filename>
    <member kind="function">
      <type>CConnection *</type>
      <name>ml_connection_new</name>
      <anchorfile>_connection_wrapper_8h.html</anchorfile>
      <anchor>a0f9f96ce7400bf0f66d951c499f039ce</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>ml_connection_delete</name>
      <anchorfile>_connection_wrapper_8h.html</anchorfile>
      <anchor>a613b334d14483b593a62a82dd357d093</anchor>
      <arglist>(CConnection *t)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>ml_connection_configure</name>
      <anchorfile>_connection_wrapper_8h.html</anchorfile>
      <anchor>a39f47ecbe026017cb9964e238481fd5b</anchor>
      <arglist>(const CConnection *conn, const char *hostname, const char *port, const char *username, const char *password, const int usessl)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DocumentContent.hpp</name>
    <path>/Users/adamfowler/Documents/marklogic/git/mlcplusplus/release/src/</path>
    <filename>_document_content_8hpp</filename>
    <class kind="class">mlclient::IDocumentContent</class>
    <class kind="class">mlclient::ITextDocumentContent</class>
    <class kind="class">mlclient::GenericTextDocumentContent</class>
    <class kind="class">mlclient::IBinaryDocumentContent</class>
    <namespace>mlclient</namespace>
    <member kind="enumeration">
      <type></type>
      <name>BinaryEncoding</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>ad47ff6baab050e78452eb2167a2a3b54</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>SearchDescription.hpp</name>
    <path>/Users/adamfowler/Documents/marklogic/git/mlcplusplus/release/src/</path>
    <filename>_search_description_8hpp</filename>
    <includes id="_document_content_8hpp" name="DocumentContent.hpp" local="yes" imported="no">DocumentContent.hpp</includes>
    <class kind="class">mlclient::SearchDescription</class>
    <namespace>mlclient</namespace>
  </compound>
  <compound kind="file">
    <name>PugiXmlHelper.hpp</name>
    <path>/Users/adamfowler/Documents/marklogic/git/mlcplusplus/release/src/utilities/</path>
    <filename>_pugi_xml_helper_8hpp</filename>
    <includes id="_document_content_8hpp" name="DocumentContent.hpp" local="yes" imported="no">../DocumentContent.hpp</includes>
    <class kind="class">mlclient::utilities::PugiXmlHelper</class>
    <namespace>mlclient</namespace>
    <namespace>mlclient::utilities</namespace>
  </compound>
  <compound kind="class">
    <name>mlclient::Connection</name>
    <filename>classmlclient_1_1_connection.html</filename>
    <member kind="function">
      <type></type>
      <name>Connection</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>ac135be7c9c00c0d66a9d84a0525373e3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~Connection</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>abdcaf6fb409edc750246fa1f1bcb3953</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>configure</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a864eb69ce6f54a34532fc3ea649b8e82</anchor>
      <arglist>(const std::string &amp;hostname, const std::string &amp;port, const std::string &amp;username, const std::string &amp;password, const bool usessl=false)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>configure</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a716b1aee10f890f3ce5051648445fb83</anchor>
      <arglist>(const std::string &amp;hostname, const std::string &amp;port, const std::string &amp;username, const std::string &amp;password)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDatabaseName</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a35b2b58a54bf1f5f96e72f8a4ecee10b</anchor>
      <arglist>(const std::string &amp;db)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>getDatabaseName</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a431277f6777ce8e30988c846537a5dde</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>doGet</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>ae5da2adac3a3bc58f1b23ffe4f5b31ff</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>doPut</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a44f935f37c386a616eeef89728f9692f</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>doPost</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a1205e9e925ea521c3c7727c67431b6fa</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>doDelete</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a5a19f3a64d7e8a9293571a05ba782d55</anchor>
      <arglist>(const std::string &amp;pathAndQueryString)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>getDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a43032fb517b52f967d942668e9707939</anchor>
      <arglist>(const std::string &amp;uri)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>saveDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a9b042fe6311d603c13220648e90c073b</anchor>
      <arglist>(const std::string &amp;uri, const IDocumentContent &amp;payload)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>deleteDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>ad28e88100e5fd070e0d9c69ce7bb8417</anchor>
      <arglist>(const std::string &amp;uri)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>search</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>aa8573e1cb107975c675befb93e02c2cd</anchor>
      <arglist>(const SearchDescription &amp;desc)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>configure</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a864eb69ce6f54a34532fc3ea649b8e82</anchor>
      <arglist>(const std::string &amp;hostname, const std::string &amp;port, const std::string &amp;username, const std::string &amp;password, const bool usessl=false)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>configure</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a716b1aee10f890f3ce5051648445fb83</anchor>
      <arglist>(const std::string &amp;hostname, const std::string &amp;port, const std::string &amp;username, const std::string &amp;password)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDatabaseName</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a35b2b58a54bf1f5f96e72f8a4ecee10b</anchor>
      <arglist>(const std::string &amp;db)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>getDatabaseName</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a431277f6777ce8e30988c846537a5dde</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>doGet</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>ae5da2adac3a3bc58f1b23ffe4f5b31ff</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>doPut</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a44f935f37c386a616eeef89728f9692f</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>doPost</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a1205e9e925ea521c3c7727c67431b6fa</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>doDelete</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a5a19f3a64d7e8a9293571a05ba782d55</anchor>
      <arglist>(const std::string &amp;pathAndQueryString)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>getDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a43032fb517b52f967d942668e9707939</anchor>
      <arglist>(const std::string &amp;uri)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>saveDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a9b042fe6311d603c13220648e90c073b</anchor>
      <arglist>(const std::string &amp;uri, const IDocumentContent &amp;payload)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>deleteDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>ad28e88100e5fd070e0d9c69ce7bb8417</anchor>
      <arglist>(const std::string &amp;uri)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>search</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>aa8573e1cb107975c675befb93e02c2cd</anchor>
      <arglist>(const SearchDescription &amp;desc)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::CppRestJsonDocumentContent</name>
    <filename>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</filename>
    <base>mlclient::ITextDocumentContent</base>
    <member kind="function">
      <type></type>
      <name>CppRestJsonDocumentContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>abf2fdf83328540c53e2a54c04cfac5fb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~CppRestJsonDocumentContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a724d370d8fb0b851557b013cb05d48a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>af9018322b3e967ed3041affbad11831a</anchor>
      <arglist>(const web::json::value &amp;json)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream *</type>
      <name>getStream</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>af39265eb985910665a2097c4784371c1</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a1424d0bac3e03350bf943a0043944584</anchor>
      <arglist>(std::string content) override</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>getContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a2597ba7ca0d8c17a5be610894afa2ecc</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>getMimeType</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a08f053568a7c54781402db0bd36dffa0</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setMimeType</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>aa7e571e60255efcdc21ea5f56e6fbed8</anchor>
      <arglist>(const std::string &amp;mt) override</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getLength</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a595f0785725d2aaca64740bff492e222</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>web::json::value &amp;</type>
      <name>getJson</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a84d84494235c260a31735ac92640e45c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>af9018322b3e967ed3041affbad11831a</anchor>
      <arglist>(const web::json::value &amp;json)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream *</type>
      <name>getStream</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>af39265eb985910665a2097c4784371c1</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a1424d0bac3e03350bf943a0043944584</anchor>
      <arglist>(std::string content) override</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>getContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a2597ba7ca0d8c17a5be610894afa2ecc</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>getMimeType</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a08f053568a7c54781402db0bd36dffa0</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setMimeType</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>aa7e571e60255efcdc21ea5f56e6fbed8</anchor>
      <arglist>(const std::string &amp;mt) override</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getLength</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a595f0785725d2aaca64740bff492e222</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>web::json::value &amp;</type>
      <name>getJson</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a84d84494235c260a31735ac92640e45c</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::CppRestJsonHelper</name>
    <filename>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</filename>
    <member kind="function" static="yes">
      <type>static ITextDocumentContent *</type>
      <name>toDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>adaeb5213b9be3d09eab78b7adeebd2b5</anchor>
      <arglist>(const web::json::value json)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static web::json::value</type>
      <name>fromDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>a9453c8574f5455c41712c81c02c090c9</anchor>
      <arglist>(const IDocumentContent &amp;doc)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static web::json::value</type>
      <name>fromResponse</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>a549fde831bf5144b19c029e710fecb80</anchor>
      <arglist>(const Response &amp;resp)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static ITextDocumentContent *</type>
      <name>toDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>adaeb5213b9be3d09eab78b7adeebd2b5</anchor>
      <arglist>(const web::json::value json)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static web::json::value</type>
      <name>fromDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>a9453c8574f5455c41712c81c02c090c9</anchor>
      <arglist>(const IDocumentContent &amp;doc)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static web::json::value</type>
      <name>fromResponse</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>a549fde831bf5144b19c029e710fecb80</anchor>
      <arglist>(const Response &amp;resp)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CWrapper</name>
    <filename>class_c_wrapper.html</filename>
    <templarg></templarg>
  </compound>
  <compound kind="class">
    <name>mlclient::GenericTextDocumentContent</name>
    <filename>classmlclient_1_1_generic_text_document_content.html</filename>
    <base>mlclient::ITextDocumentContent</base>
    <member kind="function">
      <type></type>
      <name>GenericTextDocumentContent</name>
      <anchorfile>classmlclient_1_1_generic_text_document_content.html</anchorfile>
      <anchor>a4b6d427ab361ed48fa3d76bfa2a35805</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>GenericTextDocumentContent</name>
      <anchorfile>classmlclient_1_1_generic_text_document_content.html</anchorfile>
      <anchor>ab3ae7235b73518099e57d0e50da0edd2</anchor>
      <arglist>(const GenericTextDocumentContent &amp;doc)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>GenericTextDocumentContent</name>
      <anchorfile>classmlclient_1_1_generic_text_document_content.html</anchorfile>
      <anchor>a1437182afa2e2d4f92f276af8ad3d823</anchor>
      <arglist>(const ITextDocumentContent &amp;doc)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~GenericTextDocumentContent</name>
      <anchorfile>classmlclient_1_1_generic_text_document_content.html</anchorfile>
      <anchor>aafc291c2d3fbafb37946e52c3b404ea9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setContent</name>
      <anchorfile>classmlclient_1_1_generic_text_document_content.html</anchorfile>
      <anchor>ad051f989ef07b8d24b2454864c831b9c</anchor>
      <arglist>(std::string content) override</arglist>
    </member>
    <member kind="function">
      <type>std::ostream *</type>
      <name>getStream</name>
      <anchorfile>classmlclient_1_1_generic_text_document_content.html</anchorfile>
      <anchor>a5363fc970e08a32ef5dcacee62884cbb</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>getContent</name>
      <anchorfile>classmlclient_1_1_generic_text_document_content.html</anchorfile>
      <anchor>a70818dba76a1b1dc28cd1ac1b03ab6a2</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>getMimeType</name>
      <anchorfile>classmlclient_1_1_generic_text_document_content.html</anchorfile>
      <anchor>a4487625bb4ab15e2d7709778a2926458</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setMimeType</name>
      <anchorfile>classmlclient_1_1_generic_text_document_content.html</anchorfile>
      <anchor>a5e53fb0737d1488448332f222671816e</anchor>
      <arglist>(const std::string &amp;mt) override</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getLength</name>
      <anchorfile>classmlclient_1_1_generic_text_document_content.html</anchorfile>
      <anchor>a507199891ebb1dfaa994f287a33eaf22</anchor>
      <arglist>() const  override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::IBinaryDocumentContent</name>
    <filename>classmlclient_1_1_i_binary_document_content.html</filename>
    <base>mlclient::IDocumentContent</base>
    <member kind="function">
      <type></type>
      <name>IBinaryDocumentContent</name>
      <anchorfile>classmlclient_1_1_i_binary_document_content.html</anchorfile>
      <anchor>a0422bc609995315371f01f2e5ba86510</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~IBinaryDocumentContent</name>
      <anchorfile>classmlclient_1_1_i_binary_document_content.html</anchorfile>
      <anchor>a5d661a5094264e8484edcebb68f0f2db</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual std::string</type>
      <name>getMimeType</name>
      <anchorfile>classmlclient_1_1_i_binary_document_content.html</anchorfile>
      <anchor>a90c5e793e93d58d4780114ce3ffd4a96</anchor>
      <arglist>() const  override=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>setMimeType</name>
      <anchorfile>classmlclient_1_1_i_binary_document_content.html</anchorfile>
      <anchor>ae9871f1ba9c5b85ed2a2463577828f72</anchor>
      <arglist>(const std::string &amp;mt) override=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual std::ostream *</type>
      <name>getStream</name>
      <anchorfile>classmlclient_1_1_i_binary_document_content.html</anchorfile>
      <anchor>aa2b472a0dac3cf1b852615579cd8dd53</anchor>
      <arglist>() const  override=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual std::string</type>
      <name>getContent</name>
      <anchorfile>classmlclient_1_1_i_binary_document_content.html</anchorfile>
      <anchor>ab4c50abc28510d17e3c8803e014fcd21</anchor>
      <arglist>() const  override=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::IDocumentContent</name>
    <filename>classmlclient_1_1_i_document_content.html</filename>
    <member kind="function">
      <type></type>
      <name>IDocumentContent</name>
      <anchorfile>classmlclient_1_1_i_document_content.html</anchorfile>
      <anchor>ab22722f1867bce185bba426e5f8afba2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~IDocumentContent</name>
      <anchorfile>classmlclient_1_1_i_document_content.html</anchorfile>
      <anchor>afdc1b9115e2a4d051fb263e74e06c21a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual std::ostream *</type>
      <name>getStream</name>
      <anchorfile>classmlclient_1_1_i_document_content.html</anchorfile>
      <anchor>abc5817a03238a61c176f7c5c3607d509</anchor>
      <arglist>() const  =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual std::string</type>
      <name>getContent</name>
      <anchorfile>classmlclient_1_1_i_document_content.html</anchorfile>
      <anchor>ab1a7515e7f7d2f3d8ac4b8bd20ec9f8b</anchor>
      <arglist>() const  =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual std::string</type>
      <name>getMimeType</name>
      <anchorfile>classmlclient_1_1_i_document_content.html</anchorfile>
      <anchor>a20e1cc7e2a9958596ac52b6a39605119</anchor>
      <arglist>() const  =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>setMimeType</name>
      <anchorfile>classmlclient_1_1_i_document_content.html</anchorfile>
      <anchor>acf7ba80db8786497f8e3bf794b4775c7</anchor>
      <arglist>(const std::string &amp;mt)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::InvalidFormatException</name>
    <filename>classmlclient_1_1_invalid_format_exception.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>what</name>
      <anchorfile>classmlclient_1_1_invalid_format_exception.html</anchorfile>
      <anchor>ad18b7a305e6768f07b8683c0e168c304</anchor>
      <arglist>() const  override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::ITextDocumentContent</name>
    <filename>classmlclient_1_1_i_text_document_content.html</filename>
    <base>mlclient::IDocumentContent</base>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>setContent</name>
      <anchorfile>classmlclient_1_1_i_text_document_content.html</anchorfile>
      <anchor>a6eaf74649ada2436bc5f25c2635a9543</anchor>
      <arglist>(std::string content)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>getLength</name>
      <anchorfile>classmlclient_1_1_i_text_document_content.html</anchorfile>
      <anchor>a81c0edab2ac29ece7a86b91fa6ca0c48</anchor>
      <arglist>() const  =0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::NoCredentialsException</name>
    <filename>classmlclient_1_1_no_credentials_exception.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>what</name>
      <anchorfile>classmlclient_1_1_no_credentials_exception.html</anchorfile>
      <anchor>ae9df0a71170f161b0857f9ef7b8b6351</anchor>
      <arglist>() const  override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::PugiXmlHelper</name>
    <filename>classmlclient_1_1utilities_1_1_pugi_xml_helper.html</filename>
    <member kind="function" static="yes">
      <type>static ITextDocumentContent *</type>
      <name>toDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_helper.html</anchorfile>
      <anchor>adeeb796d03dd51becf80598060eefdaf</anchor>
      <arglist>(const pugi::xml_document &amp;dc)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static pugi::xml_document *</type>
      <name>fromDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_helper.html</anchorfile>
      <anchor>a5427cb837d708fe0a3503972605a24ce</anchor>
      <arglist>(const IDocumentContent &amp;dc)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static pugi::xml_document *</type>
      <name>fromResponse</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_helper.html</anchorfile>
      <anchor>a0ce6782a3b9e82ae92a5e52d0b8dcc5e</anchor>
      <arglist>(const Response &amp;resp)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::Response</name>
    <filename>classmlclient_1_1_response.html</filename>
    <member kind="function">
      <type></type>
      <name>Response</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>a6fe9f3d9b1e2b056ca9c994135252974</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setResponseCode</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>a8df32c7a735c11fe23eb216a0ff7d7d7</anchor>
      <arglist>(const ResponseCode &amp;code)</arglist>
    </member>
    <member kind="function">
      <type>ResponseType</type>
      <name>getResponseType</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>a4d2dd5829c9f12d1cca84c12502369f5</anchor>
      <arglist>(void) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setResponseType</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>a2a19e062190a54b18dea43008dd15c7b</anchor>
      <arglist>(const enum ResponseType &amp;type)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setResponseHeaders</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>a73d6560614478ee46082b2464aa9efe4</anchor>
      <arglist>(const web::http::http_headers &amp;headers)</arglist>
    </member>
    <member kind="function">
      <type>ResponseCode</type>
      <name>getResponseCode</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>a65a5133e83bca31c37bd443da37451eb</anchor>
      <arglist>(void) const </arglist>
    </member>
    <member kind="function">
      <type>web::http::http_headers</type>
      <name>getResponseHeaders</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>ac8af98e570832afad9afa17505cc9db8</anchor>
      <arglist>(void) const </arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>read</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>a628325fb5e48c06f69fb4ead94fbb367</anchor>
      <arglist>(void *buffer, const size_t &amp;max_size, const size_t off=0)</arglist>
    </member>
    <member kind="function">
      <type>const std::string &amp;</type>
      <name>getContent</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>a0487a31c6d74e7a1d5dc4ba1f9b263e2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setContent</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>a646820f18250f5a743fe031ade050451</anchor>
      <arglist>(std::unique_ptr&lt; std::string &gt; content)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::SearchDescription</name>
    <filename>classmlclient_1_1_search_description.html</filename>
    <member kind="function">
      <type></type>
      <name>SearchDescription</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>a6253c1b631946b551413f101777177fe</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~SearchDescription</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>a3c508b1f24a5d35e2c91dd9086d9f5a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setOptions</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>a90a96320f526f5010697d8daf88df2df</anchor>
      <arglist>(ITextDocumentContent &amp;options)</arglist>
    </member>
    <member kind="function">
      <type>const ITextDocumentContent &amp;</type>
      <name>getOptions</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>a4f7800af7906e1fdd0f56c89b89fbd1f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setQuery</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>ada430d382bcf1ee4d090c832375185cf</anchor>
      <arglist>(ITextDocumentContent &amp;query)</arglist>
    </member>
    <member kind="function">
      <type>const ITextDocumentContent &amp;</type>
      <name>getQuery</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>a1bf0e745f41880624e31b7966b8d9c31</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setQueryText</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>a9c95c65185f1ba08fa4181eebcc9758c</anchor>
      <arglist>(std::string qtext)</arglist>
    </member>
    <member kind="function">
      <type>const std::string &amp;</type>
      <name>getQueryText</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>afb81430fb17d3e0844d68b52d285ce68</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>ITextDocumentContent *</type>
      <name>getPayload</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>a55f519e073c45d2138c3d26d692528f4</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>mlclient</name>
    <filename>namespacemlclient.html</filename>
    <namespace>mlclient::utilities</namespace>
    <class kind="class">mlclient::Connection</class>
    <class kind="class">mlclient::GenericTextDocumentContent</class>
    <class kind="class">mlclient::IBinaryDocumentContent</class>
    <class kind="class">mlclient::IDocumentContent</class>
    <class kind="class">mlclient::InvalidFormatException</class>
    <class kind="class">mlclient::ITextDocumentContent</class>
    <class kind="class">mlclient::NoCredentialsException</class>
    <class kind="class">mlclient::Response</class>
    <class kind="class">mlclient::SearchDescription</class>
    <member kind="enumeration">
      <type></type>
      <name>BinaryEncoding</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>ad47ff6baab050e78452eb2167a2a3b54</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>ResponseType</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>aff058411252d0c404caf56d2d0b65090</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>ResponseCode</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>ac8a0790b90fd9b1df837c9476659fb23</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>mlclient::utilities</name>
    <filename>namespacemlclient_1_1utilities.html</filename>
    <class kind="class">mlclient::utilities::CppRestJsonDocumentContent</class>
    <class kind="class">mlclient::utilities::CppRestJsonHelper</class>
    <class kind="class">mlclient::utilities::PugiXmlHelper</class>
  </compound>
  <compound kind="page">
    <name>page_Design</name>
    <title>Design</title>
    <filename>page__design</filename>
    <docanchor file="page__design" title="C++ Public API">The</docanchor>
  </compound>
  <compound kind="page">
    <name>index</name>
    <title>MarkLogic C/C++ API Documentation</title>
    <filename>index</filename>
    <docanchor file="index" title="Contents">sec_Contents</docanchor>
    <docanchor file="index" title="Overview">sec_Overview</docanchor>
    <docanchor file="index" title="Design">sec_Design</docanchor>
    <docanchor file="index" title="Examples">sec_Examples</docanchor>
    <docanchor file="index" title="See Also">sec_SeeAlso</docanchor>
    <docanchor file="index" title="API Documentation">sec_ApiDocs</docanchor>
  </compound>
</tagfile>
