#include <gtest/gtest.h>

#include <string>

/// SUT
#include "database/sqlite_handler.hpp"

/// Fixture
class DatabaseTestFixture : public ::testing::Test {
 public:
  DatabaseTestFixture() : sut_("test.db") {}

  SQLiteHandler sut_;
};

TEST_F(DatabaseTestFixture, Init_Database) {}
