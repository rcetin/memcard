#ifndef _GENERATOR_UUID_H__
#define _GENERATOR_UUID_H__

#include <memory>

class IUUIDGenerator {
 public:
  virtual std::string GenerateUUID() = 0;

  virtual ~IUUIDGenerator() = default;
};

class UUIDGenerator : IUUIDGenerator {
 public:
  UUIDGenerator();

  std::string GenerateUUID() override;
};

std::unique_ptr<UUIDGenerator> CreateUUIDGenerator();

#endif