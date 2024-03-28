#ifndef UI_PRACTICE_SCREEN_IMPL_H_
#define UI_PRACTICE_SCREEN_IMPL_H_

#include <functional>
#include <vector>

#include "UI/callbacks.hpp"
#include "UI/generated/gui.h"
#include "types/card.hpp"

class PracticeScreenImpl : public PracticeScreen {
 public:
  enum class card_position {
    kFront,
    kBack,
  };

  using NotifyNoCardsToShow = std::function<void(int)>;

  PracticeScreenImpl();

  void SetCallbacks(GetAllCardsCb, NotifyAddCardCb, NotifyNoCardsToShow);

  void Show(void);
  void Show(int deck_id);

 private:
  void OnPracticeShowClicked(wxCommandEvent& event) override;
  void OnPracticeCancelClicked(wxCommandEvent& event) override;
  void OnPracticeAddCardClicked(wxCommandEvent& event) override;
  void OnPracticeNextClicked(wxCommandEvent& event) override;

  void ShowCard(const Card&, card_position);

  GetAllCardsCb get_all_cards_cb_;
  NotifyAddCardCb notify_add_card_cb_;
  NotifyNoCardsToShow notify_no_cards_to_show_cb_;
  std::vector<Card> cards_;
  int current_card_idx_;
  int current_deck_id_;
};

#endif
