#include "add_edit_card_screen_impl.hpp"

#include <wx/log.h>

#include "UI/message/message.hpp"
#include "generator/uuid.hpp"
#include "types/card.hpp"

AddEditCardScreenImpl::AddEditCardScreenImpl()
    : AddEditCardScreen(nullptr, wxID_ANY, "Edit Card", wxPoint(0, 0),
                        wxDefaultSize, 0),
      create_new_card_cb_(nullptr),
      get_card_by_id_cb_(nullptr),
      edit_card_cb_(nullptr),
      notify_add_edit_completed_cb_(nullptr),
      current_deck_id_{-1} {}

void AddEditCardScreenImpl::SetCallbacks(
    CreateNewCardCb create_new_card_cb, GetCardByIdCb get_card_by_id_cb,
    EditCardCb edit_card_cb,
    NotifyAddEditCompleted notify_add_edit_completed_cb) {
  create_new_card_cb_ = create_new_card_cb;
  get_card_by_id_cb_ = get_card_by_id_cb;
  edit_card_cb_ = edit_card_cb;
  notify_add_edit_completed_cb_ = notify_add_edit_completed_cb;
}

void AddEditCardScreenImpl::Show() { AddEditCardScreen::Show(true); }

void AddEditCardScreenImpl::Show(Operation op, int id) {
  current_op_ = op;
  if (op == Operation::kEdit) {
    ArrangeEditCardScreen(id);
  } else {
    ArrangeAddCardScreen(id);
  }

  AddEditCardScreen::Show(true);
}

void AddEditCardScreenImpl::ArrangeAddCardScreen(int deck_id) {
  current_deck_id_ = deck_id;
  add_edit_card_title->SetLabel(add_operation_title);
  addEditCardSaveBtn->SetLabel(add_button_title);
}

void AddEditCardScreenImpl::ArrangeEditCardScreen(int card_id) {
  current_edited_card_id_ = card_id;
  add_edit_card_title->SetLabel(edit_operation_title);
  addEditCardSaveBtn->SetLabel(edit_button_title);

  auto card_opt = get_card_by_id_cb_(current_edited_card_id_);
  if (!card_opt.has_value()) {
    /// internal error
    return;
  }

  current_edited_card_ = card_opt.value();

  cardFrontTextBox->SetValue(current_edited_card_.front);
  cardBackTextBox->SetValue(current_edited_card_.back);
}

void AddEditCardScreenImpl::OnAddEditCardSaveClicked(wxCommandEvent& event) {
  if (current_op_ == Operation::kEdit) {
    current_edited_card_.front = cardFrontTextBox->GetValue().ToStdString();
    current_edited_card_.back = cardBackTextBox->GetValue().ToStdString();

    edit_card_cb_(current_edited_card_id_, current_edited_card_);

    std::cout << "Card edited!!\n";
    Message m("");
    m.ShowInfo("Card is edited successfully");

    Hide();
    notify_add_edit_completed_cb_(current_edited_card_);

    return;
  }

  std::cout << "Add button clicked with front= "
            << cardFrontTextBox->GetValue().ToStdString()
            << " back=" << cardBackTextBox->GetValue().ToStdString() << "\n";

  UUIDGenerator gen;
  Card card{gen.GenerateUUID(), cardFrontTextBox->GetValue().ToStdString(),
            cardBackTextBox->GetValue().ToStdString(), -1, current_deck_id_};

  std::cout << "AddEdit: adding card into deck id= " << current_deck_id_
            << "\n";
  create_new_card_cb_(current_deck_id_, card);

  Message m("");
  m.ShowInfo("Card is created");

  cardFrontTextBox->SetValue("");
  cardBackTextBox->SetValue("");
}

void AddEditCardScreenImpl::OnAddEditCardCancelClicked(wxCommandEvent& event) {
  AddEditCardScreen::Show(false);
}
