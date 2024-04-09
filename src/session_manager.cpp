#include "session_manager.hpp"

#include <wx/log.h>

#include <iostream>

SessionManager::SessionManager(
    std::shared_ptr<IDatabaseHandler> database_handler)
    : database_handler_{database_handler},
      deck_id_(-1),
      is_session_active_(false) {}

void SessionManager::StartSesssion(int deck_id) {
  deck_id_ = deck_id;
  is_session_active_ = true;

  wxLogDebug("Session Manager: Session is started!");
}

std::optional<Card> SessionManager::GetCard(void) const {
  if (!database_handler_) {
    wxLogDebug("Session Manager: Database handle is null!");
    std::vector<Card>();
  }

  auto cards = database_handler_->GetAllCardsByDeck(deck_id_);
  if (cards.empty()) {
    wxLogDebug("Session Manager: Cards are empty for deck id=%d!", deck_id_);
    return std::nullopt;
  }

  return cards[0];
}

std::unique_ptr<SessionManager> CreateSessionManager(
    std::shared_ptr<IDatabaseHandler> database_handler) {
  return std::make_unique<SessionManager>(database_handler);
}
