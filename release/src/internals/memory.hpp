/*
 * memory.hpp
 *
 *  Created on: 16 May 2016
 *      Author: adamfowler
 */

#ifndef SRC_INTERNALS_MEMORY_HPP_
#define SRC_INTERNALS_MEMORY_HPP_

namespace mlclient {

// make_unique<T>
/*
 * Provides an implementation of std::make_unique - not supplied by some compilers.
 * This function should be used for the creation of ALL std::unique_ptr objects
 * as it guarantees the object is created correctly and consistently.
 *
 * Note a syntax error for the array form, and the disallowed array element form.
 * These use variadic templates from C++14
 */
template<class T, class... Types> std::unique_ptr<T> make_unique(Types&&... Args) {
  return (std::unique_ptr<T>(new T(std::forward<Types>(Args)...)));
}

// make_unique<T[]>
//template<class T> make_unique(size_t Size) {
//  return (std::unique_ptr<T>(new Elem[Size]()));
//}

// make_unique<T[N]> disallowed
//template<class T, class... Types> typename enable_if extent<T>::value != 0, <void>::type make_unique(Types&&...) = delete;


} // end namespace mlclient

#endif /* SRC_INTERNALS_MEMORY_HPP_ */
