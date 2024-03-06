#ifndef TYPES_CARD_HPP_
#define TYPES_CARD_HPP_

#include <string>

#include "deck.hpp"

class Card {
 public:
  std::string name;
  std::string front;
  std::string back;
  int id;
  int deck_id;
};

#endif