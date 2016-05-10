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
    <class kind="class">mlclient::DocumentContent</class>
    <class kind="class">mlclient::TextDocumentContent</class>
    <class kind="class">mlclient::BinaryDocumentContent</class>
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
    <name>CppRestJsonDocumentContent.cpp</name>
    <path>/Users/adamfowler/Documents/marklogic/git/mlcplusplus/release/src/utilities/</path>
    <filename>_cpp_rest_json_document_content_8cpp</filename>
    <namespace>mlclient</namespace>
    <namespace>mlclient::utilities</namespace>
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
    <name>mlclient::BinaryDocumentContent</name>
    <filename>classmlclient_1_1_binary_document_content.html</filename>
    <base>mlclient::DocumentContent</base>
    <member kind="function">
      <type></type>
      <name>BinaryDocumentContent</name>
      <anchorfile>classmlclient_1_1_binary_document_content.html</anchorfile>
      <anchor>ad70648d3a162c4876b1688d454f4992c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~BinaryDocumentContent</name>
      <anchorfile>classmlclient_1_1_binary_document_content.html</anchorfile>
      <anchor>a6183420ef5307387838158987e43913c</anchor>
      <arglist>()</arglist>
    </member>
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
      <anchor>ae09d89728e8fd7268a80ed896f18a296</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>doPut</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a09ce9e55dbc9b74382076dcc0ff0bf8f</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const DocumentContent &amp;payload)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>doPost</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>ad53cbbac65c5b91c8aa0c08034ca6366</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const DocumentContent &amp;payload)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>doDelete</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>ade33cc96ba01727b158b5b632c82e887</anchor>
      <arglist>(const std::string &amp;pathAndQueryString)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>getDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a2acf717538aa317ad5b142303d9222c9</anchor>
      <arglist>(const std::string &amp;uri)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>saveDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>af6582211972df77eb81bb751efeba2ca</anchor>
      <arglist>(const std::string &amp;uri, const DocumentContent &amp;payload)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>search</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>ac1e4858d53240e3e81fe2ec199597338</anchor>
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
      <anchor>ae09d89728e8fd7268a80ed896f18a296</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>doPut</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a09ce9e55dbc9b74382076dcc0ff0bf8f</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const DocumentContent &amp;payload)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>doPost</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>ad53cbbac65c5b91c8aa0c08034ca6366</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const DocumentContent &amp;payload)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>doDelete</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>ade33cc96ba01727b158b5b632c82e887</anchor>
      <arglist>(const std::string &amp;pathAndQueryString)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>getDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a2acf717538aa317ad5b142303d9222c9</anchor>
      <arglist>(const std::string &amp;uri)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>saveDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>af6582211972df77eb81bb751efeba2ca</anchor>
      <arglist>(const std::string &amp;uri, const DocumentContent &amp;payload)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Response &gt;</type>
      <name>search</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>ac1e4858d53240e3e81fe2ec199597338</anchor>
      <arglist>(const SearchDescription &amp;desc)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::CppRestJsonDocumentContent</name>
    <filename>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</filename>
    <base>mlclient::TextDocumentContent</base>
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
      <anchor>aa9bfe09196fd7facb6106d98c3b3f490</anchor>
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
      <anchor>a4615b46d0f98709d735a301e43380cca</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>web::json::value &amp;</type>
      <name>getJson</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>acd761ff1c682b49bbd2fa4fbe447f1b4</anchor>
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
      <anchor>a4615b46d0f98709d735a301e43380cca</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>web::json::value &amp;</type>
      <name>getJson</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>acd761ff1c682b49bbd2fa4fbe447f1b4</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::CppRestJsonHelper</name>
    <filename>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</filename>
    <member kind="function" static="yes">
      <type>static TextDocumentContent *</type>
      <name>toDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>a7f4a350b6478549cf74fc5f7d05fdc18</anchor>
      <arglist>(const web::json::value json)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static web::json::value</type>
      <name>fromDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>a5e3ed63d7769a93646671f4aa9997774</anchor>
      <arglist>(const DocumentContent &amp;doc)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static web::json::value</type>
      <name>fromResponse</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>a46db30548677c5889820b29cb2b06986</anchor>
      <arglist>(const Response &amp;resp)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static TextDocumentContent *</type>
      <name>toDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>a7f4a350b6478549cf74fc5f7d05fdc18</anchor>
      <arglist>(const web::json::value json)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static web::json::value</type>
      <name>fromDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>a5e3ed63d7769a93646671f4aa9997774</anchor>
      <arglist>(const DocumentContent &amp;doc)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static web::json::value</type>
      <name>fromResponse</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>a46db30548677c5889820b29cb2b06986</anchor>
      <arglist>(const Response &amp;resp)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CWrapper</name>
    <filename>class_c_wrapper.html</filename>
    <templarg></templarg>
  </compound>
  <compound kind="class">
    <name>mlclient::DocumentContent</name>
    <filename>classmlclient_1_1_document_content.html</filename>
    <member kind="function">
      <type></type>
      <name>DocumentContent</name>
      <anchorfile>classmlclient_1_1_document_content.html</anchorfile>
      <anchor>a65fd0bfc31fcfeb870039e139898d8dc</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~DocumentContent</name>
      <anchorfile>classmlclient_1_1_document_content.html</anchorfile>
      <anchor>a121511976bfebd4920052866a14ba7b7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual std::ostream *</type>
      <name>getStream</name>
      <anchorfile>classmlclient_1_1_document_content.html</anchorfile>
      <anchor>ad26b2d1737aa7f9f39ce241e810d5b89</anchor>
      <arglist>() const  =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual std::string</type>
      <name>getContent</name>
      <anchorfile>classmlclient_1_1_document_content.html</anchorfile>
      <anchor>ae66dffb64fcb673a5d51b7bdafc51e94</anchor>
      <arglist>() const  =0</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>getMimeType</name>
      <anchorfile>classmlclient_1_1_document_content.html</anchorfile>
      <anchor>acc5ed218bed7474b9ecb0f062fe3d40f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setMimeType</name>
      <anchorfile>classmlclient_1_1_document_content.html</anchorfile>
      <anchor>a5dd0bf51580aa8ce4c2c9359f235807b</anchor>
      <arglist>(const std::string &amp;mt)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const std::string</type>
      <name>MIME_JSON</name>
      <anchorfile>classmlclient_1_1_document_content.html</anchorfile>
      <anchor>a00defc73beb6236ae4031f75ef7444e0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const std::string</type>
      <name>MIME_XML</name>
      <anchorfile>classmlclient_1_1_document_content.html</anchorfile>
      <anchor>aba94da0d65a4047c41bf16bf246936c5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::InvalidFormatException</name>
    <filename>classmlclient_1_1_invalid_format_exception.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>what</name>
      <anchorfile>classmlclient_1_1_invalid_format_exception.html</anchorfile>
      <anchor>a5501004e340585882251855475db0bf2</anchor>
      <arglist>() const  override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::NoCredentialsException</name>
    <filename>classmlclient_1_1_no_credentials_exception.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>what</name>
      <anchorfile>classmlclient_1_1_no_credentials_exception.html</anchorfile>
      <anchor>ab49d0f7efbd347ad3619f6e65c5e3d58</anchor>
      <arglist>() const  override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::PugiXmlHelper</name>
    <filename>classmlclient_1_1utilities_1_1_pugi_xml_helper.html</filename>
    <member kind="function" static="yes">
      <type>static TextDocumentContent *</type>
      <name>toDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_helper.html</anchorfile>
      <anchor>a45ad8986c6a65bcdebfef8b68a34c4af</anchor>
      <arglist>(const pugi::xml_document &amp;dc)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static pugi::xml_document *</type>
      <name>fromDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_helper.html</anchorfile>
      <anchor>a4fcf93a35e90aa0664095857dd479301</anchor>
      <arglist>(const DocumentContent &amp;dc)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static pugi::xml_document *</type>
      <name>fromResponse</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_helper.html</anchorfile>
      <anchor>a55f66d0fe047e5fe86b5161433276499</anchor>
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
      <anchor>a9470917a7e84069e6fe0483c04cd1fd6</anchor>
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
      <anchor>a28840b77a83e8e0be3200e443110bbf6</anchor>
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
      <anchor>a02475443b9da34b0bc011469221d4e9c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setOptions</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>aeadec07540e3187f939f0738b80c7ea5</anchor>
      <arglist>(TextDocumentContent &amp;options)</arglist>
    </member>
    <member kind="function">
      <type>const TextDocumentContent &amp;</type>
      <name>getOptions</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>a06f8001a14a4303ff2a0c46b3b7a793e</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setQuery</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>a5d684c86f2e566af4899f03f71a24787</anchor>
      <arglist>(TextDocumentContent &amp;query)</arglist>
    </member>
    <member kind="function">
      <type>const TextDocumentContent &amp;</type>
      <name>getQuery</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>af3a69bd7f34017406a30c5674e6f6c24</anchor>
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
      <anchor>a14a275e341cd71c97f1858f1c73e2617</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const TextDocumentContent &amp;</type>
      <name>getPayload</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>ad4986018d1183e1aefa4617055bc6d6c</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Textable</name>
    <filename>class_textable.html</filename>
  </compound>
  <compound kind="class">
    <name>mlclient::TextDocumentContent</name>
    <filename>classmlclient_1_1_text_document_content.html</filename>
    <base>mlclient::DocumentContent</base>
    <member kind="function">
      <type></type>
      <name>TextDocumentContent</name>
      <anchorfile>classmlclient_1_1_text_document_content.html</anchorfile>
      <anchor>a58169cb4e3357f876ec7250c0db1dec3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TextDocumentContent</name>
      <anchorfile>classmlclient_1_1_text_document_content.html</anchorfile>
      <anchor>aa073a30bd440b059ae34ac29e2bd92ea</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setContent</name>
      <anchorfile>classmlclient_1_1_text_document_content.html</anchorfile>
      <anchor>a15f9e7039be35aa3141a7228183bfbd3</anchor>
      <arglist>(std::string content)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream *</type>
      <name>getStream</name>
      <anchorfile>classmlclient_1_1_text_document_content.html</anchorfile>
      <anchor>a60a079e6e1b2c246b727d0fa564c9513</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>getContent</name>
      <anchorfile>classmlclient_1_1_text_document_content.html</anchorfile>
      <anchor>af11139496d2161ffbfc2ffdb5fa040d2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getLength</name>
      <anchorfile>classmlclient_1_1_text_document_content.html</anchorfile>
      <anchor>a3d857988aec90bdfd8dd5ca71c143d30</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>mlclient</name>
    <filename>namespacemlclient.html</filename>
    <namespace>mlclient::utilities</namespace>
    <class kind="class">mlclient::BinaryDocumentContent</class>
    <class kind="class">mlclient::Connection</class>
    <class kind="class">mlclient::DocumentContent</class>
    <class kind="class">mlclient::InvalidFormatException</class>
    <class kind="class">mlclient::NoCredentialsException</class>
    <class kind="class">mlclient::Response</class>
    <class kind="class">mlclient::SearchDescription</class>
    <class kind="class">mlclient::TextDocumentContent</class>
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
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>ac70556bf7f059b82d1f13ef54634eb35</anchor>
      <arglist>(std::ostream &amp;os, const ResponseType &amp;rt)</arglist>
    </member>
    <member kind="function">
      <type>std::string &amp;</type>
      <name>operator+</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>a552e719edcc7c70165bb96137ad79dc3</anchor>
      <arglist>(std::string &amp;s, const ResponseType &amp;rt)</arglist>
    </member>
    <member kind="function">
      <type>const std::string</type>
      <name>translate</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>a5e38f2d1ec1383c9105a87c535af1e68</anchor>
      <arglist>(const ResponseType &amp;rt)</arglist>
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
    <docanchor file="page__design" title="The C++ Public API">subsec_CppPublicApi</docanchor>
    <docanchor file="page__design" title="The C++ Public Utilities API">subsec_CppUtilitiesApi</docanchor>
    <docanchor file="page__design" title="The C++ Internal API">subsec_CppInternalApi</docanchor>
    <docanchor file="page__design" title="The C API">subsec_CApi</docanchor>
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
