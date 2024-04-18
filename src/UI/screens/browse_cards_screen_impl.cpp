#include "browse_cards_screen_impl.hpp"

#include <wx/log.h>

#include "UI/message/message.hpp"
#include "types/deck.hpp"

BrowseCardsScreenImpl::BrowseCardsScreenImpl()
    : BrowseCardsScreen(nullptr, wxID_ANY, "Browse Card", wxPoint(0, 0),
                        wxDefaultSize, 0),
      get_all_cards_cb_{nullptr},
      notify_editing_card_started_cb_{nullptr},
      current_selected_card_idx_{-1} {
  browseCardsListCtrlr->InsertColumn(0, _("Front"));
  browseCardsListCtrlr->InsertColumn(1, _("Back"));
}

void BrowseCardsScreenImpl::Show(int deck_id) {
  if (!get_all_cards_cb_) {
    std::cout << "BrowseCardsScreenImpl: get_all_cards_cb_ is nullptr\n";
    return;
  }

  auto cards = get_all_cards_cb_(deck_id);

  std::cout << "Got " << cards.size()
            << "number of cards from deck id=" << deck_id << "\n";

  auto idx = 0;
  for (auto& card : cards) {
    std::cout << card.front << " " << card.back << "\n";

    long inserted_index = browseCardsListCtrlr->InsertItem(idx++, card.front);
    browseCardsListCtrlr->SetItem(inserted_index, 1, card.back);
    listed_cards_.push_back({inserted_index, card});
    std::cout << "putting card in list idx= " << inserted_index << "\n";

    ResizeList();
  }

  BrowseCardsScreen::Show(true);
}

void BrowseCardsScreenImpl::SetCallbacks(
    GetAllCardsCb get_all_cards_cb,
    NotifyEditingCardStartedCb notify_editing_card_started_cb) {
  get_all_cards_cb_ = get_all_cards_cb;
  notify_editing_card_started_cb_ = notify_editing_card_started_cb;
}

void BrowseCardsScreenImpl::OnBrowseCardsShowClicked(wxCommandEvent& event) {
  ///
}

void BrowseCardsScreenImpl::OnBrowseCardsEditClicked(wxCommandEvent& event) {
  const auto res =
      std::find_if(listed_cards_.begin(), listed_cards_.end(),
                   [this](const auto& card_pair) {
                     std::cout << "checking idx = " << card_pair.first << "\n";
                     if (current_selected_card_idx_ == card_pair.first) {
                       return true;
                     }
                     return false;
                   });
  if (res == listed_cards_.end()) {
    /// internal error
    std::cout << "card couldnot be found\n";
    return;
  }

  notify_editing_card_started_cb_(res->second.id);
}

void BrowseCardsScreenImpl::OnBrowseCardsDeleteClicked(wxCommandEvent& event) {
  ///
}

void BrowseCardsScreenImpl::OnCardSelected(wxListEvent& event) {
  current_selected_card_idx_ = event.GetIndex();
  std::cout << "selected card idx = " << current_selected_card_idx_ << "\n";
}

void BrowseCardsScreenImpl::ResizeList(void) {
  browseCardsListCtrlr->SetColumnWidth(0, wxLIST_AUTOSIZE_USEHEADER);
  browseCardsListCtrlr->SetColumnWidth(1, wxLIST_AUTOSIZE_USEHEADER);
}