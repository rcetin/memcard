#include "select_deck_screen_impl.hpp"

#include <wx/log.h>

#include <algorithm>
#include <iostream>
#include <string>

#include "UI/message/message.hpp"

SelectDeckScreenImpl::SelectDeckScreenImpl()
    : SelectDeckScreen(nullptr, wxID_ANY, "Select Deck", wxPoint(0, 0),
                       wxDefaultSize, 0),
      get_all_decks_cb_{nullptr},
      notify_deck_selected_{nullptr},
      selected_deck_idx{-1} {
  selectDeckListCtrlr->InsertColumn(0, _("Id"));
  selectDeckListCtrlr->InsertColumn(1, _("Name"));
  ResizeList();
}

void SelectDeckScreenImpl::SetCallbacks(
    GetAllDecksCb get_all_decks_cb, NotifyDeckSelected notify_deck_selected) {
  get_all_decks_cb_ = get_all_decks_cb;
  notify_deck_selected_ = notify_deck_selected;
}

void SelectDeckScreenImpl::ResizeList(void) {
  selectDeckListCtrlr->SetColumnWidth(0, wxLIST_AUTOSIZE_USEHEADER);
  selectDeckListCtrlr->SetColumnWidth(1, wxLIST_AUTOSIZE_USEHEADER);
}

void SelectDeckScreenImpl::Show() {
  auto decks = get_all_decks_cb_();

  std::cout << "Got decks from Select Deck screen\n";

  std::sort(decks.begin(), decks.end(),
            [](const Deck& l, const Deck& r) { return l.id > r.id; });

  for (auto& deck : decks) {
    std::cout << deck.name << " " << deck.id << "\n";

    long index = selectDeckListCtrlr->InsertItem(0, std::to_string(deck.id));
    selectDeckListCtrlr->SetItem(index, 1, deck.name);
    ResizeList();
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

  notify_deck_selected_(selected_deck_idx);
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