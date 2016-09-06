<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile>
  <compound kind="file">
    <name>Connection.hpp</name>
    <path>/Users/adamfowler/Documents/marklogic/git/mlcplusplus/release/include/mlclient/</path>
    <filename>_connection_8hpp</filename>
    <includes id="_document_content_8hpp" name="DocumentContent.hpp" local="no" imported="no">mlclient/DocumentContent.hpp</includes>
    <includes id="_search_description_8hpp" name="SearchDescription.hpp" local="no" imported="no">mlclient/SearchDescription.hpp</includes>
    <includes id="_document_set_8hpp" name="DocumentSet.hpp" local="no" imported="no">mlclient/DocumentSet.hpp</includes>
    <class kind="class">mlclient::IConnection</class>
    <class kind="class">mlclient::Connection</class>
    <namespace>mlclient</namespace>
  </compound>
  <compound kind="file">
    <name>ConnectionWrapper.h</name>
    <path>/Users/adamfowler/Documents/marklogic/git/mlcplusplus/release/include/mlclient/</path>
    <filename>_connection_wrapper_8h</filename>
    <includes id="_response_wrapper_8h" name="ResponseWrapper.h" local="no" imported="no">mlclient/ResponseWrapper.h</includes>
    <member kind="function">
      <type>MLCLIENT_API CConnection *</type>
      <name>ml_connection_new</name>
      <anchorfile>_connection_wrapper_8h.html</anchorfile>
      <anchor>ae51d0c89f69858afc306e0db9dc40bf8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>ml_connection_delete</name>
      <anchorfile>_connection_wrapper_8h.html</anchorfile>
      <anchor>a9a4c39d112c4914b5986edb882b529cd</anchor>
      <arglist>(CConnection *t)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>ml_connection_configure</name>
      <anchorfile>_connection_wrapper_8h.html</anchorfile>
      <anchor>a45b61af5db0a2e53bacbb157b61db733</anchor>
      <arglist>(const CConnection *conn, const char *hostname, const char *port, const char *username, const char *password, const int usessl)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API CResponse *</type>
      <name>ml_connection_doGet</name>
      <anchorfile>_connection_wrapper_8h.html</anchorfile>
      <anchor>a022e306b067719c6e082ea31435281dc</anchor>
      <arglist>(const CConnection *conn, const char *pathAndQuerystring)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API CResponse *</type>
      <name>ml_connection_doPut</name>
      <anchorfile>_connection_wrapper_8h.html</anchorfile>
      <anchor>a0856b09ce1d065d015c8b9f5d934684d</anchor>
      <arglist>(const CConnection *conn, const char *pathAndQuerystring, const char *payload)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API CResponse *</type>
      <name>ml_connection_doPost</name>
      <anchorfile>_connection_wrapper_8h.html</anchorfile>
      <anchor>ac4842aa4c201590f1bab895e68cb66be</anchor>
      <arglist>(const CConnection *conn, const char *pathAndQuerystring, const char *payload)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API CResponse *</type>
      <name>ml_connection_doDelete</name>
      <anchorfile>_connection_wrapper_8h.html</anchorfile>
      <anchor>af2c0fae28024c6ee3d72dfd856205da7</anchor>
      <arglist>(const CConnection *conn, const char *path)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API CResponse *</type>
      <name>ml_connection_getDocument</name>
      <anchorfile>_connection_wrapper_8h.html</anchorfile>
      <anchor>a20ee2cb689da7b31499bc600b50935b8</anchor>
      <arglist>(const CConnection *conn, const char *uri)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API CResponse *</type>
      <name>ml_connection_saveDocument</name>
      <anchorfile>_connection_wrapper_8h.html</anchorfile>
      <anchor>ac2693382bd036a27e68b9af519e90d5e</anchor>
      <arglist>(const CConnection *conn, const char *uri, const char *payload)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API CResponse *</type>
      <name>ml_connection_deleteDocument</name>
      <anchorfile>_connection_wrapper_8h.html</anchorfile>
      <anchor>af26f1c488eba5e8eb92410b7980a905f</anchor>
      <arglist>(const CConnection *conn, const char *uri)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API CResponse *</type>
      <name>ml_connection_search</name>
      <anchorfile>_connection_wrapper_8h.html</anchorfile>
      <anchor>a66fa6cc9bccdeb608458ff920c063a06</anchor>
      <arglist>(const CConnection *conn, const char *searchQuery, const char *qtext, const char *options)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DocumentContent.hpp</name>
    <path>/Users/adamfowler/Documents/marklogic/git/mlcplusplus/release/include/mlclient/</path>
    <filename>_document_content_8hpp</filename>
    <class kind="class">mlclient::IDocumentContent</class>
    <class kind="class">mlclient::IDocumentNode</class>
    <class kind="class">mlclient::IDocumentNavigator</class>
    <class kind="class">mlclient::ITextDocumentContent</class>
    <class kind="class">mlclient::GenericTextDocumentContent</class>
    <class kind="class">mlclient::FileDocumentContent</class>
    <namespace>mlclient</namespace>
    <member kind="enumeration">
      <type></type>
      <name>BinaryEncoding</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>ad47ff6baab050e78452eb2167a2a3b54</anchor>
      <arglist></arglist>
      <enumvalue file="namespacemlclient.html" anchor="ad47ff6baab050e78452eb2167a2a3b54a58c9566f3c750ce7147b045fdd14202b">HEX</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ad47ff6baab050e78452eb2167a2a3b54a35d3245a21b0942070419ef6602d239e">BIN</enumvalue>
    </member>
  </compound>
  <compound kind="file">
    <name>DocumentSet.hpp</name>
    <path>/Users/adamfowler/Documents/marklogic/git/mlcplusplus/release/include/mlclient/</path>
    <filename>_document_set_8hpp</filename>
    <namespace>mlclient</namespace>
    <member kind="typedef">
      <type>std::vector&lt; Document &gt;</type>
      <name>DocumentSet</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>ab61bc9af3d081c084f28073c63fdbda1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; Document &gt;::const_iterator</type>
      <name>DocumentIterator</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>af4bcdd3248b070cb3faca6f86186ec1d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Conversions.hpp</name>
    <path>/Users/adamfowler/Documents/marklogic/git/mlcplusplus/release/include/mlclient/internals/</path>
    <filename>_conversions_8hpp</filename>
  </compound>
  <compound kind="file">
    <name>logging.hpp</name>
    <path>/Users/adamfowler/Documents/marklogic/git/mlcplusplus/release/include/mlclient/</path>
    <filename>logging_8hpp</filename>
    <class kind="struct">mlclient::LoggingConfiguration</class>
    <namespace>mlclient</namespace>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>reconfigureLogging</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>a88d4ac6b7910817c101534a471f02e27</anchor>
      <arglist>(int argc, const char *argv[])</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>reconfigureLoggingSettings</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>afe73e314dfbe4d339c7fd2d0ad00b285</anchor>
      <arglist>(const LoggingConfiguration &amp;config)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ResponseWrapper.h</name>
    <path>/Users/adamfowler/Documents/marklogic/git/mlcplusplus/release/include/mlclient/</path>
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
    <member kind="typedef">
      <type>void</type>
      <name>CResponse</name>
      <anchorfile>_response_wrapper_8h.html</anchorfile>
      <anchor>a54619e103c7689cd29a0910288372ecd</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>ml_response_delete</name>
      <anchorfile>_response_wrapper_8h.html</anchorfile>
      <anchor>a6d10ca625ff125a3449ad605ca74af99</anchor>
      <arglist>(CResponse *t)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const int</type>
      <name>ml_response_length</name>
      <anchorfile>_response_wrapper_8h.html</anchorfile>
      <anchor>a8a115c63d5bc023dff43031e46dadf7f</anchor>
      <arglist>(CResponse *t)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const char *const</type>
      <name>ml_response_String</name>
      <anchorfile>_response_wrapper_8h.html</anchorfile>
      <anchor>a06b4c25815ae6793fe1166d81e5a4d1f</anchor>
      <arglist>(CResponse *t)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const int</type>
      <name>ml_response_GetResponseType</name>
      <anchorfile>_response_wrapper_8h.html</anchorfile>
      <anchor>a275c7c1c833b6fea89852de7d29bd55e</anchor>
      <arglist>(CResponse *t)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const int</type>
      <name>ml_response_GetResponseCode</name>
      <anchorfile>_response_wrapper_8h.html</anchorfile>
      <anchor>a6ab1ef7e6b3bbd69b1920a214ddeb689</anchor>
      <arglist>(CResponse *t)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const char *const</type>
      <name>ml_responsecodes_translate</name>
      <anchorfile>_response_wrapper_8h.html</anchorfile>
      <anchor>a9b55cc6cdcaa9e670e154d1052863fba</anchor>
      <arglist>(int code)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>SearchDescription.hpp</name>
    <path>/Users/adamfowler/Documents/marklogic/git/mlcplusplus/release/include/mlclient/</path>
    <filename>_search_description_8hpp</filename>
    <includes id="_document_content_8hpp" name="DocumentContent.hpp" local="no" imported="no">mlclient/DocumentContent.hpp</includes>
    <class kind="class">mlclient::SearchDescription</class>
    <namespace>mlclient</namespace>
  </compound>
  <compound kind="file">
    <name>DocumentBatchHelper.hpp</name>
    <path>/Users/adamfowler/Documents/marklogic/git/mlcplusplus/release/include/mlclient/utilities/</path>
    <filename>_document_batch_helper_8hpp</filename>
    <includes id="_document_content_8hpp" name="DocumentContent.hpp" local="no" imported="no">mlclient/DocumentContent.hpp</includes>
    <includes id="_document_set_8hpp" name="DocumentSet.hpp" local="no" imported="no">mlclient/DocumentSet.hpp</includes>
    <class kind="class">mlclient::utilities::DocumentBatchHelper</class>
    <namespace>mlclient</namespace>
    <namespace>mlclient::utilities</namespace>
  </compound>
  <compound kind="file">
    <name>PugiXmlHelper.hpp</name>
    <path>/Users/adamfowler/Documents/marklogic/git/mlcplusplus/release/include/mlclient/utilities/</path>
    <filename>_pugi_xml_helper_8hpp</filename>
    <includes id="_document_content_8hpp" name="DocumentContent.hpp" local="no" imported="no">mlclient/DocumentContent.hpp</includes>
    <class kind="class">mlclient::utilities::PugiXmlHelper</class>
    <namespace>mlclient</namespace>
    <namespace>mlclient::utilities</namespace>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::AggregateInfo</name>
    <filename>classmlclient_1_1utilities_1_1_aggregate_info.html</filename>
  </compound>
  <compound kind="class">
    <name>mlclient::internals::AuthenticatingProxy</name>
    <filename>classmlclient_1_1internals_1_1_authenticating_proxy.html</filename>
    <member kind="function">
      <type></type>
      <name>AuthenticatingProxy</name>
      <anchorfile>classmlclient_1_1internals_1_1_authenticating_proxy.html</anchorfile>
      <anchor>a07e22f99ca92351d1f9478d7d717dddc</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>addCredentials</name>
      <anchorfile>classmlclient_1_1internals_1_1_authenticating_proxy.html</anchorfile>
      <anchor>a32f96433d127266157a4cdb92cb22a66</anchor>
      <arglist>(const Credentials &amp;c)</arglist>
    </member>
    <member kind="function">
      <type>const Credentials &amp;</type>
      <name>getCredentials</name>
      <anchorfile>classmlclient_1_1internals_1_1_authenticating_proxy.html</anchorfile>
      <anchor>a1960a9cc8656a8114798e4c7b6d6ef0f</anchor>
      <arglist>(void) const </arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>getSync</name>
      <anchorfile>classmlclient_1_1internals_1_1_authenticating_proxy.html</anchorfile>
      <anchor>a23e1ac4227e078eb28ac91c67eccbb2f</anchor>
      <arglist>(const std::string &amp;host, const std::string &amp;path, const mlclient::HttpHeaders &amp;headers=blankHeaders)</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>postSync</name>
      <anchorfile>classmlclient_1_1internals_1_1_authenticating_proxy.html</anchorfile>
      <anchor>a1bab8a4346bf2b71b2f660e4828bd711</anchor>
      <arglist>(const std::string &amp;host, const std::string &amp;path, const IDocumentContent &amp;body, const mlclient::HttpHeaders &amp;headers=blankHeaders)</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>multiPostSync</name>
      <anchorfile>classmlclient_1_1internals_1_1_authenticating_proxy.html</anchorfile>
      <anchor>a8c1460626e09c8d7c18d438c1c750425</anchor>
      <arglist>(const std::string &amp;host, const std::string &amp;path, const DocumentSet &amp;allContent, const long startPosInclusive, const long endPosInclusive, const mlclient::HttpHeaders &amp;commonHeaders=blankHeaders)</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>putSync</name>
      <anchorfile>classmlclient_1_1internals_1_1_authenticating_proxy.html</anchorfile>
      <anchor>a71cf2df60bc54f17ee576013c98202c4</anchor>
      <arglist>(const std::string &amp;host, const std::string &amp;path, const IDocumentContent &amp;body, const mlclient::HttpHeaders &amp;headers=blankHeaders)</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>deleteSync</name>
      <anchorfile>classmlclient_1_1internals_1_1_authenticating_proxy.html</anchorfile>
      <anchor>a07789ecbe2c239ec64776b67d7028235</anchor>
      <arglist>(const std::string &amp;host, const std::string &amp;path, const mlclient::HttpHeaders &amp;headers=blankHeaders)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::internals::AuthorizationBuilder</name>
    <filename>classmlclient_1_1internals_1_1_authorization_builder.html</filename>
    <member kind="function">
      <type>std::string</type>
      <name>usernameRealmAndPassword</name>
      <anchorfile>classmlclient_1_1internals_1_1_authorization_builder.html</anchorfile>
      <anchor>a144328f7204dff1d33820b00e5b83e31</anchor>
      <arglist>(const std::string &amp;username, const std::string &amp;realm, const std::string &amp;password)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>userRealmPassNonceCnonce</name>
      <anchorfile>classmlclient_1_1internals_1_1_authorization_builder.html</anchorfile>
      <anchor>a5571edb79a2d735d4ffd31c3ab676eac</anchor>
      <arglist>(const std::string &amp;username, const std::string &amp;realm, const std::string &amp;password, const std::string &amp;nonce, const std::string &amp;cnonce)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>methodAndURL</name>
      <anchorfile>classmlclient_1_1internals_1_1_authorization_builder.html</anchorfile>
      <anchor>a4b4304ed3182ccdcc40d96f078605c52</anchor>
      <arglist>(const std::string &amp;method, const std::string &amp;url)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>methodURLAndBodyHash</name>
      <anchorfile>classmlclient_1_1internals_1_1_authorization_builder.html</anchorfile>
      <anchor>a45e027ce65223f141a5f6b43be0200d6</anchor>
      <arglist>(const std::string &amp;method, const std::string &amp;url, const std::string &amp;bodyHash)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>response</name>
      <anchorfile>classmlclient_1_1internals_1_1_authorization_builder.html</anchorfile>
      <anchor>a28c9c035f921bb32dedcc1f79c7c1fb2</anchor>
      <arglist>(const std::string &amp;hash1, const std::string &amp;nonce, const std::string &amp;nonceCount, const std::string &amp;clientNonce, const std::string &amp;qop, const std::string &amp;hash2)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>response</name>
      <anchorfile>classmlclient_1_1internals_1_1_authorization_builder.html</anchorfile>
      <anchor>a147eb6510846ef7685a7ec045bb8e3af</anchor>
      <arglist>(const std::string &amp;hash1, const std::string &amp;nonce, const std::string &amp;hash2)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::Connection</name>
    <filename>classmlclient_1_1_connection.html</filename>
    <base>mlclient::IConnection</base>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>Connection</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a0fa4c3ba43b9eb4dba17173d9864cf00</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>~Connection</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a3f1cfc96bcd34c40f7b62e3d65178996</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>configure</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a94730373b161a41c4cafd1771fcad57f</anchor>
      <arglist>(const std::string &amp;hostname, const std::string &amp;port, const std::string &amp;username, const std::string &amp;password, const bool usessl=false) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>connect</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a727c9d325eedebc7ccc8ed7cbefd453e</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>disconnect</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a56a8416e511507a8a1b42d2065032b16</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setDatabaseName</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a67146fa0ef2ca45fd2f96efc67adb991</anchor>
      <arglist>(const std::string &amp;db) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::string</type>
      <name>getDatabaseName</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a110fecd6b2a50500ba0ae1af9cb23f6a</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>doGet</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a75dc5a7b1a8dfb01dcbf13543fdbfbd2</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>doPut</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a39f2438137287d2dd095f01c5f98e3b7</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>doPost</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>aa0c7272174f1aaba17112a3281dcb3f9</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>doDelete</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a2c7a94f74a1355ba2797fcefb7f0c66a</anchor>
      <arglist>(const std::string &amp;pathAndQueryString) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>getDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a9456f042efcb2c121821c00a5a7408b2</anchor>
      <arglist>(const std::string &amp;uri) override</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual MLCLIENT_API Response *</type>
      <name>getDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a29c15c72e3f46cff8904656bd073b5c7</anchor>
      <arglist>(Document &amp;inout_document) override</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual MLCLIENT_API Response *</type>
      <name>getDocumentContent</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a9adbe1d784cd76d23565f856ce3bfc4a</anchor>
      <arglist>(Document &amp;inout_document) override</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual MLCLIENT_API Response *</type>
      <name>getDocumentProperties</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a7e68508b31fd3a94572dcdf7c274bce2</anchor>
      <arglist>(Document &amp;inout_document) override</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual MLCLIENT_API Response *</type>
      <name>getDocumentPermissions</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a43d3221b859e35ff8618db48839611cb</anchor>
      <arglist>(Document &amp;inout_document) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>saveDocumentContent</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a17c6ec458e420630edaeb099b5482313</anchor>
      <arglist>(const std::string &amp;uri, const IDocumentContent &amp;payload) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>saveDocuments</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a89f26ceb86c718f7a504fbddbd5d5be6</anchor>
      <arglist>(const DocumentSet &amp;documents, const long startPosInclusive, const long endPosInclusive) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>saveDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a182fb20168a38dc3c2ce010cd2f27d51</anchor>
      <arglist>(const Document &amp;doc) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>deleteDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>afad6e3a23b8685ec954f12e8b11712b2</anchor>
      <arglist>(const std::string &amp;uri) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>search</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>aee08dd03abf8d7bd7d34901f17696a22</anchor>
      <arglist>(const SearchDescription &amp;desc) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>searchExtension</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>aacc13387f10b8e34c25a22f3d4ef308d</anchor>
      <arglist>(const std::string &amp;extensionName, const SearchDescription &amp;desc) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>saveSearchOptions</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a5c8b82ff0f799f16db0c4ad4556ef89f</anchor>
      <arglist>(const std::string &amp;name, const IDocumentContent *optionsDoc) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>values</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>ab3a14008c2f2970c2a0031b17312a244</anchor>
      <arglist>(const std::string &amp;valuesName, const std::string &amp;optionsName) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>valuesExtension</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a3ebd6c7ffa6a25488f46bf77d24611dd</anchor>
      <arglist>(const std::string &amp;extensionName, const std::string &amp;valuesName, const std::string &amp;optionsName, const SearchDescription &amp;desc) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>listRootCollections</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a790cdfa2d5842ac076002989617f12d5</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>listCollections</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>af904a48e7f2b016d4c6159fc4b1e5831</anchor>
      <arglist>(const std::string &amp;parentCollection) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>configure</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a94730373b161a41c4cafd1771fcad57f</anchor>
      <arglist>(const std::string &amp;hostname, const std::string &amp;port, const std::string &amp;username, const std::string &amp;password, const bool usessl=false) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>connect</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a727c9d325eedebc7ccc8ed7cbefd453e</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>disconnect</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a56a8416e511507a8a1b42d2065032b16</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setDatabaseName</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a67146fa0ef2ca45fd2f96efc67adb991</anchor>
      <arglist>(const std::string &amp;db) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::string</type>
      <name>getDatabaseName</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a110fecd6b2a50500ba0ae1af9cb23f6a</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>doGet</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a75dc5a7b1a8dfb01dcbf13543fdbfbd2</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>doPut</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a39f2438137287d2dd095f01c5f98e3b7</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>doPost</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>aa0c7272174f1aaba17112a3281dcb3f9</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>doDelete</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a2c7a94f74a1355ba2797fcefb7f0c66a</anchor>
      <arglist>(const std::string &amp;pathAndQueryString) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>getDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a9456f042efcb2c121821c00a5a7408b2</anchor>
      <arglist>(const std::string &amp;uri) override</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual MLCLIENT_API Response *</type>
      <name>getDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a29c15c72e3f46cff8904656bd073b5c7</anchor>
      <arglist>(Document &amp;inout_document) override</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual MLCLIENT_API Response *</type>
      <name>getDocumentContent</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a9adbe1d784cd76d23565f856ce3bfc4a</anchor>
      <arglist>(Document &amp;inout_document) override</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual MLCLIENT_API Response *</type>
      <name>getDocumentProperties</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a7e68508b31fd3a94572dcdf7c274bce2</anchor>
      <arglist>(Document &amp;inout_document) override</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual MLCLIENT_API Response *</type>
      <name>getDocumentPermissions</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a43d3221b859e35ff8618db48839611cb</anchor>
      <arglist>(Document &amp;inout_document) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>saveDocumentContent</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a17c6ec458e420630edaeb099b5482313</anchor>
      <arglist>(const std::string &amp;uri, const IDocumentContent &amp;payload) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>saveDocuments</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a89f26ceb86c718f7a504fbddbd5d5be6</anchor>
      <arglist>(const DocumentSet &amp;documents, const long startPosInclusive, const long endPosInclusive) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>saveDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a182fb20168a38dc3c2ce010cd2f27d51</anchor>
      <arglist>(const Document &amp;doc) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>deleteDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>afad6e3a23b8685ec954f12e8b11712b2</anchor>
      <arglist>(const std::string &amp;uri) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>search</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>aee08dd03abf8d7bd7d34901f17696a22</anchor>
      <arglist>(const SearchDescription &amp;desc) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>searchExtension</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>aacc13387f10b8e34c25a22f3d4ef308d</anchor>
      <arglist>(const std::string &amp;extensionName, const SearchDescription &amp;desc) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>saveSearchOptions</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a5c8b82ff0f799f16db0c4ad4556ef89f</anchor>
      <arglist>(const std::string &amp;name, const IDocumentContent *optionsDoc) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>values</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>ab3a14008c2f2970c2a0031b17312a244</anchor>
      <arglist>(const std::string &amp;valuesName, const std::string &amp;optionsName) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>valuesExtension</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a3ebd6c7ffa6a25488f46bf77d24611dd</anchor>
      <arglist>(const std::string &amp;extensionName, const std::string &amp;valuesName, const std::string &amp;optionsName, const SearchDescription &amp;desc) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>listRootCollections</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>a790cdfa2d5842ac076002989617f12d5</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Response *</type>
      <name>listCollections</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>af904a48e7f2b016d4c6159fc4b1e5831</anchor>
      <arglist>(const std::string &amp;parentCollection) override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::CppRestJsonArrayNode</name>
    <filename>classmlclient_1_1utilities_1_1_cpp_rest_json_array_node.html</filename>
    <base>mlclient::utilities::CppRestJsonContainerNode</base>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isArray</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_array_node.html</anchorfile>
      <anchor>a9050662e3d80d61b18e976f45ce48794</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isObject</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_array_node.html</anchorfile>
      <anchor>ad8dcd056d4b3289091d5fecf66bdafb4</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IDocumentNode *</type>
      <name>asArray</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_array_node.html</anchorfile>
      <anchor>a07ea3987d40505a802d98778a7a72ebc</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IDocumentNode *</type>
      <name>asObject</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_array_node.html</anchorfile>
      <anchor>a88f341db3c9902abdde74d110418e376</anchor>
      <arglist>() const  override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::CppRestJsonContainerNode</name>
    <filename>classmlclient_1_1utilities_1_1_cpp_rest_json_container_node.html</filename>
    <base>mlclient::IDocumentNode</base>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isNull</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_container_node.html</anchorfile>
      <anchor>a99db6a011dce6f7936639a7a1d1d3c52</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isBoolean</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_container_node.html</anchorfile>
      <anchor>a8b00c730a241613434387f4acfbec32e</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isInteger</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_container_node.html</anchorfile>
      <anchor>a865c4d664726bda679705063b9ec00bb</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isDouble</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_container_node.html</anchorfile>
      <anchor>af84bd583caef9f9d6ed14874eba157a1</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isString</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_container_node.html</anchorfile>
      <anchor>a93a895f63895d836fab3782c5c3f503a</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>asBoolean</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_container_node.html</anchorfile>
      <anchor>a38d62077da8c84fc843e06dc162e8d7d</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API int32_t</type>
      <name>asInteger</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_container_node.html</anchorfile>
      <anchor>abb611c20ec91179c2704f1327f60c229</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API double</type>
      <name>asDouble</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_container_node.html</anchorfile>
      <anchor>aa08faf4430cca238085035e1ae2f3bb9</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::string</type>
      <name>asString</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_container_node.html</anchorfile>
      <anchor>aae0f3065ed85abeecea025f8d7585f9a</anchor>
      <arglist>() const  override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::CppRestJsonDocumentContent</name>
    <filename>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</filename>
    <base>mlclient::ITextDocumentContent</base>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>CppRestJsonDocumentContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>af57a52a753ed0eb4246a478dafb39526</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual MLCLIENT_API</type>
      <name>~CppRestJsonDocumentContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a1eb426c6afe674cf3c20aab1de7d4115</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>ab13ad566cef40ea220ef00c5f0fe243d</anchor>
      <arglist>(web::json::value &amp;json)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::istream *</type>
      <name>getStream</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a235ebb39e2d621b4ce7372e9ec8c90be</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a52594a811341eb11ca1f8541074e88c3</anchor>
      <arglist>(std::string content) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::string</type>
      <name>getContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a6a9c060857f3608047df0e1674b0a019</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::string</type>
      <name>getMimeType</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a033220ba51b31a6d95617cc2dae37562</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setMimeType</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a53a21dc81815613ae948a4466acf9a3a</anchor>
      <arglist>(const std::string &amp;mt) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API int</type>
      <name>getLength</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>af66993623cd3862a76779ef7a6cc0986</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IDocumentNavigator *</type>
      <name>navigate</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a736a5c01ef0a0ce473042bb36df70279</anchor>
      <arglist>(bool firstElementAsRoot=false) const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const web::json::value &amp;</type>
      <name>getJson</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a2de79c91ec94662acceb7cfad0a0e919</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>ab13ad566cef40ea220ef00c5f0fe243d</anchor>
      <arglist>(web::json::value &amp;json)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::istream *</type>
      <name>getStream</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a235ebb39e2d621b4ce7372e9ec8c90be</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a52594a811341eb11ca1f8541074e88c3</anchor>
      <arglist>(std::string content) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::string</type>
      <name>getContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a6a9c060857f3608047df0e1674b0a019</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::string</type>
      <name>getMimeType</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a033220ba51b31a6d95617cc2dae37562</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setMimeType</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a53a21dc81815613ae948a4466acf9a3a</anchor>
      <arglist>(const std::string &amp;mt) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API int</type>
      <name>getLength</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>af66993623cd3862a76779ef7a6cc0986</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IDocumentNavigator *</type>
      <name>navigate</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a736a5c01ef0a0ce473042bb36df70279</anchor>
      <arglist>(bool firstElementAsRoot=false) const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const web::json::value &amp;</type>
      <name>getJson</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_content.html</anchorfile>
      <anchor>a2de79c91ec94662acceb7cfad0a0e919</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::CppRestJsonDocumentNavigator</name>
    <filename>classmlclient_1_1utilities_1_1_cpp_rest_json_document_navigator.html</filename>
    <base>mlclient::IDocumentNavigator</base>
    <member kind="function">
      <type>MLCLIENT_API IDocumentNode *</type>
      <name>at</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_navigator.html</anchorfile>
      <anchor>ab1270201ff210bc391b7091c2e39b45f</anchor>
      <arglist>(const std::string &amp;key) const  override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::CppRestJsonDocumentNode</name>
    <filename>classmlclient_1_1utilities_1_1_cpp_rest_json_document_node.html</filename>
    <base>mlclient::IDocumentNode</base>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isNull</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_node.html</anchorfile>
      <anchor>ae9409fbee3f0fcf4cfe844047cb8a648</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isBoolean</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_node.html</anchorfile>
      <anchor>acdc53931f6dbdb31cfe41332bf833123</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isInteger</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_node.html</anchorfile>
      <anchor>afe1e038e1e84d97ea291032cdfc82e8b</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isDouble</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_node.html</anchorfile>
      <anchor>a4de19e4e1e7a3d4895dedf7ce844c96b</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isString</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_node.html</anchorfile>
      <anchor>a56d079e5373769f7b78995901172f803</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isArray</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_node.html</anchorfile>
      <anchor>a3af3d4f416cfa35957db29629d850eaf</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isObject</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_node.html</anchorfile>
      <anchor>a3a496a81aaa3517bef4622697da8334c</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>asBoolean</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_node.html</anchorfile>
      <anchor>a5eb94b47fee42ceeb6b9bc8b064a8a72</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API int32_t</type>
      <name>asInteger</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_node.html</anchorfile>
      <anchor>aeaa00f3b87684ae5f3b6ca4d1d8216fc</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API double</type>
      <name>asDouble</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_node.html</anchorfile>
      <anchor>ad6d1ce6067f3f2510f987e943dc7ceed</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::string</type>
      <name>asString</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_node.html</anchorfile>
      <anchor>a3aeb0f0bc788e30b59852c8391cde59d</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IDocumentNode *</type>
      <name>asArray</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_node.html</anchorfile>
      <anchor>a55e13c107a1dba5e88a172c63d0db54c</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IDocumentNode *</type>
      <name>asObject</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_document_node.html</anchorfile>
      <anchor>ac8ef1cd5f16ed27d55c7664ba07ba1ae</anchor>
      <arglist>() const  override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::CppRestJsonHelper</name>
    <filename>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</filename>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API ITextDocumentContent *</type>
      <name>toDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>a59d2d85146edddd3eb23952c8d5cc543</anchor>
      <arglist>(web::json::value &amp;json)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API ITextDocumentContent *</type>
      <name>toDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>aef55421b7e27a8c75b1bcbdf23f23e23</anchor>
      <arglist>(const Response &amp;resp)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API const web::json::value</type>
      <name>fromDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>ac4945fd15c6f028757650bc70cd3442b</anchor>
      <arglist>(const IDocumentContent &amp;doc)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API const web::json::value</type>
      <name>fromDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>a3535d11bcaf835ea56e84162698e750a</anchor>
      <arglist>(const CppRestJsonDocumentContent &amp;doc)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API web::json::value</type>
      <name>fromResponse</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>a48bd37d846b20bec96d8085e1f83f561</anchor>
      <arglist>(const Response &amp;resp)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API PermissionSet</type>
      <name>permissionsFromResponse</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>a4103891f233ae3c686cadb30c65cebd1</anchor>
      <arglist>(const Response &amp;resp)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API ITextDocumentContent *</type>
      <name>toDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>a59d2d85146edddd3eb23952c8d5cc543</anchor>
      <arglist>(web::json::value &amp;json)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API ITextDocumentContent *</type>
      <name>toDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>aef55421b7e27a8c75b1bcbdf23f23e23</anchor>
      <arglist>(const Response &amp;resp)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API const web::json::value</type>
      <name>fromDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>ac4945fd15c6f028757650bc70cd3442b</anchor>
      <arglist>(const IDocumentContent &amp;doc)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API const web::json::value</type>
      <name>fromDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>a3535d11bcaf835ea56e84162698e750a</anchor>
      <arglist>(const CppRestJsonDocumentContent &amp;doc)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API web::json::value</type>
      <name>fromResponse</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>a48bd37d846b20bec96d8085e1f83f561</anchor>
      <arglist>(const Response &amp;resp)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API PermissionSet</type>
      <name>permissionsFromResponse</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_helper.html</anchorfile>
      <anchor>a4103891f233ae3c686cadb30c65cebd1</anchor>
      <arglist>(const Response &amp;resp)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::CppRestJsonObjectNode</name>
    <filename>classmlclient_1_1utilities_1_1_cpp_rest_json_object_node.html</filename>
    <base>mlclient::utilities::CppRestJsonContainerNode</base>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isArray</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_object_node.html</anchorfile>
      <anchor>abfbc58d052e7ab02df5175d44c2de6e9</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isObject</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_object_node.html</anchorfile>
      <anchor>a25675f5583ea7ffa73b804eb67670ecb</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IDocumentNode *</type>
      <name>asArray</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_object_node.html</anchorfile>
      <anchor>ab38d1c541436c244c9ce244f7cb87b6a</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IDocumentNode *</type>
      <name>asObject</name>
      <anchorfile>classmlclient_1_1utilities_1_1_cpp_rest_json_object_node.html</anchorfile>
      <anchor>a672795effa05f2c25ccf32ba49412b61</anchor>
      <arglist>() const  override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::internals::Credentials</name>
    <filename>classmlclient_1_1internals_1_1_credentials.html</filename>
    <member kind="function">
      <type></type>
      <name>Credentials</name>
      <anchorfile>classmlclient_1_1internals_1_1_credentials.html</anchorfile>
      <anchor>aee8918e48fe396575aad7b2d0b36afe0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Credentials</name>
      <anchorfile>classmlclient_1_1internals_1_1_credentials.html</anchorfile>
      <anchor>a414db42ca9070b44ec2853bbe03fd012</anchor>
      <arglist>(const std::string &amp;username, const std::string &amp;password)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Credentials</name>
      <anchorfile>classmlclient_1_1internals_1_1_credentials.html</anchorfile>
      <anchor>af6a8629e459ffe55e4e4658f4ae363b4</anchor>
      <arglist>(const std::string &amp;username, const std::string &amp;password, const std::string &amp;cnonce, const uint32_t &amp;nc)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Credentials</name>
      <anchorfile>classmlclient_1_1internals_1_1_credentials.html</anchorfile>
      <anchor>a4c6d0d8ff204c2ca111c67d7fb61ed9d</anchor>
      <arglist>(const std::wstring &amp;username, const std::wstring &amp;password)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>canAuthenticate</name>
      <anchorfile>classmlclient_1_1internals_1_1_credentials.html</anchorfile>
      <anchor>a92543eaefce0baec76989762c0f59496</anchor>
      <arglist>(void) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>parseWWWAuthenticateHeader</name>
      <anchorfile>classmlclient_1_1internals_1_1_credentials.html</anchorfile>
      <anchor>ac22af4ce831b8495d1f23c3976b43f57</anchor>
      <arglist>(const std::string &amp;_raw)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>getNonce</name>
      <anchorfile>classmlclient_1_1internals_1_1_credentials.html</anchorfile>
      <anchor>a98cff009cd048769ba2db8bc45889168</anchor>
      <arglist>(void) const </arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>getQop</name>
      <anchorfile>classmlclient_1_1internals_1_1_credentials.html</anchorfile>
      <anchor>a3505f55878e110f8a7113b227a2d090a</anchor>
      <arglist>(void) const </arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>getOpaque</name>
      <anchorfile>classmlclient_1_1internals_1_1_credentials.html</anchorfile>
      <anchor>a19e6bcca49c9cefc233aaebd738f4db9</anchor>
      <arglist>(void) const </arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>getRealm</name>
      <anchorfile>classmlclient_1_1internals_1_1_credentials.html</anchorfile>
      <anchor>af9b2370d48e21a03630b98df8af00fee</anchor>
      <arglist>(void) const </arglist>
    </member>
    <member kind="function" protection="protected">
      <type>std::string</type>
      <name>authenticate</name>
      <anchorfile>classmlclient_1_1internals_1_1_credentials.html</anchorfile>
      <anchor>a62464319281bf6c2702b27a717387e63</anchor>
      <arglist>(const std::string &amp;method, const std::string &amp;uri, const std::string &amp;auth_header)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>std::string</type>
      <name>authenticate</name>
      <anchorfile>classmlclient_1_1internals_1_1_credentials.html</anchorfile>
      <anchor>a09d202ba3bc1651ec5e8dd5ac3c63792</anchor>
      <arglist>(const std::string &amp;method, const std::string &amp;uri)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>std::string</type>
      <name>generateRandomCnonce</name>
      <anchorfile>classmlclient_1_1internals_1_1_credentials.html</anchorfile>
      <anchor>afdf42763c9e139b66d3c9a8527a989a4</anchor>
      <arglist>(void) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CWrapper</name>
    <filename>class_c_wrapper.html</filename>
    <templarg></templarg>
  </compound>
  <compound kind="class">
    <name>mlclient::Document</name>
    <filename>classmlclient_1_1_document.html</filename>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>Document</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>a10c44588974d23d9601bf73ac85d42a7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>Document</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>a8914df79aea0d0bd770150fc5fcb4a92</anchor>
      <arglist>(const std::string &amp;uri)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>Document</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>a0457b15c2473d07f76138785981b516e</anchor>
      <arglist>(const std::string &amp;uri, IDocumentContent *own_content)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>Document</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>a830313bef08c90f59fc7e30b204a10b8</anchor>
      <arglist>(const std::string &amp;uri, IDocumentContent *own_content, IDocumentContent *own_properties)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>Document</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>a01d8c0c3b0267124a67c49842fe8f151</anchor>
      <arglist>(const std::string &amp;uri, IDocumentContent *own_content, IDocumentContent *own_properties, PermissionSet own_permissions)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual MLCLIENT_API</type>
      <name>~Document</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>a9e15c68581c11bf05236e7f2ea56dd9b</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::string &amp;</type>
      <name>getUri</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>a0eb62460d003eccaa54e9509f913077a</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setUri</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>a17e7891d7c2529a930b26a64cf252276</anchor>
      <arglist>(const std::string &amp;uri)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const bool</type>
      <name>hasUri</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>a20fdfbe76bf5fa64304453f05d8ed04a</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const CollectionSet</type>
      <name>getCollections</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>a9a64c31ba3bed7c400bea4ffc2dc5846</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setCollections</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>a940587860713fb1b45824d3e6db6640b</anchor>
      <arglist>(const CollectionSet &amp;collections)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const bool</type>
      <name>hasCollections</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>a58471c8a789aa7646ff9a7ee7f74ee7b</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const IDocumentContent *</type>
      <name>getContent</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>a3c75af9322deaff79276dc96eec53c81</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const bool</type>
      <name>hasContent</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>a8dc6ed31ec726da89dad45d42140f5e4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setContent</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>a46a3b7b652b436ea79de519a3bcb9a0e</anchor>
      <arglist>(IDocumentContent *own_content)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const IDocumentContent *</type>
      <name>getProperties</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>abb1ef65d2c23e2f1ad301eb80ef03a8e</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const bool</type>
      <name>hasProperties</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>acc5329570c631f4400a27ab9f75127b6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setProperties</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>aa12a0154efd9fee5c659ceb60f5063a8</anchor>
      <arglist>(IDocumentContent *own_properties)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const PermissionSet</type>
      <name>getPermissions</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>a7a25e5063557efcf072b080ee5536a91</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const bool</type>
      <name>hasPermissions</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>aa54412b88438b9f397d128377b0e2add</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setPermissions</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>a0766c996a5f08ba4f0ecc473e3778196</anchor>
      <arglist>(PermissionSet own_permissions)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>operator==</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>a8d930ad06b3d322175223077943fd5c3</anchor>
      <arglist>(const Document &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>operator!=</name>
      <anchorfile>classmlclient_1_1_document.html</anchorfile>
      <anchor>a4e68a2f34724a09cfdf6c73005e099a5</anchor>
      <arglist>(const Document &amp;other)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::DocumentBatchHelper</name>
    <filename>classmlclient_1_1utilities_1_1_document_batch_helper.html</filename>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API void</type>
      <name>addFilesToDocumentSet</name>
      <anchorfile>classmlclient_1_1utilities_1_1_document_batch_helper.html</anchorfile>
      <anchor>a243afd01b2530114c9807c4300c14e27</anchor>
      <arglist>(const std::string &amp;folder, const std::string &amp;baseFolder, const bool stripBase, const std::string &amp;appendBase, const CollectionSet &amp;collections, const PermissionSet &amp;permissions, IDocumentContent *properties, DocumentSet &amp;addTo, bool showHiddenDirs=false)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::DocumentBatchWriter</name>
    <filename>classmlclient_1_1utilities_1_1_document_batch_writer.html</filename>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>DocumentBatchWriter</name>
      <anchorfile>classmlclient_1_1utilities_1_1_document_batch_writer.html</anchorfile>
      <anchor>a8bf6b417569ec8f6f8a7556524278959</anchor>
      <arglist>(IConnection *conn)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>DocumentBatchWriter</name>
      <anchorfile>classmlclient_1_1utilities_1_1_document_batch_writer.html</anchorfile>
      <anchor>a434f0fe37626853a4bc79f9db805e630</anchor>
      <arglist>(const DocumentBatchWriter &amp;other)=delete</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>~DocumentBatchWriter</name>
      <anchorfile>classmlclient_1_1utilities_1_1_document_batch_writer.html</anchorfile>
      <anchor>a2f781b0a5f7156bfd4a0fadfd0c3c63e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>assignDocuments</name>
      <anchorfile>classmlclient_1_1utilities_1_1_document_batch_writer.html</anchorfile>
      <anchor>a9e8a774dbb3097da8087591e8614ffa1</anchor>
      <arglist>(DocumentSet &amp;&amp;set)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setBatchParameters</name>
      <anchorfile>classmlclient_1_1utilities_1_1_document_batch_writer.html</anchorfile>
      <anchor>ac0647a0d283ad02b7e6322a0f01e5007</anchor>
      <arglist>(const int parallelTasks, const int batchSize, const TransactionMode &amp;mode)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const int</type>
      <name>getParallelTasks</name>
      <anchorfile>classmlclient_1_1utilities_1_1_document_batch_writer.html</anchorfile>
      <anchor>a5cdbcb32447332960065a3989f0068ec</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const int</type>
      <name>getBatchSize</name>
      <anchorfile>classmlclient_1_1utilities_1_1_document_batch_writer.html</anchorfile>
      <anchor>a4022825ecdda4a737a144222b51bea03</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const TransactionMode</type>
      <name>getMode</name>
      <anchorfile>classmlclient_1_1utilities_1_1_document_batch_writer.html</anchorfile>
      <anchor>ae86a4a0eb89e7ca8a759aab36e7e3a17</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>addBatchListener</name>
      <anchorfile>classmlclient_1_1utilities_1_1_document_batch_writer.html</anchorfile>
      <anchor>aeea1bc1ca86ebeb6494821a47a82e3ab</anchor>
      <arglist>(IBatchNotifiable *notifiable)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>removeBatchListener</name>
      <anchorfile>classmlclient_1_1utilities_1_1_document_batch_writer.html</anchorfile>
      <anchor>a4ad20ecfc0a85c51ac1f2dc42b99601c</anchor>
      <arglist>(IBatchNotifiable *notifiable)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>send</name>
      <anchorfile>classmlclient_1_1utilities_1_1_document_batch_writer.html</anchorfile>
      <anchor>a33513013acb21b4076040b7964a47460</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>stop</name>
      <anchorfile>classmlclient_1_1utilities_1_1_document_batch_writer.html</anchorfile>
      <anchor>a2f0c297771d40b04292210cfb77958d9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>wait</name>
      <anchorfile>classmlclient_1_1utilities_1_1_document_batch_writer.html</anchorfile>
      <anchor>a55c3361aee41499df23e8cb1834e14f4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const bool</type>
      <name>isComplete</name>
      <anchorfile>classmlclient_1_1utilities_1_1_document_batch_writer.html</anchorfile>
      <anchor>a74cf27d56d87a71845014e8d9182414c</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const bool</type>
      <name>isCancelled</name>
      <anchorfile>classmlclient_1_1utilities_1_1_document_batch_writer.html</anchorfile>
      <anchor>afe5344e5aaa094f0bda0ac96e702d03f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const bool</type>
      <name>isFinished</name>
      <anchorfile>classmlclient_1_1utilities_1_1_document_batch_writer.html</anchorfile>
      <anchor>a484a29fe03fce83380928a3e58cc800d</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const Progress</type>
      <name>getProgress</name>
      <anchorfile>classmlclient_1_1utilities_1_1_document_batch_writer.html</anchorfile>
      <anchor>a165978a3d88c4147ca7ab30e25dc829a</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::DocumentHelper</name>
    <filename>classmlclient_1_1utilities_1_1_document_helper.html</filename>
    <member kind="function" static="yes">
      <type>static Document *</type>
      <name>fromResponse</name>
      <anchorfile>classmlclient_1_1utilities_1_1_document_helper.html</anchorfile>
      <anchor>a04e6383e83375e63b8cd88629615d675</anchor>
      <arglist>(const Response &amp;resp)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>fromResponse</name>
      <anchorfile>classmlclient_1_1utilities_1_1_document_helper.html</anchorfile>
      <anchor>a57de7167f57031ed33aac864127777cf</anchor>
      <arglist>(const Response &amp;resp, Document &amp;doc)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static IDocumentContent *</type>
      <name>contentFromResponse</name>
      <anchorfile>classmlclient_1_1utilities_1_1_document_helper.html</anchorfile>
      <anchor>a2e50e38d175015ac967f64d6afac985b</anchor>
      <arglist>(const Response &amp;resp)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::internals::FakeConnection</name>
    <filename>classmlclient_1_1internals_1_1_fake_connection.html</filename>
    <base>mlclient::IConnection</base>
    <member kind="function">
      <type></type>
      <name>FakeConnection</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>ad6187f5dec9a05eefc688cf083b085af</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FakeConnection</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>acc0cc78a6f99914b06339b25ea6cad84</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>configure</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>a71cacc229c9c0f7ac03804e5fb8b1669</anchor>
      <arglist>(const std::string &amp;hostname, const std::string &amp;port, const std::string &amp;username, const std::string &amp;password, const bool usessl=false) override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDatabaseName</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>a33fed601b3c93c873b91b6a17e47861d</anchor>
      <arglist>(const std::string &amp;db) override</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>getDatabaseName</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>a08fede186cf73a60eeaf076609f690f4</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>connect</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>a9973040a19ee0269c527814198f97307</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>disconnect</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>a3aa2c739a2bbaa8e5e101c5c56fd931b</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>doGet</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>afde3fe440884a9bd028012c156afe5b9</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>doPut</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>a73410f141efeac8651f4d40249a84a74</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>doPost</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>a739a3b0945f8e9e9fbe892b1c947d1d4</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>doDelete</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>a2fe0bcc66df5c275abe88e47390c8742</anchor>
      <arglist>(const std::string &amp;pathAndQueryString) override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>configure</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>a71cacc229c9c0f7ac03804e5fb8b1669</anchor>
      <arglist>(const std::string &amp;hostname, const std::string &amp;port, const std::string &amp;username, const std::string &amp;password, const bool usessl=false) override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDatabaseName</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>a33fed601b3c93c873b91b6a17e47861d</anchor>
      <arglist>(const std::string &amp;db) override</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>getDatabaseName</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>a08fede186cf73a60eeaf076609f690f4</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>connect</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>a9973040a19ee0269c527814198f97307</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>disconnect</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>a3aa2c739a2bbaa8e5e101c5c56fd931b</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>doGet</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>afde3fe440884a9bd028012c156afe5b9</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>doPut</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>a73410f141efeac8651f4d40249a84a74</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>doPost</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>a739a3b0945f8e9e9fbe892b1c947d1d4</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>doDelete</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>a2fe0bcc66df5c275abe88e47390c8742</anchor>
      <arglist>(const std::string &amp;pathAndQueryString) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>getDocument</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>aac31e04366f4b9b88fb61d122afc96da</anchor>
      <arglist>(const std::string &amp;uri) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>saveDocumentContent</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>a84dacbd78315e0f776bfb902b6ec5787</anchor>
      <arglist>(const std::string &amp;uri, const IDocumentContent &amp;payload) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>deleteDocument</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>a23df410e9531d788e3513794d84015a6</anchor>
      <arglist>(const std::string &amp;uri) override</arglist>
    </member>
    <member kind="function">
      <type>Response *</type>
      <name>search</name>
      <anchorfile>classmlclient_1_1internals_1_1_fake_connection.html</anchorfile>
      <anchor>a7d9c3a99d890555bbbae83724220ce0e</anchor>
      <arglist>(const SearchDescription &amp;desc) override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::FileDocumentContent</name>
    <filename>classmlclient_1_1_file_document_content.html</filename>
    <base>mlclient::IDocumentContent</base>
    <member kind="function">
      <type>MLCLIENT_API std::istream *</type>
      <name>getStream</name>
      <anchorfile>classmlclient_1_1_file_document_content.html</anchorfile>
      <anchor>a0b4d2ff97352ccb172e309d860c39af9</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::string</type>
      <name>getContent</name>
      <anchorfile>classmlclient_1_1_file_document_content.html</anchorfile>
      <anchor>aa844fe80c0aeb1136c44780c9a37f755</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::string</type>
      <name>getMimeType</name>
      <anchorfile>classmlclient_1_1_file_document_content.html</anchorfile>
      <anchor>a03a383671f0435a8716740f7fb97a2e4</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setMimeType</name>
      <anchorfile>classmlclient_1_1_file_document_content.html</anchorfile>
      <anchor>abd36cdc094d45fffba6ba251b2ed9273</anchor>
      <arglist>(const std::string &amp;mt) override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::GenericQuery</name>
    <filename>classmlclient_1_1utilities_1_1_generic_query.html</filename>
    <base>mlclient::utilities::IQuery</base>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>GenericQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_generic_query.html</anchorfile>
      <anchor>ae5ef7929a024d1780c215bd8db3499e8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_generic_query.html</anchorfile>
      <anchor>a35768c58fe1e0c74b1cfe81b721ae730</anchor>
      <arglist>(const std::string &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::string &amp;</type>
      <name>getQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_generic_query.html</anchorfile>
      <anchor>a1fdf85eadda7ae4a86293f1344ec460e</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::GenericTextDocumentContent</name>
    <filename>classmlclient_1_1_generic_text_document_content.html</filename>
    <base>mlclient::ITextDocumentContent</base>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>GenericTextDocumentContent</name>
      <anchorfile>classmlclient_1_1_generic_text_document_content.html</anchorfile>
      <anchor>a23ed3f174cc318bbd86e43d642ffa002</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>GenericTextDocumentContent</name>
      <anchorfile>classmlclient_1_1_generic_text_document_content.html</anchorfile>
      <anchor>adf638c372d1e764c0f2325b58a926989</anchor>
      <arglist>(const GenericTextDocumentContent &amp;doc)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>GenericTextDocumentContent</name>
      <anchorfile>classmlclient_1_1_generic_text_document_content.html</anchorfile>
      <anchor>a19114836dfc6358121cefc824e2aecc2</anchor>
      <arglist>(const ITextDocumentContent &amp;doc)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual MLCLIENT_API</type>
      <name>~GenericTextDocumentContent</name>
      <anchorfile>classmlclient_1_1_generic_text_document_content.html</anchorfile>
      <anchor>a25aadcdff58128e0d681ea917c546e89</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setContent</name>
      <anchorfile>classmlclient_1_1_generic_text_document_content.html</anchorfile>
      <anchor>a93333fc4d98ef30727217e80bd2a622a</anchor>
      <arglist>(std::string content) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::istream *</type>
      <name>getStream</name>
      <anchorfile>classmlclient_1_1_generic_text_document_content.html</anchorfile>
      <anchor>a6e36d71587856cea729a9473fa528ce3</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::string</type>
      <name>getContent</name>
      <anchorfile>classmlclient_1_1_generic_text_document_content.html</anchorfile>
      <anchor>a48bebdfcd811adcdc3fa0689a421daf7</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::string</type>
      <name>getMimeType</name>
      <anchorfile>classmlclient_1_1_generic_text_document_content.html</anchorfile>
      <anchor>ad2ce0ba1359c36b12770971b874b7bc5</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setMimeType</name>
      <anchorfile>classmlclient_1_1_generic_text_document_content.html</anchorfile>
      <anchor>ace062272c69845f247b328f101d01db2</anchor>
      <arglist>(const std::string &amp;mt) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API int</type>
      <name>getLength</name>
      <anchorfile>classmlclient_1_1_generic_text_document_content.html</anchorfile>
      <anchor>afe0a92e6b4cd39d1791666484f9cb89f</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IDocumentNavigator *</type>
      <name>navigate</name>
      <anchorfile>classmlclient_1_1_generic_text_document_content.html</anchorfile>
      <anchor>ab9f0c496dc863049da1639bfc2b244a2</anchor>
      <arglist>(bool firstElementAsRoot=false) const  override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::HttpHeaders</name>
    <filename>classmlclient_1_1_http_headers.html</filename>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::IBatchNotifiable</name>
    <filename>classmlclient_1_1utilities_1_1_i_batch_notifiable.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API void</type>
      <name>batchOperationComplete</name>
      <anchorfile>classmlclient_1_1utilities_1_1_i_batch_notifiable.html</anchorfile>
      <anchor>a4cdf83a6ab8d7aa23139744ec60b0a57</anchor>
      <arglist>(const DocumentUriSet out_uris, bool success, std::exception *problem)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::IConnection</name>
    <filename>classmlclient_1_1_i_connection.html</filename>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>IConnection</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>afaf4c99c9844c7a73feff2cde9f6bd2e</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~IConnection</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a8e661d92e40d63962d78dd3e659e38f2</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API void</type>
      <name>configure</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a82edc93d7ca0cc723323cde23e70ac98</anchor>
      <arglist>(const std::string &amp;hostname, const std::string &amp;port, const std::string &amp;username, const std::string &amp;password, const bool usessl=false)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API bool</type>
      <name>connect</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a62b6796afd2354dcc0af0574282fd461</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API void</type>
      <name>disconnect</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a59fc665d5052673448a689a346877b7e</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API void</type>
      <name>setDatabaseName</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>ab234cd14790c42d94d53bba2d8df71ab</anchor>
      <arglist>(const std::string &amp;db)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API std::string</type>
      <name>getDatabaseName</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a9d414f4ff7797d6265001faee51a5329</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>doGet</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>aff746a444f75971bef0e57a6fcb5bef5</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>doPut</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a6e5b776fc496d8fb129c8e78d15da976</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>doPost</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>aeff605e34986204afd5b2f5040c193b9</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>doDelete</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a41b90eac128498d6739eb757cb93aeb2</anchor>
      <arglist>(const std::string &amp;pathAndQueryString)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>getDocument</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a3e57f048d29086c67c052c2c657b2a3f</anchor>
      <arglist>(const std::string &amp;uri)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>getDocument</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a280818f153bd49f32df4dad793c97653</anchor>
      <arglist>(Document &amp;inout_document)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>getDocumentContent</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>abfe3cdb418eb5af045594633d4034e78</anchor>
      <arglist>(Document &amp;inout_document)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>getDocumentProperties</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a4b68b70b974d7d626b20f9e3c0842b25</anchor>
      <arglist>(Document &amp;inout_document)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>getDocumentPermissions</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a08993a40b25df23c7ccca68fd68cd795</anchor>
      <arglist>(Document &amp;inout_document)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>saveDocumentContent</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a34e2014c15e67a1487906ef57f31909d</anchor>
      <arglist>(const std::string &amp;uri, const IDocumentContent &amp;payload)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>saveDocuments</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a9e2be0a1db1f52d602d0d9863567e078</anchor>
      <arglist>(const DocumentSet &amp;documents, const long startPosInclusive, const long endPosInclusive)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>saveDocument</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a62a35d805f695ac7c0ccb4bad1d03703</anchor>
      <arglist>(const Document &amp;doc)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>deleteDocument</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>ab5fb8f4ea90f281db3a87196e2752950</anchor>
      <arglist>(const std::string &amp;uri)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>search</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>ad4a6a559fe192c6f4efd30b54f81fc65</anchor>
      <arglist>(const SearchDescription &amp;desc)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>searchExtension</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a317b4495984961ebed3bb905083acc5d</anchor>
      <arglist>(const std::string &amp;extensionName, const SearchDescription &amp;desc)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>saveSearchOptions</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a1798c63b69694f6f45f014315033beb7</anchor>
      <arglist>(const std::string &amp;optionsName, const IDocumentContent *optionsDoc)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>values</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a7292786947716b79ce2721bf388c1675</anchor>
      <arglist>(const std::string &amp;valuesName, const std::string &amp;optionsName)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>valuesExtension</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a87683d6d193a962f0a8a811610e3fb67</anchor>
      <arglist>(const std::string &amp;extensionName, const std::string &amp;valuesName, const std::string &amp;optionsName, const SearchDescription &amp;desc)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>listRootCollections</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>abc3ea8a461292cab4eb0ec8d73e96bee</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>listCollections</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a50942c2e1b4255b3aa433efb26e93b3c</anchor>
      <arglist>(const std::string &amp;parentCollection)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API void</type>
      <name>configure</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a82edc93d7ca0cc723323cde23e70ac98</anchor>
      <arglist>(const std::string &amp;hostname, const std::string &amp;port, const std::string &amp;username, const std::string &amp;password, const bool usessl=false)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API bool</type>
      <name>connect</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a62b6796afd2354dcc0af0574282fd461</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API void</type>
      <name>disconnect</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a59fc665d5052673448a689a346877b7e</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API void</type>
      <name>setDatabaseName</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>ab234cd14790c42d94d53bba2d8df71ab</anchor>
      <arglist>(const std::string &amp;db)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API std::string</type>
      <name>getDatabaseName</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a9d414f4ff7797d6265001faee51a5329</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>doGet</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>aff746a444f75971bef0e57a6fcb5bef5</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>doPut</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a6e5b776fc496d8fb129c8e78d15da976</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>doPost</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>aeff605e34986204afd5b2f5040c193b9</anchor>
      <arglist>(const std::string &amp;pathAndQuerystring, const IDocumentContent &amp;payload)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>doDelete</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a41b90eac128498d6739eb757cb93aeb2</anchor>
      <arglist>(const std::string &amp;pathAndQueryString)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>getDocument</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a3e57f048d29086c67c052c2c657b2a3f</anchor>
      <arglist>(const std::string &amp;uri)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>getDocument</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a280818f153bd49f32df4dad793c97653</anchor>
      <arglist>(Document &amp;inout_document)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>getDocumentContent</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>abfe3cdb418eb5af045594633d4034e78</anchor>
      <arglist>(Document &amp;inout_document)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>getDocumentProperties</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a4b68b70b974d7d626b20f9e3c0842b25</anchor>
      <arglist>(Document &amp;inout_document)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>getDocumentPermissions</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a08993a40b25df23c7ccca68fd68cd795</anchor>
      <arglist>(Document &amp;inout_document)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>saveDocumentContent</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a34e2014c15e67a1487906ef57f31909d</anchor>
      <arglist>(const std::string &amp;uri, const IDocumentContent &amp;payload)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>saveDocuments</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a9e2be0a1db1f52d602d0d9863567e078</anchor>
      <arglist>(const DocumentSet &amp;documents, const long startPosInclusive, const long endPosInclusive)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>saveDocument</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a62a35d805f695ac7c0ccb4bad1d03703</anchor>
      <arglist>(const Document &amp;doc)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>deleteDocument</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>ab5fb8f4ea90f281db3a87196e2752950</anchor>
      <arglist>(const std::string &amp;uri)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>search</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>ad4a6a559fe192c6f4efd30b54f81fc65</anchor>
      <arglist>(const SearchDescription &amp;desc)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>searchExtension</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a317b4495984961ebed3bb905083acc5d</anchor>
      <arglist>(const std::string &amp;extensionName, const SearchDescription &amp;desc)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>saveSearchOptions</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a1798c63b69694f6f45f014315033beb7</anchor>
      <arglist>(const std::string &amp;optionsName, const IDocumentContent *optionsDoc)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>values</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a7292786947716b79ce2721bf388c1675</anchor>
      <arglist>(const std::string &amp;valuesName, const std::string &amp;optionsName)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>valuesExtension</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a87683d6d193a962f0a8a811610e3fb67</anchor>
      <arglist>(const std::string &amp;extensionName, const std::string &amp;valuesName, const std::string &amp;optionsName, const SearchDescription &amp;desc)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>listRootCollections</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>abc3ea8a461292cab4eb0ec8d73e96bee</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API Response *</type>
      <name>listCollections</name>
      <anchorfile>classmlclient_1_1_i_connection.html</anchorfile>
      <anchor>a50942c2e1b4255b3aa433efb26e93b3c</anchor>
      <arglist>(const std::string &amp;parentCollection)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::IContainerRef</name>
    <filename>classmlclient_1_1utilities_1_1_i_container_ref.html</filename>
  </compound>
  <compound kind="class">
    <name>mlclient::IDocumentContent</name>
    <filename>classmlclient_1_1_i_document_content.html</filename>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>IDocumentContent</name>
      <anchorfile>classmlclient_1_1_i_document_content.html</anchorfile>
      <anchor>a086d89454998056b283bcad56e780025</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API</type>
      <name>~IDocumentContent</name>
      <anchorfile>classmlclient_1_1_i_document_content.html</anchorfile>
      <anchor>a540378b9f20716c53cbef978b01b0d39</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API std::istream *</type>
      <name>getStream</name>
      <anchorfile>classmlclient_1_1_i_document_content.html</anchorfile>
      <anchor>a87dbdd7e43ac68860874435fdc88922e</anchor>
      <arglist>() const  =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API std::string</type>
      <name>getContent</name>
      <anchorfile>classmlclient_1_1_i_document_content.html</anchorfile>
      <anchor>a0e840e72ae60363cd6b44f0554241592</anchor>
      <arglist>() const  =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API std::string</type>
      <name>getMimeType</name>
      <anchorfile>classmlclient_1_1_i_document_content.html</anchorfile>
      <anchor>af492b5a5f9e021f7b19e0da1801a3a5e</anchor>
      <arglist>() const  =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API void</type>
      <name>setMimeType</name>
      <anchorfile>classmlclient_1_1_i_document_content.html</anchorfile>
      <anchor>ad68d2a0cec49bb4c5b590f1c1b97cbc0</anchor>
      <arglist>(const std::string &amp;mt)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::IDocumentNavigator</name>
    <filename>classmlclient_1_1_i_document_navigator.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API IDocumentNode *</type>
      <name>at</name>
      <anchorfile>classmlclient_1_1_i_document_navigator.html</anchorfile>
      <anchor>ab013800190a58bb7687e2d7e306e0dfd</anchor>
      <arglist>(const std::string &amp;key) const  =0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::IDocumentNode</name>
    <filename>classmlclient_1_1_i_document_node.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API bool</type>
      <name>isNull</name>
      <anchorfile>classmlclient_1_1_i_document_node.html</anchorfile>
      <anchor>a140110907b91bdc6f08e2e0d4b02776a</anchor>
      <arglist>() const  =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API bool</type>
      <name>isBoolean</name>
      <anchorfile>classmlclient_1_1_i_document_node.html</anchorfile>
      <anchor>a4ce9afd75b99012cbd607e64d6a38d5b</anchor>
      <arglist>() const  =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API bool</type>
      <name>isInteger</name>
      <anchorfile>classmlclient_1_1_i_document_node.html</anchorfile>
      <anchor>a31c3703eb78a6eaf20099e2c07a4c41e</anchor>
      <arglist>() const  =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API bool</type>
      <name>isDouble</name>
      <anchorfile>classmlclient_1_1_i_document_node.html</anchorfile>
      <anchor>a0a2fb6902e6e56de983d9685d074ebaa</anchor>
      <arglist>() const  =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API bool</type>
      <name>isString</name>
      <anchorfile>classmlclient_1_1_i_document_node.html</anchorfile>
      <anchor>a3ca7f7648ab2026ad29d50c25660c311</anchor>
      <arglist>() const  =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API bool</type>
      <name>isArray</name>
      <anchorfile>classmlclient_1_1_i_document_node.html</anchorfile>
      <anchor>a0c0621b56e82aff8f7460db5a1cc7d61</anchor>
      <arglist>() const  =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API bool</type>
      <name>isObject</name>
      <anchorfile>classmlclient_1_1_i_document_node.html</anchorfile>
      <anchor>a6ac9bf7f4d7af1b272d9c00e415672c1</anchor>
      <arglist>() const  =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API bool</type>
      <name>asBoolean</name>
      <anchorfile>classmlclient_1_1_i_document_node.html</anchorfile>
      <anchor>ac96b39e5cfa63c9f3ea4e891f8a5d3e0</anchor>
      <arglist>() const  =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API int32_t</type>
      <name>asInteger</name>
      <anchorfile>classmlclient_1_1_i_document_node.html</anchorfile>
      <anchor>acc9cee378e2d393be9c5f353b4f53b16</anchor>
      <arglist>() const  =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API double</type>
      <name>asDouble</name>
      <anchorfile>classmlclient_1_1_i_document_node.html</anchorfile>
      <anchor>a7a4517e098de65735257aad81e54c492</anchor>
      <arglist>() const  =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API std::string</type>
      <name>asString</name>
      <anchorfile>classmlclient_1_1_i_document_node.html</anchorfile>
      <anchor>a93e528813a3f85c9dc514ff726c2fdbb</anchor>
      <arglist>() const  =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API IDocumentNode *</type>
      <name>asArray</name>
      <anchorfile>classmlclient_1_1_i_document_node.html</anchorfile>
      <anchor>a0078fe4cae36802eb22a13b5276a71be</anchor>
      <arglist>() const  =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API IDocumentNode *</type>
      <name>asObject</name>
      <anchorfile>classmlclient_1_1_i_document_node.html</anchorfile>
      <anchor>aa32b77e614e167c8a754b9815a3b795e</anchor>
      <arglist>() const  =0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::ILexiconRef</name>
    <filename>classmlclient_1_1utilities_1_1_i_lexicon_ref.html</filename>
  </compound>
  <compound kind="class">
    <name>mlclient::InvalidFormatException</name>
    <filename>classmlclient_1_1_invalid_format_exception.html</filename>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::IQuery</name>
    <filename>classmlclient_1_1utilities_1_1_i_query.html</filename>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>IQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_i_query.html</anchorfile>
      <anchor>a07a93ef52666085735bdadd351954d55</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual MLCLIENT_API</type>
      <name>~IQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_i_query.html</anchorfile>
      <anchor>a71e7eb94cc99947bbcbf7163cf7ac189</anchor>
      <arglist>()=default</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::ITextDocumentContent</name>
    <filename>classmlclient_1_1_i_text_document_content.html</filename>
    <base>mlclient::IDocumentContent</base>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API void</type>
      <name>setContent</name>
      <anchorfile>classmlclient_1_1_i_text_document_content.html</anchorfile>
      <anchor>a57ef056274a3976bcf415f46a8d5d7a3</anchor>
      <arglist>(std::string content)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API int</type>
      <name>getLength</name>
      <anchorfile>classmlclient_1_1_i_text_document_content.html</anchorfile>
      <anchor>ace9cde97ae7c89b837fd243097494799</anchor>
      <arglist>() const  =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual MLCLIENT_API IDocumentNavigator *</type>
      <name>navigate</name>
      <anchorfile>classmlclient_1_1_i_text_document_content.html</anchorfile>
      <anchor>a1ef6ac941c24a4c608dbbf95d47ffd3f</anchor>
      <arglist>(bool firstElementAsRoot=false) const  =0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::ITypedValue</name>
    <filename>classmlclient_1_1utilities_1_1_i_typed_value.html</filename>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::JsonPropertyQuery</name>
    <filename>classmlclient_1_1utilities_1_1_json_property_query.html</filename>
    <base>mlclient::utilities::IQuery</base>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>JsonPropertyQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_json_property_query.html</anchorfile>
      <anchor>a3cf7b898ac971ef0b1c09b638a2fbad2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_json_property_query.html</anchorfile>
      <anchor>a962b0df5dd5b8eb28eaf1809a1239ed6</anchor>
      <arglist>(const std::string &amp;property, const std::string &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::string &amp;</type>
      <name>getQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_json_property_query.html</anchorfile>
      <anchor>af4ce9881b45ce2d58bc6c642f958c6bb</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::JsonPropertyRef</name>
    <filename>classmlclient_1_1utilities_1_1_json_property_ref.html</filename>
    <base>mlclient::utilities::IContainerRef</base>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setProperty</name>
      <anchorfile>classmlclient_1_1utilities_1_1_json_property_ref.html</anchorfile>
      <anchor>a39ee836ea1e1a1719ef8a306ad77d4fa</anchor>
      <arglist>(const std::string &amp;property)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::string</type>
      <name>getRef</name>
      <anchorfile>classmlclient_1_1utilities_1_1_json_property_ref.html</anchorfile>
      <anchor>a782178e477942ab19feb8490015fce01</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>mlclient::LoggingConfiguration</name>
    <filename>structmlclient_1_1_logging_configuration.html</filename>
    <member kind="variable">
      <type>std::string</type>
      <name>folder</name>
      <anchorfile>structmlclient_1_1_logging_configuration.html</anchorfile>
      <anchor>a37148601380a58492d80c06dbf452bee</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>std::string</type>
      <name>level</name>
      <anchorfile>structmlclient_1_1_logging_configuration.html</anchorfile>
      <anchor>a65722232a3227f30d6af31abf590a007</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>bool</type>
      <name>toerr</name>
      <anchorfile>structmlclient_1_1_logging_configuration.html</anchorfile>
      <anchor>ae75713ccc4f65707504a0818753d0202</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::internals::MLCrypto</name>
    <filename>classmlclient_1_1internals_1_1_m_l_crypto.html</filename>
    <member kind="function">
      <type></type>
      <name>MLCrypto</name>
      <anchorfile>classmlclient_1_1internals_1_1_m_l_crypto.html</anchorfile>
      <anchor>a6fef8a6eb60b68444b0b52b1bccb72a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>MLCrypto</name>
      <anchorfile>classmlclient_1_1internals_1_1_m_l_crypto.html</anchorfile>
      <anchor>a6149bbe955b9a203bb606c4b4cd3d0ae</anchor>
      <arglist>(const MLCrypto &amp;orig)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>md5</name>
      <anchorfile>classmlclient_1_1internals_1_1_m_l_crypto.html</anchorfile>
      <anchor>a473f2e32bf5bbd591b272036e4c0a679</anchor>
      <arglist>(const std::string &amp;raw) const </arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>toHex</name>
      <anchorfile>classmlclient_1_1internals_1_1_m_l_crypto.html</anchorfile>
      <anchor>a0eee8a9ec539a31e006224de232b3c6e</anchor>
      <arglist>(const uint8_t *bytes, const size_t &amp;length) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::NoCredentialsException</name>
    <filename>classmlclient_1_1_no_credentials_exception.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual MLCLIENT_API const char *</type>
      <name>what</name>
      <anchorfile>classmlclient_1_1_no_credentials_exception.html</anchorfile>
      <anchor>a06124d02b6081fada864ec346e7b5abc</anchor>
      <arglist>() const  override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::Permission</name>
    <filename>classmlclient_1_1_permission.html</filename>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>Permission</name>
      <anchorfile>classmlclient_1_1_permission.html</anchorfile>
      <anchor>a754906650a9d5f183a379998ce9f89c1</anchor>
      <arglist>(const std::string &amp;role, const Capability &amp;capability)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>Permission</name>
      <anchorfile>classmlclient_1_1_permission.html</anchorfile>
      <anchor>a4ca71baa4363bd8e174b214e0c0f0fb7</anchor>
      <arglist>(Permission &amp;&amp;other)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>Permission</name>
      <anchorfile>classmlclient_1_1_permission.html</anchorfile>
      <anchor>aa7f7e46c71c47d4709832501e1df861d</anchor>
      <arglist>(const Permission &amp;other)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual MLCLIENT_API</type>
      <name>~Permission</name>
      <anchorfile>classmlclient_1_1_permission.html</anchorfile>
      <anchor>a3e50870eefd956b8a87d1877d4191d4a</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API Permission &amp;</type>
      <name>operator=</name>
      <anchorfile>classmlclient_1_1_permission.html</anchorfile>
      <anchor>adac2345083216a76b41f252919ed42ad</anchor>
      <arglist>(const Permission &amp;other)=default</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::string &amp;</type>
      <name>getRole</name>
      <anchorfile>classmlclient_1_1_permission.html</anchorfile>
      <anchor>ad9fd39bd05f9c9a627fd2ac68fe76876</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setRole</name>
      <anchorfile>classmlclient_1_1_permission.html</anchorfile>
      <anchor>a67a20c7f085db3d6db5a0efdf0d6b0f6</anchor>
      <arglist>(const std::string &amp;role)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const Capability &amp;</type>
      <name>getCapability</name>
      <anchorfile>classmlclient_1_1_permission.html</anchorfile>
      <anchor>a4c4b0638f686bfac2cfbf5a1a9725301</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setCapability</name>
      <anchorfile>classmlclient_1_1_permission.html</anchorfile>
      <anchor>afe1e59c6dc650e8df4a36558cb96a8c7</anchor>
      <arglist>(const Capability &amp;capability)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>mlclient::utilities::Progress</name>
    <filename>structmlclient_1_1utilities_1_1_progress.html</filename>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::PugiXmlArrayNode</name>
    <filename>classmlclient_1_1utilities_1_1_pugi_xml_array_node.html</filename>
    <base>mlclient::utilities::PugiXmlContainerNode</base>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isArray</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_array_node.html</anchorfile>
      <anchor>ad3da8c371206bd770d3a9234c3b8624e</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isObject</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_array_node.html</anchorfile>
      <anchor>ac8054cdb1db4fb392865a86b6f88bcfc</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IDocumentNode *</type>
      <name>asArray</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_array_node.html</anchorfile>
      <anchor>a319f168665cabffe9d7a77f647b5f454</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IDocumentNode *</type>
      <name>asObject</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_array_node.html</anchorfile>
      <anchor>af3a4ea7c602529985184c389c4dab58b</anchor>
      <arglist>() const  override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::PugiXmlContainerNode</name>
    <filename>classmlclient_1_1utilities_1_1_pugi_xml_container_node.html</filename>
    <base>mlclient::IDocumentNode</base>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isNull</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_container_node.html</anchorfile>
      <anchor>adbeb7db591b56771f7a695083c8c204a</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isBoolean</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_container_node.html</anchorfile>
      <anchor>a329c6cf371f7e90e1af7d44df312bcda</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isInteger</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_container_node.html</anchorfile>
      <anchor>a1f0fe38b39b821009562c31368501ed6</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isDouble</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_container_node.html</anchorfile>
      <anchor>a02436edf16953b6aa5074c3ce897f96e</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isString</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_container_node.html</anchorfile>
      <anchor>a59cc8a6f7754b0fc98730c534925f306</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>asBoolean</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_container_node.html</anchorfile>
      <anchor>a33fa1759fc7a0c302b9b9191e3e5e263</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API int32_t</type>
      <name>asInteger</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_container_node.html</anchorfile>
      <anchor>a3871978b77a7be4fced82a2849fb66c6</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API double</type>
      <name>asDouble</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_container_node.html</anchorfile>
      <anchor>ac67b519c9034be8146078c3e249d3ed6</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::string</type>
      <name>asString</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_container_node.html</anchorfile>
      <anchor>a827887b045af241e0f97ebd66af1a109</anchor>
      <arglist>() const  override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::PugiXmlDocumentContent</name>
    <filename>classmlclient_1_1utilities_1_1_pugi_xml_document_content.html</filename>
    <base>mlclient::ITextDocumentContent</base>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>PugiXmlDocumentContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_content.html</anchorfile>
      <anchor>ad641903c8f3a67621fbe363eab509010</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual MLCLIENT_API</type>
      <name>~PugiXmlDocumentContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_content.html</anchorfile>
      <anchor>ac9276e0784d8abb43d739674ecc13973</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_content.html</anchorfile>
      <anchor>a05ef2301b69220d6e79f41821b98e7a2</anchor>
      <arglist>(const pugi::xml_document &amp;xml)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::istream *</type>
      <name>getStream</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_content.html</anchorfile>
      <anchor>a7da4aec7c217d56592351fad32ffba98</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_content.html</anchorfile>
      <anchor>a99031702fb28c9f2b6b6b843919fc91b</anchor>
      <arglist>(std::string content) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::string</type>
      <name>getContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_content.html</anchorfile>
      <anchor>a5abf50c29bf3514e092a24dcb7e83284</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::string</type>
      <name>getMimeType</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_content.html</anchorfile>
      <anchor>a695ed53c7ab7f41b7f6cc8e7503f169e</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setMimeType</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_content.html</anchorfile>
      <anchor>a3caef203d7f66f484878e09691f2ae73</anchor>
      <arglist>(const std::string &amp;mt) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API int</type>
      <name>getLength</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_content.html</anchorfile>
      <anchor>a6f4b7d0611b68cb03a69a407b83f1bd4</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IDocumentNavigator *</type>
      <name>navigate</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_content.html</anchorfile>
      <anchor>afde977f0237ff12a056af147bdd4741d</anchor>
      <arglist>(bool firstElementAsRoot=false) const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const pugi::xml_document &amp;</type>
      <name>getXml</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_content.html</anchorfile>
      <anchor>afdf9a9358c082af9364ee1b9f920a23c</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_content.html</anchorfile>
      <anchor>a05ef2301b69220d6e79f41821b98e7a2</anchor>
      <arglist>(const pugi::xml_document &amp;xml)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::istream *</type>
      <name>getStream</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_content.html</anchorfile>
      <anchor>a7da4aec7c217d56592351fad32ffba98</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_content.html</anchorfile>
      <anchor>a99031702fb28c9f2b6b6b843919fc91b</anchor>
      <arglist>(std::string content) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::string</type>
      <name>getContent</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_content.html</anchorfile>
      <anchor>a5abf50c29bf3514e092a24dcb7e83284</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::string</type>
      <name>getMimeType</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_content.html</anchorfile>
      <anchor>a695ed53c7ab7f41b7f6cc8e7503f169e</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setMimeType</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_content.html</anchorfile>
      <anchor>a3caef203d7f66f484878e09691f2ae73</anchor>
      <arglist>(const std::string &amp;mt) override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API int</type>
      <name>getLength</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_content.html</anchorfile>
      <anchor>a6f4b7d0611b68cb03a69a407b83f1bd4</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IDocumentNavigator *</type>
      <name>navigate</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_content.html</anchorfile>
      <anchor>afde977f0237ff12a056af147bdd4741d</anchor>
      <arglist>(bool firstElementAsRoot=false) const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const pugi::xml_document &amp;</type>
      <name>getXml</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_content.html</anchorfile>
      <anchor>afdf9a9358c082af9364ee1b9f920a23c</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::PugiXmlDocumentNavigator</name>
    <filename>classmlclient_1_1utilities_1_1_pugi_xml_document_navigator.html</filename>
    <base>mlclient::IDocumentNavigator</base>
    <member kind="function">
      <type></type>
      <name>PugiXmlDocumentNavigator</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_navigator.html</anchorfile>
      <anchor>a3cb94b21d23ab739196dabedec5f8496</anchor>
      <arglist>(const pugi::xml_document &amp;root, bool firstElementAsRoot=false)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>PugiXmlDocumentNavigator</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_navigator.html</anchorfile>
      <anchor>a64762951adabf6613f66610bc42b5edc</anchor>
      <arglist>(PugiXmlDocumentNavigator &amp;&amp;from)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~PugiXmlDocumentNavigator</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_navigator.html</anchorfile>
      <anchor>a26b36aa118f0ab31d5e0be9afdcca17d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IDocumentNode *</type>
      <name>at</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_navigator.html</anchorfile>
      <anchor>a7d42a449a603ae38bbef5c5cc4ad66db</anchor>
      <arglist>(const std::string &amp;key) const  override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::PugiXmlDocumentNode</name>
    <filename>classmlclient_1_1utilities_1_1_pugi_xml_document_node.html</filename>
    <base>mlclient::IDocumentNode</base>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isNull</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_node.html</anchorfile>
      <anchor>ae732bb747e43fce827d433da8b46d288</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isBoolean</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_node.html</anchorfile>
      <anchor>a2ba6e78fd2f60fda1fe31beecfc28d12</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isInteger</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_node.html</anchorfile>
      <anchor>ae61bd2dc72fa7923ac6bb0a973de49e9</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isDouble</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_node.html</anchorfile>
      <anchor>a9e7c1d8b0888efe9621baa475bdff850</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isString</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_node.html</anchorfile>
      <anchor>a60b8dca103334214a02422f79dd6d187</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isArray</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_node.html</anchorfile>
      <anchor>a9fd76aaf9a716e8bb41f392b215a147b</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isObject</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_node.html</anchorfile>
      <anchor>a2de66f8c5323ed0707eef748b7dc799b</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>asBoolean</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_node.html</anchorfile>
      <anchor>ad2087f3fcec0420f606b6acd457508a2</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API int32_t</type>
      <name>asInteger</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_node.html</anchorfile>
      <anchor>af4bac63d2486a48492c1e4114dc2e5de</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API double</type>
      <name>asDouble</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_node.html</anchorfile>
      <anchor>ab175f45c265bbd0959a5f9df04b620b9</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::string</type>
      <name>asString</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_node.html</anchorfile>
      <anchor>a1fe45f1a317a850e674977fa0886e63d</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IDocumentNode *</type>
      <name>asArray</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_node.html</anchorfile>
      <anchor>a19618711f795c5558718af1bb235cc6e</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IDocumentNode *</type>
      <name>asObject</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_document_node.html</anchorfile>
      <anchor>a2a0025f8e1f3e551a0b1cedf35de4cf6</anchor>
      <arglist>() const  override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::PugiXmlHelper</name>
    <filename>classmlclient_1_1utilities_1_1_pugi_xml_helper.html</filename>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API ITextDocumentContent *</type>
      <name>toDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_helper.html</anchorfile>
      <anchor>a391f98e93779b6547f18eb51e9ce113d</anchor>
      <arglist>(const pugi::xml_document &amp;dc)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API ITextDocumentContent *</type>
      <name>toDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_helper.html</anchorfile>
      <anchor>aa4a16f068df0e2a70deea2a26d7f7ab0</anchor>
      <arglist>(const std::string &amp;content)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API ITextDocumentContent *</type>
      <name>toDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_helper.html</anchorfile>
      <anchor>a7c312f1c24cbfcb8535415fa7d4df7c9</anchor>
      <arglist>(const Response &amp;resp)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API pugi::xml_document *</type>
      <name>fromDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_helper.html</anchorfile>
      <anchor>a56f82ee758de32df0738267c88c6807d</anchor>
      <arglist>(const IDocumentContent &amp;dc)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API pugi::xml_document *</type>
      <name>fromResponse</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_helper.html</anchorfile>
      <anchor>ac4a8f5fc27ce99de3f03c2fac9fbb05c</anchor>
      <arglist>(const Response &amp;resp)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::PugiXmlObjectNode</name>
    <filename>classmlclient_1_1utilities_1_1_pugi_xml_object_node.html</filename>
    <base>mlclient::utilities::PugiXmlContainerNode</base>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isArray</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_object_node.html</anchorfile>
      <anchor>a951e6ee73ba95a8d5c1581ed47bbf99d</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>isObject</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_object_node.html</anchorfile>
      <anchor>aa4731270ece7a4b419cd22ade1d99059</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IDocumentNode *</type>
      <name>asArray</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_object_node.html</anchorfile>
      <anchor>ac3492466c27d563da871551c6524751e</anchor>
      <arglist>() const  override</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IDocumentNode *</type>
      <name>asObject</name>
      <anchorfile>classmlclient_1_1utilities_1_1_pugi_xml_object_node.html</anchorfile>
      <anchor>a895384eee3b56de0ecb1308c6d4c7abe</anchor>
      <arglist>() const  override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::RangeLexiconRef</name>
    <filename>classmlclient_1_1utilities_1_1_range_lexicon_ref.html</filename>
    <base>mlclient::utilities::ILexiconRef</base>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::RangeOptions</name>
    <filename>classmlclient_1_1utilities_1_1_range_options.html</filename>
  </compound>
  <compound kind="class">
    <name>mlclient::Response</name>
    <filename>classmlclient_1_1_response.html</filename>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>Response</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>a6ea72bb39c0c88bb2f234926c4ba524f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setResponseCode</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>a81bc2f4f369eebf8ea60cdde461e4f6e</anchor>
      <arglist>(const ResponseCode &amp;code)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API ResponseType</type>
      <name>getResponseType</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>ad6c769c6dbdb18cfa6f163d734adb8b8</anchor>
      <arglist>(void) const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setResponseType</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>a8024beb81d778ea94c46ebf9630a0cf4</anchor>
      <arglist>(const ResponseType &amp;type)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setResponseHeaders</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>a9145483612c3ac5493fbbaa93b29f634</anchor>
      <arglist>(const mlclient::HttpHeaders &amp;headers)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API ResponseCode</type>
      <name>getResponseCode</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>a264b7f6e797621db31d60fcbbc831936</anchor>
      <arglist>(void) const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API mlclient::HttpHeaders</type>
      <name>getResponseHeaders</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>a3e02f69c6c6f4f83b093335d3275f895</anchor>
      <arglist>(void) const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API size_t</type>
      <name>read</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>a207a41f92e3a34e0c2b7c4f6265de606</anchor>
      <arglist>(void *buffer, const size_t &amp;max_size, const size_t off=0)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::string &amp;</type>
      <name>getContent</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>a91c2ff92401a46f128652df91db2db00</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setContent</name>
      <anchorfile>classmlclient_1_1_response.html</anchorfile>
      <anchor>a4b835b37ecf8b5334fd35074da6a6d0a</anchor>
      <arglist>(std::string *content)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::ResponseHelper</name>
    <filename>classmlclient_1_1utilities_1_1_response_helper.html</filename>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API bool</type>
      <name>isInError</name>
      <anchorfile>classmlclient_1_1utilities_1_1_response_helper.html</anchorfile>
      <anchor>a6305cc2920bbdcd2887a3daa7052bb9b</anchor>
      <arglist>(const Response &amp;resp)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API std::string</type>
      <name>getErrorMessage</name>
      <anchorfile>classmlclient_1_1utilities_1_1_response_helper.html</anchorfile>
      <anchor>a7c09012ef72575aa5e3a2545fef2f033</anchor>
      <arglist>(const Response &amp;resp)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API std::string</type>
      <name>getErrorDetailAsString</name>
      <anchorfile>classmlclient_1_1utilities_1_1_response_helper.html</anchorfile>
      <anchor>a678dfb388ac3a5ce1bdb2166f7c5f361</anchor>
      <arglist>(const Response &amp;resp)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API std::vector&lt; std::string &gt;</type>
      <name>getSuggestions</name>
      <anchorfile>classmlclient_1_1utilities_1_1_response_helper.html</anchorfile>
      <anchor>a3a43f85b5d3e899fe271f7b33947fad8</anchor>
      <arglist>(const Response &amp;resp)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API double</type>
      <name>getAggregateResult</name>
      <anchorfile>classmlclient_1_1utilities_1_1_response_helper.html</anchorfile>
      <anchor>a0e7bf585d6ed891e5ee6a03f28f6f555</anchor>
      <arglist>(const Response &amp;resp, const std::string &amp;aggName)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API void</type>
      <name>getAggregateResults</name>
      <anchorfile>classmlclient_1_1utilities_1_1_response_helper.html</anchorfile>
      <anchor>a85ba7cb07b7d3dd9620cc60c2a5472e8</anchor>
      <arglist>(const Response &amp;resp, ValuesResult &amp;vr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API void</type>
      <name>getComplexAggregateResults</name>
      <anchorfile>classmlclient_1_1utilities_1_1_response_helper.html</anchorfile>
      <anchor>a199042f7b809064f39e061af1a1ed956</anchor>
      <arglist>(const Response &amp;resp, ValuesResult &amp;vr)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::SearchBuilder</name>
    <filename>classmlclient_1_1utilities_1_1_search_builder.html</filename>
    <member kind="function">
      <type>MLCLIENT_API IQuery *</type>
      <name>valueQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a7ec359a8547ef19b6e8027c7225ba0b3</anchor>
      <arglist>(const std::string ref, const std::string value)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IQuery *</type>
      <name>jsonValueQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a8065a70250cc5b3be9222a9b3dc05d22</anchor>
      <arglist>(const std::string ref, const std::string value)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IQuery *</type>
      <name>xmlValueQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a6fdc8189d0e473098d5eb638c56482b2</anchor>
      <arglist>(const std::string ref, const std::string value)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IQuery *</type>
      <name>rangeQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a07e43f979ea76d2ae57078cf0048c47d</anchor>
      <arglist>(const std::string ref, const RangeOperation op, const std::string value)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IQuery *</type>
      <name>jsonRangeQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>af2c084321916768b99ca2fe6d1d6da6d</anchor>
      <arglist>(const std::string ref, const RangeOperation op, const std::string value)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IQuery *</type>
      <name>xmlRangeQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a8168dc586d51332f246c23dbc4667fe5</anchor>
      <arglist>(const std::string ref, const RangeOperation op, const std::string value)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API SearchBuilder *</type>
      <name>setQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a2195936ac6040944448997b1f21182ad</anchor>
      <arglist>(IQuery *query)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setDefaultXmlNamespace</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a288129ec5d37bafa022b784ebcc749c1</anchor>
      <arglist>(const std::string &amp;ns)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::string &amp;</type>
      <name>getDefaultXmlNamespace</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a0ec8340a21226482c0db913b5dbbd515</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setMode</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a27f051a1a6148aaf768fff58899806a2</anchor>
      <arglist>(const QueryBuilderMode mode)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const QueryBuilderMode</type>
      <name>getMode</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a35ca7e9cb851783b7fce205149051890</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API ITextDocumentContent *</type>
      <name>toDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>af7fa7983bef32e9a497f8112808b5ff2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API IQuery *</type>
      <name>collectionQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a0bc1cef68aa4df9a90f11c41e9326cc1</anchor>
      <arglist>(const CollectionSet &amp;collections)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API IQuery *</type>
      <name>documentQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a57e86a93c1505bbbd1cc45025e50b1a2</anchor>
      <arglist>(const DocumentUriSet &amp;uris)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API IQuery *</type>
      <name>andQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>aa594cddcc23dfe0c6b5953ba62a55349</anchor>
      <arglist>(const std::vector&lt; IQuery * &gt; &amp;queries)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API IQuery *</type>
      <name>orQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a05acd8b22c3f586e8e0323bb751b4322</anchor>
      <arglist>(const std::vector&lt; IQuery * &gt; &amp;queries)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API IQuery *</type>
      <name>notQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a6a936da35adb02af48a1f9ec68148855</anchor>
      <arglist>(const IQuery *query)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API IQuery *</type>
      <name>andQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>aa594cddcc23dfe0c6b5953ba62a55349</anchor>
      <arglist>(const std::vector&lt; IQuery * &gt; &amp;queries)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API IQuery *</type>
      <name>orQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a05acd8b22c3f586e8e0323bb751b4322</anchor>
      <arglist>(const std::vector&lt; IQuery * &gt; &amp;queries)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static MLCLIENT_API IQuery *</type>
      <name>notQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a6a936da35adb02af48a1f9ec68148855</anchor>
      <arglist>(const IQuery *query)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IQuery *</type>
      <name>valueQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a7ec359a8547ef19b6e8027c7225ba0b3</anchor>
      <arglist>(const std::string ref, const std::string value)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IQuery *</type>
      <name>jsonValueQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a8065a70250cc5b3be9222a9b3dc05d22</anchor>
      <arglist>(const std::string ref, const std::string value)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IQuery *</type>
      <name>xmlValueQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a6fdc8189d0e473098d5eb638c56482b2</anchor>
      <arglist>(const std::string ref, const std::string value)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IQuery *</type>
      <name>rangeQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a07e43f979ea76d2ae57078cf0048c47d</anchor>
      <arglist>(const std::string ref, const RangeOperation op, const std::string value)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IQuery *</type>
      <name>jsonRangeQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>af2c084321916768b99ca2fe6d1d6da6d</anchor>
      <arglist>(const std::string ref, const RangeOperation op, const std::string value)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API IQuery *</type>
      <name>xmlRangeQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a8168dc586d51332f246c23dbc4667fe5</anchor>
      <arglist>(const std::string ref, const RangeOperation op, const std::string value)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API SearchBuilder *</type>
      <name>setQuery</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a2195936ac6040944448997b1f21182ad</anchor>
      <arglist>(IQuery *query)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setDefaultXmlNamespace</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a288129ec5d37bafa022b784ebcc749c1</anchor>
      <arglist>(const std::string &amp;ns)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::string &amp;</type>
      <name>getDefaultXmlNamespace</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a0ec8340a21226482c0db913b5dbbd515</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setMode</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a27f051a1a6148aaf768fff58899806a2</anchor>
      <arglist>(const QueryBuilderMode mode)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const QueryBuilderMode</type>
      <name>getMode</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>a35ca7e9cb851783b7fce205149051890</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API ITextDocumentContent *</type>
      <name>toDocument</name>
      <anchorfile>classmlclient_1_1utilities_1_1_search_builder.html</anchorfile>
      <anchor>af7fa7983bef32e9a497f8112808b5ff2</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::SearchDescription</name>
    <filename>classmlclient_1_1_search_description.html</filename>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>SearchDescription</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>a55ec5723fa00676b91d698f736e0cb45</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual MLCLIENT_API</type>
      <name>~SearchDescription</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>a3a43087c5effa2f91fba5e797a85a7da</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setOptions</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>acca4ea00d660acddde2707291e1dbcb2</anchor>
      <arglist>(ITextDocumentContent &amp;options)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const ITextDocumentContent &amp;</type>
      <name>getOptions</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>acff2412c7a92378a861385cf434bffd2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setQuery</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>ad27551891b1563c932cb651c93a993bc</anchor>
      <arglist>(ITextDocumentContent &amp;query)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const ITextDocumentContent &amp;</type>
      <name>getQuery</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>a8cc43578e5dc06a83c6e224d02bb7a73</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setQueryText</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>a0c54a0531ec194759e9ce23f80208044</anchor>
      <arglist>(std::string qtext)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::string &amp;</type>
      <name>getQueryText</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>af06b69660d11acf49af090bd9c04024f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API ITextDocumentContent *</type>
      <name>getPayload</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>ad653610f93e940bd441790a94996dd01</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setStart</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>abd67bf61129c19275510f18cf02dca54</anchor>
      <arglist>(const long start)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const long</type>
      <name>getStart</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>a02593a1cf89db373a2aca1c46a0f6232</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setPageLength</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>a02717dbff9d85ea3be757d177e4a9122</anchor>
      <arglist>(const long pageLength)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const long</type>
      <name>getPageLength</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>a9dbac95a2fb3ae0f900e4d185c29dfbd</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setStart</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>abd67bf61129c19275510f18cf02dca54</anchor>
      <arglist>(const long start)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const long</type>
      <name>getStart</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>a02593a1cf89db373a2aca1c46a0f6232</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setPageLength</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>a02717dbff9d85ea3be757d177e4a9122</anchor>
      <arglist>(const long pageLength)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const long</type>
      <name>getPageLength</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>a9dbac95a2fb3ae0f900e4d185c29dfbd</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::SearchOptionsBuilder</name>
    <filename>classmlclient_1_1utilities_1_1_search_options_builder.html</filename>
  </compound>
  <compound kind="class">
    <name>mlclient::SearchResult</name>
    <filename>classmlclient_1_1_search_result.html</filename>
    <member kind="enumeration">
      <type></type>
      <name>Detail</name>
      <anchorfile>classmlclient_1_1_search_result.html</anchorfile>
      <anchor>a18992fa277c632e1142239ba6fef218d</anchor>
      <arglist></arglist>
      <enumvalue file="classmlclient_1_1_search_result.html" anchor="a18992fa277c632e1142239ba6fef218dab0a3a1162d9ebbf1cfc6e5d0d5fe475e">SNIPPETS</enumvalue>
      <enumvalue file="classmlclient_1_1_search_result.html" anchor="a18992fa277c632e1142239ba6fef218da45685e95985e20822fb2538a522a5ccf">CONTENT</enumvalue>
      <enumvalue file="classmlclient_1_1_search_result.html" anchor="a18992fa277c632e1142239ba6fef218dab50339a10e1de285ac99d4c3990b8693">NONE</enumvalue>
      <enumvalue file="classmlclient_1_1_search_result.html" anchor="a18992fa277c632e1142239ba6fef218da72baef04098f035e8a320b03ad197818">CUSTOM</enumvalue>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>SearchResult</name>
      <anchorfile>classmlclient_1_1_search_result.html</anchorfile>
      <anchor>a30cba8ff16a586b882658935f9b74c3a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>SearchResult</name>
      <anchorfile>classmlclient_1_1_search_result.html</anchorfile>
      <anchor>a3121856446d7d1a5cbd6c2da94c46eb3</anchor>
      <arglist>(const SearchResult &amp;other)=default</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>SearchResult</name>
      <anchorfile>classmlclient_1_1_search_result.html</anchorfile>
      <anchor>a0ce0da6985adba542967cf3c2a783701</anchor>
      <arglist>(SearchResult &amp;&amp;other)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API SearchResult &amp;</type>
      <name>operator=</name>
      <anchorfile>classmlclient_1_1_search_result.html</anchorfile>
      <anchor>a72fde9d4cbe40236f60b7bdb329825ae</anchor>
      <arglist>(SearchResult &amp;&amp;other)</arglist>
    </member>
    <member kind="function">
      <type>SearchResult &amp;</type>
      <name>operator=</name>
      <anchorfile>classmlclient_1_1_search_result.html</anchorfile>
      <anchor>a22c34b576940349f73c8ca8dafedfc94</anchor>
      <arglist>(const SearchResult &amp;&amp;other)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>~SearchResult</name>
      <anchorfile>classmlclient_1_1_search_result.html</anchorfile>
      <anchor>a927167d127eab774e4363f2aa050604d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>SearchResult</name>
      <anchorfile>classmlclient_1_1_search_result.html</anchorfile>
      <anchor>a74a8fe5fd29d3d5238fd29f9c393b936</anchor>
      <arglist>(const long index, const std::string &amp;uri, const std::string &amp;path, const long score, const double confidence, const double fitness, const Detail &amp;detail, IDocumentContent *detailContent=nullptr, const std::string &amp;mimeType=&quot;&quot;, const Format &amp;format=Format::JSON)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API long</type>
      <name>getIndex</name>
      <anchorfile>classmlclient_1_1_search_result.html</anchorfile>
      <anchor>adc0c5e629df4e206ceabb538a3979ff9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::string &amp;</type>
      <name>getUri</name>
      <anchorfile>classmlclient_1_1_search_result.html</anchorfile>
      <anchor>a30ae98e12b248736712e2d48572c798f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::string &amp;</type>
      <name>getPath</name>
      <anchorfile>classmlclient_1_1_search_result.html</anchorfile>
      <anchor>a0ebf1d550c960dbc6f137d5ed5031784</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API long</type>
      <name>getScore</name>
      <anchorfile>classmlclient_1_1_search_result.html</anchorfile>
      <anchor>a3dbc1526ca5fd2d8248dd5ec844c6d22</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API double</type>
      <name>getConfidence</name>
      <anchorfile>classmlclient_1_1_search_result.html</anchorfile>
      <anchor>a96bf390fc898a6a97060dddc52a20148</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API double</type>
      <name>getFitness</name>
      <anchorfile>classmlclient_1_1_search_result.html</anchorfile>
      <anchor>a1ab3f60f0df03b34ad3c01add9d1cde5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const Detail &amp;</type>
      <name>getDetail</name>
      <anchorfile>classmlclient_1_1_search_result.html</anchorfile>
      <anchor>af2012b159131a608076b796bc3eed4c7</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const IDocumentContent *</type>
      <name>getDetailContent</name>
      <anchorfile>classmlclient_1_1_search_result.html</anchorfile>
      <anchor>a8e389e27a51fbdf0df8288add372e6b7</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::string &amp;</type>
      <name>getMimeType</name>
      <anchorfile>classmlclient_1_1_search_result.html</anchorfile>
      <anchor>a6a00d3819ddbbf601dd4e850dda046a4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const Format &amp;</type>
      <name>getFormat</name>
      <anchorfile>classmlclient_1_1_search_result.html</anchorfile>
      <anchor>a84d918ced60244cd876fc351ca0b69f5</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::SearchResultSet</name>
    <filename>classmlclient_1_1_search_result_set.html</filename>
    <member kind="typedef">
      <type>SearchResultSetIterator</type>
      <name>const_iterator</name>
      <anchorfile>classmlclient_1_1_search_result_set.html</anchorfile>
      <anchor>aa3e88d6827ec33a932c24e25f0377732</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>SearchResultSet</name>
      <anchorfile>classmlclient_1_1_search_result_set.html</anchorfile>
      <anchor>a4d52dbdce25bc9c4a9cef17ebfb3e185</anchor>
      <arglist>(IConnection *conn, SearchDescription *desc)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual MLCLIENT_API</type>
      <name>~SearchResultSet</name>
      <anchorfile>classmlclient_1_1_search_result_set.html</anchorfile>
      <anchor>a4295ab621db4abdaf16eb860c6d10b24</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API SearchResultSetIterator *</type>
      <name>begin</name>
      <anchorfile>classmlclient_1_1_search_result_set.html</anchorfile>
      <anchor>a77c6a328b91846c6a2d7a81ee16f52a6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API SearchResultSetIterator *</type>
      <name>end</name>
      <anchorfile>classmlclient_1_1_search_result_set.html</anchorfile>
      <anchor>a94e37fc00f7357d3bf8f3e7a68c46671</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>fetch</name>
      <anchorfile>classmlclient_1_1_search_result_set.html</anchorfile>
      <anchor>ac4755a7f44f075ce047020ac5765ecf1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::exception *</type>
      <name>getFetchException</name>
      <anchorfile>classmlclient_1_1_search_result_set.html</anchorfile>
      <anchor>a4be482fcac51b47580039e299a11cdc0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const long</type>
      <name>getStart</name>
      <anchorfile>classmlclient_1_1_search_result_set.html</anchorfile>
      <anchor>a5090e48e72828ad5eefa41f35a136b3f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const long</type>
      <name>getTotal</name>
      <anchorfile>classmlclient_1_1_search_result_set.html</anchorfile>
      <anchor>a0344ba483d11c5f12fd484a217e0212c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const long</type>
      <name>getPageLength</name>
      <anchorfile>classmlclient_1_1_search_result_set.html</anchorfile>
      <anchor>a6bd96eb10a11af13de8fd1d6d2a2ee4e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::string &amp;</type>
      <name>getSnippetFormat</name>
      <anchorfile>classmlclient_1_1_search_result_set.html</anchorfile>
      <anchor>a7a1a325ca168b95074343395611746ac</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::string &amp;</type>
      <name>getQueryResolutionTime</name>
      <anchorfile>classmlclient_1_1_search_result_set.html</anchorfile>
      <anchor>a2991c99518ebbcde43853f6d75bb9f3d</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::string &amp;</type>
      <name>getSnippetResolutionTime</name>
      <anchorfile>classmlclient_1_1_search_result_set.html</anchorfile>
      <anchor>a1be44365f9afbfcefe4a0ac5d9346189</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::string &amp;</type>
      <name>getTotalTime</name>
      <anchorfile>classmlclient_1_1_search_result_set.html</anchorfile>
      <anchor>a53da644eb5938bb16495bab350e6d057</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const long</type>
      <name>getPageCount</name>
      <anchorfile>classmlclient_1_1_search_result_set.html</anchorfile>
      <anchor>adea67ea687ba7dfc1ebc74937221ad89</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setMaxResults</name>
      <anchorfile>classmlclient_1_1_search_result_set.html</anchorfile>
      <anchor>a704789e3237ea8a068a40febbc8e0421</anchor>
      <arglist>(long maxResults)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::SearchResultSetIterator</name>
    <filename>classmlclient_1_1_search_result_set_iterator.html</filename>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>SearchResultSetIterator</name>
      <anchorfile>classmlclient_1_1_search_result_set_iterator.html</anchorfile>
      <anchor>abcf0267287f83bfde4b610885a83ae51</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>SearchResultSetIterator</name>
      <anchorfile>classmlclient_1_1_search_result_set_iterator.html</anchorfile>
      <anchor>a0a71f2ea20202d95d0964634cedda601</anchor>
      <arglist>(SearchResultSet *set)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>SearchResultSetIterator</name>
      <anchorfile>classmlclient_1_1_search_result_set_iterator.html</anchorfile>
      <anchor>a6d0801a01fd256b6570c234e5b10d540</anchor>
      <arglist>(SearchResultSet *set, long pos)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API SearchResultSetIterator *</type>
      <name>begin</name>
      <anchorfile>classmlclient_1_1_search_result_set_iterator.html</anchorfile>
      <anchor>ac4c46b2bb3eb9a6075bd9946edc787e2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API SearchResultSetIterator *</type>
      <name>end</name>
      <anchorfile>classmlclient_1_1_search_result_set_iterator.html</anchorfile>
      <anchor>a0037912084e2ff6a87f16862d51d3bf6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>operator==</name>
      <anchorfile>classmlclient_1_1_search_result_set_iterator.html</anchorfile>
      <anchor>af78924af61605029d9d401004efd84cd</anchor>
      <arglist>(const SearchResultSetIterator &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>operator!=</name>
      <anchorfile>classmlclient_1_1_search_result_set_iterator.html</anchorfile>
      <anchor>a26967582e30901d3337425e9ad47f3f4</anchor>
      <arglist>(const SearchResultSetIterator &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>operator++</name>
      <anchorfile>classmlclient_1_1_search_result_set_iterator.html</anchorfile>
      <anchor>ac48e6090ce7de45c5bfa9037f0367cb0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const SearchResult</type>
      <name>operator*</name>
      <anchorfile>classmlclient_1_1_search_result_set_iterator.html</anchorfile>
      <anchor>ad39e16ac3c1b7fcf3876834b6fa68ab8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API SearchResultSetIterator</type>
      <name>operator=</name>
      <anchorfile>classmlclient_1_1_search_result_set_iterator.html</anchorfile>
      <anchor>a433f54d0122c6533248e9ff43e49aa02</anchor>
      <arglist>(const SearchResultSetIterator &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const SearchResult &amp;</type>
      <name>first</name>
      <anchorfile>classmlclient_1_1_search_result_set_iterator.html</anchorfile>
      <anchor>aac68a240578a6555a8caf146bd6897cb</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::utilities::ValuesInfo</name>
    <filename>classmlclient_1_1utilities_1_1_values_info.html</filename>
  </compound>
  <compound kind="class">
    <name>mlclient::ValuesIterator</name>
    <filename>classmlclient_1_1_values_iterator.html</filename>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>ValuesIterator</name>
      <anchorfile>classmlclient_1_1_values_iterator.html</anchorfile>
      <anchor>a573e06551c203d7411e159e840c0f29c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>ValuesIterator</name>
      <anchorfile>classmlclient_1_1_values_iterator.html</anchorfile>
      <anchor>abce950a0552db7dbb5c100f92be94ed2</anchor>
      <arglist>(ValuesResultSet *set)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>ValuesIterator</name>
      <anchorfile>classmlclient_1_1_values_iterator.html</anchorfile>
      <anchor>a775ae979bc4588c8fda6ed35f29967de</anchor>
      <arglist>(ValuesResultSet *set, long pos)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API ValuesIterator *</type>
      <name>begin</name>
      <anchorfile>classmlclient_1_1_values_iterator.html</anchorfile>
      <anchor>a6286a0665aa9e122bafd5aae81f94517</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API ValuesIterator *</type>
      <name>end</name>
      <anchorfile>classmlclient_1_1_values_iterator.html</anchorfile>
      <anchor>a15be608a572742eff593a40469637039</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>operator==</name>
      <anchorfile>classmlclient_1_1_values_iterator.html</anchorfile>
      <anchor>ad6b820ef645ad4e8628f6a4c75275df2</anchor>
      <arglist>(const ValuesIterator &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>operator!=</name>
      <anchorfile>classmlclient_1_1_values_iterator.html</anchorfile>
      <anchor>a5b6e158536d875d5e6dee9e8ab8805b5</anchor>
      <arglist>(const ValuesIterator &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>operator++</name>
      <anchorfile>classmlclient_1_1_values_iterator.html</anchorfile>
      <anchor>a4b3f93d4188c12cb21a5a71eecfbea9f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const ValuesResult</type>
      <name>operator*</name>
      <anchorfile>classmlclient_1_1_values_iterator.html</anchorfile>
      <anchor>a21d92281d8cafb5131646e378cadac78</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API ValuesIterator</type>
      <name>operator=</name>
      <anchorfile>classmlclient_1_1_values_iterator.html</anchorfile>
      <anchor>a5bfc2d762b0bbdb2498a9d1cbaa0702d</anchor>
      <arglist>(const ValuesIterator &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const ValuesResult &amp;</type>
      <name>first</name>
      <anchorfile>classmlclient_1_1_values_iterator.html</anchorfile>
      <anchor>ad63037072bd73b896ee724468f51303f</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>mlclient::ValuesResult</name>
    <filename>classmlclient_1_1_values_result.html</filename>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>ValuesResult</name>
      <anchorfile>classmlclient_1_1_values_result.html</anchorfile>
      <anchor>aef6e8dcbaa2190a0d6fe2407024259e8</anchor>
      <arglist>(const std::string &amp;optionsName, const std::string &amp;valuesName)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>ValuesResult</name>
      <anchorfile>classmlclient_1_1_values_result.html</anchorfile>
      <anchor>a7975dcf5564a2bf8ff9457b7d9cc2e39</anchor>
      <arglist>(ValuesResult &amp;&amp;other)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>ValuesResult</name>
      <anchorfile>classmlclient_1_1_values_result.html</anchorfile>
      <anchor>a645ce88c493462dbe6982633eb4b862c</anchor>
      <arglist>(const ValuesResult &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>~ValuesResult</name>
      <anchorfile>classmlclient_1_1_values_result.html</anchorfile>
      <anchor>a14fd2d9d7edfc92d9996889c9f27db3d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>addValue</name>
      <anchorfile>classmlclient_1_1_values_result.html</anchorfile>
      <anchor>a7cd214c4d9a1654343cee4be56929fa4</anchor>
      <arglist>(const ValuesResultValue &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::vector&lt; ValuesResultValue &gt;</type>
      <name>getValues</name>
      <anchorfile>classmlclient_1_1_values_result.html</anchorfile>
      <anchor>a7a627ddc17685169aee2c49c008ee8ba</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>addAggregate</name>
      <anchorfile>classmlclient_1_1_values_result.html</anchorfile>
      <anchor>a324c56b154343280190acee95a38ee28</anchor>
      <arglist>(const ValuesResultAggregate &amp;aggregate)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const bool</type>
      <name>hasAggregates</name>
      <anchorfile>classmlclient_1_1_values_result.html</anchorfile>
      <anchor>a89a0d3756c6be500926c1a4cc96c346f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const long</type>
      <name>getAggregateCount</name>
      <anchorfile>classmlclient_1_1_values_result.html</anchorfile>
      <anchor>a353b456a580264eebc8411eaf8a414af</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::vector&lt; ValuesResultAggregate &gt;::const_iterator</type>
      <name>aggregateBegin</name>
      <anchorfile>classmlclient_1_1_values_result.html</anchorfile>
      <anchor>aebf7be0a41de54e62eccf92d02259aaa</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::vector&lt; ValuesResultAggregate &gt;::const_iterator</type>
      <name>aggregateEnd</name>
      <anchorfile>classmlclient_1_1_values_result.html</anchorfile>
      <anchor>aa6c50dadb3c6a104f8edf15c093c9a92</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setTimes</name>
      <anchorfile>classmlclient_1_1_values_result.html</anchorfile>
      <anchor>ade2c6bd3a08e8091d43caded34ef8ae7</anchor>
      <arglist>(const std::string &amp;valuesResolutionTime, const std::string &amp;aggregateResolutionTime, const std::string &amp;totalTime)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>setType</name>
      <anchorfile>classmlclient_1_1_values_result.html</anchorfile>
      <anchor>a1007ef38c889d82162ba7bddeff9c131</anchor>
      <arglist>(const mlclient::utilities::RangeIndexType &amp;type)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const mlclient::utilities::RangeIndexType &amp;</type>
      <name>getType</name>
      <anchorfile>classmlclient_1_1_values_result.html</anchorfile>
      <anchor>ae38c4cc2e82335e4348574dfe18382dc</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const long</type>
      <name>getStart</name>
      <anchorfile>classmlclient_1_1_values_result.html</anchorfile>
      <anchor>a23d353018796d87698a69f0026b50b7c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const long</type>
      <name>getTotal</name>
      <anchorfile>classmlclient_1_1_values_result.html</anchorfile>
      <anchor>a5d83f384da78454c0082b8c92e07b3cd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::string &amp;</type>
      <name>getValuesResolutionTime</name>
      <anchorfile>classmlclient_1_1_values_result.html</anchorfile>
      <anchor>a08431ea21e2402ff3efccabb4d1657c1</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::string &amp;</type>
      <name>getAggregateResolutionTime</name>
      <anchorfile>classmlclient_1_1_values_result.html</anchorfile>
      <anchor>a1bcf6021e6ed521888625289e4c82db9</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::string &amp;</type>
      <name>getTotalTime</name>
      <anchorfile>classmlclient_1_1_values_result.html</anchorfile>
      <anchor>a54a9b2c31d6cd3aed33403d030b5344c</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::string &amp;</type>
      <name>getOptionsName</name>
      <anchorfile>classmlclient_1_1_values_result.html</anchorfile>
      <anchor>a81573740bb31db4e9337cd96750f240a</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const std::string &amp;</type>
      <name>getValuesName</name>
      <anchorfile>classmlclient_1_1_values_result.html</anchorfile>
      <anchor>a56b09c4ad6eb36f446ca9eef29dbcfc8</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>mlclient::ValuesResultAggregate</name>
    <filename>structmlclient_1_1_values_result_aggregate.html</filename>
  </compound>
  <compound kind="class">
    <name>mlclient::ValuesResultSet</name>
    <filename>classmlclient_1_1_values_result_set.html</filename>
    <member kind="typedef">
      <type>ValuesIterator</type>
      <name>const_iterator</name>
      <anchorfile>classmlclient_1_1_values_result_set.html</anchorfile>
      <anchor>ab3001b468d8b96bafcf67978a89faa2d</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>ValuesResultSet</name>
      <anchorfile>classmlclient_1_1_values_result_set.html</anchorfile>
      <anchor>a4c5d2323b4e92698f699fdd6053c0333</anchor>
      <arglist>(IConnection *conn)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API</type>
      <name>ValuesResultSet</name>
      <anchorfile>classmlclient_1_1_values_result_set.html</anchorfile>
      <anchor>aa67bbf1e00680120f23a3f6a4d9630e6</anchor>
      <arglist>(const ValuesResultSet &amp;other)=delete</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>addLookup</name>
      <anchorfile>classmlclient_1_1_values_result_set.html</anchorfile>
      <anchor>a9a82a7b36617615c0cc99651fc042742</anchor>
      <arglist>(const std::string &amp;optionsName, const std::string &amp;valuesName)</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API const long</type>
      <name>getTotal</name>
      <anchorfile>classmlclient_1_1_values_result_set.html</anchorfile>
      <anchor>ae5050c64adb345dd1558c3cd947ecd0e</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API ValuesIterator *</type>
      <name>begin</name>
      <anchorfile>classmlclient_1_1_values_result_set.html</anchorfile>
      <anchor>a0f9c524b8c269a460812ab82cc70638d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API ValuesIterator *</type>
      <name>end</name>
      <anchorfile>classmlclient_1_1_values_result_set.html</anchorfile>
      <anchor>abc52a076de66c95e6f3c20883f6e8c2a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API bool</type>
      <name>fetch</name>
      <anchorfile>classmlclient_1_1_values_result_set.html</anchorfile>
      <anchor>a100125a6be4cf105b5675cc7189a5539</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API std::exception *</type>
      <name>getFetchException</name>
      <anchorfile>classmlclient_1_1_values_result_set.html</anchorfile>
      <anchor>ae35d67074d03c5f963d99f5ca23b83a4</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>mlclient::ValuesResultValue</name>
    <filename>structmlclient_1_1_values_result_value.html</filename>
  </compound>
  <compound kind="class">
    <name>pugi::xml_attribute</name>
    <filename>classpugi_1_1xml__attribute.html</filename>
  </compound>
  <compound kind="class">
    <name>pugi::xml_attribute_iterator</name>
    <filename>classpugi_1_1xml__attribute__iterator.html</filename>
  </compound>
  <compound kind="class">
    <name>pugi::xml_document</name>
    <filename>classpugi_1_1xml__document.html</filename>
    <base>pugi::xml_node</base>
  </compound>
  <compound kind="class">
    <name>pugi::xml_named_node_iterator</name>
    <filename>classpugi_1_1xml__named__node__iterator.html</filename>
  </compound>
  <compound kind="class">
    <name>pugi::xml_node</name>
    <filename>classpugi_1_1xml__node.html</filename>
  </compound>
  <compound kind="class">
    <name>pugi::xml_node_iterator</name>
    <filename>classpugi_1_1xml__node__iterator.html</filename>
  </compound>
  <compound kind="class">
    <name>pugi::xml_object_range</name>
    <filename>classpugi_1_1xml__object__range.html</filename>
    <templarg>It</templarg>
  </compound>
  <compound kind="struct">
    <name>pugi::xml_parse_result</name>
    <filename>structpugi_1_1xml__parse__result.html</filename>
  </compound>
  <compound kind="class">
    <name>pugi::xml_text</name>
    <filename>classpugi_1_1xml__text.html</filename>
  </compound>
  <compound kind="class">
    <name>pugi::xml_tree_walker</name>
    <filename>classpugi_1_1xml__tree__walker.html</filename>
  </compound>
  <compound kind="class">
    <name>pugi::xml_writer</name>
    <filename>classpugi_1_1xml__writer.html</filename>
  </compound>
  <compound kind="class">
    <name>pugi::xml_writer_file</name>
    <filename>classpugi_1_1xml__writer__file.html</filename>
    <base>pugi::xml_writer</base>
  </compound>
  <compound kind="class">
    <name>pugi::xml_writer_stream</name>
    <filename>classpugi_1_1xml__writer__stream.html</filename>
    <base>pugi::xml_writer</base>
  </compound>
  <compound kind="class">
    <name>pugi::xpath_exception</name>
    <filename>classpugi_1_1xpath__exception.html</filename>
  </compound>
  <compound kind="class">
    <name>pugi::xpath_node</name>
    <filename>classpugi_1_1xpath__node.html</filename>
  </compound>
  <compound kind="class">
    <name>pugi::xpath_node_set</name>
    <filename>classpugi_1_1xpath__node__set.html</filename>
  </compound>
  <compound kind="struct">
    <name>pugi::xpath_parse_result</name>
    <filename>structpugi_1_1xpath__parse__result.html</filename>
  </compound>
  <compound kind="class">
    <name>pugi::xpath_query</name>
    <filename>classpugi_1_1xpath__query.html</filename>
  </compound>
  <compound kind="class">
    <name>pugi::xpath_variable</name>
    <filename>classpugi_1_1xpath__variable.html</filename>
  </compound>
  <compound kind="class">
    <name>pugi::xpath_variable_set</name>
    <filename>classpugi_1_1xpath__variable__set.html</filename>
  </compound>
  <compound kind="namespace">
    <name>mlclient</name>
    <filename>namespacemlclient.html</filename>
    <namespace>mlclient::utilities</namespace>
    <class kind="class">mlclient::Connection</class>
    <class kind="class">mlclient::Document</class>
    <class kind="class">mlclient::FileDocumentContent</class>
    <class kind="class">mlclient::GenericTextDocumentContent</class>
    <class kind="class">mlclient::HttpHeaders</class>
    <class kind="class">mlclient::IConnection</class>
    <class kind="class">mlclient::IDocumentContent</class>
    <class kind="class">mlclient::IDocumentNavigator</class>
    <class kind="class">mlclient::IDocumentNode</class>
    <class kind="class">mlclient::InvalidFormatException</class>
    <class kind="class">mlclient::ITextDocumentContent</class>
    <class kind="struct">mlclient::LoggingConfiguration</class>
    <class kind="class">mlclient::NoCredentialsException</class>
    <class kind="class">mlclient::Permission</class>
    <class kind="class">mlclient::Response</class>
    <class kind="class">mlclient::SearchDescription</class>
    <class kind="class">mlclient::SearchResult</class>
    <class kind="class">mlclient::SearchResultSet</class>
    <class kind="class">mlclient::SearchResultSetIterator</class>
    <class kind="class">mlclient::ValuesIterator</class>
    <class kind="class">mlclient::ValuesResult</class>
    <class kind="struct">mlclient::ValuesResultAggregate</class>
    <class kind="class">mlclient::ValuesResultSet</class>
    <class kind="struct">mlclient::ValuesResultValue</class>
    <member kind="typedef">
      <type>std::string</type>
      <name>Collection</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>ac2ae986929fdfa3b03a266f2c3ddc05c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; Collection &gt;</type>
      <name>CollectionSet</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>a8d44f4574f9bf24e002c154f15c54823</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; Collection &gt;::const_iterator</type>
      <name>CollectionIterator</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>a89399a3138a28498a6a3fd5055e02952</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::string</type>
      <name>DocumentUri</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>a37b55d6a2233d1274c1bc9905de10405</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; DocumentUri &gt;</type>
      <name>DocumentUriSet</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>adf9f3b438c3c8122814026276fd65ba8</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; DocumentUri &gt;::const_iterator</type>
      <name>DocumentUriIterator</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>acab87e5d51d7bb0f4ea78e7a85f22535</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; Document &gt;</type>
      <name>DocumentSet</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>ab61bc9af3d081c084f28073c63fdbda1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; Document &gt;::const_iterator</type>
      <name>DocumentIterator</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>af4bcdd3248b070cb3faca6f86186ec1d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; Permission &gt;</type>
      <name>PermissionSet</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>a28b8105838290b93ae00557c06f44fe1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; Permission &gt;::const_iterator</type>
      <name>PermissionIterator</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>ad92744b2c9466b61fca54f060b5cd655</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>BinaryEncoding</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>ad47ff6baab050e78452eb2167a2a3b54</anchor>
      <arglist></arglist>
      <enumvalue file="namespacemlclient.html" anchor="ad47ff6baab050e78452eb2167a2a3b54a58c9566f3c750ce7147b045fdd14202b">HEX</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ad47ff6baab050e78452eb2167a2a3b54a35d3245a21b0942070419ef6602d239e">BIN</enumvalue>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>Capability</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>a18194d1f28de36ba0ea9ead9063efa7c</anchor>
      <arglist></arglist>
      <enumvalue file="namespacemlclient.html" anchor="a18194d1f28de36ba0ea9ead9063efa7ca5d76688e2261e6805ee36ad961b3fa7a">EXECUTE</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="a18194d1f28de36ba0ea9ead9063efa7ca61ee777e7f71dc466c3b2c685d8d313b">INSERT</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="a18194d1f28de36ba0ea9ead9063efa7ca3466fab4975481651940ed328aa990e4">READ</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="a18194d1f28de36ba0ea9ead9063efa7ca15a8022d0ed9cd9c2a2e756822703eb4">UPDATE</enumvalue>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>ResponseType</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>aff058411252d0c404caf56d2d0b65090</anchor>
      <arglist></arglist>
      <enumvalue file="namespacemlclient.html" anchor="aff058411252d0c404caf56d2d0b65090a7280a7d8974164a48d863dee5e341f27">UNKNOWN_TYPE</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="aff058411252d0c404caf56d2d0b65090a3501bb093d363810b671059b9cfed3f8">XML</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="aff058411252d0c404caf56d2d0b65090a0ecd11c1d7a287401d148a23bbd7a2f8">JSON</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="aff058411252d0c404caf56d2d0b65090a61a96ffcb251bb9bf0abf8fec19d0ea8">TEXT</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="aff058411252d0c404caf56d2d0b65090a98ad0e8750ae10ad556ed7a62affb452">BINARY</enumvalue>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>ResponseCode</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>ac8a0790b90fd9b1df837c9476659fb23</anchor>
      <arglist></arglist>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a72d8beb0e5785711f1659e6d4db90b9f">UNKNOWN_CODE</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a2f453cfe638e57e27bb0c9512436111e">CONTINUE</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23ae0aa021e21dddbd6d8cecec71e9cf564">OK</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a98690bf632c29c17c9e4c5a64069903c">CREATED</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23aa806f1d2c42338ef5fa6497b66153e79">ACCEPTED</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23af84f5b7a440bd2021a9049dd8cf8d13e">NO_CONTENT</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a674c0a5a76a51ee504b65421e29b5126">RESET_CONTENT</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23ad906a5a1be7a9fc5d8546e34d1608a1e">PARTIAL_CONTENT</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23acfcb28ddf47c74db504f5432a7c1cb69">MULTIPLE_CHOICES</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23abbe3b000d07140412431bb07d043c287">MOVED_PERMANENTLY</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a3e918e9c9f594bda6b0cf358391c3b1a">FOUND</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a4093e2ac3e1287ac13d1d0ca3317b503">SEE_OTHER</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23aa6809b1b35a6debe4edc98fc79a02944">NOT_MODIFIED</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23aa48862350ffe6149a62081634a725e94">USE_PROXY</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a698dcee850e80b3dfc04ad8b5dcedd3a">TEMPORARY_REDIRECT</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a0bbffe9eb8bbfc49246e867fccaefb73">BAD_REQUEST</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a0ab06e7c28266cc1ed601325013a874c">UNAUTHORIZED</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a6713760be5f3d289ab8f42e837c126de">PAYMENT_REQUIRED</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a4a76a6ecac6e4077588fd966db329fa3">FORBIDDEN</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a8c02547a8a3b02382bac3557bcb2280d">NOT_FOUND</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a109f8ca7d4aeb39feec752e24fac4098">METHOD_NOT_ALLOWED</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a9846b1a1c52dfc91442151cd7f3fd4e7">NOT_ACCEPTABLE</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a0cf3ee42fff927594af686698d09e863">PROXY_AUTHENTICATION_REQUIRED</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23ac8ab880d2064ef632e61f01c05cd0b66">REQUEST_TIMEOUT</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23addbe277f267f119df2ef18a8fe3364ae">CONFLICT</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a9c745ef7d5f5c7618ce90dbec9a62b74">GONE</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23aef31f194fc00edd0b1986110a13a13f9">LENGTH_REQUIRED</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a8e4ccfab0ccae403001d7ac710307c31">PRECONDITION_FAILED</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a2748ee1c8148e5b3dda5390944e9e99e">REQUEST_ENTITY_TOO_LARGE</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a283bca27273ad6070f767f05b3b399e5">REQUEST_URI_TOO_LONG</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23ac8def42f5dfe44bd1ea86a055fb1b5a6">UNSUPPORTED_MEDIA_TYPE</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23ab785d7c0379a3b49f42b519dc740a1f1">REQUEST_RANGE_BAD</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a0dd5a8948b360d099aaffe504790bcfb">EXPECTATION_FAILED</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a45d9cc15c3d3229e11b4c33387598850">INTERNAL_SERVER_ERROR</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a3e860a081575fc82cc7b6ed2ca602947">NOT_IMPLEMENTED</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a2a685d68f06ec03e4b658cc0d6ca4e54">BAD_GATEWAY</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a321504743197244f08c01a4fd2df88b5">SERVICE_UNAVAILABLE</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23a2210ac0628249cd94f48da970567a831">GATEWAY_TIMEOUT</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ac8a0790b90fd9b1df837c9476659fb23aede7ad622f9c071f0cf49c5e3fd8877b">HTTP_VERSION_NOT_SUPPORTED</enumvalue>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>Format</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>ab1cd81178c7ab61a41b52c2d93e7d5e4</anchor>
      <arglist></arglist>
      <enumvalue file="namespacemlclient.html" anchor="ab1cd81178c7ab61a41b52c2d93e7d5e4a0ecd11c1d7a287401d148a23bbd7a2f8">JSON</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ab1cd81178c7ab61a41b52c2d93e7d5e4a3501bb093d363810b671059b9cfed3f8">XML</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ab1cd81178c7ab61a41b52c2d93e7d5e4a98ad0e8750ae10ad556ed7a62affb452">BINARY</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ab1cd81178c7ab61a41b52c2d93e7d5e4ab50339a10e1de285ac99d4c3990b8693">NONE</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="ab1cd81178c7ab61a41b52c2d93e7d5e4a61a96ffcb251bb9bf0abf8fec19d0ea8">TEXT</enumvalue>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>ValuesResultAggregateType</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>a779f5c828b0a87bbb4b9fee51c6eb3cd</anchor>
      <arglist></arglist>
      <enumvalue file="namespacemlclient.html" anchor="a779f5c828b0a87bbb4b9fee51c6eb3cdad5e69c7de3ce010c1aade8e8f9495797">SIMPLE_DOUBLE</enumvalue>
      <enumvalue file="namespacemlclient.html" anchor="a779f5c828b0a87bbb4b9fee51c6eb3cda43892e920fee9b94afcc184bfda20af5">COMPLEX_MAP_ARRAY</enumvalue>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>reconfigureLogging</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>a88d4ac6b7910817c101534a471f02e27</anchor>
      <arglist>(int argc, const char *argv[])</arglist>
    </member>
    <member kind="function">
      <type>MLCLIENT_API void</type>
      <name>reconfigureLoggingSettings</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>afe73e314dfbe4d339c7fd2d0ad00b285</anchor>
      <arglist>(const LoggingConfiguration &amp;config)</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>mlclient::utilities</name>
    <filename>namespacemlclient_1_1utilities.html</filename>
    <class kind="class">mlclient::utilities::AggregateInfo</class>
    <class kind="class">mlclient::utilities::CppRestJsonArrayNode</class>
    <class kind="class">mlclient::utilities::CppRestJsonContainerNode</class>
    <class kind="class">mlclient::utilities::CppRestJsonDocumentContent</class>
    <class kind="class">mlclient::utilities::CppRestJsonDocumentNavigator</class>
    <class kind="class">mlclient::utilities::CppRestJsonDocumentNode</class>
    <class kind="class">mlclient::utilities::CppRestJsonHelper</class>
    <class kind="class">mlclient::utilities::CppRestJsonObjectNode</class>
    <class kind="class">mlclient::utilities::DocumentBatchHelper</class>
    <class kind="class">mlclient::utilities::DocumentBatchWriter</class>
    <class kind="class">mlclient::utilities::DocumentHelper</class>
    <class kind="class">mlclient::utilities::GenericQuery</class>
    <class kind="class">mlclient::utilities::IBatchNotifiable</class>
    <class kind="class">mlclient::utilities::IContainerRef</class>
    <class kind="class">mlclient::utilities::ILexiconRef</class>
    <class kind="class">mlclient::utilities::IQuery</class>
    <class kind="class">mlclient::utilities::ITypedValue</class>
    <class kind="class">mlclient::utilities::JsonPropertyQuery</class>
    <class kind="class">mlclient::utilities::JsonPropertyRef</class>
    <class kind="struct">mlclient::utilities::Progress</class>
    <class kind="class">mlclient::utilities::PugiXmlArrayNode</class>
    <class kind="class">mlclient::utilities::PugiXmlContainerNode</class>
    <class kind="class">mlclient::utilities::PugiXmlDocumentContent</class>
    <class kind="class">mlclient::utilities::PugiXmlDocumentNavigator</class>
    <class kind="class">mlclient::utilities::PugiXmlDocumentNode</class>
    <class kind="class">mlclient::utilities::PugiXmlHelper</class>
    <class kind="class">mlclient::utilities::PugiXmlObjectNode</class>
    <class kind="class">mlclient::utilities::RangeLexiconRef</class>
    <class kind="class">mlclient::utilities::RangeOptions</class>
    <class kind="class">mlclient::utilities::ResponseHelper</class>
    <class kind="class">mlclient::utilities::SearchBuilder</class>
    <class kind="class">mlclient::utilities::SearchOptionsBuilder</class>
    <class kind="class">mlclient::utilities::ValuesInfo</class>
    <member kind="enumeration">
      <type></type>
      <name>TransactionMode</name>
      <anchorfile>namespacemlclient_1_1utilities.html</anchorfile>
      <anchor>ac0b22719c717d40d4ce9ea0ffd840418</anchor>
      <arglist></arglist>
      <enumvalue file="namespacemlclient_1_1utilities.html" anchor="ac0b22719c717d40d4ce9ea0ffd840418ad6892801a8fec7534b2725d065cd24a8">PER_RECORD</enumvalue>
      <enumvalue file="namespacemlclient_1_1utilities.html" anchor="ac0b22719c717d40d4ce9ea0ffd840418a6525955aa4936ca47037f146fe79f351">PER_BATCH</enumvalue>
      <enumvalue file="namespacemlclient_1_1utilities.html" anchor="ac0b22719c717d40d4ce9ea0ffd840418a5fb1f955b45e38e31789286a1790398d">ALL</enumvalue>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>RangeOperation</name>
      <anchorfile>namespacemlclient_1_1utilities.html</anchorfile>
      <anchor>aa37042226c740dea51edeb939bdd2e43</anchor>
      <arglist></arglist>
      <enumvalue file="namespacemlclient_1_1utilities.html" anchor="aa37042226c740dea51edeb939bdd2e43a7280a7d8974164a48d863dee5e341f27">UNKNOWN_TYPE</enumvalue>
      <enumvalue file="namespacemlclient_1_1utilities.html" anchor="aa37042226c740dea51edeb939bdd2e43af803729628adf4199f224c2a225038e9">GE</enumvalue>
      <enumvalue file="namespacemlclient_1_1utilities.html" anchor="aa37042226c740dea51edeb939bdd2e43acd6a9bd2a175104eed40f0d33a8b4020">GT</enumvalue>
      <enumvalue file="namespacemlclient_1_1utilities.html" anchor="aa37042226c740dea51edeb939bdd2e43ac562607189d77eb9dfb707464c1e7b0b">LT</enumvalue>
      <enumvalue file="namespacemlclient_1_1utilities.html" anchor="aa37042226c740dea51edeb939bdd2e43acfe6055d2e0503be378bb63449ec7ba6">LE</enumvalue>
      <enumvalue file="namespacemlclient_1_1utilities.html" anchor="aa37042226c740dea51edeb939bdd2e43a2dcbad7477fd40561e8b8198f173bd47">EQ</enumvalue>
      <enumvalue file="namespacemlclient_1_1utilities.html" anchor="aa37042226c740dea51edeb939bdd2e43adc33066c3993e0d50896e533fd692ce0">NE</enumvalue>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>QueryBuilderMode</name>
      <anchorfile>namespacemlclient_1_1utilities.html</anchorfile>
      <anchor>a14ae5aa40d0d72888030b22730f93421</anchor>
      <arglist></arglist>
      <enumvalue file="namespacemlclient_1_1utilities.html" anchor="a14ae5aa40d0d72888030b22730f93421a5fb1f955b45e38e31789286a1790398d">ALL</enumvalue>
      <enumvalue file="namespacemlclient_1_1utilities.html" anchor="a14ae5aa40d0d72888030b22730f93421a3501bb093d363810b671059b9cfed3f8">XML</enumvalue>
      <enumvalue file="namespacemlclient_1_1utilities.html" anchor="a14ae5aa40d0d72888030b22730f93421a0ecd11c1d7a287401d148a23bbd7a2f8">JSON</enumvalue>
    </member>
    <member kind="function">
      <type>IDocumentNode *</type>
      <name>createNode</name>
      <anchorfile>namespacemlclient_1_1utilities.html</anchorfile>
      <anchor>a98eff32e2427ab4714ee264cd59d7507</anchor>
      <arglist>(pugi::xml_node &amp;parent, const std::string &amp;key)</arglist>
    </member>
  </compound>
  <compound kind="page">
    <name>page_CWrapper</name>
    <title>C Language Wrapper</title>
    <filename>page__c_wrapper</filename>
  </compound>
  <compound kind="page">
    <name>page_design</name>
    <title>Design</title>
    <filename>page_design</filename>
    <docanchor file="page_design" title="C++ Public API">The</docanchor>
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
    <docanchor file="page_devguide" title="Cleaning up Resources">sec_cleaningup</docanchor>
    <docanchor file="page_devguide" title="Query Options">sec_queryoptions</docanchor>
    <docanchor file="page_devguide" title="Using query options">sec_usingqueryoptions</docanchor>
    <docanchor file="page_devguide" title="Default query options">sec_defaultqueryoptions</docanchor>
    <docanchor file="page_devguide" title="Creating query options">sec_createqueryoptions</docanchor>
    <docanchor file="page_devguide" title="Updating query options">sec_updatequeryoptions</docanchor>
    <docanchor file="page_devguide" title="Deleting query options">sec_deletequeryoptions</docanchor>
    <docanchor file="page_devguide" title="Creating query options from raw XML or JSON">sec_createoptionsfromtext</docanchor>
    <docanchor file="page_devguide" title="Validating query options">sec_validatequeryoptions</docanchor>
    <docanchor file="page_devguide" title="Searching">sec_search</docanchor>
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
    <docanchor file="page_devguide" title="Extending the C++ API">sec_extending</docanchor>
    <docanchor file="page_devguide" title="Performing an ad-hoc query to any REST endpoint">sec_adhocendpoint</docanchor>
    <docanchor file="page_devguide" title="Troubleshooting">sec_trouble</docanchor>
    <docanchor file="page_devguide" title="Error detection">sec_errors</docanchor>
    <docanchor file="page_devguide" title="General Troubleshooting Techniques">sec_troubletechs</docanchor>
  </compound>
  <compound kind="page">
    <name>page_home_c</name>
    <title>C Documentation</title>
    <filename>page_home_c</filename>
    <docanchor file="page_home_c" title="Features">sec_home_c_features</docanchor>
    <docanchor file="page_home_c" title="Installation">sec_home_c_install</docanchor>
    <docanchor file="page_home_c" title="Quickstart">sec_home_c_quickstart</docanchor>
    <docanchor file="page_home_c" title="Language Specific Features">sec_home_c_langspecific</docanchor>
    <docanchor file="page_home_c" title="name patterns">Function</docanchor>
    <docanchor file="page_home_c" title="Extending">sec_home_c_extending</docanchor>
  </compound>
  <compound kind="page">
    <name>page_home_cpp</name>
    <title>C++ Documentation</title>
    <filename>page_home_cpp</filename>
    <docanchor file="page_home_cpp" title="Features">sec_home_cpp_features</docanchor>
    <docanchor file="page_home_cpp" title="Installation">sec_home_cpp_install</docanchor>
    <docanchor file="page_home_cpp" title="Quickstart">sec_home_cpp_quickstart</docanchor>
    <docanchor file="page_home_cpp" title="Language Specific Features">sec_home_cpp_langspecific</docanchor>
    <docanchor file="page_home_cpp" title="Support for C++ STL Iterators and Collections">sec_home_cpp_langspecific_stl</docanchor>
    <docanchor file="page_home_cpp" title="Pointers and move semantics">sec_home_cpp_langspecific_pointers</docanchor>
    <docanchor file="page_home_cpp" title="Developer&apos;s guide">sec_home_cpp_devguide</docanchor>
    <docanchor file="page_home_cpp" title="Extending">sec_home_cpp_extending</docanchor>
  </compound>
  <compound kind="page">
    <name>page_home_csharp</name>
    <title>C# Documentation</title>
    <filename>page_home_csharp</filename>
    <docanchor file="page_home_csharp" title="Features">sec_home_csharp_features</docanchor>
    <docanchor file="page_home_csharp" title="Installation">sec_home_csharp_install</docanchor>
    <docanchor file="page_home_csharp" title="Quickstart">sec_home_csharp_quickstart</docanchor>
    <docanchor file="page_home_csharp" title="Language Specific Features">sec_home_csharp_langspecific</docanchor>
    <docanchor file="page_home_csharp" title="Function name patterns">sec_home_csharp_functions</docanchor>
    <docanchor file="page_home_csharp" title="Extending">sec_home_csharp_extending</docanchor>
    <docanchor file="page_home_csharp" title="Troubleshooting">sec_home_csharp_troubleshooting</docanchor>
  </compound>
  <compound kind="page">
    <name>page_home_python</name>
    <title>Python Documentation</title>
    <filename>page_home_python</filename>
    <docanchor file="page_home_python" title="Features">sec_home_python_features</docanchor>
    <docanchor file="page_home_python" title="Installation">sec_home_python_install</docanchor>
    <docanchor file="page_home_python" title="Quickstart">sec_home_python_quickstart</docanchor>
    <docanchor file="page_home_python" title="Language Specific Features">sec_home_python_langspecific</docanchor>
    <docanchor file="page_home_python" title="Function name patterns">sec_home_python_functions</docanchor>
    <docanchor file="page_home_python" title="Extending">sec_home_python_extending</docanchor>
  </compound>
  <compound kind="page">
    <name>page_install</name>
    <title>Installing MLCPlusPlus</title>
    <filename>page_install</filename>
    <docanchor file="page_install" title="Get Casablanca">sec_getcasablanca</docanchor>
    <docanchor file="page_install" title="Using PUGI XML">sec_getpugixml</docanchor>
    <docanchor file="page_install" title="Building the MLCPlusPlus library from source">sec_buildit</docanchor>
    <docanchor file="page_install" title="Installing MLCPlusPlus globally in your system">sec_install_for_dev</docanchor>
    <docanchor file="page_install" title="Using the MLCPlusPlus library in your C++ application">sec_using</docanchor>
    <docanchor file="page_install" title="Compiling the tests">sec_compilingtests</docanchor>
  </compound>
  <compound kind="page">
    <name>page_mac_install_pkg</name>
    <title>Mac Installation from the Package installer</title>
    <filename>page_mac_install_pkg</filename>
    <docanchor file="page_mac_install_pkg" title="Install dependencies">sec_mac_install_pkg_deps</docanchor>
  </compound>
  <compound kind="page">
    <name>page_mac_install_raw</name>
    <title>Mac Installation from the raw dylib library files</title>
    <filename>page_mac_install_raw</filename>
    <docanchor file="page_mac_install_raw" title="Install include files">sec_mac_install_raw_include</docanchor>
    <docanchor file="page_mac_install_raw" title="Install compiled libraries">sec_mac_install_raw_libs</docanchor>
    <docanchor file="page_mac_install_raw" title="Install dependencies">sec_mac_install_raw_deps</docanchor>
  </compound>
  <compound kind="page">
    <name>page_ubuntu_install_raw</name>
    <title>Ubuntu Installation from the raw so library files</title>
    <filename>page_ubuntu_install_raw</filename>
    <docanchor file="page_ubuntu_install_raw" title="Install include files">sec_ubuntu_install_raw_include</docanchor>
    <docanchor file="page_ubuntu_install_raw" title="Install compiled libraries">sec_ubuntu_install_raw_libs</docanchor>
    <docanchor file="page_ubuntu_install_raw" title="Install dependencies">sec_ubuntu_install_raw_deps</docanchor>
  </compound>
  <compound kind="page">
    <name>page_win_install_raw</name>
    <title>Mac Installation from the raw dylib library files</title>
    <filename>page_win_install_raw</filename>
    <docanchor file="page_win_install_raw" title="Install include files">sec_win_install_raw_include</docanchor>
    <docanchor file="page_win_install_raw" title="Install compiled libraries">sec_win_install_raw_libs</docanchor>
    <docanchor file="page_win_install_raw" title="Install dependencies">sec_win_install_raw_deps</docanchor>
  </compound>
  <compound kind="page">
    <name>index</name>
    <title>MarkLogic Connect Client API Collection Documentation</title>
    <filename>index</filename>
    <docanchor file="index" title="Support">sec_support</docanchor>
    <docanchor file="index" title="Copyright">sec_legal</docanchor>
    <docanchor file="index" title="Developer&apos;s guide">sec_devguidelink</docanchor>
  </compound>
</tagfile>
