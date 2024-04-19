#ifndef UI_MAIN_SCREEN_IMPL_H_
#define UI_MAIN_SCREEN_IMPL_H_

#include <functional>

#include "UI/generated/gui.h"
#include "add_card_boarding_screen_impl.hpp"
#include "add_edit_card_screen_impl.hpp"
#include "browse_cards_screen_impl.hpp"
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
                    GetAllDecksCb, NotifyPracticeStartedCb,
                    NotifyPracticeEndedCb, GetCardCb, GetCardByIdCb,
                    EditCardCb);

  void Show();

 private:
  CreateDeckScreenImpl* create_deck_screen_;
  AddEditCardScreenImpl* add_edit_card_screen_;
  SelectDeckScreenImpl* select_deck_screen_;
  ShowCardScreenImpl* show_card_screen_;
  PracticeScreenImpl* practice_screen_;
  AddCardBoardingScreenImpl* add_card_boarding_screen_;
  BrowseCardsScreenImpl* browse_cards_screen_;

  CreateNewCardCb create_new_card_cb_;
  CreateNewDeckCb create_new_deck_cb_;
  GetAllCardsCb get_all_cards_cb_;
  GetAllDecksCb get_all_decks_cb_;
  NotifyPracticeStartedCb notify_practice_started_cb_;
  NotifyPracticeEndedCb notify_practice_ended_cb_;
  GetCardCb get_card_cb_;
  EditCardCb edit_card_cb_;
  GetCardByIdCb get_card_by_id_cb_;

  void onCreateDeckClicked(wxCommandEvent& event) override;
  void OnQuitClicked(wxCommandEvent& event) override;
  void OnBrowseDecksClicked(wxCommandEvent& event) override;

  /// Callbacks
  void OnNewDeckCreateRequestReceived(Deck&) const;
  void OnNewCardCreateRequestReceived(const Deck&, Card&) const;
  void OnDeckPracticeStartedRequestReceived(int deck_id) const;
  void OnDeckBrowseStartedRequestReceived(int deck_id) const;
  void OnAddCardRequestReceived(int deck_id) const;
  void OnNoCardsToShowRequestReceived(int deck_id) const;
  void OnEditingCardStarted(int card_id) const;
  void OnAddEditingCompleted(const Card& card) const;

  int current_deck_id_;
};

MainScreen* CreateMainScreen();

#endif