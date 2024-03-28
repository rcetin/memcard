#ifndef UI_MAIN_SCREEN_IMPL_H_
#define UI_MAIN_SCREEN_IMPL_H_

#include <functional>

#include "UI/generated/gui.h"
#include "add_card_boarding_screen_impl.hpp"
#include "add_edit_card_screen_impl.hpp"
#include "create_deck_screen_impl.hpp"
#include "practice_screen_impl.hpp"
#include "select_deck_screen_impl.hpp"
#include "show_card_screen_impl.hpp"
#include "types/card.hpp"
#include "types/deck.hpp"

class MainScreenImpl : public MainScreen {
 public:
  MainScreenImpl();

  void SetCallbacks(CreateNewDeckCb, CreateNewCardCb, GetAllCardsCb,
                    GetAllDecksCb);

  void Show();

 private:
  CreateDeckScreenImpl* create_deck_screen_;
  AddEditCardScreenImpl* add_edit_card_screen_;
  SelectDeckScreenImpl* select_deck_screen_;
  ShowCardScreenImpl* show_card_screen_;
  PracticeScreenImpl* practice_screen_;
  AddCardBoardingScreenImpl* add_card_boarding_screen_;

  CreateNewCardCb create_new_card_cb_;
  CreateNewDeckCb create_new_deck_cb_;
  GetAllCardsCb get_all_cards_cb_;
  GetAllDecksCb get_all_decks_cb_;

  void onCreateDeckClicked(wxCommandEvent& event) override;
  void OnPracticeClicked(wxCommandEvent& event) override;
  void OnQuitClicked(wxCommandEvent& event) override;

  /// Callbacks
  void OnNewDeckCreateRequestReceived(Deck&) const;
  void OnNewCardCreateRequestReceived(const Deck&, Card&) const;
  void OnStartPracticeRequestReceived(int deck_id) const;
  void OnAddCardRequestReceived(int deck_id) const;
  void OnNoCardsToShowRequestReceived(int deck_id) const;

  int current_deck_id_;
};

MainScreen* CreateMainScreen();

#endif