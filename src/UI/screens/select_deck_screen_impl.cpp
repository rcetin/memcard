#include "select_deck_screen_impl.hpp"

#include <wx/log.h>

#include <iostream>
#include <string>

#include "UI/message/message.hpp"

SelectDeckScreenImpl::SelectDeckScreenImpl()
    : SelectDeckScreen(nullptr, wxID_ANY, "Select Deck", wxPoint(0, 0),
                       wxDefaultSize, 0),
      get_all_decks_cb_{nullptr},
      start_practice_cb_{nullptr},
      selected_deck_idx{-1} {
  selectDeckListCtrlr->InsertColumn(0, _("Deck Id"));
  selectDeckListCtrlr->InsertColumn(1, _("Deck Name"));
}

void SelectDeckScreenImpl::SetCallbacks(GetAllDecksCb get_all_decks_cb,
                                        StartPracticeCb start_practice_cb) {
  get_all_decks_cb_ = get_all_decks_cb;
  start_practice_cb_ = start_practice_cb;
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
  if (-1 == selected_deck_idx) {
    std::cout << "No deck is selected\n";
    Message* msgs = new Message(wxT("Messages"));
    msgs->ShowWarning("Please select a deck before practicing");
    return;
  }

  start_practice_cb_(selected_deck_idx);
  selected_deck_idx = -1;
  ClearDecksList();
  SelectDeckScreen::Show(false);
}

void SelectDeckScreenImpl::OnItemSelected(wxListEvent& event) {
  selected_deck_idx = std::stoi(event.GetLabel().ToStdString());
  std::cout << "Selected deck idx= " << selected_deck_idx << "\n";
}

void SelectDeckScreenImpl::OnSelectDeckCancelClicked(wxCommandEvent& event) {
  ClearDecksList();
  SelectDeckScreen::Show(false);
}

void SelectDeckScreenImpl::ClearDecksList(void) {
  selectDeckListCtrlr->DeleteAllItems();
}