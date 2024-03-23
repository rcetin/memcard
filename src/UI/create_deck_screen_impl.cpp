#include <wx/log.h>

#include <iostream>

#include "main_screen_impl.hpp"
#include "types/deck.hpp"

CreateDeckScreenImpl::CreateDeckScreenImpl()
    : CreateDeckScreen(nullptr, wxID_ANY, "Create Deck", wxPoint(0, 0),
                       wxDefaultSize, 0),
      create_new_deck_cb_{nullptr} {}

void CreateDeckScreenImpl::SetCallbacks(CreateNewDeckCb create_new_deck_cb) {
  create_new_deck_cb_ = create_new_deck_cb;
}

void CreateDeckScreenImpl::Show() { CreateDeckScreen::Show(true); }

void CreateDeckScreenImpl::Hide() { CreateDeckScreen::Show(false); }

void CreateDeckScreenImpl::OnDeckCreateClicked(wxCommandEvent& event) {
  auto text = deckNameTextBox->GetLineText(0);
  std::cout << "DECK NAME=" << text << std::endl;
  auto d = Deck{text.ToStdString(), -1};
  create_new_deck_cb_(d);
}

void CreateDeckScreenImpl::OnCreateDeckCancelClicked(wxCommandEvent& event) {
  CreateDeckScreen::Show(false);
}
