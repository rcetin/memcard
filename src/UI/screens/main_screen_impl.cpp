#include "main_screen_impl.hpp"

#include <wx/log.h>

#include "add_edit_card_screen_impl.hpp"
#include "create_deck_screen_impl.hpp"

MainScreenImpl::MainScreenImpl()
    : MainScreen(nullptr, wxID_ANY, "MemCard", wxPoint(0, 0), wxDefaultSize, 0),
      create_deck_screen_{new CreateDeckScreenImpl()},
      add_edit_card_screen_{new AddEditCardScreenImpl()},
      select_deck_screen_{new SelectDeckScreenImpl()},
      show_card_screen_{new ShowCardScreenImpl()},
      practice_screen_{new PracticeScreenImpl()},
      add_card_boarding_screen_{new AddCardBoardingScreenImpl()},
      browse_cards_screen_{new BrowseCardsScreenImpl()},
      create_new_card_cb_{nullptr},
      create_new_deck_cb_{nullptr},
      get_all_cards_cb_{nullptr},
      get_all_decks_cb_{nullptr},
      notify_practice_started_cb_{nullptr},
      notify_practice_ended_cb_{nullptr},
      get_card_cb_{nullptr},
      edit_card_cb_{nullptr},
      current_deck_id_{-1} {}

void MainScreenImpl::Show() { MainScreen::Show(true); }

void MainScreenImpl::SetCallbacks(
    CreateNewDeckCb create_new_deck_cb, CreateNewCardCb create_new_card_cb,
    GetAllCardsCb get_all_cards_cb, GetAllDecksCb get_all_decks_cb,
    NotifyPracticeStartedCb notify_practice_started_cb,
    NotifyPracticeEndedCb notify_practice_ended_cb, GetCardCb get_card_cb,
    GetCardByIdCb get_card_by_id_cb, EditCardCb edit_card_cb) {
  create_deck_screen_->SetCallbacks(
      std::bind(&MainScreenImpl::OnNewDeckCreateRequestReceived, this,
                std::placeholders::_1));

  select_deck_screen_->SetCallbacks(
      get_all_decks_cb, get_all_cards_cb,
      std::bind(&MainScreenImpl::OnDeckPracticeStartedRequestReceived, this,
                std::placeholders::_1),
      std::bind(&MainScreenImpl::OnDeckBrowseStartedRequestReceived, this,
                std::placeholders::_1));

  browse_cards_screen_->SetCallbacks(
      get_all_cards_cb, std::bind(&MainScreenImpl::OnEditingCardStarted, this,
                                  std::placeholders::_1));

  practice_screen_->SetCallbacks(
      get_card_cb,
      std::bind(&MainScreenImpl::OnAddCardRequestReceived, this,
                std::placeholders::_1),
      std::bind(&MainScreenImpl::OnNoCardsToShowRequestReceived, this,
                std::placeholders::_1));

  add_card_boarding_screen_->SetCallbacks(std::bind(
      &MainScreenImpl::OnAddCardRequestReceived, this, std::placeholders::_1));

  add_edit_card_screen_->SetCallbacks(
      create_new_card_cb, get_card_by_id_cb, edit_card_cb,
      std::bind(&MainScreenImpl::OnAddEditingCompleted, this,
                std::placeholders::_1));

  create_new_deck_cb_ = create_new_deck_cb;
  create_new_card_cb_ = create_new_card_cb;
  get_all_cards_cb_ = get_all_cards_cb;
  get_all_decks_cb_ = get_all_decks_cb;
  notify_practice_started_cb_ = notify_practice_started_cb;
  notify_practice_ended_cb_ = notify_practice_ended_cb;
  get_card_cb_ = get_card_cb;
  get_card_by_id_cb_ = get_card_by_id_cb;
  edit_card_cb_ = edit_card_cb;
}

void MainScreenImpl::OnDeckBrowseStartedRequestReceived(int deck_id) const {
  select_deck_screen_->Hide();
  browse_cards_screen_->Show(deck_id);
}

void MainScreenImpl::OnDeckPracticeStartedRequestReceived(int deck_id) const {
  std::cout << "Start Practice Clicked for deck id = " << deck_id << "\n";

  auto cards = get_all_cards_cb_(deck_id);
  if (cards.empty()) {
    add_card_boarding_screen_->Show(
        deck_id, AddCardBoardingScreenImpl::BoardingReason::kNoCardsInDeck);
    return;
  }

  notify_practice_started_cb_(deck_id);
  practice_screen_->Show(deck_id);
}

void MainScreenImpl::OnAddCardRequestReceived(int deck_id) const {
  add_edit_card_screen_->Show(AddEditCardScreenImpl::Operation::kAdd, deck_id);
}

void MainScreenImpl::OnNoCardsToShowRequestReceived(int deck_id) const {
  add_card_boarding_screen_->Show(
      deck_id, AddCardBoardingScreenImpl::BoardingReason::kCardsAreCompleted);
  practice_screen_->Hide();
}

void MainScreenImpl::OnEditingCardStarted(int card_id) const {
  std::cout << "Editing started for card id=" << card_id << "\n";
  add_edit_card_screen_->Show(AddEditCardScreenImpl::Operation::kEdit, card_id);
}

void MainScreenImpl::OnAddEditingCompleted(const Card& card) const {
  browse_cards_screen_->Show(card.deck_id);
}

void MainScreenImpl::onCreateDeckClicked(wxCommandEvent& event) {
  create_deck_screen_->Show();
}

void MainScreenImpl::OnQuitClicked(wxCommandEvent& event) {
  Close(true);
  exit(0);
}

void MainScreenImpl::OnNewDeckCreateRequestReceived(Deck& deck) const {
  create_new_deck_cb_(deck);
  select_deck_screen_->Show();
}

void MainScreenImpl::OnBrowseDecksClicked(wxCommandEvent& event) {
  select_deck_screen_->Show();
}

MainScreen* CreateMainScreen() { return new MainScreenImpl(); }