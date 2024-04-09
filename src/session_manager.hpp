#ifndef _SESSION_MANAGER_H__
#define _SESSION_MANAGER_H__

#include <memory>
#include <optional>

#include "database/database_handler.hpp"
#include "types/card.hpp"

class ISessionManager {
 public:
  virtual void StartSesssion(int deck_id) = 0;

  virtual std::optional<Card> GetCard(void) const = 0;

  virtual ~ISessionManager() = default;
};

/**
 * This class will manager the cards that are selected to be shown in a session
 */
class SessionManager : public ISessionManager {
 public:
  SessionManager(std::shared_ptr<IDatabaseHandler> database_handler);

  SessionManager(const SessionManager&) = delete;
  SessionManager& operator=(const SessionManager&) = delete;

  SessionManager(SessionManager&&) = delete;
  SessionManager& operator=(SessionManager&&) = delete;

  void StartSesssion(int deck_id) override;
  std::optional<Card> GetCard(void) const override;

  ~SessionManager() = default;

 private:
  std::shared_ptr<IDatabaseHandler> database_handler_;
  int deck_id_;
  bool is_session_active_;
};

std::unique_ptr<SessionManager> CreateSessionManager(
    std::shared_ptr<IDatabaseHandler> database_handler);

#endif
