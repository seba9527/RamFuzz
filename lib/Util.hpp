// Copyright 2016-2017 The RamFuzz contributors. All rights reserved.
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

#pragma once

#include "clang/AST/DeclCXX.h"

/// True iff C is visible outside all its parent contexts.
bool globally_visible(const clang::CXXRecordDecl *C);

namespace ramfuzz {

/// Keeps class details permanently, even after AST is destructed.
class ClassReference {
public:
  ClassReference() = default;
  explicit ClassReference(const clang::CXXRecordDecl &);
  const std::string &prefix() const;
  const std::string &name() const { return name_; };
  const std::string &suffix() const { return suffix_; }
  bool operator<(const ClassReference &that) const {
    return this->name_ < that.name_;
  }
  bool operator<(const std::string &s) const { return name_ < s; }
  ClassReference &operator=(const ClassReference &that) = default;
  bool is_template() const { return is_template_; }
  bool is_visible() const { return is_visible_; }

private:
  std::string name_, suffix_;
  bool is_template_; ///< True iff this is a class template.
  ///< True iff this class is visible from the outermost scope.
  bool is_visible_;
};

inline bool operator<(const std::string &s, const ClassReference &ref) {
  return ref.name() < s;
}

} // namespace ramfuzz
