#ifndef UI_CALLBACKS_HPP_
#define UI_CALLBACKS_HPP_

#include <functional>
#include <vector>

#include "types/card.hpp"
#include "types/deck.hpp"

using CreateNewDeckCb = std::function<void(Deck&)>;
using CreateNewCardCb = std::function<void(const Deck&, Card&)>;
using GetAllCardsCb = std::function<std::vector<Card>(const Deck&)>;
using GetAllDecksCb = std::function<std::vector<Deck>(void)>;

#endif