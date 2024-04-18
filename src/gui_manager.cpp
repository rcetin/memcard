#include "gui_manager.hpp"

#include <wx/log.h>

#include <functional>
#include <utility>

#include "UI/screens/main_screen_impl.hpp"
#include "database/sqlite_handler.hpp"

GUIManager::GUIManager(MainScreenImpl* main_screen,
                       std::shared_ptr<IDatabaseHandler> database_handler,
                       std::shared_ptr<ISessionManager> session_manager)
    : main_screen_{main_screen},
      database_handler_{std::move(database_handler)},
      session_manager_(std::move(session_manager)) {
  main_screen_->SetCallbacks(
      std::bind(&GUIManager::CreateNewDeck, this, std::placeholders::_1),
      std::bind(&GUIManager::CreateNewCard, this, std::placeholders::_1,
                std::placeholders::_2),
      std::bind(&GUIManager::GetAllCards, this, std::placeholders::_1),
      std::bind(&GUIManager::GetAllDecks, this),
      std::bind(&GUIManager::PracticeIsStarted, this, std::placeholders::_1),
      std::bind(&GUIManager::PracticeIsEnded, this, std::placeholders::_1),
      std::bind(&GUIManager::GetCard, this),
      std::bind(&GUIManager::GetCardById, this, std::placeholders::_1),
      std::bind(&GUIManager::EditCard, this, std::placeholders::_1,
                std::placeholders::_2));
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

  auto cards = database_handler_->GetAllCardsByDeckId(deck_id);
  return cards;
}

std::vector<Deck> GUIManager::GetAllDecks(void) const {
  return database_handler_->GetAllDecks();
}

void GUIManager::PracticeIsStarted(int deck_id) const {
  wxLogDebug("GUI: Session is started!");

  session_manager_->StartSesssion(deck_id);
}

void GUIManager::PracticeIsEnded(int deck_id) const {
  ///
}

std::optional<Card> GUIManager::GetCard(void) const {
  return session_manager_->GetCard();
}

std::optional<Card> GUIManager::GetCardById(int card_id) const {
  return database_handler_->GetCardById(card_id);
}

void GUIManager::EditCard(int card_id, Card card) const {
  database_handler_->EditCard(card_id, card);
}

void GUIManager::StartApplication() const { main_screen_->Show(); }

std::unique_ptr<GUIManager> CreateGUIManager() {
  static std::shared_ptr<IDatabaseHandler> db_handler =
      std::make_shared<SQLiteHandler>("memcard.db");
  static std::shared_ptr<ISessionManager> session_mgr =
      std::make_shared<SessionManager>(db_handler);

  return std::make_unique<GUIManager>(new MainScreenImpl(), db_handler,
                                      session_mgr);
}
