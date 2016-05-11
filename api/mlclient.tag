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
    <name>el::base::utils::AbstractRegistry</name>
    <filename>classel_1_1base_1_1utils_1_1_abstract_registry.html</filename>
    <templarg>T_Ptr</templarg>
    <templarg>Container</templarg>
    <base>el::base::threading::ThreadSafe</base>
    <member kind="function">
      <type></type>
      <name>AbstractRegistry</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>afe13c67ebd1ed1aa72845926894dffa2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AbstractRegistry</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a9f468010439d491e90419f9334afcdba</anchor>
      <arglist>(AbstractRegistry &amp;&amp;sr)</arglist>
    </member>
    <member kind="function">
      <type>AbstractRegistry &amp;</type>
      <name>operator=</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a5727a3cadeee6a2b10d8f46fb91956e7</anchor>
      <arglist>(AbstractRegistry &amp;&amp;sr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual iterator</type>
      <name>begin</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a4ad971b1dddff996d327452d852e55b2</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual iterator</type>
      <name>end</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a67c40207c171f23ad50a71db819e84f9</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const_iterator</type>
      <name>cbegin</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a37f743184e808d7c0028e21e0d0898bb</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const_iterator</type>
      <name>cend</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>ad3ee081b4b25c5d77f971f949bdb9158</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>empty</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a43ff6484b778c298416c482c07a4df3f</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::size_t</type>
      <name>size</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a58a7b8ea964bdf6008701dcfb6609ca5</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Container &amp;</type>
      <name>list</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a072859d3728a75f910c2898f62fd12da</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const Container &amp;</type>
      <name>list</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a1c3da2af9177cbfae6f10b9e5dbe615c</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>unregisterAll</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a19223bc1fea48dbe6b47b4879aa4672f</anchor>
      <arglist>(void)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>AbstractRegistry&lt; base::HitCounter, std::vector&lt; base::HitCounter * &gt; &gt;</name>
    <filename>classel_1_1base_1_1utils_1_1_abstract_registry.html</filename>
    <base>el::base::threading::ThreadSafe</base>
    <member kind="function">
      <type></type>
      <name>AbstractRegistry</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>afe13c67ebd1ed1aa72845926894dffa2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AbstractRegistry</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a9f468010439d491e90419f9334afcdba</anchor>
      <arglist>(AbstractRegistry &amp;&amp;sr)</arglist>
    </member>
    <member kind="function">
      <type>AbstractRegistry &amp;</type>
      <name>operator=</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a5727a3cadeee6a2b10d8f46fb91956e7</anchor>
      <arglist>(AbstractRegistry &amp;&amp;sr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual iterator</type>
      <name>begin</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a4ad971b1dddff996d327452d852e55b2</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual iterator</type>
      <name>end</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a67c40207c171f23ad50a71db819e84f9</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const_iterator</type>
      <name>cbegin</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a37f743184e808d7c0028e21e0d0898bb</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const_iterator</type>
      <name>cend</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>ad3ee081b4b25c5d77f971f949bdb9158</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>empty</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a43ff6484b778c298416c482c07a4df3f</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::size_t</type>
      <name>size</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a58a7b8ea964bdf6008701dcfb6609ca5</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::vector&lt; base::HitCounter * &gt; &amp;</type>
      <name>list</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a072859d3728a75f910c2898f62fd12da</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const std::vector&lt; base::HitCounter * &gt; &amp;</type>
      <name>list</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a1c3da2af9177cbfae6f10b9e5dbe615c</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>unregisterAll</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a19223bc1fea48dbe6b47b4879aa4672f</anchor>
      <arglist>(void)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>AbstractRegistry&lt; Configuration, std::vector&lt; Configuration * &gt; &gt;</name>
    <filename>classel_1_1base_1_1utils_1_1_abstract_registry.html</filename>
    <base>el::base::threading::ThreadSafe</base>
    <member kind="function">
      <type></type>
      <name>AbstractRegistry</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>afe13c67ebd1ed1aa72845926894dffa2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AbstractRegistry</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a9f468010439d491e90419f9334afcdba</anchor>
      <arglist>(AbstractRegistry &amp;&amp;sr)</arglist>
    </member>
    <member kind="function">
      <type>AbstractRegistry &amp;</type>
      <name>operator=</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a5727a3cadeee6a2b10d8f46fb91956e7</anchor>
      <arglist>(AbstractRegistry &amp;&amp;sr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual iterator</type>
      <name>begin</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a4ad971b1dddff996d327452d852e55b2</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual iterator</type>
      <name>end</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a67c40207c171f23ad50a71db819e84f9</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const_iterator</type>
      <name>cbegin</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a37f743184e808d7c0028e21e0d0898bb</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const_iterator</type>
      <name>cend</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>ad3ee081b4b25c5d77f971f949bdb9158</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>empty</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a43ff6484b778c298416c482c07a4df3f</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::size_t</type>
      <name>size</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a58a7b8ea964bdf6008701dcfb6609ca5</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::vector&lt; Configuration * &gt; &amp;</type>
      <name>list</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a072859d3728a75f910c2898f62fd12da</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const std::vector&lt; Configuration * &gt; &amp;</type>
      <name>list</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a1c3da2af9177cbfae6f10b9e5dbe615c</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>unregisterAll</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a19223bc1fea48dbe6b47b4879aa4672f</anchor>
      <arglist>(void)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>AbstractRegistry&lt; Logger, std::map&lt; std::string, Logger * &gt; &gt;</name>
    <filename>classel_1_1base_1_1utils_1_1_abstract_registry.html</filename>
    <base>el::base::threading::ThreadSafe</base>
    <member kind="function">
      <type></type>
      <name>AbstractRegistry</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>afe13c67ebd1ed1aa72845926894dffa2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AbstractRegistry</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a9f468010439d491e90419f9334afcdba</anchor>
      <arglist>(AbstractRegistry &amp;&amp;sr)</arglist>
    </member>
    <member kind="function">
      <type>AbstractRegistry &amp;</type>
      <name>operator=</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a5727a3cadeee6a2b10d8f46fb91956e7</anchor>
      <arglist>(AbstractRegistry &amp;&amp;sr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual iterator</type>
      <name>begin</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a4ad971b1dddff996d327452d852e55b2</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual iterator</type>
      <name>end</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a67c40207c171f23ad50a71db819e84f9</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const_iterator</type>
      <name>cbegin</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a37f743184e808d7c0028e21e0d0898bb</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const_iterator</type>
      <name>cend</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>ad3ee081b4b25c5d77f971f949bdb9158</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>empty</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a43ff6484b778c298416c482c07a4df3f</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::size_t</type>
      <name>size</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a58a7b8ea964bdf6008701dcfb6609ca5</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::map&lt; std::string, Logger * &gt; &amp;</type>
      <name>list</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a072859d3728a75f910c2898f62fd12da</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const std::map&lt; std::string, Logger * &gt; &amp;</type>
      <name>list</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a1c3da2af9177cbfae6f10b9e5dbe615c</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>unregisterAll</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a19223bc1fea48dbe6b47b4879aa4672f</anchor>
      <arglist>(void)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>AbstractRegistry&lt; T_Ptr, std::map&lt; T_Key, T_Ptr * &gt; &gt;</name>
    <filename>classel_1_1base_1_1utils_1_1_abstract_registry.html</filename>
    <base>el::base::threading::ThreadSafe</base>
    <member kind="function">
      <type></type>
      <name>AbstractRegistry</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>afe13c67ebd1ed1aa72845926894dffa2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AbstractRegistry</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a9f468010439d491e90419f9334afcdba</anchor>
      <arglist>(AbstractRegistry &amp;&amp;sr)</arglist>
    </member>
    <member kind="function">
      <type>AbstractRegistry &amp;</type>
      <name>operator=</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a5727a3cadeee6a2b10d8f46fb91956e7</anchor>
      <arglist>(AbstractRegistry &amp;&amp;sr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual iterator</type>
      <name>begin</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a4ad971b1dddff996d327452d852e55b2</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual iterator</type>
      <name>end</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a67c40207c171f23ad50a71db819e84f9</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const_iterator</type>
      <name>cbegin</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a37f743184e808d7c0028e21e0d0898bb</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const_iterator</type>
      <name>cend</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>ad3ee081b4b25c5d77f971f949bdb9158</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>empty</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a43ff6484b778c298416c482c07a4df3f</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::size_t</type>
      <name>size</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a58a7b8ea964bdf6008701dcfb6609ca5</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::map&lt; T_Key, T_Ptr * &gt; &amp;</type>
      <name>list</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a072859d3728a75f910c2898f62fd12da</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const std::map&lt; T_Key, T_Ptr * &gt; &amp;</type>
      <name>list</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a1c3da2af9177cbfae6f10b9e5dbe615c</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>unregisterAll</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a19223bc1fea48dbe6b47b4879aa4672f</anchor>
      <arglist>(void)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>AbstractRegistry&lt; T_Ptr, std::vector&lt; T_Ptr * &gt; &gt;</name>
    <filename>classel_1_1base_1_1utils_1_1_abstract_registry.html</filename>
    <base>el::base::threading::ThreadSafe</base>
    <member kind="function">
      <type></type>
      <name>AbstractRegistry</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>afe13c67ebd1ed1aa72845926894dffa2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AbstractRegistry</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a9f468010439d491e90419f9334afcdba</anchor>
      <arglist>(AbstractRegistry &amp;&amp;sr)</arglist>
    </member>
    <member kind="function">
      <type>AbstractRegistry &amp;</type>
      <name>operator=</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a5727a3cadeee6a2b10d8f46fb91956e7</anchor>
      <arglist>(AbstractRegistry &amp;&amp;sr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual iterator</type>
      <name>begin</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a4ad971b1dddff996d327452d852e55b2</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual iterator</type>
      <name>end</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a67c40207c171f23ad50a71db819e84f9</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const_iterator</type>
      <name>cbegin</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a37f743184e808d7c0028e21e0d0898bb</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const_iterator</type>
      <name>cend</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>ad3ee081b4b25c5d77f971f949bdb9158</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>empty</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a43ff6484b778c298416c482c07a4df3f</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::size_t</type>
      <name>size</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a58a7b8ea964bdf6008701dcfb6609ca5</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::vector&lt; T_Ptr * &gt; &amp;</type>
      <name>list</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a072859d3728a75f910c2898f62fd12da</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const std::vector&lt; T_Ptr * &gt; &amp;</type>
      <name>list</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a1c3da2af9177cbfae6f10b9e5dbe615c</anchor>
      <arglist>(void) const ELPP_FINAL</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>unregisterAll</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_abstract_registry.html</anchorfile>
      <anchor>a19223bc1fea48dbe6b47b4879aa4672f</anchor>
      <arglist>(void)=0</arglist>
    </member>
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
    <name>el::Callback</name>
    <filename>classel_1_1_callback.html</filename>
    <templarg>T</templarg>
    <base protection="protected">el::base::threading::ThreadSafe</base>
  </compound>
  <compound kind="class">
    <name>Callback&lt; LogDispatchData &gt;</name>
    <filename>classel_1_1_callback.html</filename>
    <base protection="protected">el::base::threading::ThreadSafe</base>
  </compound>
  <compound kind="class">
    <name>Callback&lt; PerformanceTrackingData &gt;</name>
    <filename>classel_1_1_callback.html</filename>
    <base protection="protected">el::base::threading::ThreadSafe</base>
  </compound>
  <compound kind="class">
    <name>el::base::utils::CommandLineArgs</name>
    <filename>classel_1_1base_1_1utils_1_1_command_line_args.html</filename>
    <member kind="function">
      <type>void</type>
      <name>setArgs</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_command_line_args.html</anchorfile>
      <anchor>a2d59b4184e0a6a314ef1c9a4c6d946e6</anchor>
      <arglist>(int argc, const char **argv)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setArgs</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_command_line_args.html</anchorfile>
      <anchor>af88a16e6ce7b5d48f9679f304367b27a</anchor>
      <arglist>(int argc, char **argv)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>hasParamWithValue</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_command_line_args.html</anchorfile>
      <anchor>acc9fa8eeed2deecffb6019173de5ab48</anchor>
      <arglist>(const char *paramKey) const </arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>getParamValue</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_command_line_args.html</anchorfile>
      <anchor>ad1abe08dfdbdd95c72474197ba4a3cbd</anchor>
      <arglist>(const char *paramKey) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>hasParam</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_command_line_args.html</anchorfile>
      <anchor>a83fbd7e5d8422e98a7d58d65283f144f</anchor>
      <arglist>(const char *paramKey) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>empty</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_command_line_args.html</anchorfile>
      <anchor>a014c586d14eb73f2ec1deb5b08bdd6a7</anchor>
      <arglist>(void) const </arglist>
    </member>
    <member kind="function">
      <type>std::size_t</type>
      <name>size</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_command_line_args.html</anchorfile>
      <anchor>ab335b66a2ca2dea6c9c7b8d54760e975</anchor>
      <arglist>(void) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>el::Configuration</name>
    <filename>classel_1_1_configuration.html</filename>
    <base>el::Loggable</base>
    <class kind="class">el::Configuration::Predicate</class>
    <member kind="function">
      <type></type>
      <name>Configuration</name>
      <anchorfile>classel_1_1_configuration.html</anchorfile>
      <anchor>a1a00abf955e028debaaf7556a647dbf5</anchor>
      <arglist>(Level level, ConfigurationType configurationType, const std::string &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>Level</type>
      <name>level</name>
      <anchorfile>classel_1_1_configuration.html</anchorfile>
      <anchor>a66a96cf46d20204c50718f8a5e3622e2</anchor>
      <arglist>(void) const </arglist>
    </member>
    <member kind="function">
      <type>ConfigurationType</type>
      <name>configurationType</name>
      <anchorfile>classel_1_1_configuration.html</anchorfile>
      <anchor>aab5091dcca176e309c0a2268ff55db0d</anchor>
      <arglist>(void) const </arglist>
    </member>
    <member kind="function">
      <type>const std::string &amp;</type>
      <name>value</name>
      <anchorfile>classel_1_1_configuration.html</anchorfile>
      <anchor>ab31605eb195a222cf32baa4922bb9a3c</anchor>
      <arglist>(void) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setValue</name>
      <anchorfile>classel_1_1_configuration.html</anchorfile>
      <anchor>a04755de11422d7570869433ea157b705</anchor>
      <arglist>(const std::string &amp;value)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>el::Configurations</name>
    <filename>classel_1_1_configurations.html</filename>
    <base>RegistryWithPred&lt; Configuration, Configuration::Predicate &gt;</base>
    <class kind="class">el::Configurations::Parser</class>
    <member kind="function">
      <type></type>
      <name>Configurations</name>
      <anchorfile>classel_1_1_configurations.html</anchorfile>
      <anchor>ae299dd1b60a1df9c013cc23029242a77</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Configurations</name>
      <anchorfile>classel_1_1_configurations.html</anchorfile>
      <anchor>ae341bd647734d1180a5a138222d2f1ea</anchor>
      <arglist>(const std::string &amp;configurationFile, bool useDefaultsForRemaining=true, Configurations *base=nullptr)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>parseFromFile</name>
      <anchorfile>classel_1_1_configurations.html</anchorfile>
      <anchor>aaa098126d64a5ee04a3944b1a65dcdca</anchor>
      <arglist>(const std::string &amp;configurationFile, Configurations *base=nullptr)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>parseFromText</name>
      <anchorfile>classel_1_1_configurations.html</anchorfile>
      <anchor>af262a41dff665a11889261137b62af4a</anchor>
      <arglist>(const std::string &amp;configurationsString, Configurations *base=nullptr)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFromBase</name>
      <anchorfile>classel_1_1_configurations.html</anchorfile>
      <anchor>a4c6db218908b39d23cc09b1a16a18e83</anchor>
      <arglist>(Configurations *base)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>hasConfiguration</name>
      <anchorfile>classel_1_1_configurations.html</anchorfile>
      <anchor>a1e812370f896b6429bf46b31fcd4e3e0</anchor>
      <arglist>(ConfigurationType configurationType)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>hasConfiguration</name>
      <anchorfile>classel_1_1_configurations.html</anchorfile>
      <anchor>a5313557efac3b0c78f973a5a1d685277</anchor>
      <arglist>(Level level, ConfigurationType configurationType)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set</name>
      <anchorfile>classel_1_1_configurations.html</anchorfile>
      <anchor>a332717de96efc851a202b7afcc5e395c</anchor>
      <arglist>(Level level, ConfigurationType configurationType, const std::string &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set</name>
      <anchorfile>classel_1_1_configurations.html</anchorfile>
      <anchor>a0ab07520b9409fe9f2c16a705d6936f1</anchor>
      <arglist>(Configuration *conf)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setGlobally</name>
      <anchorfile>classel_1_1_configurations.html</anchorfile>
      <anchor>a56c82c15ea39cc230a5c85ec2c41cbfd</anchor>
      <arglist>(ConfigurationType configurationType, const std::string &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>clear</name>
      <anchorfile>classel_1_1_configurations.html</anchorfile>
      <anchor>a2a13be6154439286a68d2eccf8417edf</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const std::string &amp;</type>
      <name>configurationFile</name>
      <anchorfile>classel_1_1_configurations.html</anchorfile>
      <anchor>a18df64bb5cd97bee672160290133141c</anchor>
      <arglist>(void) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setToDefault</name>
      <anchorfile>classel_1_1_configurations.html</anchorfile>
      <anchor>ab34fa2ed4ac77f47b41e464c2d186239</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setRemainingToDefault</name>
      <anchorfile>classel_1_1_configurations.html</anchorfile>
      <anchor>ad89b7d2dd750e4d1b3deff800e278fdb</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>el::ConfigurationTypeHelper</name>
    <filename>classel_1_1_configuration_type_helper.html</filename>
    <base protection="private">el::base::StaticClass</base>
    <member kind="function" static="yes">
      <type>static base::type::EnumType</type>
      <name>castToInt</name>
      <anchorfile>classel_1_1_configuration_type_helper.html</anchorfile>
      <anchor>aa53161071fee3ce3f371ab90c62d5fc2</anchor>
      <arglist>(ConfigurationType configurationType)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static ConfigurationType</type>
      <name>castFromInt</name>
      <anchorfile>classel_1_1_configuration_type_helper.html</anchorfile>
      <anchor>a62301cbc966cf7e7e2a7b55cc3259996</anchor>
      <arglist>(base::type::EnumType c)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static const char *</type>
      <name>convertToString</name>
      <anchorfile>classel_1_1_configuration_type_helper.html</anchorfile>
      <anchor>ad7f0a19c416c4a8ddaf85330b141383c</anchor>
      <arglist>(ConfigurationType configurationType)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static ConfigurationType</type>
      <name>convertFromString</name>
      <anchorfile>classel_1_1_configuration_type_helper.html</anchorfile>
      <anchor>af4a35305e3941fd578e55fec624eba43</anchor>
      <arglist>(const char *configStr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>forEachConfigType</name>
      <anchorfile>classel_1_1_configuration_type_helper.html</anchorfile>
      <anchor>aa0524147f792309fc09e0b8d14826c17</anchor>
      <arglist>(base::type::EnumType *startIndex, const std::function&lt; bool(void)&gt; &amp;fn)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const base::type::EnumType</type>
      <name>kMinValid</name>
      <anchorfile>classel_1_1_configuration_type_helper.html</anchorfile>
      <anchor>ab7266e698eb32dec2da285325a66e322</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const base::type::EnumType</type>
      <name>kMaxValid</name>
      <anchorfile>classel_1_1_configuration_type_helper.html</anchorfile>
      <anchor>aa02f3cefb127e7eb97d7e1dd7f51a12d</anchor>
      <arglist></arglist>
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
      <name>deleteDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>ad406949e7a41b0b4e32974be725131a7</anchor>
      <arglist>(const std::string &amp;uri)</arglist>
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
      <name>deleteDocument</name>
      <anchorfile>classmlclient_1_1_connection.html</anchorfile>
      <anchor>ad406949e7a41b0b4e32974be725131a7</anchor>
      <arglist>(const std::string &amp;uri)</arglist>
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
    <name>el::base::debug::CrashHandler</name>
    <filename>classel_1_1base_1_1debug_1_1_crash_handler.html</filename>
    <base protection="private">el::base::NoCopy</base>
  </compound>
  <compound kind="class">
    <name>el::CustomFormatSpecifier</name>
    <filename>classel_1_1_custom_format_specifier.html</filename>
  </compound>
  <compound kind="class">
    <name>CWrapper</name>
    <filename>class_c_wrapper.html</filename>
    <templarg></templarg>
  </compound>
  <compound kind="class">
    <name>el::base::utils::DateTime</name>
    <filename>classel_1_1base_1_1utils_1_1_date_time.html</filename>
    <base protection="private">el::base::StaticClass</base>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>gettimeofday</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_date_time.html</anchorfile>
      <anchor>ac000e6ecf705c2194a173d618ff4acfd</anchor>
      <arglist>(struct timeval *tv)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::string</type>
      <name>getDateTime</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_date_time.html</anchorfile>
      <anchor>aa813c606a98b8741f59ccdf5aacef733</anchor>
      <arglist>(const char *format, const base::MillisecondsWidth *msWidth)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static base::type::string_t</type>
      <name>formatTime</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_date_time.html</anchorfile>
      <anchor>a1eea58fffe291c969a526d08515d29d7</anchor>
      <arglist>(unsigned long long time, base::TimestampUnit timestampUnit)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static unsigned long long</type>
      <name>getTimeDifference</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_date_time.html</anchorfile>
      <anchor>a9181a3544442e1d3c05d8c96bbfff16d</anchor>
      <arglist>(const struct timeval &amp;endTime, const struct timeval &amp;startTime, base::TimestampUnit timestampUnit)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>el::base::DefaultLogBuilder</name>
    <filename>classel_1_1base_1_1_default_log_builder.html</filename>
    <base>el::LogBuilder</base>
  </compound>
  <compound kind="class">
    <name>el::base::DefaultLogDispatchCallback</name>
    <filename>classel_1_1base_1_1_default_log_dispatch_callback.html</filename>
    <base>el::LogDispatchCallback</base>
  </compound>
  <compound kind="class">
    <name>el::base::DefaultPerformanceTrackingCallback</name>
    <filename>classel_1_1base_1_1_default_performance_tracking_callback.html</filename>
    <base>el::PerformanceTrackingCallback</base>
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
    <name>el::base::utils::File</name>
    <filename>classel_1_1base_1_1utils_1_1_file.html</filename>
    <base protection="private">el::base::StaticClass</base>
    <member kind="function" static="yes">
      <type>static base::type::fstream_t *</type>
      <name>newFileStream</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_file.html</anchorfile>
      <anchor>aa4bef1f2e00269d75c1c1eabb0ce4563</anchor>
      <arglist>(const std::string &amp;filename)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::size_t</type>
      <name>getSizeOfFile</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_file.html</anchorfile>
      <anchor>a54415ba02f698ba978795265f7f4b86c</anchor>
      <arglist>(base::type::fstream_t *fs)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>pathExists</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_file.html</anchorfile>
      <anchor>a4fc9e36b814f1aeaa4931e35d58e5b45</anchor>
      <arglist>(const char *path, bool considerFile=false)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>createPath</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_file.html</anchorfile>
      <anchor>a34fbb5b06201c7e3db71db80e017fb96</anchor>
      <arglist>(const std::string &amp;path)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::string</type>
      <name>extractPathFromFilename</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_file.html</anchorfile>
      <anchor>af541c62ed408de7e368d339f96c0c6cf</anchor>
      <arglist>(const std::string &amp;fullPath, const char *seperator=base::consts::kFilePathSeperator)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>buildStrippedFilename</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_file.html</anchorfile>
      <anchor>a38e3b3c72f73de47563b289eff13ae2d</anchor>
      <arglist>(const char *filename, char buff[], std::size_t limit=base::consts::kSourceFilenameMaxLength)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>buildBaseFilename</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_file.html</anchorfile>
      <anchor>ad6c3703c16b95bd4992f501380d503b4</anchor>
      <arglist>(const std::string &amp;fullPath, char buff[], std::size_t limit=base::consts::kSourceFilenameMaxLength, const char *seperator=base::consts::kFilePathSeperator)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>el::Helpers</name>
    <filename>classel_1_1_helpers.html</filename>
    <base protection="private">el::base::StaticClass</base>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>setStorage</name>
      <anchorfile>classel_1_1_helpers.html</anchorfile>
      <anchor>af78fd39725281e3dddd7c0fbdc14f11f</anchor>
      <arglist>(base::type::StoragePointer storage)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static base::type::StoragePointer</type>
      <name>storage</name>
      <anchorfile>classel_1_1_helpers.html</anchorfile>
      <anchor>a13a5365de36b3af27660cf9b358829d3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>setArgs</name>
      <anchorfile>classel_1_1_helpers.html</anchorfile>
      <anchor>a68748f618a0c2840b96dc12532b09bf0</anchor>
      <arglist>(int argc, char **argv)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>setArgs</name>
      <anchorfile>classel_1_1_helpers.html</anchorfile>
      <anchor>afac7a023e2c13a62d0295cf0239eb848</anchor>
      <arglist>(int argc, const char **argv)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>setCrashHandler</name>
      <anchorfile>classel_1_1_helpers.html</anchorfile>
      <anchor>a4155f6fff0074ad93aa56fd7fe064097</anchor>
      <arglist>(const el::base::debug::CrashHandler::Handler &amp;crashHandler)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>crashAbort</name>
      <anchorfile>classel_1_1_helpers.html</anchorfile>
      <anchor>a6e16f0e07ce40e0659fcfec4ea5b6fe1</anchor>
      <arglist>(int sig, const char *sourceFile=&quot;&quot;, unsigned int long line=0)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logCrashReason</name>
      <anchorfile>classel_1_1_helpers.html</anchorfile>
      <anchor>abf1ae61428740e1e6c5d5f0c36500faa</anchor>
      <arglist>(int sig, bool stackTraceIfAvailable=false, Level level=Level::Fatal, const char *logger=base::consts::kDefaultLoggerId)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>installPreRollOutCallback</name>
      <anchorfile>classel_1_1_helpers.html</anchorfile>
      <anchor>a5fd7ad6d636c28d2e706203d0c43cf8c</anchor>
      <arglist>(const PreRollOutCallback &amp;callback)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>uninstallPreRollOutCallback</name>
      <anchorfile>classel_1_1_helpers.html</anchorfile>
      <anchor>ab829e5ed1b43bf965f5c288bc0280376</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>installLogDispatchCallback</name>
      <anchorfile>classel_1_1_helpers.html</anchorfile>
      <anchor>a3f3e84057567a8ac568a35899318544a</anchor>
      <arglist>(const std::string &amp;id)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>uninstallLogDispatchCallback</name>
      <anchorfile>classel_1_1_helpers.html</anchorfile>
      <anchor>ac94b44cc8d399a5842703126478300d7</anchor>
      <arglist>(const std::string &amp;id)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>installPerformanceTrackingCallback</name>
      <anchorfile>classel_1_1_helpers.html</anchorfile>
      <anchor>a93e2727d3a7a5c06ccc41a2ae7fe1835</anchor>
      <arglist>(const std::string &amp;id)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>uninstallPerformanceTrackingCallback</name>
      <anchorfile>classel_1_1_helpers.html</anchorfile>
      <anchor>af1c5a4951991179dca4879ba05fb67a6</anchor>
      <arglist>(const std::string &amp;id)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::string</type>
      <name>convertTemplateToStdString</name>
      <anchorfile>classel_1_1_helpers.html</anchorfile>
      <anchor>a8b032e32cd042ddc4fef4e814bad1082</anchor>
      <arglist>(const T &amp;templ)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static const el::base::utils::CommandLineArgs *</type>
      <name>commandLineArgs</name>
      <anchorfile>classel_1_1_helpers.html</anchorfile>
      <anchor>a83bab44f77a4961f8f5231e7ce9917bb</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>installCustomFormatSpecifier</name>
      <anchorfile>classel_1_1_helpers.html</anchorfile>
      <anchor>aa6de15a09db4f2a6763a6652c0ea12b1</anchor>
      <arglist>(const CustomFormatSpecifier &amp;customFormatSpecifier)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>uninstallCustomFormatSpecifier</name>
      <anchorfile>classel_1_1_helpers.html</anchorfile>
      <anchor>a23ec73819c25758d604d149ad0c6b73f</anchor>
      <arglist>(const char *formatSpecifier)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>hasCustomFormatSpecifier</name>
      <anchorfile>classel_1_1_helpers.html</anchorfile>
      <anchor>a154ce041890564d1ae5f87184e24f13d</anchor>
      <arglist>(const char *formatSpecifier)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>el::base::HitCounter</name>
    <filename>classel_1_1base_1_1_hit_counter.html</filename>
    <class kind="class">el::base::HitCounter::Predicate</class>
    <member kind="function">
      <type>void</type>
      <name>resetLocation</name>
      <anchorfile>classel_1_1base_1_1_hit_counter.html</anchorfile>
      <anchor>af58479cb66b71a76a3f8fd26193bfde1</anchor>
      <arglist>(const char *filename, unsigned long int lineNumber)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>validateHitCounts</name>
      <anchorfile>classel_1_1base_1_1_hit_counter.html</anchorfile>
      <anchor>a04dcca0a3f1b1f9a0ef8d812f00cecf0</anchor>
      <arglist>(std::size_t n)</arglist>
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
    <name>el::LevelHelper</name>
    <filename>classel_1_1_level_helper.html</filename>
    <base protection="private">el::base::StaticClass</base>
    <member kind="function" static="yes">
      <type>static base::type::EnumType</type>
      <name>castToInt</name>
      <anchorfile>classel_1_1_level_helper.html</anchorfile>
      <anchor>a6576fd7cd6d1d839952145115c6e4b38</anchor>
      <arglist>(Level level)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Level</type>
      <name>castFromInt</name>
      <anchorfile>classel_1_1_level_helper.html</anchorfile>
      <anchor>a1279f27df29a003df5ecc3d0bf4dacbb</anchor>
      <arglist>(base::type::EnumType l)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static const char *</type>
      <name>convertToString</name>
      <anchorfile>classel_1_1_level_helper.html</anchorfile>
      <anchor>a53b3e226a09af6e87c2072c115b3ba1a</anchor>
      <arglist>(Level level)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Level</type>
      <name>convertFromString</name>
      <anchorfile>classel_1_1_level_helper.html</anchorfile>
      <anchor>a4ff401c62931609c849d580fb6ad2028</anchor>
      <arglist>(const char *levelStr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>forEachLevel</name>
      <anchorfile>classel_1_1_level_helper.html</anchorfile>
      <anchor>a94449b79778145f4c58fd1da6bcaf45d</anchor>
      <arglist>(base::type::EnumType *startIndex, const std::function&lt; bool(void)&gt; &amp;fn)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const base::type::EnumType</type>
      <name>kMinValid</name>
      <anchorfile>classel_1_1_level_helper.html</anchorfile>
      <anchor>a3ecfe43d5b242e9946bad7f61ea4d89d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const base::type::EnumType</type>
      <name>kMaxValid</name>
      <anchorfile>classel_1_1_level_helper.html</anchorfile>
      <anchor>aa06e80c65db5c336c4aad25872cf9a48</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>el::LogBuilder</name>
    <filename>classel_1_1_log_builder.html</filename>
    <base protection="private">el::base::NoCopy</base>
  </compound>
  <compound kind="class">
    <name>el::LogDispatchCallback</name>
    <filename>classel_1_1_log_dispatch_callback.html</filename>
    <base>Callback&lt; LogDispatchData &gt;</base>
  </compound>
  <compound kind="class">
    <name>el::LogDispatchData</name>
    <filename>classel_1_1_log_dispatch_data.html</filename>
  </compound>
  <compound kind="class">
    <name>el::base::LogDispatcher</name>
    <filename>classel_1_1base_1_1_log_dispatcher.html</filename>
    <base protection="private">el::base::NoCopy</base>
  </compound>
  <compound kind="class">
    <name>el::base::LogFormat</name>
    <filename>classel_1_1base_1_1_log_format.html</filename>
    <base>el::Loggable</base>
    <member kind="function">
      <type>void</type>
      <name>parseFromFormat</name>
      <anchorfile>classel_1_1base_1_1_log_format.html</anchorfile>
      <anchor>ab7c1b15cfdad24cfbc6dbced8b9d66eb</anchor>
      <arglist>(const base::type::string_t &amp;userFormat)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>updateDateFormat</name>
      <anchorfile>classel_1_1base_1_1_log_format.html</anchorfile>
      <anchor>a3146651eadd6b1164bde74e5b273ec94</anchor>
      <arglist>(std::size_t index, base::type::string_t &amp;currFormat) ELPP_FINAL</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>updateFormatSpec</name>
      <anchorfile>classel_1_1base_1_1_log_format.html</anchorfile>
      <anchor>afee2335cce2b627dfd7f918d5a2b85f3</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>el::Loggable</name>
    <filename>classel_1_1_loggable.html</filename>
  </compound>
  <compound kind="class">
    <name>el::Logger</name>
    <filename>classel_1_1_logger.html</filename>
    <base>el::base::threading::ThreadSafe</base>
    <base>el::Loggable</base>
    <member kind="function">
      <type>void</type>
      <name>configure</name>
      <anchorfile>classel_1_1_logger.html</anchorfile>
      <anchor>ad9db621dbf8977bf814dc7baea8dcee4</anchor>
      <arglist>(const Configurations &amp;configurations)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reconfigure</name>
      <anchorfile>classel_1_1_logger.html</anchorfile>
      <anchor>adfd57ab27fb398cc980a3edfab92927e</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>flush</name>
      <anchorfile>classel_1_1_logger.html</anchorfile>
      <anchor>a9a89d454008b1ee1a197eec4b92ce22a</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>el::Loggers</name>
    <filename>classel_1_1_loggers.html</filename>
    <base protection="private">el::base::StaticClass</base>
    <class kind="class">el::Loggers::ScopedAddFlag</class>
    <class kind="class">el::Loggers::ScopedRemoveFlag</class>
    <member kind="function" static="yes">
      <type>static Logger *</type>
      <name>getLogger</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>aaebf868c558e3ba1d2e4f073a00f1d4a</anchor>
      <arglist>(const std::string &amp;identity, bool registerIfNotAvailable=true)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>unregisterLogger</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>a201d261ea57c070f07f0bf2006158587</anchor>
      <arglist>(const std::string &amp;identity)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>hasLogger</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>a2d7a056cb7d9da3d96c709a2fac5c2bb</anchor>
      <arglist>(const std::string &amp;identity)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Logger *</type>
      <name>reconfigureLogger</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>a888aca5bdccccc322da2eed430909d04</anchor>
      <arglist>(Logger *logger, const Configurations &amp;configurations)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Logger *</type>
      <name>reconfigureLogger</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>a105f776fe19cb7fa2fccd2993d9f7a7c</anchor>
      <arglist>(const std::string &amp;identity, const Configurations &amp;configurations)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Logger *</type>
      <name>reconfigureLogger</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>aef49fdae329cefcc1c01428568dced4b</anchor>
      <arglist>(const std::string &amp;identity, ConfigurationType configurationType, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>reconfigureAllLoggers</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>ac834df0f5e9e3dab18e70321a2543af7</anchor>
      <arglist>(const Configurations &amp;configurations)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>reconfigureAllLoggers</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>a1ebd33bc0208b430f41508e34509c7c9</anchor>
      <arglist>(ConfigurationType configurationType, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>reconfigureAllLoggers</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>ab24b99e5bb3c907d1418ee3266f15397</anchor>
      <arglist>(Level level, ConfigurationType configurationType, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>setDefaultConfigurations</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>ab9fb62a8ff904ff887fefde3282f46a4</anchor>
      <arglist>(const Configurations &amp;configurations, bool reconfigureExistingLoggers=false)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static const Configurations *</type>
      <name>defaultConfigurations</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>a96f2336fafdc3ef2c4df01a73ae5ffb7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static const base::LogStreamsReferenceMap *</type>
      <name>logStreamsReference</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>ad17312c9474d94bc98efcaf08ca279a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static base::TypedConfigurations</type>
      <name>defaultTypedConfigurations</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>af296007c3eb3b71602ec80ff59875b46</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::vector&lt; std::string &gt; *</type>
      <name>populateAllLoggerIds</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>adea07ec6cbc1dfc50f939d69dcac7160</anchor>
      <arglist>(std::vector&lt; std::string &gt; *targetList)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>configureFromGlobal</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>a9992995a85745639aa9aa5a2df2255f5</anchor>
      <arglist>(const char *globalConfigurationFilePath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>configureFromArg</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>a28acf6f2b1ea7e5edd1b2560cde82406</anchor>
      <arglist>(const char *argKey)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>flushAll</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>a1834480e970c16817459ca3ee26b44b5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>addFlag</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>aedd2de02dd701b0f20ddaa10f1f728f1</anchor>
      <arglist>(LoggingFlag flag)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>removeFlag</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>a23fcb4b492f70a34285c45c0b5e2e515</anchor>
      <arglist>(LoggingFlag flag)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>hasFlag</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>a591a45565c1eb7073ec3a979df8b5a4c</anchor>
      <arglist>(LoggingFlag flag)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>setLoggingLevel</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>afbee019d722fef5148d8355f45ba7993</anchor>
      <arglist>(Level level)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>setVerboseLevel</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>a826b238fe4f3719305a2d19f0c121fa0</anchor>
      <arglist>(base::type::VerboseLevel level)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static base::type::VerboseLevel</type>
      <name>verboseLevel</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>ad4840bb4b6b80746a2212cf3cc058142</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>setVModules</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>acbc5e2cef230331c57f364852a671507</anchor>
      <arglist>(const char *modules)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>clearVModules</name>
      <anchorfile>classel_1_1_loggers.html</anchorfile>
      <anchor>afcf50abc11530eb7f28fcab7eab27e4f</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>el::LogMessage</name>
    <filename>classel_1_1_log_message.html</filename>
  </compound>
  <compound kind="class">
    <name>el::base::MessageBuilder</name>
    <filename>classel_1_1base_1_1_message_builder.html</filename>
  </compound>
  <compound kind="class">
    <name>el::base::MillisecondsWidth</name>
    <filename>classel_1_1base_1_1_milliseconds_width.html</filename>
  </compound>
  <compound kind="class">
    <name>el::base::NoCopy</name>
    <filename>classel_1_1base_1_1_no_copy.html</filename>
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
    <name>el::base::threading::internal::NoMutex</name>
    <filename>classel_1_1base_1_1threading_1_1internal_1_1_no_mutex.html</filename>
    <base protection="private">el::base::NoCopy</base>
  </compound>
  <compound kind="class">
    <name>el::base::threading::internal::NoScopedLock</name>
    <filename>classel_1_1base_1_1threading_1_1internal_1_1_no_scoped_lock.html</filename>
    <templarg></templarg>
    <base protection="private">el::base::NoCopy</base>
  </compound>
  <compound kind="class">
    <name>el::base::NullWriter</name>
    <filename>classel_1_1base_1_1_null_writer.html</filename>
    <base protection="private">el::base::NoCopy</base>
  </compound>
  <compound kind="class">
    <name>el::base::utils::OS</name>
    <filename>classel_1_1base_1_1utils_1_1_o_s.html</filename>
    <base protection="private">el::base::StaticClass</base>
    <member kind="function" static="yes">
      <type>static const std::string</type>
      <name>getBashOutput</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_o_s.html</anchorfile>
      <anchor>a91304c76c872459eaa9fdb3466367cd3</anchor>
      <arglist>(const char *command)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::string</type>
      <name>getEnvironmentVariable</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_o_s.html</anchorfile>
      <anchor>a91540f3d8c87bd121e55fc39270eac3c</anchor>
      <arglist>(const char *variableName, const char *defaultVal, const char *alternativeBashCommand=nullptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::string</type>
      <name>currentUser</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_o_s.html</anchorfile>
      <anchor>ac7839ecd50e379dbdfcfce130906386e</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::string</type>
      <name>currentHost</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_o_s.html</anchorfile>
      <anchor>aae4fdf83828228fc440f8a875c5942b0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>termSupportsColor</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_o_s.html</anchorfile>
      <anchor>a2c941329a14ce0ea920f57779857864c</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>el::Configurations::Parser</name>
    <filename>classel_1_1_configurations_1_1_parser.html</filename>
    <base protection="private">el::base::StaticClass</base>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>parseFromFile</name>
      <anchorfile>classel_1_1_configurations_1_1_parser.html</anchorfile>
      <anchor>a45def5007bf368c4d2a505af58cd94c2</anchor>
      <arglist>(const std::string &amp;configurationFile, Configurations *sender, Configurations *base=nullptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>parseFromText</name>
      <anchorfile>classel_1_1_configurations_1_1_parser.html</anchorfile>
      <anchor>a39ec1b06f673e8155a83d66e08229129</anchor>
      <arglist>(const std::string &amp;configurationsString, Configurations *sender, Configurations *base=nullptr)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>el::base::PerformanceTracker</name>
    <filename>classel_1_1base_1_1_performance_tracker.html</filename>
    <base>el::base::threading::ThreadSafe</base>
    <base>el::Loggable</base>
    <member kind="function">
      <type></type>
      <name>PerformanceTracker</name>
      <anchorfile>classel_1_1base_1_1_performance_tracker.html</anchorfile>
      <anchor>a49e655c1f414f904b2d6a9abb0d344f4</anchor>
      <arglist>(const PerformanceTracker &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>checkpoint</name>
      <anchorfile>classel_1_1base_1_1_performance_tracker.html</anchorfile>
      <anchor>aec9a6e149674c5782cc855e49aeb0aaf</anchor>
      <arglist>(const std::string &amp;id=std::string(), const char *file=__FILE__, unsigned long int line=__LINE__, const char *func=&quot;&quot;)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>el::PerformanceTrackingCallback</name>
    <filename>classel_1_1_performance_tracking_callback.html</filename>
    <base>Callback&lt; PerformanceTrackingData &gt;</base>
  </compound>
  <compound kind="class">
    <name>el::PerformanceTrackingData</name>
    <filename>classel_1_1_performance_tracking_data.html</filename>
  </compound>
  <compound kind="class">
    <name>el::base::PErrorWriter</name>
    <filename>classel_1_1base_1_1_p_error_writer.html</filename>
    <base>el::base::Writer</base>
  </compound>
  <compound kind="class">
    <name>el::Configuration::Predicate</name>
    <filename>classel_1_1_configuration_1_1_predicate.html</filename>
  </compound>
  <compound kind="class">
    <name>el::base::HitCounter::Predicate</name>
    <filename>classel_1_1base_1_1_hit_counter_1_1_predicate.html</filename>
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
    <name>el::base::RegisteredHitCounters</name>
    <filename>classel_1_1base_1_1_registered_hit_counters.html</filename>
    <base>RegistryWithPred&lt; base::HitCounter, base::HitCounter::Predicate &gt;</base>
    <member kind="function">
      <type>bool</type>
      <name>validateEveryN</name>
      <anchorfile>classel_1_1base_1_1_registered_hit_counters.html</anchorfile>
      <anchor>a18fecedc6be778cfd63e30cc42fb9c82</anchor>
      <arglist>(const char *filename, unsigned long int lineNumber, std::size_t n)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>validateAfterN</name>
      <anchorfile>classel_1_1base_1_1_registered_hit_counters.html</anchorfile>
      <anchor>af6fa32ffd76776863d8bd2f0e9b341fc</anchor>
      <arglist>(const char *filename, unsigned long int lineNumber, std::size_t n)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>validateNTimes</name>
      <anchorfile>classel_1_1base_1_1_registered_hit_counters.html</anchorfile>
      <anchor>aa270c1b9a8cc3a4d12cea45e07560d98</anchor>
      <arglist>(const char *filename, unsigned long int lineNumber, std::size_t n)</arglist>
    </member>
    <member kind="function">
      <type>const base::HitCounter *</type>
      <name>getCounter</name>
      <anchorfile>classel_1_1base_1_1_registered_hit_counters.html</anchorfile>
      <anchor>a0ca8cd04da5686048644e8cc1533b561</anchor>
      <arglist>(const char *filename, unsigned long int lineNumber)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>el::base::RegisteredLoggers</name>
    <filename>classel_1_1base_1_1_registered_loggers.html</filename>
    <base>Registry&lt; Logger, std::string &gt;</base>
  </compound>
  <compound kind="class">
    <name>el::base::utils::Registry</name>
    <filename>classel_1_1base_1_1utils_1_1_registry.html</filename>
    <templarg>T_Ptr</templarg>
    <templarg>T_Key</templarg>
    <base>AbstractRegistry&lt; T_Ptr, std::map&lt; T_Key, T_Ptr * &gt; &gt;</base>
    <member kind="function">
      <type></type>
      <name>Registry</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry.html</anchorfile>
      <anchor>adf5e97aa801be3b93e116ad645304759</anchor>
      <arglist>(const Registry &amp;sr)</arglist>
    </member>
    <member kind="function">
      <type>Registry &amp;</type>
      <name>operator=</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry.html</anchorfile>
      <anchor>a80e0ce12b7d0c24462b385fc7b3149e0</anchor>
      <arglist>(const Registry &amp;sr)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>unregisterAll</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry.html</anchorfile>
      <anchor>ac40e62ddf5017beb91c28b472c9628c2</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>registerNew</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry.html</anchorfile>
      <anchor>ab10b3dd25ff0df036e7a015635a15dee</anchor>
      <arglist>(const T_Key &amp;uniqKey, T_Ptr *ptr) ELPP_FINAL</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>unregister</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry.html</anchorfile>
      <anchor>aab6f0ce3a99feff11add0bd8b869fcb8</anchor>
      <arglist>(const T_Key &amp;uniqKey)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>T_Ptr *</type>
      <name>get</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry.html</anchorfile>
      <anchor>a18c332267f2acbe78c97a611dec2e5c2</anchor>
      <arglist>(const T_Key &amp;uniqKey)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Registry&lt; Logger, std::string &gt;</name>
    <filename>classel_1_1base_1_1utils_1_1_registry.html</filename>
    <base>AbstractRegistry&lt; Logger, std::map&lt; std::string, Logger * &gt; &gt;</base>
    <member kind="function">
      <type></type>
      <name>Registry</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry.html</anchorfile>
      <anchor>adf5e97aa801be3b93e116ad645304759</anchor>
      <arglist>(const Registry &amp;sr)</arglist>
    </member>
    <member kind="function">
      <type>Registry &amp;</type>
      <name>operator=</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry.html</anchorfile>
      <anchor>a80e0ce12b7d0c24462b385fc7b3149e0</anchor>
      <arglist>(const Registry &amp;sr)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>unregisterAll</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry.html</anchorfile>
      <anchor>ac40e62ddf5017beb91c28b472c9628c2</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>registerNew</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry.html</anchorfile>
      <anchor>ab10b3dd25ff0df036e7a015635a15dee</anchor>
      <arglist>(const std::string &amp;uniqKey, Logger *ptr) ELPP_FINAL</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>unregister</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry.html</anchorfile>
      <anchor>aab6f0ce3a99feff11add0bd8b869fcb8</anchor>
      <arglist>(const std::string &amp;uniqKey)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>Logger *</type>
      <name>get</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry.html</anchorfile>
      <anchor>a18c332267f2acbe78c97a611dec2e5c2</anchor>
      <arglist>(const std::string &amp;uniqKey)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>el::base::utils::RegistryWithPred</name>
    <filename>classel_1_1base_1_1utils_1_1_registry_with_pred.html</filename>
    <templarg>T_Ptr</templarg>
    <templarg>Pred</templarg>
    <base>AbstractRegistry&lt; T_Ptr, std::vector&lt; T_Ptr * &gt; &gt;</base>
    <member kind="function">
      <type></type>
      <name>RegistryWithPred</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry_with_pred.html</anchorfile>
      <anchor>a0e75c7daaa5fbf824b29180c7a5fd155</anchor>
      <arglist>(const RegistryWithPred &amp;sr)</arglist>
    </member>
    <member kind="function">
      <type>RegistryWithPred &amp;</type>
      <name>operator=</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry_with_pred.html</anchorfile>
      <anchor>adb7e568c8cb084589467b937eab86b86</anchor>
      <arglist>(const RegistryWithPred &amp;sr)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>unregisterAll</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry_with_pred.html</anchorfile>
      <anchor>a66b4eca5bb71f3fa3f0737105a00890c</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>T_Ptr *</type>
      <name>get</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry_with_pred.html</anchorfile>
      <anchor>a811d9cc011d945bc7237e6ae1cf2f096</anchor>
      <arglist>(const T &amp;arg1, const T2 arg2)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RegistryWithPred&lt; base::HitCounter, base::HitCounter::Predicate &gt;</name>
    <filename>classel_1_1base_1_1utils_1_1_registry_with_pred.html</filename>
    <base>AbstractRegistry&lt; base::HitCounter, std::vector&lt; base::HitCounter * &gt; &gt;</base>
    <member kind="function">
      <type></type>
      <name>RegistryWithPred</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry_with_pred.html</anchorfile>
      <anchor>a0e75c7daaa5fbf824b29180c7a5fd155</anchor>
      <arglist>(const RegistryWithPred &amp;sr)</arglist>
    </member>
    <member kind="function">
      <type>RegistryWithPred &amp;</type>
      <name>operator=</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry_with_pred.html</anchorfile>
      <anchor>adb7e568c8cb084589467b937eab86b86</anchor>
      <arglist>(const RegistryWithPred &amp;sr)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>unregisterAll</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry_with_pred.html</anchorfile>
      <anchor>a66b4eca5bb71f3fa3f0737105a00890c</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>base::HitCounter *</type>
      <name>get</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry_with_pred.html</anchorfile>
      <anchor>a811d9cc011d945bc7237e6ae1cf2f096</anchor>
      <arglist>(const T &amp;arg1, const T2 arg2)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RegistryWithPred&lt; Configuration, Configuration::Predicate &gt;</name>
    <filename>classel_1_1base_1_1utils_1_1_registry_with_pred.html</filename>
    <base>AbstractRegistry&lt; Configuration, std::vector&lt; Configuration * &gt; &gt;</base>
    <member kind="function">
      <type></type>
      <name>RegistryWithPred</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry_with_pred.html</anchorfile>
      <anchor>a0e75c7daaa5fbf824b29180c7a5fd155</anchor>
      <arglist>(const RegistryWithPred &amp;sr)</arglist>
    </member>
    <member kind="function">
      <type>RegistryWithPred &amp;</type>
      <name>operator=</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry_with_pred.html</anchorfile>
      <anchor>adb7e568c8cb084589467b937eab86b86</anchor>
      <arglist>(const RegistryWithPred &amp;sr)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>unregisterAll</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry_with_pred.html</anchorfile>
      <anchor>a66b4eca5bb71f3fa3f0737105a00890c</anchor>
      <arglist>(void) ELPP_FINAL</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>Configuration *</type>
      <name>get</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_registry_with_pred.html</anchorfile>
      <anchor>a811d9cc011d945bc7237e6ae1cf2f096</anchor>
      <arglist>(const T &amp;arg1, const T2 arg2)</arglist>
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
    <name>el::Loggers::ScopedAddFlag</name>
    <filename>classel_1_1_loggers_1_1_scoped_add_flag.html</filename>
  </compound>
  <compound kind="class">
    <name>el::Loggers::ScopedRemoveFlag</name>
    <filename>classel_1_1_loggers_1_1_scoped_remove_flag.html</filename>
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
      <type>TextDocumentContent *</type>
      <name>getPayload</name>
      <anchorfile>classmlclient_1_1_search_description.html</anchorfile>
      <anchor>a9d90076a68721477ce84c72143d57424</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>el::base::debug::StackTrace</name>
    <filename>classel_1_1base_1_1debug_1_1_stack_trace.html</filename>
    <base protection="private">el::base::NoCopy</base>
    <class kind="class">el::base::debug::StackTrace::StackTraceEntry</class>
  </compound>
  <compound kind="class">
    <name>el::base::debug::StackTrace::StackTraceEntry</name>
    <filename>classel_1_1base_1_1debug_1_1_stack_trace_1_1_stack_trace_entry.html</filename>
  </compound>
  <compound kind="class">
    <name>el::base::StaticClass</name>
    <filename>classel_1_1base_1_1_static_class.html</filename>
  </compound>
  <compound kind="class">
    <name>el::base::Storage</name>
    <filename>classel_1_1base_1_1_storage.html</filename>
    <base protection="private">el::base::NoCopy</base>
    <base>el::base::threading::ThreadSafe</base>
  </compound>
  <compound kind="class">
    <name>el::base::utils::Str</name>
    <filename>classel_1_1base_1_1utils_1_1_str.html</filename>
    <base protection="private">el::base::StaticClass</base>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>isDigit</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_str.html</anchorfile>
      <anchor>a4caae91dfe0310d9f182bd9b7e99103c</anchor>
      <arglist>(char c)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>wildCardMatch</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_str.html</anchorfile>
      <anchor>a95e007a25dfcbd77d4c573b0f73b3153</anchor>
      <arglist>(const char *str, const char *pattern)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::string &amp;</type>
      <name>ltrim</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_str.html</anchorfile>
      <anchor>a64b7a841f04ed916ed8d234b8508703e</anchor>
      <arglist>(std::string &amp;str)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::string &amp;</type>
      <name>rtrim</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_str.html</anchorfile>
      <anchor>a9202797763e10861c4fa84ffd40198bb</anchor>
      <arglist>(std::string &amp;str)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::string &amp;</type>
      <name>trim</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_str.html</anchorfile>
      <anchor>aba0bc132c410fd3c1e128d1038e996ba</anchor>
      <arglist>(std::string &amp;str)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>startsWith</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_str.html</anchorfile>
      <anchor>acf80221cec72da701ef50995a61ab91f</anchor>
      <arglist>(const std::string &amp;str, const std::string &amp;start)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>endsWith</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_str.html</anchorfile>
      <anchor>a5bcf5f6cc41a7ed683be115148579561</anchor>
      <arglist>(const std::string &amp;str, const std::string &amp;end)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::string &amp;</type>
      <name>replaceAll</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_str.html</anchorfile>
      <anchor>aa07bfda259ed194120b371401734ae86</anchor>
      <arglist>(std::string &amp;str, char replaceWhat, char replaceWith)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::string &amp;</type>
      <name>replaceAll</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_str.html</anchorfile>
      <anchor>a8e823aa60b160451ca0b8732c3c75568</anchor>
      <arglist>(std::string &amp;str, const std::string &amp;replaceWhat, const std::string &amp;replaceWith)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::string &amp;</type>
      <name>toUpper</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_str.html</anchorfile>
      <anchor>a6a05315fb967508dc1faf0584421a95d</anchor>
      <arglist>(std::string &amp;str)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>cStringEq</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_str.html</anchorfile>
      <anchor>a8081458c7848ff991d765c69f7858c44</anchor>
      <arglist>(const char *s1, const char *s2)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>cStringCaseEq</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_str.html</anchorfile>
      <anchor>aaa37755d713b5e6475950134ce9ce0e8</anchor>
      <arglist>(const char *s1, const char *s2)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>contains</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_str.html</anchorfile>
      <anchor>a27cc1c1625b21597eb75df62b8fca0f8</anchor>
      <arglist>(const char *str, char c)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static char *</type>
      <name>wcharPtrToCharPtr</name>
      <anchorfile>classel_1_1base_1_1utils_1_1_str.html</anchorfile>
      <anchor>a6dc022e7e8d4cbf2c80ba9e1354feaea</anchor>
      <arglist>(const wchar_t *line)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>el::SysLogInitializer</name>
    <filename>classel_1_1_sys_log_initializer.html</filename>
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
  <compound kind="class">
    <name>el::base::threading::ThreadSafe</name>
    <filename>classel_1_1base_1_1threading_1_1_thread_safe.html</filename>
  </compound>
  <compound kind="class">
    <name>el::base::TypedConfigurations</name>
    <filename>classel_1_1base_1_1_typed_configurations.html</filename>
    <base>el::base::threading::ThreadSafe</base>
    <member kind="function">
      <type></type>
      <name>TypedConfigurations</name>
      <anchorfile>classel_1_1base_1_1_typed_configurations.html</anchorfile>
      <anchor>a1b6d90479bb79da27c3e351a9be593ae</anchor>
      <arglist>(Configurations *configurations, base::LogStreamsReferenceMap *logStreamsReference)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>el::VersionInfo</name>
    <filename>classel_1_1_version_info.html</filename>
    <base protection="private">el::base::StaticClass</base>
    <member kind="function" static="yes">
      <type>static const std::string</type>
      <name>version</name>
      <anchorfile>classel_1_1_version_info.html</anchorfile>
      <anchor>a6fee512d52168445b2118ff2b31b4058</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static const std::string</type>
      <name>releaseDate</name>
      <anchorfile>classel_1_1_version_info.html</anchorfile>
      <anchor>ab23c2545115898f4071fa4e125204946</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>el::base::VRegistry</name>
    <filename>classel_1_1base_1_1_v_registry.html</filename>
    <base protection="private">el::base::NoCopy</base>
    <base>el::base::threading::ThreadSafe</base>
    <member kind="function">
      <type>void</type>
      <name>setLevel</name>
      <anchorfile>classel_1_1base_1_1_v_registry.html</anchorfile>
      <anchor>aea4fb84a03363080ee2501193084f71f</anchor>
      <arglist>(base::type::VerboseLevel level)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>vModulesEnabled</name>
      <anchorfile>classel_1_1base_1_1_v_registry.html</anchorfile>
      <anchor>ad7a8e939daf6b3d6b949def0a9f65a1f</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>el::base::Writer</name>
    <filename>classel_1_1base_1_1_writer.html</filename>
    <base protection="private">el::base::NoCopy</base>
  </compound>
  <compound kind="namespace">
    <name>el</name>
    <filename>namespaceel.html</filename>
    <namespace>el::base</namespace>
    <class kind="class">el::Callback</class>
    <class kind="class">el::Configuration</class>
    <class kind="class">el::Configurations</class>
    <class kind="class">el::ConfigurationTypeHelper</class>
    <class kind="class">el::CustomFormatSpecifier</class>
    <class kind="class">el::Helpers</class>
    <class kind="class">el::LevelHelper</class>
    <class kind="class">el::LogBuilder</class>
    <class kind="class">el::LogDispatchCallback</class>
    <class kind="class">el::LogDispatchData</class>
    <class kind="class">el::Loggable</class>
    <class kind="class">el::Logger</class>
    <class kind="class">el::Loggers</class>
    <class kind="class">el::LogMessage</class>
    <class kind="class">el::PerformanceTrackingCallback</class>
    <class kind="class">el::PerformanceTrackingData</class>
    <class kind="class">el::SysLogInitializer</class>
    <class kind="class">el::VersionInfo</class>
    <member kind="typedef">
      <type>std::function&lt; const char *(void)&gt;</type>
      <name>FormatSpecifierValueResolver</name>
      <anchorfile>namespaceel.html</anchorfile>
      <anchor>ab3cd18425a11df166a041d9024b8b5c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>Level</name>
      <anchorfile>namespaceel.html</anchorfile>
      <anchor>ab0ac6091262344c52dd2d3ad099e8e36</anchor>
      <arglist></arglist>
      <enumvalue file="namespaceel.html" anchor="ab0ac6091262344c52dd2d3ad099e8e36a4cc6684df7b4a92b1dec6fce3264fac8">Global</enumvalue>
      <enumvalue file="namespaceel.html" anchor="ab0ac6091262344c52dd2d3ad099e8e36add4ec0ac4e58f7c32a01244ae91150b1">Trace</enumvalue>
      <enumvalue file="namespaceel.html" anchor="ab0ac6091262344c52dd2d3ad099e8e36aa603905470e2a5b8c13e96b579ef0dba">Debug</enumvalue>
      <enumvalue file="namespaceel.html" anchor="ab0ac6091262344c52dd2d3ad099e8e36a882384ec38ce8d9582b57e70861730e4">Fatal</enumvalue>
      <enumvalue file="namespaceel.html" anchor="ab0ac6091262344c52dd2d3ad099e8e36a902b0d55fddef6f8d651fe1035b7d4bd">Error</enumvalue>
      <enumvalue file="namespaceel.html" anchor="ab0ac6091262344c52dd2d3ad099e8e36a0eaadb4fcb48a0a0ed7bc9868be9fbaa">Warning</enumvalue>
      <enumvalue file="namespaceel.html" anchor="ab0ac6091262344c52dd2d3ad099e8e36ad4a9fa383ab700c5bdd6f31cf7df0faf">Verbose</enumvalue>
      <enumvalue file="namespaceel.html" anchor="ab0ac6091262344c52dd2d3ad099e8e36a4059b0251f66a18cb56f544728796875">Info</enumvalue>
      <enumvalue file="namespaceel.html" anchor="ab0ac6091262344c52dd2d3ad099e8e36a88183b946cc5f0e8c96b2e66e1c74a7e">Unknown</enumvalue>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>ConfigurationType</name>
      <anchorfile>namespaceel.html</anchorfile>
      <anchor>a281f5db6d6163678bc68a8b23b59e124</anchor>
      <arglist></arglist>
      <enumvalue file="namespaceel.html" anchor="a281f5db6d6163678bc68a8b23b59e124a00d23a76e43b46dae9ec7aa9dcbebb32">Enabled</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a281f5db6d6163678bc68a8b23b59e124acb76297988b895ca263f62728b32dbcc">ToFile</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a281f5db6d6163678bc68a8b23b59e124a9b9a9244b0b26da988f9af8310ab899d">ToStandardOutput</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a281f5db6d6163678bc68a8b23b59e124a520d0db389f362bf79ef56ca0af3dcab">Format</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a281f5db6d6163678bc68a8b23b59e124a1351017ac6423911223bc19a8cb7c653">Filename</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a281f5db6d6163678bc68a8b23b59e124a052bf0f0c813b3c41c5b5046ebc26529">MillisecondsWidth</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a281f5db6d6163678bc68a8b23b59e124abe9e43d200c5698cb8519daed7035874">PerformanceTracking</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a281f5db6d6163678bc68a8b23b59e124a4b35e615142d60db6383426f051e700b">MaxLogFileSize</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a281f5db6d6163678bc68a8b23b59e124ac1b4aae5c168e64292c9aa87a124ae86">LogFlushThreshold</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a281f5db6d6163678bc68a8b23b59e124a88183b946cc5f0e8c96b2e66e1c74a7e">Unknown</enumvalue>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>LoggingFlag</name>
      <anchorfile>namespaceel.html</anchorfile>
      <anchor>a2784aacd04cb7816ac1c0b20fcbf83cb</anchor>
      <arglist></arglist>
      <enumvalue file="namespaceel.html" anchor="a2784aacd04cb7816ac1c0b20fcbf83cba8246f93d9afd63f87632d2d718cabca8">NewLineForContainer</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a2784aacd04cb7816ac1c0b20fcbf83cbac80d746c4296fe8e99ed032f5ffef31e">AllowVerboseIfModuleNotSpecified</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a2784aacd04cb7816ac1c0b20fcbf83cba81ac37ef3ee37a01bf853be6abeb4ede">LogDetailedCrashReason</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a2784aacd04cb7816ac1c0b20fcbf83cba8dd9782f8a19cf7a41e4ec38d1c6a4ae">DisableApplicationAbortOnFatalLog</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a2784aacd04cb7816ac1c0b20fcbf83cba7817e369fa619155822043e76ef88c7c">ImmediateFlush</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a2784aacd04cb7816ac1c0b20fcbf83cba8496303f20ab09751ff3ec8802b187f5">StrictLogFileSizeCheck</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a2784aacd04cb7816ac1c0b20fcbf83cbaeececaef2fc38e4f3c91f9f6b6fb6d49">ColoredTerminalOutput</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a2784aacd04cb7816ac1c0b20fcbf83cbaa2ce18adf399149a1b75bdafa773617e">MultiLoggerSupport</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a2784aacd04cb7816ac1c0b20fcbf83cba18ea5964e8caa7c476dd5eee8e4f74a0">DisablePerformanceTrackingCheckpointComparison</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a2784aacd04cb7816ac1c0b20fcbf83cba22cae5066e8e0623cb90e20a18abb631">DisableVModules</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a2784aacd04cb7816ac1c0b20fcbf83cba18a8e65b84ca0cc82451b5e155d7aeb4">DisableVModulesExtensions</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a2784aacd04cb7816ac1c0b20fcbf83cba477de0500d7a5b64a4500d82811fc058">HierarchicalLogging</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a2784aacd04cb7816ac1c0b20fcbf83cba2afa5afe77105aadedcbb90dd8547cc3">CreateLoggerAutomatically</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a2784aacd04cb7816ac1c0b20fcbf83cba34620f140246d3c3b68c17fdf7b8ada7">AutoSpacing</enumvalue>
      <enumvalue file="namespaceel.html" anchor="a2784aacd04cb7816ac1c0b20fcbf83cbaebbb601e28e0cf821dfe13b4a7cf409e">FixedTimeFormat</enumvalue>
    </member>
  </compound>
  <compound kind="namespace">
    <name>el::base</name>
    <filename>namespaceel_1_1base.html</filename>
    <namespace>el::base::consts</namespace>
    <namespace>el::base::debug</namespace>
    <namespace>el::base::type</namespace>
    <namespace>el::base::utils</namespace>
    <class kind="class">el::base::DefaultLogBuilder</class>
    <class kind="class">el::base::DefaultLogDispatchCallback</class>
    <class kind="class">el::base::DefaultPerformanceTrackingCallback</class>
    <class kind="class">el::base::HitCounter</class>
    <class kind="class">el::base::LogDispatcher</class>
    <class kind="class">el::base::LogFormat</class>
    <class kind="class">el::base::MessageBuilder</class>
    <class kind="class">el::base::MillisecondsWidth</class>
    <class kind="class">el::base::NoCopy</class>
    <class kind="class">el::base::NullWriter</class>
    <class kind="class">el::base::PerformanceTracker</class>
    <class kind="class">el::base::PErrorWriter</class>
    <class kind="class">el::base::RegisteredHitCounters</class>
    <class kind="class">el::base::RegisteredLoggers</class>
    <class kind="class">el::base::StaticClass</class>
    <class kind="class">el::base::Storage</class>
    <class kind="class">el::base::TypedConfigurations</class>
    <class kind="class">el::base::VRegistry</class>
    <class kind="class">el::base::Writer</class>
    <member kind="enumeration">
      <type></type>
      <name>TimestampUnit</name>
      <anchorfile>namespaceel_1_1base.html</anchorfile>
      <anchor>a1b886858c6409097395b24b1bdf03c39</anchor>
      <arglist></arglist>
      <enumvalue file="namespaceel_1_1base.html" anchor="a1b886858c6409097395b24b1bdf03c39a1f14b3811ca5de688daa740d8471249e">Microsecond</enumvalue>
      <enumvalue file="namespaceel_1_1base.html" anchor="a1b886858c6409097395b24b1bdf03c39a988bbeeb80e7e0a6b4651aab5a76b413">Millisecond</enumvalue>
      <enumvalue file="namespaceel_1_1base.html" anchor="a1b886858c6409097395b24b1bdf03c39ac22cf8376b1893dcfcef0649fe1a7d87">Second</enumvalue>
      <enumvalue file="namespaceel_1_1base.html" anchor="a1b886858c6409097395b24b1bdf03c39a62902641c38f3a4a8eb3212454360e24">Minute</enumvalue>
      <enumvalue file="namespaceel_1_1base.html" anchor="a1b886858c6409097395b24b1bdf03c39ab55e509c697e4cca0e1d160a7806698f">Hour</enumvalue>
      <enumvalue file="namespaceel_1_1base.html" anchor="a1b886858c6409097395b24b1bdf03c39a03727ac48595a24daed975559c944a44">Day</enumvalue>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>FormatFlags</name>
      <anchorfile>namespaceel_1_1base.html</anchorfile>
      <anchor>a28939c5a884e67fcf12259f4b8848e00</anchor>
      <arglist></arglist>
      <enumvalue file="namespaceel_1_1base.html" anchor="a28939c5a884e67fcf12259f4b8848e00a8cf10d2341ed01492506085688270c1e">DateTime</enumvalue>
      <enumvalue file="namespaceel_1_1base.html" anchor="a28939c5a884e67fcf12259f4b8848e00a1bfb431e0c673464b7a57c135e5fe861">LoggerId</enumvalue>
      <enumvalue file="namespaceel_1_1base.html" anchor="a28939c5a884e67fcf12259f4b8848e00a0b27918290ff5323bea1e3b78a9cf04e">File</enumvalue>
      <enumvalue file="namespaceel_1_1base.html" anchor="a28939c5a884e67fcf12259f4b8848e00a4803e6b9e63dabf04de980788d6a13c4">Line</enumvalue>
      <enumvalue file="namespaceel_1_1base.html" anchor="a28939c5a884e67fcf12259f4b8848e00ace5bf551379459c1c61d2a204061c455">Location</enumvalue>
      <enumvalue file="namespaceel_1_1base.html" anchor="a28939c5a884e67fcf12259f4b8848e00a86408593c34af77fdd90df932f8b5261">Function</enumvalue>
      <enumvalue file="namespaceel_1_1base.html" anchor="a28939c5a884e67fcf12259f4b8848e00a8f9bfe9d1345237cb3b2b205864da075">User</enumvalue>
      <enumvalue file="namespaceel_1_1base.html" anchor="a28939c5a884e67fcf12259f4b8848e00ac2ca16d048ec66e04bca283eab048ec2">Host</enumvalue>
      <enumvalue file="namespaceel_1_1base.html" anchor="a28939c5a884e67fcf12259f4b8848e00a80672412fb77a287c9c90cbacf039fc7">LogMessage</enumvalue>
      <enumvalue file="namespaceel_1_1base.html" anchor="a28939c5a884e67fcf12259f4b8848e00a52e9b703699c35fb5be3d84511bc86b8">VerboseLevel</enumvalue>
      <enumvalue file="namespaceel_1_1base.html" anchor="a28939c5a884e67fcf12259f4b8848e00aa6d1acde6e20d49a9d81f90622732227">AppName</enumvalue>
      <enumvalue file="namespaceel_1_1base.html" anchor="a28939c5a884e67fcf12259f4b8848e00a693e7589872f7acd3e69d831d022d6ea">ThreadId</enumvalue>
      <enumvalue file="namespaceel_1_1base.html" anchor="a28939c5a884e67fcf12259f4b8848e00aa0db49ba470c1c9ae2128c3470339153">Level</enumvalue>
      <enumvalue file="namespaceel_1_1base.html" anchor="a28939c5a884e67fcf12259f4b8848e00a363d6c255447a7ca6ef9c06b73a8a87d">FileBase</enumvalue>
      <enumvalue file="namespaceel_1_1base.html" anchor="a28939c5a884e67fcf12259f4b8848e00a9d8794d3178b4df3b87654adbed5c846">LevelShort</enumvalue>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>DispatchAction</name>
      <anchorfile>namespaceel_1_1base.html</anchorfile>
      <anchor>a3aa2563d38e47388ba242a1694fc2839</anchor>
      <arglist></arglist>
      <enumvalue file="namespaceel_1_1base.html" anchor="a3aa2563d38e47388ba242a1694fc2839a6adf97f83acf6453d4a6a4b1070f3754">None</enumvalue>
      <enumvalue file="namespaceel_1_1base.html" anchor="a3aa2563d38e47388ba242a1694fc2839a44d8ee68145a7d9849eeaa634c443602">NormalLog</enumvalue>
      <enumvalue file="namespaceel_1_1base.html" anchor="a3aa2563d38e47388ba242a1694fc2839aa0861ec9150978a150dcefab74fad51b">SysLog</enumvalue>
    </member>
  </compound>
  <compound kind="namespace">
    <name>el::base::consts</name>
    <filename>namespaceel_1_1base_1_1consts.html</filename>
  </compound>
  <compound kind="namespace">
    <name>el::base::debug</name>
    <filename>namespaceel_1_1base_1_1debug.html</filename>
    <class kind="class">el::base::debug::CrashHandler</class>
    <class kind="class">el::base::debug::StackTrace</class>
  </compound>
  <compound kind="namespace">
    <name>el::base::type</name>
    <filename>namespaceel_1_1base_1_1type.html</filename>
  </compound>
  <compound kind="namespace">
    <name>el::base::utils</name>
    <filename>namespaceel_1_1base_1_1utils.html</filename>
    <namespace>el::base::utils::bitwise</namespace>
    <class kind="class">el::base::utils::AbstractRegistry</class>
    <class kind="class">el::base::utils::CommandLineArgs</class>
    <class kind="class">el::base::utils::DateTime</class>
    <class kind="class">el::base::utils::File</class>
    <class kind="class">el::base::utils::OS</class>
    <class kind="class">el::base::utils::Registry</class>
    <class kind="class">el::base::utils::RegistryWithPred</class>
    <class kind="class">el::base::utils::Str</class>
  </compound>
  <compound kind="namespace">
    <name>el::base::utils::bitwise</name>
    <filename>namespaceel_1_1base_1_1utils_1_1bitwise.html</filename>
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
      <type>int</type>
      <name>runOnce</name>
      <anchorfile>namespacemlclient.html</anchorfile>
      <anchor>a356e20b227d8082d513f38341d3ec997</anchor>
      <arglist>()</arglist>
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
