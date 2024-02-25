#include "database_handler.hpp"

class SQLiteHandler : public IDatabaseHandler {
 public:
  /// @brief: Stores a new deck
  /// @param deck: Deck to store
  /// @return true if operation is successful, false otherwise
  bool StoreDeck(const Deck& deck) const override;

  /// @brief: Deletes a deck
  /// @param deck: Deck to delete
  /// @return true if operation is successful, false otherwise
  bool DeleteDeck(const Deck& deck) const override;

  /// @brief: Stores a deck
  /// @param deck: Deck to store the card
  /// @param card: Card to store
  /// @return true if operation is successful, false otherwise
  bool StoreCard(const Deck& deck, const Card& card) const override;

  /// @brief: Gets all cards from a deck
  /// @param deck: Deck to get the cards from
  /// @return true if operation is successful, false otherwise
  std::vector<Card> GetAllCards(const Deck& deck) const override;
};