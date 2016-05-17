/**
 * Creates a generic template for a wrapper holding a unique_ptr to an instance of an mlclient
 * object that needs to be held and casted to and from a C wrapper class.
 * Examples are CResponse -> std::unique_ptr<Response>
 * and CConnection -> std:unique_ptr<Connection>
 */

using namespace mlclient;

/**
 * \brief A template container allowing the holding of any C++ object within a wrapper accessible from C.
 *
 * See the ConnectionWrapper.h file for connecting to MarkLogic and making requests, the ResponseWrapper.h file for working
 * with the results from those calls.
 */
template <typename T>
class CWrapper {
public:
  CWrapper(T* obj) : ptr(obj) {
    ;
  }
  ~CWrapper() {
    ;
  }

  T& get() {
    return *ptr;
  }

private:
  T* ptr;
};
