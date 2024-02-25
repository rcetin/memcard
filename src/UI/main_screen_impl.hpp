#ifndef UI_MAIN_SCREEN_IMPL_H_
#define UI_MAIN_SCREEN_IMPL_H_

#include "create_deck_screen_impl.hpp"
#include "edit_card_screen_impl.hpp"
#include "generated/gui.h"

class MainScreenImpl : public MainScreen {
 public:
  MainScreenImpl();

  void Show();

 private:
  CreateDeckScreenImpl* createDeckScreen;
  EditCardScreenImpl* editCardScreen;

  void onCreateDeckClicked(wxCommandEvent& event) override;
  void OnPracticeClicked(wxCommandEvent& event) override;
  void OnQuitClicked(wxCommandEvent& event) override;
};

#endif