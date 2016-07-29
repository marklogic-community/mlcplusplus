
#include "mlclient/logging.hpp"


#include <cpprest/http_client.h>
#include <array>
#include <iostream>


class ResultsHolder {
public:
  ResultsHolder() : total(-1), lastFetched(0), results() {
    //TIMED_FUNC(ResultsHolder_ResultsHolder);
    ;
  };

  void setResult(int idx,int value) {
    //TIMED_FUNC(ResultsHolder_setResult);
    results[idx] = value;
  };
  void incrementLastFetched(int by) {
    //TIMED_FUNC(ResultsHolder_ResultsHolder);
    lastFetched += by;
  };
  int getResult(int idx) {
    //TIMED_FUNC(ResultsHolder_ResultsHolder);
    return results[idx];
  };
  int getTotal() {
    //TIMED_FUNC(ResultsHolder_ResultsHolder);
    return total;
  };
  void setTotal(int t) {
    //TIMED_FUNC(ResultsHolder_ResultsHolder);
    total = t;
  };
  int getLastFetched() {
    //TIMED_FUNC(ResultsHolder_ResultsHolder);
    return lastFetched;
  };

private:
  int total; // not fetched results yet
  int lastFetched;
  std::array<int,100000> results;
};




int main(int argc, const char * argv[])
{
  std::cout << "In Main Func" << std::endl;
  //std::cout << "Easy logging started" << std::endl;
/*
  el::Configurations defaultConf;
  defaultConf.setToDefault();
  // Values are always std::string
  defaultConf.setGlobally(el::ConfigurationType::Format, "%datetime %level %fbase:%line %msg");
  //defaultConf.setGlobally(el::ConfigurationType::ToStandardOutput, "false");
  // default logger uses default configurations
  el::Loggers::reconfigureLogger("default", defaultConf);
  std::cout << "default logger configured" << std::endl;

  el::Configurations performanceConf;
  performanceConf.setToDefault();
  performanceConf.set(el::Level::Info, el::ConfigurationType::Format, "%msg");
  performanceConf.set(el::Level::Info,el::ConfigurationType::Filename,"../performance.log"); /// TODO make output file include version number of this upcoming release
  //performanceConf.set(el::Level::Info,el::ConfigurationType::MillisecondsWidth,"6");
  el::Loggers::reconfigureLogger("performance", performanceConf);
  el::Loggers::addFlag(el::LoggingFlag::FixedTimeFormat); // ensures performance numbers are always quoted as seconds, never formatted
*/
  //std::cout << "perf logger configured" << std::endl;

  //el::Logger* logger = el::Loggers::getLogger("cppproducer");

  //std::cout << "Running producer..." << std::endl;

  ResultsHolder rh;

  //std::cout << "Creating initial results task" << std::endl;
  pplx::task<void> runningTask([&rh] () {
/*
    for (int j = 0;j < 100000000;j++) {
      float k = j * 47 / 0.33;
    }
*/
    for (int i3 = 0;i3 <= 9;i3++) {
      //std::cout << "initial populating: " << i3 << std::endl;
      LOG(DEBUG) << "initial populating...";
      rh.setResult(i3,i3 * i3);
    }
    rh.incrementLastFetched(9);
    rh.setTotal(100000);
  });


  if (-1 == rh.getTotal()) {
    LOG(DEBUG) << "Waiting for initial population";
    //std::cout << "No results fetched yet. Waiting for initial results task." << std::endl;
    runningTask.wait();
  }


  for (int i = 0;i < rh.getTotal();i++) {
    if (i > rh.getLastFetched()) {
      LOG(DEBUG) << "Waiting for result last page runningTask: " << i;
      std::cout << "Waiting for result: " << i << std::endl;
      runningTask.wait();
    }
    //std::cout << "Result at index: " << i << " is: " << rh.getResult(i) << std::endl;
    LOG(DEBUG) << "Result at index: " << i  << " is: " << rh.getResult(i);
    std::cout << "Result at index: " << i  << " is: " << rh.getResult(i) << std::endl;
    // now check to see if we need to continue the task
    if (runningTask.is_done() && i > rh.getLastFetched() - 10 && rh.getLastFetched() < rh.getTotal()) {
      //std::cout << "Scheduling the next fetch task (fire and forget)" << std::endl;
      runningTask = pplx::task<void>([&rh] () {

        for (int j = 0;j < 100000;j++) {
          float k = j * 47 / 0.33;
        }

        int max = rh.getLastFetched() + 10;
        // make sure we don't overflow the array
        if (max > rh.getTotal() - 1) {
          max = rh.getTotal() - 1;
        }
        for (int i2 = rh.getLastFetched() + 1;i2 <= max;i2++) {
          LOG(DEBUG) << "second task populating: " << i2;
          std::cout << "second task populating: " << i2 << std::endl;
          rh.setResult(i2,i2 * i2);
        }
        rh.incrementLastFetched(10);
        std::cout << "Just finished fetching results up to: " << rh.getLastFetched() << std::endl;
        LOG(DEBUG) << "Just finished fetching results up to: " << rh.getLastFetched();
      });
    }

    // now add our own thread delay, increasing as we process more of the result set (so we see both sides of the performance curve)
    // At start of test - we see main thread wait for initial results
    // Toward start of test - we see main thread wait for second page
    // Toward end of test - we see fetching thread keeps almost 2 pages ahead of processing thread


    for (int j = 0;j < 100 * i ;j++) {
      float k = j * 47 / 0.33;
    }

  }

  std::cout << "Completing main thread" << std::endl;
  LOG(DEBUG) << "Completing main thread";

  return 0;
}
