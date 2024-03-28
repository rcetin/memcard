#include "add_edit_card_screen_impl.hpp"

#include <wx/log.h>

#include "UI/message/message.hpp"
#include "generator/uuid.hpp"
#include "types/card.hpp"

AddEditCardScreenImpl::AddEditCardScreenImpl()
    : AddEditCardScreen(nullptr, wxID_ANY, "Edit Card", wxPoint(0, 0),
                        wxDefaultSize, 0),
      current_deck_id_{-1} {}

void AddEditCardScreenImpl::SetCallbacks(CreateNewCardCb create_new_card_cb) {
  create_new_card_cb_ = create_new_card_cb;
}

void AddEditCardScreenImpl::Show() { AddEditCardScreen::Show(true); }

void AddEditCardScreenImpl::Show(Operation op, int deck_id) {
  current_deck_id_ = deck_id;
  add_edit_card_title->SetLabel(op == Operation::kEdit ? edit_operation_title
                                                       : add_operation_title);
  addEditCardSaveBtn->SetLabel(op == Operation::kEdit ? edit_button_title
                                                      : add_button_title);

  AddEditCardScreen::Show(true);
}

void AddEditCardScreenImpl::OnAddEditCardSaveClicked(wxCommandEvent& event) {
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
