#ifndef UI_CREATE_DECK_SCREEN_IMPL_H_
#define UI_CREATE_DECK_SCREEN_IMPL_H_

#include "generated/gui.h"

class CreateDeckScreenImpl : public CreateDeckScreen {
 public:
  CreateDeckScreenImpl();

  void Show();

 private:
  void OnDeckCreateClicked(wxCommandEvent& event) override;
};

#endif
