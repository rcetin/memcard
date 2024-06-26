#ifndef UI_SELECT_DECK_SCREEN_IMPL_H_
#define UI_SELECT_DECK_SCREEN_IMPL_H_

#include "UI/callbacks.hpp"
#include "UI/generated/gui.h"

class SelectDeckScreenImpl : public SelectDeckScreen {
 public:
  using NotifyDeckPracticeStarted = std::function<void(int deck_id)>;
  using NotifyDeckBrowseStarted = std::function<void(int deck_id)>;

  SelectDeckScreenImpl();

  void SetCallbacks(GetAllDecksCb get_all_decks_cb,
                    GetAllCardsCb get_all_cards_cb,
                    NotifyDeckPracticeStarted notify_deck_practice_started,
                    NotifyDeckBrowseStarted notify_deck_browse_started);

  void Show();

 private:
  void OnSelectDeckPracticeClicked(wxCommandEvent& event) override;
  void OnSelectDeckCancelClicked(wxCommandEvent& event) override;
  void OnSelectDeckBrowseClicked(wxCommandEvent& event) override;
  void OnItemSelected(wxListEvent& event) override;

  void ResizeList(void);

  void ClearDecksList(void);

  GetAllDecksCb get_all_decks_cb_;
  GetAllCardsCb get_all_cards_cb_;
  NotifyDeckPracticeStarted notify_deck_practice_started_;
  NotifyDeckBrowseStarted notify_deck_browse_started_;
  int selected_deck_idx;
};

#endif
