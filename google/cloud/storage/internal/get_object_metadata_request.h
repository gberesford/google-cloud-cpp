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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_STORAGE_INTERNAL_GET_OBJECT_METADATA_REQUEST_H_
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_STORAGE_INTERNAL_GET_OBJECT_METADATA_REQUEST_H_

#include "google/cloud/storage/internal/generic_request.h"
#include "google/cloud/storage/well_known_parameters.h"
#include <iosfwd>

namespace google {
namespace cloud {
namespace storage {
inline namespace STORAGE_CLIENT_NS {
namespace internal {
/**
 * Request the metadata for a bucket.
 */
class GetObjectMetadataRequest
    : public GenericRequest<GetObjectMetadataRequest, Generation,
                            IfGenerationMatch, IfGenerationNotMatch,
                            IfMetaGenerationMatch, IfMetaGenerationNotMatch,
                            Projection, UserProject> {
 public:
  GetObjectMetadataRequest() = default;
  explicit GetObjectMetadataRequest(std::string bucket_name,
                                    std::string object_name)
      : bucket_name_(std::move(bucket_name)),
        object_name_(std::move(object_name)) {}

  std::string const& bucket_name() const { return bucket_name_; }
  GetObjectMetadataRequest& set_bucket_name(std::string bucket_name) {
    bucket_name_ = std::move(bucket_name);
    return *this;
  }
  std::string const& object_name() const { return object_name_; }
  GetObjectMetadataRequest& set_object_name(std::string object_name) {
    object_name_ = std::move(object_name);
    return *this;
  }

 private:
  std::string bucket_name_;
  std::string object_name_;
};

std::ostream& operator<<(std::ostream& os, GetObjectMetadataRequest const& r);
}  // namespace internal
}  // namespace STORAGE_CLIENT_NS
}  // namespace storage
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_STORAGE_INTERNAL_GET_OBJECT_METADATA_REQUEST_H_