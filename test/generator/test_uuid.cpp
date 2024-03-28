#include <gtest/gtest.h>

#include <string>

/// SUT
#include "generator/uuid.hpp"

/// Fixture
class UUIDTestFixture : public ::testing::Test {
 public:
  UUIDTestFixture() : sut_() {}

  UUIDGenerator sut_;

  ~UUIDTestFixture() {}
};

TEST_F(UUIDTestFixture, generate_uuid) {
  auto uuid = sut_.GenerateUUID();
  std::cout << "Generated UUID= " << uuid << "\n";

  ASSERT_TRUE(uuid != std::string(""));
}
