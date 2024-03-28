#ifndef UI_CALLBACKS_HPP_
#define UI_CALLBACKS_HPP_

#include <functional>
#include <vector>

#include "types/card.hpp"
#include "types/deck.hpp"

using CreateNewDeckCb = std::function<void(Deck&)>;
using CreateNewCardCb = std::function<void(int deck_id, Card&)>;
using GetAllCardsCb = std::function<std::vector<Card>(int deck_id)>;
using GetAllDecksCb = std::function<std::vector<Deck>(void)>;
using NotifyAddCardCb = std::function<void(int)>;

#endif