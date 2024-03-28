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
  ASSERT_EQ(d.id, 1);
  ASSERT_NO_THROW(sut_.StoreDeck(d));
  ASSERT_EQ(d.id, 2);
}

TEST_F(DatabaseTestFixture, Delete_deck) {
  Deck d{"myDeck", -1};

  ASSERT_NO_THROW(sut_.StoreDeck(d));
  ASSERT_EQ(d.id, 1);

  ASSERT_NO_THROW(sut_.DeleteDeck(d.id));
}

TEST_F(DatabaseTestFixture, StoreCard) {
  Deck d{"myDeck", -1};

  ASSERT_NO_THROW(sut_.StoreDeck(d));
  ASSERT_EQ(d.id, 1);

  auto c = Card{"card1", "front1", "back1", -1, d.id};

  ASSERT_NO_THROW(sut_.StoreCard(d.id, c));
  ASSERT_EQ(c.id, 1);
}

TEST_F(DatabaseTestFixture, GetStoredCard) {
  Deck d{"myDeck", -1};

  ASSERT_NO_THROW(sut_.StoreDeck(d));
  ASSERT_EQ(d.id, 1);

  auto c = Card{"card1", "front1", "back1", -1, d.id};

  ASSERT_NO_THROW(sut_.StoreCard(d.id, c));
  ASSERT_EQ(c.id, 1);
  ASSERT_NO_THROW(sut_.StoreCard(d.id, c));
  ASSERT_EQ(c.id, 2);

  decltype(sut_.GetAllCardsByDeck(d.id)) cards;
  ASSERT_NO_THROW(cards = sut_.GetAllCardsByDeck(d.id));
  ASSERT_EQ(cards.size(), 2);
}

TEST_F(DatabaseTestFixture, testMove) {
  std::unique_ptr<SQLiteHandler> db1 =
      std::make_unique<SQLiteHandler>("test2.db");

  Deck d{"myDeck", -1};

  ASSERT_NO_THROW(db1->StoreDeck(d));
  ASSERT_EQ(d.id, 1);

  auto c = Card{"card1", "front1", "back1", -1, d.id};

  ASSERT_NO_THROW(db1->StoreCard(d.id, c));
  ASSERT_EQ(c.id, 1);

  auto db2 = std::move(db1);
  decltype(db2->GetAllCardsByDeck(d.id)) cards;
  ASSERT_NO_THROW(cards = db2->GetAllCardsByDeck(d.id));
  ASSERT_EQ(cards.size(), 1);

  std::system("rm -f test2.db");
}