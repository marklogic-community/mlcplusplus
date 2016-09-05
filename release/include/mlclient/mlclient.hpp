/*
 * Copyright (c) MarkLogic Corporation. All rights reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#ifndef MLCLIENT_HPP
#define MLCLIENT_HPP

#include <memory>

//#include "mlclient/ext/easylogging++.h"

#ifdef _WIN32

#ifdef MLCLIENT_EXPORTS
#define MLCLIENT_API __declspec(dllexport)
#else
#define MLCLIENT_API __declspec(dllimport)
#endif

#include <ostream>
#include <sstream>
#include <string>

/*
namespace mlclient {
  MLCLIENT_API el::base::type::StoragePointer sharedLoggingRepository();
}
*/

#else
#define MLCLIENT_API
#endif

namespace mlclient {
  // note: this implementation does not disable this overload for array types
  template<typename T, typename... Args>
  std::unique_ptr<T> make_unique(Args&&... args)
  {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
  }
} // end namespace mlclient

#endif /* defined(MLCLIENT_HPP) */
