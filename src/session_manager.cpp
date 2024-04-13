#include "session_manager.hpp"

#include <wx/log.h>

#include <iostream>
#include <queue>

SessionManager::SessionManager(
    std::shared_ptr<IDatabaseHandler> database_handler)
    : database_handler_{database_handler},
      deck_id_(-1),
      is_session_active_(false) {}

void SessionManager::StartSesssion(int deck_id) {
  wxLogDebug("Session Manager: Session is started for deck:%d!", deck_id);

  if (!database_handler_) {
    wxLogDebug("Session Manager: Database handle is null!");
    return;
  }

  cards_ = database_handler_->GetAllCardsByDeck(deck_id);

  deck_id_ = deck_id;
  is_session_active_ = true;
}

std::optional<Card> SessionManager::GetCard(void) {
  if (!is_session_active_) {
    wxLogDebug(
        "Session Manager: Session is not active, cannot provide a card!");
    return std::nullopt;
  }

  if (cards_.empty()) {
    return std::nullopt;
  }

  auto card = cards_.back();
  cards_.pop_back();

  return card;
}

std::unique_ptr<SessionManager> CreateSessionManager(
    std::shared_ptr<IDatabaseHandler> database_handler) {
  return std::make_unique<SessionManager>(database_handler);
}
