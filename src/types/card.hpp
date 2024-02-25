#ifndef TYPES_CARD_HPP_
#define TYPES_CARD_HPP_

#include <string>

#include "deck.hpp"

class Card {
 public:
  const std::string name_;
  const std::string front_;
  const std::string back_;
  const int id_;
  const Deck& deck_;
};

#endif