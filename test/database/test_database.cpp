#include <gtest/gtest.h>

#include <string>

/// SUT
#include "database/sqlite_handler.hpp"

/// Fixture
class DatabaseTestFixture : public ::testing::Test {
 public:
  DatabaseTestFixture() : sut_("test.db") {}

  SQLiteHandler sut_;

  ~DatabaseTestFixture() { std::system("rm -f test.db"); }
};

TEST_F(DatabaseTestFixture, Insert_deck) {
  Deck d{"myDeck", -1};

  ASSERT_NO_THROW(sut_.StoreDeck(d));
  ASSERT_EQ(d.id, 1);
}

TEST_F(DatabaseTestFixture, Insert_deck_id_increase) {
  Deck d{"myDeck", -1};

  ASSERT_NO_THROW(sut_.StoreDeck(d));
  ASSERT_NO_THROW(sut_.StoreDeck(d));
  ASSERT_EQ(d.id, 2);
}

TEST_F(DatabaseTestFixture, Delete_deck) {
  Deck d{"myDeck", -1};

  ASSERT_NO_THROW(sut_.StoreDeck(d));
  ASSERT_EQ(d.id, 1);

  ASSERT_NO_THROW(sut_.DeleteDeck(d));
}

TEST_F(DatabaseTestFixture, StoreCard) {
  Deck d{"myDeck", -1};

  ASSERT_NO_THROW(sut_.StoreDeck(d));
  ASSERT_EQ(d.id, 1);

  auto c = Card{"card1", "front1", "back1", -1, d.id};

  ASSERT_NO_THROW(sut_.StoreCard(d, c));
  ASSERT_EQ(c.id, 1);
}

TEST_F(DatabaseTestFixture, GetStoredCard) {
  Deck d{"myDeck", -1};

  ASSERT_NO_THROW(sut_.StoreDeck(d));
  ASSERT_EQ(d.id, 1);

  auto c = Card{"card1", "front1", "back1", -1, d.id};

  ASSERT_NO_THROW(sut_.StoreCard(d, c));
  ASSERT_EQ(c.id, 1);

  decltype(sut_.GetAllCardsByDeck(d)) cards;
  ASSERT_NO_THROW(cards = sut_.GetAllCardsByDeck(d));
  ASSERT_EQ(cards.size(), 1);
}
