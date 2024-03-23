#ifndef UI_SELECT_DECK_SCREEN_IMPL_H_
#define UI_SELECT_DECK_SCREEN_IMPL_H_

#include "callbacks.hpp"
#include "generated/gui.h"

class SelectDeckScreenImpl : public SelectDeckScreen {
 public:
  SelectDeckScreenImpl();

  void SetCallbacks(GetAllDecksCb);

  void Show();

 private:
  void OnSelectDeckClicked(wxCommandEvent& event) override;
  void OnSelectDeckCancelClicked(wxCommandEvent& event) override;
  GetAllDecksCb get_all_decks_cb_;
};

#endif
