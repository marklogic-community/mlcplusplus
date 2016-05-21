<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile>
  <compound kind="file">
    <name>Connection.hpp</name>
    <path>/Users/adamfowler/Documents/marklogic/git/mlcplusplus/release/src/</path>
    <filename>_connection_8hpp</filename>
    <includes id="_document_content_8hpp" name="DocumentContent.hpp" local="yes" imported="no">DocumentContent.hpp</includes>
    <includes id="_search_description_8hpp" name="SearchDescription.hpp" local="yes" imported="no">SearchDescription.hpp</includes>
    <class kind="class">mlclient::IConnection</class>
    <class kind="class">mlclient::Connection</class>
    <namespace>mlclient</namespace>
  </compound>
  <compound kind="file">
    <name>ConnectionWrapper.h</name>
    <path>/Users/adamfowler/Documents/marklogic/git/mlcplusplus/release/src/</path>
    <filename>_connection_wrapper_8h</filename>
    <includes id="_response_wrapper_8h" name="ResponseWrapper.h" local="yes" imported="no">ResponseWrapper.h</includes>
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
    <member kind="function">
      <type>CResponse *</type>
      <name>ml_connection_doGet</name>
      <anchorfile>_connection_wrapper_8h.html</anchorfile>
      <anchor>a6bbf29f4338b15cb35bfae191b192f24</anchor>
      <arglist>(const CConnection *conn, const char *pathAndQuerystring)</arglist>
    </member>
    <member kind="function">
      <type>CResponse *</type>
      <name>ml_connection_doPut</name>
      <anchorfile>_connection_wrapper_8h.html</anchorfile>
      <anchor>ae660f9102176c5099c8ff98d786e4ba9</anchor>
      <arglist>(const CConnection *conn, const char *pathAndQuerystring, const char *payload)</arglist>
    </member>
    <member kind="function">
      <type>CResponse *</type>
      <name>ml_connection_doPost</name>
      <anchorfile>_connection_wrapper_8h.html</anchorfile>
      <anchor>affdd087058b68446b0ce50f0bbdacad3</anchor>
      <arglist>(const CConnection *conn, const char *pathAndQuerystring, const char *payload)</arglist>
    </member>
    <member kind="function">
      <type>CResponse *</type>
      <name>ml_connection_doDelete</name>
      <anchorfile>_connection_wrapper_8h.html</anchorfile>
      <anchor>abd4486855d9fce5a784eecb44388f446</anchor>
      <arglist>(const CConnection *conn, const char *path)</arglist>
    </member>
    <member kind="function">
      <type>CResponse *</type>
      <name>ml_connection_getDocument</name>
      <anchorfile>_connection_wrapper_8h.html</anchorfile>
      <anchor>adef37c84afd3c6aa67f0d00ab8cbf28b</anchor>
      <arglist>(const CConnection *conn, const char *uri)</arglist>
    </member>
    <member kind="function">
      <type>CResponse *</type>
      <name>ml_connection_saveDocument</name>
      <anchorfile>_connection_wrapper_8h.html</anchorfile>
      <anchor>a2980636057bdddf93031b906335be937</anchor>
      <arglist>(const CConnection *conn, const char *uri, const char *payload)</arglist>
    </member>
    <member kind="function">
      <type>CResponse *</type>
      <name>ml_connection_search</name>
      <anchorfile>_connection_wrapper_8h.html</anchorfile>
      <anchor>a72f44f2378058efa160a27dd356bc75c</anchor>
      <arglist>(const CConnection *conn, const char *searchQuery, const char *qtext, const char *options)</arglist>
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
    <name>ResponseWrapper.h</name>
    <path>/Users/adamfowler/Documents/marklogic/git/mlcplusplus/release/src/</path>
    <filename>_response_wrapper_8h</filename>
    <member kind="define">
      <type>#define</type>
      <name>RESPONSETYPE_UNKNOWN</name>
      <anchorfile>_response_wrapper_8h.html</anchorfile>
      <anchor>a496b3797502f343da29787df9d985738</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RESPONSETYPE_XML</name>
      <anchorfile>_response_wrapper_8h.html</anchorfile>
      <anchor>a0d8e237a39860c250d968e3df25e6b1b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RESPONSETYPE_JSON</name>
      <anchorfile>_response_wrapper_8h.html</anchorfile>
      <anchor>aa01abb7cfed863a2730bedca296a6478</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RESPONSETYPE_TEXT</name>
      <anchorfile>_response_wrapper_8h.html</anchorfile>
      <anchor>a65ea3e3d9c53addcbd882ad77c325506</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RESPONSETYPE_BINARY</name>
      <anchorfile>_response_wrapper_8h.html</anchorfile>
      <anchor>a84423320407e2e98db199491b51f0475</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>ml_response_delete</name>
      <anchorfile>_response_wrapper_8h.html</anchorfile>
      <anchor>a578dea9925aa14f3355f616a8987e485</anchor>
      <arglist>(CResponse *t)</arglist>
    </member>
    <member kind="function">
      <type>const int</type>
      <name>ml_response_length</name>
      <anchorfile>_response_wrapper_8h.html</anchorfile>
      <anchor>a2879bf705ca85736d538e3398bf73bc9</anchor>
      <arglist>(CResponse *t)</arglist>
    </member>
    <member kind="function">
      <type>const char *const</type>
      <name>ml_response_String</name>
      <anchorfile>_response_wrapper_8h.html</anchorfile>
      <anchor>a7faed8268459bce88a0481b4a9dad94e</anchor>
      <arglist>(CResponse *t)</arglist>
    </member>
    <member kind="function">
      <type>const int</type>
      <name>ml_response_GetResponseType</name>
      <anchorfile>_response_wrapper_8h.html</anchorfile>
      <anchor>a271df6f53d508c26f9e9029491e82b52</anchor>
      <arglist>(CResponse *t)</arglist>
    </member>
    <member kind="function">
      <type>const int</type>
      <name>ml_response_GetResponseCode</name>
      <anchorfile>_response_wrapper_8h.html</anchorfile>
      <anchor>a9971b2bb07a09aded1639586af7487ae</anchor>
      <arglist>(CResponse *t)</arglist>
    </member>
    <member kind="function">
      <type>const char *const</type>
      <name>ml_responsecodes_translate</name>
      <anchorfile>_response_wrapper_8h.html</anchorfile>
      <anchor>a63a21f0f72515ddd2b258a43ef34a7e5</anchor>
      <arglist>(int code)</arglist>
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
    <base>mlclient::IConnection</base>
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
      <anchor>a769a2073f7d09bc7f80e0a42587b0de0</anchor>
      <arglist>(const std::string &amp;hostname, const std::string &amp;port, const std::string &amp;username, const std::string &amp;password, const bool usessl=false) override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDatabaseName</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a7687e92b55868df1bd6c851300b6af1a</anchor>
      <arglist>(const std::string &amp;db) override</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>getDatabaseName</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a7a89de530a197901922db4603f75fb13</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>doGet</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a8111a379cb5e7e06abc637fff8d02e29</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>doPut</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>ae9837d1c47ee36657dcc5e4b8b9a2ce7</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>doPost</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a23f96ff9230fbfe921dfeb394524b741</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>doDelete</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a905da280d5afd2e3b8cb74b171f7fe90</anchor>
      <arglist>(const std::string &amp;pathAndQueryString) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>getDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>adad12f7f19c4fa6fe991b8a70e2f85a9</anchor>
      <arglist>(const std::string &amp;uri) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>saveDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a687b2026a97545a5d363cc5bf3ddfdcc</anchor>
      <arglist>(const std::string &amp;uri, const IDocumentContent &amp;payload) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>deleteDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a7cb0f7bc4146e00665f8d94989ad9369</anchor>
      <arglist>(const std::string &amp;uri) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>search</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a0d2dc7e12ec1eadec6d78c49536c2d4e</anchor>
      <arglist>(const SearchDescription &amp;desc) override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>configure</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a769a2073f7d09bc7f80e0a42587b0de0</anchor>
      <arglist>(const std::string &amp;hostname, const std::string &amp;port, const std::string &amp;username, const std::string &amp;password, const bool usessl=false) override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDatabaseName</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a7687e92b55868df1bd6c851300b6af1a</anchor>
      <arglist>(const std::string &amp;db) override</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>getDatabaseName</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a7a89de530a197901922db4603f75fb13</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>doGet</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a8111a379cb5e7e06abc637fff8d02e29</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>doPut</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>ae9837d1c47ee36657dcc5e4b8b9a2ce7</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>doPost</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a23f96ff9230fbfe921dfeb394524b741</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>doDelete</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a905da280d5afd2e3b8cb74b171f7fe90</anchor>
      <arglist>(const std::string &amp;pathAndQueryString) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>getDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>adad12f7f19c4fa6fe991b8a70e2f85a9</anchor>
      <arglist>(const std::string &amp;uri) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>saveDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a687b2026a97545a5d363cc5bf3ddfdcc</anchor>
      <arglist>(const std::string &amp;uri, const IDocumentContent &amp;payload) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>deleteDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a7cb0f7bc4146e00665f8d94989ad9369</anchor>
      <arglist>(const std::string &amp;uri) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>search</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a0d2dc7e12ec1eadec6d78c49536c2d4e</anchor>
      <arglist>(const SearchDescription &amp;desc) override</arglist>
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
    <name>mlclient::HttpHeaders</name>
    <filename>classmlclient_1_1_http_headers.html</filename>
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
    <name>mlclient::IConnection</name>
    <filename>classmlclient_1_1_i_connection.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~IConnection</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a8e661d92e40d63962d78dd3e659e38f2</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>configure</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a6de9145a6afe8b3e63e90188ee5e1b42</anchor>
      <arglist>(const std::string &amp;hostname, const std::string &amp;port, const std::string &amp;username, const std::string &amp;password, const bool usessl=false)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>setDatabaseName</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a989d55778b0fcfa306c3a17acff77ed4</anchor>
      <arglist>(const std::string &amp;db)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual std::string</type>
      <name>getDatabaseName</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a2b63b959736635a0e555f00ba21d20ad</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Response *</type>
      <name>doGet</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a060653d258207f6406da38c8878c33f5</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Response *</type>
      <name>doPut</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a868294d70b7a707955f79a2286bc528b</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Response *</type>
      <name>doPost</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a57c2bff6813ceb21bafe287b9e8e5317</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Response *</type>
      <name>doDelete</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a622f4ec1aa07e8c0828af5cc1d411b05</anchor>
      <arglist>(const std::string &amp;pathAndQueryString)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Response *</type>
      <name>getDocument</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a0a7d25c5af3e72eb1a8b539a5c36262c</anchor>
      <arglist>(const std::string &amp;uri)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Response *</type>
      <name>saveDocument</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a10b33ec344cf1c666cb9d42ebd9e2282</anchor>
      <arglist>(const std::string &amp;uri, const IDocumentContent &amp;payload)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Response *</type>
      <name>deleteDocument</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a54fddb7c48924d45904dd2fc686b5839</anchor>
      <arglist>(const std::string &amp;uri)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Response *</type>
      <name>search</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a79f13a3472446cb05412ddcd4a28fc75</anchor>
      <arglist>(const SearchDescription &amp;desc)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>configure</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a6de9145a6afe8b3e63e90188ee5e1b42</anchor>
      <arglist>(const std::string &amp;hostname, const std::string &amp;port, const std::string &amp;username, const std::string &amp;password, const bool usessl=false)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>setDatabaseName</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a989d55778b0fcfa306c3a17acff77ed4</anchor>
      <arglist>(const std::string &amp;db)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual std::string</type>
      <name>getDatabaseName</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a2b63b959736635a0e555f00ba21d20ad</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Response *</type>
      <name>doGet</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a060653d258207f6406da38c8878c33f5</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Response *</type>
      <name>doPut</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a868294d70b7a707955f79a2286bc528b</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Response *</type>
      <name>doPost</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a57c2bff6813ceb21bafe287b9e8e5317</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Response *</type>
      <name>doDelete</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a622f4ec1aa07e8c0828af5cc1d411b05</anchor>
      <arglist>(const std::string &amp;pathAndQueryString)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Response *</type>
      <name>getDocument</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a0a7d25c5af3e72eb1a8b539a5c36262c</anchor>
      <arglist>(const std::string &amp;uri)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Response *</type>
      <name>saveDocument</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a10b33ec344cf1c666cb9d42ebd9e2282</anchor>
      <arglist>(const std::string &amp;uri, const IDocumentContent &amp;payload)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Response *</type>
      <name>deleteDocument</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a54fddb7c48924d45904dd2fc686b5839</anchor>
      <arglist>(const std::string &amp;uri)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Response *</type>
      <name>search</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a79f13a3472446cb05412ddcd4a28fc75</anchor>
      <arglist>(const SearchDescription &amp;desc)=0</arglist>
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
      <anchor>a0f7eef7761531135409092e88b2c7258</anchor>
      <arglist>(const mlclient::HttpHeaders &amp;headers)</arglist>
    </member>
    <member kind="function">
      <type>ResponseCode</type>
      <name>getResponseCode</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>a65a5133e83bca31c37bd443da37451eb</anchor>
      <arglist>(void) const </arglist>
    </member>
    <member kind="function">
      <type>mlclient::HttpHeaders</type>
      <name>getResponseHeaders</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>a21f8301c312194b48864633dcec68246</anchor>
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
      <anchor>a92d868056fd29885b44317be4ecda999</anchor>
      <arglist>(std::string *content)</arglist>
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
    <class kind="class">mlclient::HttpHeaders</class>
    <class kind="class">mlclient::IBinaryDocumentContent</class>
    <class kind="class">mlclient::IConnection</class>
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
    <name>page_CWrapper</name>
    <title>C Language Wrapper</title>
    <filename>page__c_wrapper</filename>
  </compound>
  <compound kind="page">
    <name>page_Design</name>
    <title>Design</title>
    <filename>page__design</filename>
    <docanchor file="page__design" title="C++ Public API">The</docanchor>
  </compound>
  <compound kind="page">
    <name>page_devguide</name>
    <title>Application Developers Guide</title>
    <filename>page_devguide</filename>
    <docanchor file="page_devguide" title="Introduction to the C++ API">sec_introduction</docanchor>
    <docanchor file="page_devguide" title="Getting Started">sec_gettingstarted</docanchor>
    <docanchor file="page_devguide" title="Creating, working with, and releasing a Connection instance">sec_connection</docanchor>
    <docanchor file="page_devguide" title="Basic document retrieval example">sec_getdocumentexample</docanchor>
    <docanchor file="page_devguide" title="Using Document and IDocumentContent objects">sec_idocumentcontent</docanchor>
    <docanchor file="page_devguide" title="Thread safety">sec_threads</docanchor>
    <docanchor file="page_devguide" title="Concurrency">sec_concurrency</docanchor>
    <docanchor file="page_devguide" title="Document Operations">sec_documentoperations</docanchor>
    <docanchor file="page_devguide" title="Document Creation">sec_createdocument</docanchor>
    <docanchor file="page_devguide" title="Document Retrieval">sec_getdocument</docanchor>
    <docanchor file="page_devguide" title="Document Deletion">sec_deletedocument</docanchor>
    <docanchor file="page_devguide" title="Writing a Binary document">sec_createbinarydocument</docanchor>
    <docanchor file="page_devguide" title="Reading a Binary document">sec_getbinarydocument</docanchor>
    <docanchor file="page_devguide" title="Reading, modifying, and writing document metadata">sec_documentmetadata</docanchor>
    <docanchor file="page_devguide" title="Conversion of Document Encoding">sec_documentencoding</docanchor>
    <docanchor file="page_devguide" title="Query Options">sec_queryoptions</docanchor>
    <docanchor file="page_devguide" title="Using query options">sec_usingqueryoptions</docanchor>
    <docanchor file="page_devguide" title="Default query options">sec_defaultqueryoptions</docanchor>
    <docanchor file="page_devguide" title="Creating query options">sec_createqueryoptions</docanchor>
    <docanchor file="page_devguide" title="Updating query options">sec_updatequeryoptions</docanchor>
    <docanchor file="page_devguide" title="Deleting query options">sec_deletequeryoptions</docanchor>
    <docanchor file="page_devguide" title="Creating query options from raw XML or JSON">sec_createoptionsfromtext</docanchor>
    <docanchor file="page_devguide" title="Validating query options">sec_validatequeryoptions</docanchor>
    <docanchor file="page_devguide" title="Searching">sec_searching</docanchor>
    <docanchor file="page_devguide" title="Overview of Search in the C++ API">sec_searchoverview</docanchor>
    <docanchor file="page_devguide" title="Using the Search Results Iterator">sec_resultsiterator</docanchor>
    <docanchor file="page_devguide" title="Using simple text query search">sec_textquery</docanchor>
    <docanchor file="page_devguide" title="Using structured search and the Search Builder">sec_structuredquery</docanchor>
    <docanchor file="page_devguide" title="Prototype a query using Query By Example">sec_querybyexample</docanchor>
    <docanchor file="page_devguide" title="Using Combined Queries">sec_combinedquery</docanchor>
    <docanchor file="page_devguide" title="Searching Values and Tuples">sec_valuestuples</docanchor>
    <docanchor file="page_devguide" title="Transforming Search results">sec_searchtransforms</docanchor>
    <docanchor file="page_devguide" title="Generating Search Suggestions">sec_searchsuggest</docanchor>
    <docanchor file="page_devguide" title="Extracting a portion of matching documents">sec_searchextract</docanchor>
    <docanchor file="page_devguide" title="Reading and Writing Multiple Documents">sec_multipledocuments</docanchor>
    <docanchor file="page_devguide" title="Write multiple documents">sec_writemultiple</docanchor>
    <docanchor file="page_devguide" title="Writing multiple documents from files">sec_writemultiplefiles</docanchor>
    <docanchor file="page_devguide" title="Read multiple documents by URI">sec_readmultipleuri</docanchor>
    <docanchor file="page_devguide" title="Read multiple documents matching a query">sec_readmultiplequery</docanchor>
    <docanchor file="page_devguide" title="Apply a read transformation">sec_readtransform</docanchor>
    <docanchor file="page_devguide" title="Setting batch size">sec_multiplebatchsize</docanchor>
    <docanchor file="page_devguide" title="Transactions and Optimistic Locking">sec_transactions</docanchor>
    <docanchor file="page_devguide" title="Logging">sec_logging</docanchor>
    <docanchor file="page_devguide" title="Starting logging and setting the log level">sec_startlogging</docanchor>
    <docanchor file="page_devguide" title="Suspending logging">sec_suspendlogging</docanchor>
    <docanchor file="page_devguide" title="Stopping logging">sec_stoplogging</docanchor>
    <docanchor file="page_devguide" title="Log entry format">sec_logformat</docanchor>
    <docanchor file="page_devguide" title="Performance logging">sec_performancelogging</docanchor>
    <docanchor file="page_devguide" title="Extending the C++ API">sec_extendapi</docanchor>
    <docanchor file="page_devguide" title="Performing an ad-hoc query to any REST endpoint">sec_adhocendpoint</docanchor>
    <docanchor file="page_devguide" title="Troubleshooting">sec_trouble</docanchor>
    <docanchor file="page_devguide" title="Error detection">sec_errors</docanchor>
    <docanchor file="page_devguide" title="General Troubleshooting Techniques">sec_troubletechs</docanchor>
  </compound>
  <compound kind="page">
    <name>page_Install</name>
    <title>Installing MLCPlusPlus</title>
    <filename>page__install</filename>
    <docanchor file="page__install" title="Installation">sec_Installation</docanchor>
  </compound>
  <compound kind="page">
    <name>index</name>
    <title>MarkLogic C/C++ API Documentation</title>
    <filename>index</filename>
    <docanchor file="index" title="Contents">sec_Contents</docanchor>
    <docanchor file="index" title="Overview">sec_Overview</docanchor>
    <docanchor file="index" title="Install">sec_Install</docanchor>
    <docanchor file="index" title="Application Development Guide">sec_DevGuide</docanchor>
    <docanchor file="index" title="Design">sec_Design</docanchor>
    <docanchor file="index" title="Examples">sec_Examples</docanchor>
    <docanchor file="index" title="See Also">sec_SeeAlso</docanchor>
    <docanchor file="index" title="API Documentation">sec_ApiDocs</docanchor>
  </compound>
</tagfile>
