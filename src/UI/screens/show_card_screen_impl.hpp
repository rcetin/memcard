#ifndef UI_SHOW_CARD_SCREEN_IMPL_H_
#define UI_SHOW_CARD_SCREEN_IMPL_H_

#include "UI/generated/gui.h"

class ShowCardScreenImpl : public ShowCardScreen {
 public:
  ShowCardScreenImpl();

  void Show();

 private:
  void OnShowCardNextClicked(wxCommandEvent& event) override;
  void OnShowCardCancelClicked(wxCommandEvent& event) override;
};

#endif
