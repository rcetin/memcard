#include "practice_screen_impl.hpp"

#include <wx/log.h>

#include "types/deck.hpp"

PracticeScreenImpl::PracticeScreenImpl()
    : PracticeScreen(nullptr, wxID_ANY, "Show Card", wxPoint(0, 0),
                     wxDefaultSize, 0),
      get_all_cards_cb_{nullptr},
      current_card_idx_{0},
      current_card_pos_{card_position::kFront} {}

void PracticeScreenImpl::SetCallbacks(
    GetAllCardsCb get_all_cards_cb, NotifyAddCardCb notify_add_card_cb,
    NotifyNoCardsToShow notify_no_cards_to_show_cb) {
  get_all_cards_cb_ = get_all_cards_cb;
  notify_add_card_cb_ = notify_add_card_cb;
  notify_no_cards_to_show_cb_ = notify_no_cards_to_show_cb;
}

void PracticeScreenImpl::Show(void) { PracticeScreen::Show(true); }

void PracticeScreenImpl::Show(int deck_id) {
  cards_ = get_all_cards_cb_(deck_id);

  current_card_idx_ = 0;
  current_deck_id_ = deck_id;

  if (!cards_.empty()) {
    current_card_pos_ = card_position::kFront;
    ShowCard(cards_[current_card_idx_], current_card_pos_);
    PracticeScreen::Show(true);
  }
}

void PracticeScreenImpl::ShowCard(const Card& card, card_position pos) {
  cardFrontTextBox->SetLabel((pos == card_position::kFront) ? card.front
                                                            : card.back);
}

void PracticeScreenImpl::OnPracticeShowClicked(wxCommandEvent& event) {
  current_card_pos_ = card_position::kBack;

  ShowCard(cards_[current_card_idx_], current_card_pos_);
  ShowCard(cards_[current_card_idx_], current_card_pos_);
}

void PracticeScreenImpl::OnPracticeCancelClicked(wxCommandEvent& event) {
  PracticeScreen::Show(false);
}

void PracticeScreenImpl::OnPracticeAddCardClicked(wxCommandEvent& event) {
  notify_add_card_cb_(current_deck_id_);
}

void PracticeScreenImpl::OnPracticeNextClicked(wxCommandEvent& event) {
  if (cards_.size() == ++current_card_idx_) {
    notify_no_cards_to_show_cb_(current_deck_id_);
    PracticeScreen::Show(false);
    return;
  }

  current_card_pos_ = card_position::kFront;
  ShowCard(cards_[current_card_idx_], current_card_pos_);
}
