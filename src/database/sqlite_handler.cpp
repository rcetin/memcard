#include "sqlite_handler.hpp"

#include <sqlite_orm/sqlite_orm.h>

#include <iostream>

#include "types/card.hpp"
#include "types/deck.hpp"

using namespace sqlite_orm;

struct User {
  int id;
  std::string firstName;
  std::string lastName;
  int birthDate;
  std::unique_ptr<std::string> imageUrl;
  int typeId;
};

struct UserType {
  int id;
  std::string name;
};

SQLiteHandler::SQLiteHandler(const std::string& path) : db_path_{path} {
  auto db = InitStorage(path);
  db.sync_schema();
}

void SQLiteHandler::StoreDeck(Deck& deck) const {
  auto db = InitStorage(db_path_);

  deck.id = db.insert(deck);
}

void SQLiteHandler::DeleteDeck(const Deck& deck) const {
  auto db = InitStorage(db_path_);

  db.remove<Deck>(deck.id);
}

void SQLiteHandler::StoreCard(const Deck& deck, Card& card) const {
  auto db = InitStorage(db_path_);

  card.id = db.insert(card);
}

std::vector<Card> SQLiteHandler::GetAllCardsByDeck(const Deck& deck) const {
  auto db = InitStorage(db_path_);
  std::vector<Card> cards{};

  for (auto card : db.iterate<Card>(where(c(&Card::deck_id) == deck.id))) {
    cards.emplace_back(card);
  }

  return cards;
}
