#ifndef UI_SELECT_DECK_SCREEN_IMPL_H_
#define UI_SELECT_DECK_SCREEN_IMPL_H_

#include "UI/callbacks.hpp"
#include "UI/generated/gui.h"

class SelectDeckScreenImpl : public SelectDeckScreen {
 public:
  using NotifyDeckSelected = std::function<void(int deck_id)>;

  SelectDeckScreenImpl();

  void SetCallbacks(GetAllDecksCb get_all_decks_cb,
                    NotifyDeckSelected notify_deck_selected);

  void Show();

 private:
  void OnSelectDeckClicked(wxCommandEvent& event) override;
  void OnSelectDeckCancelClicked(wxCommandEvent& event) override;
  void OnItemSelected(wxListEvent& event) override;

  void ResizeList(void);

  void ClearDecksList(void);

  GetAllDecksCb get_all_decks_cb_;
  NotifyDeckSelected notify_deck_selected_;
  int selected_deck_idx;
};

#endif
