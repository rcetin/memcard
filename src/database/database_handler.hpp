#ifndef DATABASE_DATABASE_HANDLER_H_
#define DATABASE_DATABASE_HANDLER_H_

#include <string>
#include <vector>

#include "types/card.hpp"
#include "types/deck.hpp"

class IDatabaseHandler {
 public:
  /// @brief: Stores a new deck
  /// @param deck: Deck to store. Stored deck id will be written on Deck
  virtual void StoreDeck(Deck& deck) const = 0;

  /// @brief: Deletes a deck
  /// @param deck: Deck to delete
  virtual void DeleteDeck(const Deck& deck) const = 0;

  /// @brief: Stores a deck
  /// @param deck: Deck to store the card
  /// @param card: Card to store. Stored card id will be written on Deck
  virtual void StoreCard(const Deck& deck, Card& card) const = 0;

  /// @brief: Gets all cards from a deck
  /// @param deck: Deck to get the cards from
  /// @return vector of cards of the deck
  virtual std::vector<Card> GetAllCardsByDeck(const Deck& deck) const = 0;

  virtual ~IDatabaseHandler() = default;
};

#endif