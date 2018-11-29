// Copyright 2016-2018 The RamFuzz contributors. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "nnet.hpp"

using namespace std;
using namespace ramfuzz;

namespace {

class samplenet3 : public valgen_nnet {};

}

namespace ramfuzz {

unique_ptr<valgen_nnet> make_nnet() { return torch::make_unique<samplenet3>(); }

}  // namespace ramfuzz
