#include "browse_cards_screen_impl.hpp"

#include <wx/log.h>

#include "UI/message/message.hpp"
#include "types/deck.hpp"

BrowseCardsScreenImpl::BrowseCardsScreenImpl()
    : BrowseCardsScreen(nullptr, wxID_ANY, "Browse Card", wxPoint(0, 0),
                        wxDefaultSize, 0),
      get_all_cards_cb_{nullptr} {
  browseCardsListCtrlr->InsertColumn(0, _("Front"));
  browseCardsListCtrlr->InsertColumn(1, _("Back"));
}

void BrowseCardsScreenImpl::Show(int deck_id) {
  auto cards = get_all_cards_cb_(deck_id);

  std::cout << "Got " << cards.size()
            << "number of cards from deck id=" << deck_id << "\n";

  for (auto& card : cards) {
    std::cout << card.front << " " << card.back << "\n";

    long index = browseCardsListCtrlr->InsertItem(0, card.front);
    browseCardsListCtrlr->SetItem(index, 1, card.back);

    ResizeList();
  }

  BrowseCardsScreen::Show(true);
}

void BrowseCardsScreenImpl::SetCallbacks(GetAllCardsCb get_all_cards_cb) {
  get_all_cards_cb_ = get_all_cards_cb;
}

void BrowseCardsScreenImpl::OnBrowseCardsShowClicked(wxCommandEvent& event) {
  ///
}

void BrowseCardsScreenImpl::OnBrowseCardsEditClicked(wxCommandEvent& event) {
  ///
}

void BrowseCardsScreenImpl::OnBrowseCardsDeleteClicked(wxCommandEvent& event) {
  ///
}

void BrowseCardsScreenImpl::OnWindowSizeChanged(wxSizeEvent& event) {
  wxLogDebug("List Size changed");

  // ResizeList();
  event.Skip();
}

void BrowseCardsScreenImpl::ResizeList(void) {
  browseCardsListCtrlr->SetColumnWidth(0, wxLIST_AUTOSIZE_USEHEADER);
  browseCardsListCtrlr->SetColumnWidth(1, wxLIST_AUTOSIZE_USEHEADER);
}