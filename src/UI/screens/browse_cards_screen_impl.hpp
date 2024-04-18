#ifndef UI_BROWSE_CARDS_SCREEN_IMPL_H_
#define UI_BROWSE_CARDS_SCREEN_IMPL_H_

#include <functional>
#include <vector>

#include "UI/callbacks.hpp"
#include "UI/generated/gui.h"
#include "types/card.hpp"

class BrowseCardsScreenImpl : public BrowseCardsScreen {
 public:
  using NotifyEditingCardStartedCb = std::function<void(int card_id)>;

  BrowseCardsScreenImpl();
  ~BrowseCardsScreenImpl() {
    std::cout << "destructor of BrowseCardsScreenImpl\n";
  }

  void SetCallbacks(GetAllCardsCb get_all_cards_cb,
                    NotifyEditingCardStartedCb notify_editing_card_started_cb);

  void Show(int deck_id);

 private:
  void OnBrowseCardsShowClicked(wxCommandEvent& event) override;
  void OnBrowseCardsEditClicked(wxCommandEvent& event) override;
  void OnBrowseCardsDeleteClicked(wxCommandEvent& event) override;
  void OnCardSelected(wxListEvent& event) override;

  void ResizeList(void);

  GetAllCardsCb get_all_cards_cb_;
  NotifyEditingCardStartedCb notify_editing_card_started_cb_;
  int current_selected_card_idx_;
  std::vector<std::pair<int, Card>> listed_cards_;
};

#endif
