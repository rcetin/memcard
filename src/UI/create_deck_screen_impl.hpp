#ifndef UI_CREATE_DECK_SCREEN_IMPL_H_
#define UI_CREATE_DECK_SCREEN_IMPL_H_

#include "callbacks.hpp"
#include "generated/gui.h"

class CreateDeckScreenImpl : public CreateDeckScreen {
 public:
  CreateDeckScreenImpl();

  void SetCallbacks(CreateNewDeckCb);

  void Show();
  void Hide();

 private:
  void OnDeckCreateClicked(wxCommandEvent& event) override;
  void OnCreateDeckCancelClicked(wxCommandEvent& event) override;

  CreateNewDeckCb create_new_deck_cb_;
};

#endif
