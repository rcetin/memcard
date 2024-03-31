#include "add_card_boarding_screen_impl.hpp"

#include <wx/log.h>

AddCardBoardingScreenImpl::AddCardBoardingScreenImpl()
    : AddCardBoardingScreen(nullptr, wxID_ANY, "Add Card Boarding",
                            wxPoint(0, 0), wxDefaultSize, 0),
      current_deck_id_{-1} {}

void AddCardBoardingScreenImpl::Show() { AddCardBoardingScreen::Show(true); }

void AddCardBoardingScreenImpl::Show(int deck_id,
                                     BoardingReason boarding_reason) {
  current_deck_id_ = deck_id;

  addCardOnboardingText->SetLabel(
      (boarding_reason == BoardingReason::kCardsAreCompleted)
          ? cards_are_completed_text_
          : no_cards_in_deck_text_);

  AddCardBoardingScreen::Show(true);
}

void AddCardBoardingScreenImpl::SetCallbacks(
    NotifyAddCardCb notify_add_card_cb) {
  notify_add_card_cb_ = notify_add_card_cb;
}

void AddCardBoardingScreenImpl::OnAddCardAddClicked(wxCommandEvent& event) {
  notify_add_card_cb_(current_deck_id_);
  AddCardBoardingScreen::Show(false);
}

void AddCardBoardingScreenImpl::OnAddCardCancelClicked(wxCommandEvent& event) {
  AddCardBoardingScreen::Show(false);
}
