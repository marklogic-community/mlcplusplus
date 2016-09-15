/**
 * \file ValuesResultSetTest.cpp
 *
 * \date 16 Aug 2016
 * \author adamfowler
 */



#include "ValuesResultSetTest.hpp"
#include "mlclient/ValuesResult.hpp"
#include "mlclient/ValuesResultSet.hpp"

#include "mlclient/logging.hpp"

using namespace mlclient;

CPPUNIT_TEST_SUITE_REGISTRATION(ValuesResultSetTest);

void ValuesResultSetTest::setUp(void) {
  LOG(DEBUG) << "ENTERING TEST SUITE ValuesResultSetTest";
  // set up connection
  ml = ConnectionFactory::getConnection();
}

void ValuesResultSetTest::tearDown(void) {
  LOG(DEBUG) << "LEAVING TEST SUITE ValuesResultSetTest";
  // delete all content
  ConnectionFactory::releaseConnection(ml);
  ml = NULL;
}

void ValuesResultSetTest::testTwoAggregates() {
  TIMED_FUNC(testEmptySearch);
  LOG(DEBUG) << " --------------------------------------------";
  LOG(DEBUG) << " Entering ValuesResultSetTest::testTwoAggregates";

  ValuesResultSet vrs(ml);
  vrs.addLookup("mlcplusplustest01","ageavg");
  vrs.addLookup("mlcplusplustest01","agesum");

  vrs.fetch();

  for (auto iter = vrs.begin(); *(iter) != *(vrs.end());++(*iter)) {
    ValuesResult vr = *(*iter); // FORCES A COPY!!!
    long aggSize = vr.getAggregateCount();

    LOG(DEBUG) << "Number of returned aggregates: " << aggSize;
    CPPUNIT_ASSERT_MESSAGE("Two aggregates were not returned", 2 != aggSize);

    for (auto aggIter = vr.aggregateBegin(); aggIter != vr.aggregateEnd();++aggIter) {
      LOG(DEBUG) << " Aggregate: Name: " << aggIter->name << " = " << aggIter->value;
    }
  }

  LOG(DEBUG) << " Exception: " << "Exception?: " << vrs.getFetchException().what();
  CPPUNIT_ASSERT_MESSAGE("Exception has occurred",0 == (strcmp("std::exception", vrs.getFetchException().what())));


}


