#include "practice_screen_impl.hpp"

#include <wx/log.h>

#include "UI/message/message.hpp"
#include "types/deck.hpp"

PracticeScreenImpl::PracticeScreenImpl()
    : PracticeScreen(nullptr, wxID_ANY, "Show Card", wxPoint(0, 0),
                     wxDefaultSize, 0),
      get_card_cb_(nullptr),
      current_card_(Card()),
      current_card_pos_{card_position::kFront} {}

void PracticeScreenImpl::SetCallbacks(
    GetCardCb get_card_cb, NotifyAddCardCb notify_add_card_cb,
    NotifyNoCardsToShow notify_no_cards_to_show_cb) {
  get_card_cb_ = get_card_cb;
  notify_add_card_cb_ = notify_add_card_cb;
  notify_no_cards_to_show_cb_ = notify_no_cards_to_show_cb;
}

void PracticeScreenImpl::Show(void) { PracticeScreen::Show(true); }

void PracticeScreenImpl::Show(int deck_id) {
  const auto cardopt = get_card_cb_();
  if (!cardopt.has_value()) {
    Message m("");
    m.ShowError("Internal error! Card cannot be shown now.");
    return;
  }

  current_card_ = cardopt.value();
  ShowCard(current_card_, card_position::kFront);
  PracticeScreen::Show(true);
}

void PracticeScreenImpl::ShowCard(const Card& card, card_position pos) {
  current_card_pos_ = card_position::kFront;
  cardFrontTextBox->SetLabel((pos == card_position::kFront) ? card.front
                                                            : card.back);
}

void PracticeScreenImpl::OnPracticeShowClicked(wxCommandEvent& event) {
  ShowCard(current_card_, card_position::kBack);
}

void PracticeScreenImpl::OnPracticeCancelClicked(wxCommandEvent& event) {
  PracticeScreen::Show(false);
}

void PracticeScreenImpl::OnPracticeAddCardClicked(wxCommandEvent& event) {
  notify_add_card_cb_(current_deck_id_);
}

void PracticeScreenImpl::OnPracticeNextClicked(wxCommandEvent& event) {
  const auto cardopt = get_card_cb_();
  if (!cardopt.has_value()) {
    Message m("");
    m.ShowError("Internal error! Card cannot be shown now.");
    return;
  }

  current_card_ = cardopt.value();
  ShowCard(current_card_, card_position::kFront);
}
