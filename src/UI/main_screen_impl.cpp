#include "main_screen_impl.hpp"

#include <wx/log.h>

#include "create_deck_screen_impl.hpp"
#include "edit_card_screen_impl.hpp"

MainScreenImpl::MainScreenImpl()
    : MainScreen(nullptr, wxID_ANY, "MemCard", wxPoint(0, 0), wxDefaultSize, 0),
      create_deck_screen_{new CreateDeckScreenImpl()},
      edit_card_screen_{new EditCardScreenImpl()},
      select_deck_screen_{new SelectDeckScreenImpl()},
      create_new_card_cb_{nullptr},
      get_all_cards_cb_{nullptr} {}

void MainScreenImpl::Show() { MainScreen::Show(true); }

void MainScreenImpl::SetCallbacks(CreateNewDeckCb create_new_deck_cb,
                                  CreateNewCardCb create_new_card_cb,
                                  GetAllCardsCb get_all_cards_cb,
                                  GetAllDecksCb get_all_decks_cb) {
  create_deck_screen_->SetCallbacks(
      std::bind(&MainScreenImpl::OnNewDeckCreateRequestReceived, this,
                std::placeholders::_1));

  select_deck_screen_->SetCallbacks(get_all_decks_cb);

  create_new_deck_cb_ = create_new_deck_cb;
  create_new_card_cb_ = create_new_card_cb;
  get_all_cards_cb_ = get_all_cards_cb;
  get_all_decks_cb_ = get_all_decks_cb;
}

void MainScreenImpl::onCreateDeckClicked(wxCommandEvent& event) {
  create_deck_screen_->Show();
}

void MainScreenImpl::OnPracticeClicked(wxCommandEvent& event) {}

void MainScreenImpl::OnQuitClicked(wxCommandEvent& event) {
  Close(true);
  exit(0);
}

void MainScreenImpl::OnNewDeckCreateRequestReceived(Deck& deck) const {
  create_new_deck_cb_(deck);
  select_deck_screen_->Show();
}

MainScreen* CreateMainScreen() { return new MainScreenImpl(); }