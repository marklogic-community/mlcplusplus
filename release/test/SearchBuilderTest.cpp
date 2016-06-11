/*
 * SearchBuilderTest.cpp
 *
 *  Created on: 09 Jun 2016
 *      Author: adamfowler
 */


#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include <string>
#include "ConnectionFactory.hpp"
#include "Connection.hpp"
#include "Response.hpp"
#include "DocumentContent.hpp"
#include "SearchDescription.hpp"
#include "NoCredentialsException.hpp"

#include "SearchBuilderTest.hpp"
#include "utilities/SearchBuilder.hpp"
#include "SearchResultSet.hpp"
#include "SearchResult.hpp"

#include "ext/easylogging++.h"

using namespace mlclient;
using namespace mlclient::utilities;

CPPUNIT_TEST_SUITE_REGISTRATION(SearchBuilderTest);

void SearchBuilderTest::setUp(void) {
  LOG(DEBUG) << "ENTERING TEST SUITE SearchBuilderTest";
  // set up connection
  ml = ConnectionFactory::getConnection();
}

void SearchBuilderTest::tearDown(void) {
  LOG(DEBUG) << "LEAVING TEST SUITE SearchBuilderTest";
  // delete all content
  ConnectionFactory::releaseConnection(ml);
  ml = NULL;
}

void SearchBuilderTest::testAll() {
  TIMED_FUNC(testAll);
  LOG(DEBUG) << " --------------------------------------------";
  LOG(DEBUG) << " Entering SearchBuilderTest::testAll";
  SearchDescription desc; // default empty search object
  GenericTextDocumentContent* tdcOptions = new GenericTextDocumentContent;
  tdcOptions->setContent("\"options\": {\"transform-results\": {\"apply\": \"raw\"}}");
  desc.setOptions(*tdcOptions);

  // construct search query
  SearchBuilder builder;
  /*
  builder.setQuery(
    SearchBuilder::andQuery(
      std::list<IQuery>{
        SearchBuilder::orQuery(
          std::list<IQuery>{
            SearchBuilder::collectionQuery(std::list<std::string>{"/some/col1"})
            ,
            SearchBuilder::collectionQuery(std::list<std::string>{"/some/col2"})
          }
        ),
        SearchBuilder::notQuery(
          std::list<IQuery>{
            SearchBuilder::documentQuery(std::list<std::string>{"/some/doc.json"})
          }
        )
      }
    )
  );
  */
  ITextDocumentContent& searchDoc = *builder.toDocument();
  desc.setQuery(searchDoc);
  LOG(DEBUG) << "  Got a SearchDescription object instance";

  SearchResultSet* results = new SearchResultSet(ml,desc);

  bool res = results->fetch();
  if (!res) {
    LOG(DEBUG) << "Exception report from fetch() attempt:-";
    LOG(DEBUG) << results->getFetchException()->what();
  }
  std::string blankString("");
  CPPUNIT_ASSERT_MESSAGE("Fetch operation did not succeed", res);

  // get results iterator
  int count = 0;
  for (auto& iter : *results) {
    LOG(DEBUG) << " Result " << count << ":-";
    LOG(DEBUG) << "  URI: " << iter.getUri();
    LOG(DEBUG) << "  Content: " << iter.getDetailContent();
    CPPUNIT_ASSERT_MESSAGE("Result does not have a URI",0!=blankString.compare(iter.getUri()));
    CPPUNIT_ASSERT_MESSAGE("Result does not have content",0!=blankString.compare(iter.getDetailContent()));
  }

  // NB Response deleted by SearchResultSet fetch() method
}
