#ifndef UI_ADD_CARD_ONBOARDING_SCREEN_IMPL_H_
#define UI_ADD_CARD_ONBOARDING_SCREEN_IMPL_H_

#include <functional>

#include "UI/callbacks.hpp"
#include "UI/generated/gui.h"

class AddCardBoardingScreenImpl : public AddCardBoardingScreen {
 public:
  enum class BoardingReason {
    kNoCardsInDeck,
    kCardsAreCompleted,
  };

  AddCardBoardingScreenImpl();

  void SetCallbacks(NotifyAddCardCb);

  void Show();
  void Show(int deck_id, BoardingReason boarding_reason);

 private:
  void OnAddCardAddClicked(wxCommandEvent& event) override;
  void OnAddCardCancelClicked(wxCommandEvent& event) override;

  NotifyAddCardCb notify_add_card_cb_;
  int current_deck_id_;

  static constexpr const char* no_cards_in_deck_text_ =
      "There are no cards in deck, Please add card to start practice :)";
  static constexpr const char* cards_are_completed_text_ =
      "You completed all the cards in your deck :)";
};

#endif
