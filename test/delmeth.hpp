// Copyright 2016 The RamFuzz contributors. All rights reserved.
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

/// Deleted methods shouldn't cause compilation problems in RamFuzz test code.

class A {
public:
  A(int) {}
  A(const A &) = delete;
  A &operator=(const A &) = delete;
};

// Some of B's methods are implicitly deleted because of A.
class B {
public:
  B() : a(0){};
  A a;
  int sum = 42;
};

// Some of C's methods are implicitly deleted because of const members.
class C {
public:
  C() = default;
  const int sum = 43;
};