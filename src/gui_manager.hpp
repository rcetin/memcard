#ifndef _GUI_MANAGER_H__
#define _GUI_MANAGER_H__

#include <memory>
#include <vector>

#include "UI/screens/main_screen_impl.hpp"
#include "database/database_handler.hpp"
#include "database/sqlite_handler.hpp"
#include "types/card.hpp"
#include "types/deck.hpp"

class GUIManager {
 public:
  GUIManager(MainScreenImpl*, std::unique_ptr<IDatabaseHandler>);

  GUIManager(const GUIManager&) = delete;
  GUIManager& operator=(const GUIManager&) = delete;

  GUIManager(GUIManager&&) = delete;
  GUIManager& operator=(GUIManager&&) = delete;

  ~GUIManager() = default;

  void StartApplication() const;

 private:
  void CreateNewDeck(Deck&);
  void CreateNewCard(int deck_id, Card&) const;
  std::vector<Card> GetAllCards(int deck_id) const;
  std::vector<Deck> GetAllDecks(void) const;

  MainScreenImpl* main_screen_;
  std::unique_ptr<IDatabaseHandler> database_handler_;
};

std::unique_ptr<GUIManager> CreateGUIManager();

#endif