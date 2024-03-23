#include "select_deck_screen_impl.hpp"

#include <wx/log.h>

#include <iostream>
#include <string>

SelectDeckScreenImpl::SelectDeckScreenImpl()
    : SelectDeckScreen(nullptr, wxID_ANY, "Select Deck", wxPoint(0, 0),
                       wxDefaultSize, 0) {
  selectDeckListCtrlr->InsertColumn(0, _("Deck Id"));
  selectDeckListCtrlr->InsertColumn(1, _("Deck Name"));
}

void SelectDeckScreenImpl::SetCallbacks(GetAllDecksCb cb) {
  get_all_decks_cb_ = cb;
}

void SelectDeckScreenImpl::Show() {
  auto decks = get_all_decks_cb_();

  std::cout << "Got decks from Select Deck screen\n";
  for (auto& deck : decks) {
    std::cout << deck.name << " " << deck.id << "\n";
    // selectDeckListCtrlr->AppendColumn(deck.name);
    long index = selectDeckListCtrlr->InsertItem(0, std::to_string(deck.id));
    selectDeckListCtrlr->SetItem(index, 1, deck.name);
  }

  SelectDeckScreen::Show(true);
}

void SelectDeckScreenImpl::OnSelectDeckClicked(wxCommandEvent& event) {
  ///
}

void SelectDeckScreenImpl::OnSelectDeckCancelClicked(wxCommandEvent& event) {
  ///
}
