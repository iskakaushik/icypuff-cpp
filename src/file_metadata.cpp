#include "icypuff/file_metadata.h"

namespace icypuff {

Result<std::unique_ptr<FileMetadata>> FileMetadata::Create(
    FileMetadataParams&& params) {
  return std::make_unique<FileMetadata>(std::move(params));
}

FileMetadata::FileMetadata(FileMetadataParams&& params)
    : blobs_(std::make_move_iterator(params.blobs.begin()),
             std::make_move_iterator(params.blobs.end())),
      properties_(std::move(params.properties)) {}

FileMetadata::~FileMetadata() = default;

const std::vector<std::unique_ptr<BlobMetadata>>& FileMetadata::blobs() const {
  return blobs_;
}

const std::unordered_map<std::string, std::string>& FileMetadata::properties()
    const {
  return properties_;
}

}  // namespace icypuff