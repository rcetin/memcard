#ifndef DATABASE_DATABASE_HANDLER_H_
#define DATABASE_DATABASE_HANDLER_H_

#include <string>
#include <vector>

#include "types/card.hpp"
#include "types/deck.hpp"

class IDatabaseHandler {
 public:
  /// @brief: Stores a new deck
  /// @param deck: Deck to store
  /// @return true if operation is successful, false otherwise
  virtual bool StoreDeck(const Deck& deck) const = 0;

  /// @brief: Deletes a deck
  /// @param deck: Deck to delete
  /// @return true if operation is successful, false otherwise
  virtual bool DeleteDeck(const Deck& deck) const = 0;

  /// @brief: Stores a deck
  /// @param deck: Deck to store the card
  /// @param card: Card to store
  /// @return true if operation is successful, false otherwise
  virtual bool StoreCard(const Deck& deck, const Card& card) const = 0;

  /// @brief: Gets all cards from a deck
  /// @param deck: Deck to get the cards from
  /// @return true if operation is successful, false otherwise
  virtual std::vector<Card> GetAllCards(const Deck& deck) const = 0;

  virtual ~IDatabaseHandler() = default;
};

#endif