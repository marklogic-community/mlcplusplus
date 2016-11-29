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
#include "mlclient/Connection.hpp"
#include "mlclient/Response.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/SearchDescription.hpp"
#include "mlclient/NoCredentialsException.hpp"

#include "SearchBuilderTest.hpp"
#include "mlclient/utilities/SearchBuilder.hpp"
#include "mlclient/SearchResultSet.hpp"
#include "mlclient/SearchResult.hpp"

#include "mlclient/logging.hpp"

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
  SearchDescription* desc = new SearchDescription; // default empty search object
  LOG(DEBUG) << "Got blank desc doc";
  GenericTextDocumentContent* tdcOptions = new GenericTextDocumentContent;
  LOG(DEBUG) << "got options";
  tdcOptions->setContent("{\"transform-results\": {\"apply\": \"raw\"}}");
  LOG(DEBUG) << "have set options content";
  desc->setOptions(*tdcOptions);
  LOG(DEBUG) << "set search desc options";

  // construct search query
  SearchBuilder builder;
  LOG(DEBUG) << "got blank builder";

  builder.setQuery(
    builder.andQuery(
      std::vector<IQuery*>{
        SearchBuilder::orQuery(
          std::vector<IQuery*>{
            SearchBuilder::collectionQuery(std::vector<std::string>{"/some/col1"})
            ,
            SearchBuilder::collectionQuery(std::vector<std::string>{"/some/col2"})
          }
        ),
        SearchBuilder::notQuery(
          SearchBuilder::orQuery(
            std::vector<IQuery*>{
              SearchBuilder::documentQuery(std::vector<std::string>{"/some/doc.json"})
            }
          )
        )
      }
    )
  );

  ITextDocumentContent& searchDoc = *builder.toDocument();
  LOG(DEBUG) << "got search doc from builder";
  LOG(DEBUG) << "SearchResultBuilderTest search content: " << searchDoc.getContent();
  desc->setQuery(searchDoc);
  LOG(DEBUG) << "  Got a SearchDescription object instance";

  SearchResultSet* results = new SearchResultSet(ml,desc);

  bool res = results->fetch();
  if (!res) {
    LOG(DEBUG) << "Exception report from fetch() attempt:-";
    LOG(DEBUG) << results->getFetchException().what();
  }
  std::string blankString("");
  CPPUNIT_ASSERT_MESSAGE("Fetch operation did not succeed", res);

  // get results iterator
  int count = 0;
  for (SearchResultSetIterator* iter = results->begin();*iter != *(results->end());++(*iter)) {
    LOG(DEBUG) << " Result " << count << ":-";
    LOG(DEBUG) << "  URI: " << iter->first().getUri();
    LOG(DEBUG) << "  Content: " << iter->first().getDetailContent()->getChildContent()->getContent();
    CPPUNIT_ASSERT_MESSAGE("Result does not have a URI",0!=blankString.compare(iter->first().getUri()));
    CPPUNIT_ASSERT_MESSAGE("Result does not have content",nullptr != iter->first().getDetailContent());
    ++count;
    if (count > 20) break;
  }

  // NB Response deleted by SearchResultSet fetch() method
}
