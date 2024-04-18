#ifndef DATABASE_DATABASE_HANDLER_H_
#define DATABASE_DATABASE_HANDLER_H_

#include <optional>
#include <string>
#include <vector>

#include "types/card.hpp"
#include "types/deck.hpp"

class IDatabaseHandler {
 public:
  /// @brief: Stores a new deck
  /// @param deck: Deck to store. Stored deck id will be written on Deck
  virtual void StoreDeck(Deck& deck) = 0;

  /// @brief: Deletes a deck
  /// @param deck: Deck to delete
  virtual void DeleteDeck(int deck_id) = 0;

  /// @brief: Stores a deck
  /// @param deck: Deck to store the card
  /// @param card: Card to store. Stored card id will be written on Deck
  virtual void StoreCard(int deck_id, Card& card) = 0;

  virtual bool EditCard(int card_id, Card& card) = 0;

  /// @brief: Gets all cards from a deck
  /// @param deck: Deck to get the cards from
  /// @return vector of cards of the deck
  virtual std::vector<Card> GetAllCardsByDeckId(int deck_id) const = 0;

  virtual std::vector<Deck> GetAllDecks(void) const = 0;

  virtual std::optional<Card> GetCardById(int card_id) const = 0;

  virtual ~IDatabaseHandler() = default;
};

#endif