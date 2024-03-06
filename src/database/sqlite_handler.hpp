#include <sqlite_orm/sqlite_orm.h>

#include "database_handler.hpp"

class SQLiteHandler : public IDatabaseHandler {
 public:
  SQLiteHandler(const std::string& path);

  /// @brief: Stores a new deck
  /// @param deck: Deck to store. Stored deck id will be written on Deck
  void StoreDeck(Deck& deck) const override;

  /// @brief: Deletes a deck
  /// @param deck: Deck to delete
  void DeleteDeck(const Deck& deck) const override;

  /// @brief: Stores a deck
  /// @param deck: Deck to store the card
  /// @param card: Card to store. Stored card id will be written on Deck
  void StoreCard(const Deck& deck, Card& card) const override;

  /// @brief: Gets all cards from a deck
  /// @param deck: Deck to get the cards from
  /// @return vector of cards of the deck
  std::vector<Card> GetAllCardsByDeck(const Deck& deck) const override;

 private:
  static auto InitStorage(const std::string& path) {
    using namespace sqlite_orm;
    return make_storage(
        path,
        make_table("decks",
                   make_column("id", &Deck::id, primary_key().autoincrement()),
                   make_column("name", &Deck::name)),
        make_table("cards",
                   make_column("id", &Card::id, primary_key().autoincrement()),
                   make_column("name", &Card::name),
                   make_column("front", &Card::front),
                   make_column("back", &Card::back),
                   make_column("deck_id", &Card::deck_id)));
  }

  std::string db_path_;
};