#include "main_screen_impl.hpp"

#include <wx/log.h>

#include "create_deck_screen_impl.hpp"
#include "edit_card_screen_impl.hpp"

MainScreenImpl::MainScreenImpl()
    : MainScreen(nullptr, wxID_ANY, "MemCard", wxPoint(0, 0), wxDefaultSize,
                 0) {
  createDeckScreen = new CreateDeckScreenImpl();
  editCardScreen = new EditCardScreenImpl();
}

void MainScreenImpl::Show() { MainScreen::Show(true); }

void MainScreenImpl::onCreateDeckClicked(wxCommandEvent& event) {
  MainScreen::Show(false);
  //   createDeckScreen->Show();
  editCardScreen->Show();
}

void MainScreenImpl::OnPracticeClicked(wxCommandEvent& event) {}

void MainScreenImpl::OnQuitClicked(wxCommandEvent& event) { Close(); }
