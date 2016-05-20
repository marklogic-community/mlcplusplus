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
// A C wrapper for a C function that takes a sample JSON doc and puts it inside a C struct
//
#include "CStruct.h"
#include "ResponseWrapper.h"

#ifndef CSTRUCTWRAPPER_H
#define CSTRUCTWRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

// member/static wrapper functions
void ml_samples_cstruct_unpack(CResponse* resp,struct ml_samples_sampledoc* obj);

#ifdef __cplusplus
}
#endif


#endif
