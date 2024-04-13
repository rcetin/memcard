#ifndef TYPES_CARD_HPP_
#define TYPES_CARD_HPP_

#include <ostream>
#include <string>

#include "deck.hpp"

struct Card {
  std::string name;
  std::string front;
  std::string back;
  int id;
  int deck_id;

  friend std::ostream& operator<<(std::ostream& out, Card c) {
    return out << "Card: name= " << c.name << " front= " << c.front
               << " back= " << c.back << " id= " << c.id
               << " deck id= " << c.deck_id;
  }
};

#endif