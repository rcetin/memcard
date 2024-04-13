#include "sqlite_handler.hpp"

#include <iostream>
#include <memory>
#include <sstream>

#include "types/card.hpp"
#include "types/deck.hpp"

/// Decks table schema
/// id (key) name

SQLiteHandler::SQLiteHandler(const std::string& path)
    : db_(path, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE) {
  db_.exec(
      "CREATE TABLE IF NOT EXISTS decks (id INTEGER PRIMARY KEY, name TEXT)");
  db_.exec(
      "CREATE TABLE IF NOT EXISTS cards (id INTEGER PRIMARY KEY, name TEXT, "
      "front TEXT, back "
      " TEXT, deck_id INTEGER) ");
  std::cout << "parametric cctor<<< this=" << this << "\n";
}

void SQLiteHandler::StoreDeck(Deck& deck) {
  SQLite::Statement query{db_, "INSERT INTO decks VALUES (NULL, ?)"};
  query.bind(1, deck.name);

  query.exec();
  deck.id = db_.getLastInsertRowid();
  std::cout << "inserted id=" << deck.id << "\n";
}

void SQLiteHandler::DeleteDeck(int deck_id) {
  SQLite::Statement query{db_, "DELETE FROM decks WHERE id = ?"};
  query.bind(1, deck_id);

  query.exec();
}

void SQLiteHandler::StoreCard(int deck_id, Card& card) {
  SQLite::Statement query{db_, "INSERT INTO cards VALUES (NULL, ?, ?, ?, ?)"};
  query.bind(1, card.name);
  query.bind(2, card.front);
  query.bind(3, card.back);
  query.bind(4, deck_id);

  query.exec();

  card.id = db_.getLastInsertRowid();
}

std::vector<Card> SQLiteHandler::GetAllCardsByDeck(int deck_id) const {
  std::vector<Card> cards{};

  SQLite::Statement query(db_, "SELECT * FROM cards WHERE deck_id = ?");

  query.bind(1, deck_id);

  while (query.executeStep()) {
    // Demonstrate how to get some typed column value
    int id = query.getColumn(0);
    const char* name = query.getColumn(1);
    const char* front = query.getColumn(2);
    const char* back = query.getColumn(3);

    cards.push_back(Card{std::string{name}, std::string{front},
                         std::string{back}, id, deck_id});
  }

  std::cout << "Getting cards from db for deck: " << deck_id << "\n";
  std::cout << "sizeof cards=" << cards.size() << "\n";

  return cards;
}

std::vector<Deck> SQLiteHandler::GetAllDecks(void) const {
  std::vector<Deck> decks{};

  SQLite::Statement query(db_, "SELECT * FROM decks");

  while (query.executeStep()) {
    // Demonstrate how to get some typed column value
    int id = query.getColumn(0);
    const char* name = query.getColumn(1);

    decks.push_back(Deck{std::string{name}, id});
  }

  return decks;
}
