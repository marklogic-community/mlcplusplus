//
// Copyright (c) MarkLogic Corporation. All rights reserved.
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// In a real application this file would be replaced by your existing C struct declaration files.
// This is why I've chosen to define this struct in its own file, and not include CStructWrapper.h.
// Thus in your own application you only need to provide code like that in CStructWrapper.h/cpp and NOT
// any of the code in this file.
//
#ifndef CSTRUCT_H
#define CSTRUCT_H

struct ml_samples_sampledoc {
  char* first;
  char* second;
};

#endif
