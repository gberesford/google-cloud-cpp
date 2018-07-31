// Copyright 2018 Google LLC
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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_STORAGE_OBJECT_ACCESS_CONTROL_H_
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_STORAGE_OBJECT_ACCESS_CONTROL_H_

#include "google/cloud/storage/internal/access_control_common.h"
#include "google/cloud/storage/internal/common_metadata.h"
#include "google/cloud/storage/internal/nljson.h"

namespace google {
namespace cloud {
namespace storage {
inline namespace STORAGE_CLIENT_NS {
/**
 * A wrapper for the objectAccessControl resource in Google Cloud Storage.
 *
 * @see
 * https://cloud.google.com/storage/docs/json_api/v1/objectAccessControls for
 * an authoritative source of field definitions.
 */
class ObjectAccessControl : private internal::AccessControlCommon {
 public:
  ObjectAccessControl() : generation_(0) {}

  static ObjectAccessControl ParseFromJson(internal::nl::json const& json);
  static ObjectAccessControl ParseFromString(std::string const& payload);

  using AccessControlCommon::ROLE_OWNER;
  using AccessControlCommon::ROLE_READER;
  using AccessControlCommon::TEAM_EDITORS;
  using AccessControlCommon::TEAM_OWNERS;
  using AccessControlCommon::TEAM_VIEWERS;

  using AccessControlCommon::bucket;
  using AccessControlCommon::domain;
  using AccessControlCommon::email;

  using AccessControlCommon::entity;
  ObjectAccessControl& set_entity(std::string v) {
    AccessControlCommon::set_entity(std::move(v));
    return *this;
  }

  using AccessControlCommon::entity_id;
  using AccessControlCommon::etag;
  using AccessControlCommon::has_project_team;
  using AccessControlCommon::id;
  using AccessControlCommon::kind;
  using AccessControlCommon::project_team;

  using AccessControlCommon::role;
  ObjectAccessControl& set_role(std::string v) {
    AccessControlCommon::set_role(std::move(v));
    return *this;
  }

  using AccessControlCommon::self_link;

  std::int64_t generation() const { return generation_; }
  std::string const& object() const { return object_; }

  bool operator==(ObjectAccessControl const& rhs) const;
  bool operator!=(ObjectAccessControl const& rhs) const {
    return not(*this == rhs);
  }

 private:
  std::int64_t generation_;
  std::string object_;
};

std::ostream& operator<<(std::ostream& os, ObjectAccessControl const& rhs);

}  // namespace STORAGE_CLIENT_NS
}  // namespace storage
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_STORAGE_OBJECT_ACCESS_CONTROL_H_