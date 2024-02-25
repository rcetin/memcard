#ifndef UI_EDIT_CARD_SCREEN_IMPL_H_
#define UI_EDIT_CARD_SCREEN_IMPL_H_

#include "generated/gui.h"

class EditCardScreenImpl : public EditCardScreen {
 public:
  EditCardScreenImpl();

  void Show();

 private:
  void OnEditCardSaveClicked(wxCommandEvent& event) override;
  void OnEditCardCancelClicked(wxCommandEvent& event) override;
};

#endif
