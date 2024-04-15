#ifndef UI_BROWSE_CARDS_SCREEN_IMPL_H_
#define UI_BROWSE_CARDS_SCREEN_IMPL_H_

#include <functional>
#include <vector>

#include "UI/callbacks.hpp"
#include "UI/generated/gui.h"
#include "types/card.hpp"

class BrowseCardsScreenImpl : public BrowseCardsScreen {
 public:
  BrowseCardsScreenImpl();

  void SetCallbacks(GetAllCardsCb get_all_cards_cb);

  void Show(int deck_id);

 private:
  void OnBrowseCardsShowClicked(wxCommandEvent& event) override;
  void OnBrowseCardsEditClicked(wxCommandEvent& event) override;
  void OnBrowseCardsDeleteClicked(wxCommandEvent& event) override;
  void OnWindowSizeChanged(wxSizeEvent& event) override;

  void ResizeList(void);

  GetAllCardsCb get_all_cards_cb_;
};

#endif
