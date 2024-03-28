#include "gui_manager.hpp"

#include <functional>
#include <utility>

#include "UI/screens/main_screen_impl.hpp"
#include "database/sqlite_handler.hpp"

GUIManager::GUIManager(MainScreenImpl* main_screen,
                       std::unique_ptr<IDatabaseHandler> database_handler)
    : main_screen_{main_screen},
      database_handler_{std::move(database_handler)} {
  main_screen_->SetCallbacks(
      std::bind(&GUIManager::CreateNewDeck, this, std::placeholders::_1),
      std::bind(&GUIManager::CreateNewCard, this, std::placeholders::_1,
                std::placeholders::_2),
      std::bind(&GUIManager::GetAllCards, this, std::placeholders::_1),
      std::bind(&GUIManager::GetAllDecks, this));
}

void GUIManager::CreateNewDeck(Deck& deck) {
  if (!database_handler_) {
    std::cout << "database handler is null!\n";
    return;
  }

  database_handler_->StoreDeck(deck);
}

void GUIManager::CreateNewCard(int deck_id, Card& card) const {
  if (!database_handler_) {
    std::cout << "database handler is null!\n";
    return;
  }

  database_handler_->StoreCard(deck_id, card);
}

std::vector<Card> GUIManager::GetAllCards(int deck_id) const {
  if (!database_handler_) {
    std::cout << "database handler is null!\n";
    std::vector<Card>();
  }

  auto cards = database_handler_->GetAllCardsByDeck(deck_id);
  return cards;
}

std::vector<Deck> GUIManager::GetAllDecks(void) const {
  return database_handler_->GetAllDecks();
}

void GUIManager::StartApplication() const { main_screen_->Show(); }

std::unique_ptr<GUIManager> CreateGUIManager() {
  return std::make_unique<GUIManager>(
      new MainScreenImpl(), std::make_unique<SQLiteHandler>("memcard.db"));
}