#pragma once

#include <SQLiteCpp/SQLiteCpp.h>

#include <iostream>

#include "database_handler.hpp"

class SQLiteHandler : public IDatabaseHandler {
 public:
  SQLiteHandler(const std::string& path);

  SQLiteHandler(const SQLiteHandler&) = delete;
  SQLiteHandler& operator=(const SQLiteHandler&) = delete;

  // SQLiteHandler(SQLiteHandler&& other) = default;
  // SQLiteHandler& operator=(SQLiteHandler&& other) = default;

  SQLiteHandler(SQLiteHandler&& other) : db_{std::move(other.db_)} {
    std::cout << "move ctor<<<<<\n";
  }

  SQLiteHandler& operator=(SQLiteHandler&& other) {
    db_ = std::move(other.db_);

    std::cout << "move assign\n";

    return *this;
  }

  /// @brief: Stores a new deck
  /// @param deck: Deck to store. Stored deck id will be written on Deck
  void StoreDeck(Deck& deck) override;

  /// @brief: Deletes a deck
  /// @param deck: Deck to delete
  void DeleteDeck(int deck_id) override;

  /// @brief: Stores a deck
  /// @param deck: Deck to store the card
  /// @param card: Card to store. Stored card id will be written on Deck
  void StoreCard(int deck_id, Card& card) override;

  /// @brief: Gets all cards from a deck
  /// @param deck: Deck to get the cards from
  /// @return vector of cards of the deck
  std::vector<Card> GetAllCardsByDeckId(int deck_id) const override;

  std::optional<Card> GetCardById(int card_id) const override;

  std::vector<Deck> GetAllDecks(void) const override;

  bool EditCard(int card_id, Card& card) override;

  virtual ~SQLiteHandler() = default;

 private:
  SQLite::Database db_;  ///< Database connection
};