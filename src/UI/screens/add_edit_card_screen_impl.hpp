#ifndef UI_EDIT_CARD_SCREEN_IMPL_H_
#define UI_EDIT_CARD_SCREEN_IMPL_H_

#include "UI/callbacks.hpp"
#include "UI/generated/gui.h"

class AddEditCardScreenImpl : public AddEditCardScreen {
 public:
  enum class Operation { kAdd, kEdit };

  AddEditCardScreenImpl();

  void SetCallbacks(CreateNewCardCb);
  void Show();
  void Show(Operation, int deck_id);

 private:
  void OnAddEditCardSaveClicked(wxCommandEvent& event) override;
  void OnAddEditCardCancelClicked(wxCommandEvent& event) override;

  static constexpr const char* add_operation_title = "Add Card";
  static constexpr const char* edit_operation_title = "Edit Card";
  static constexpr const char* add_button_title = "Add";
  static constexpr const char* edit_button_title = "Edit";

  CreateNewCardCb create_new_card_cb_;
  int current_deck_id_;
};

#endif
