/**
 * Creates a generic template for a wrapper holding a unique_ptr to an instance of an mlclient
 * object that needs to be held and casted to and from a C wrapper class.
 * Examples are CResponse -> std::unique_ptr<Response>
 * and CConnection -> std:unique_ptr<Connection>
 */

using namespace mlclient;

template <typename T>
class CWrapper {
public:
  CWrapper(std::unique_ptr<T> obj) : ptr(std::move(obj)) {
    ;
  }
  ~CWrapper() {
    ;
  }

  T& get() {
    return *ptr;
  }

private:
  std::unique_ptr<T> ptr;
};
