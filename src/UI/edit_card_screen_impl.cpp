#include <wx/log.h>

#include "main_screen_impl.hpp"

EditCardScreenImpl::EditCardScreenImpl()
    : EditCardScreen(nullptr, wxID_ANY, "Edit Card", wxPoint(0, 0),
                     wxDefaultSize, 0) {}

void EditCardScreenImpl::Show() { EditCardScreen::Show(true); }

void EditCardScreenImpl::OnEditCardSaveClicked(wxCommandEvent& event) {}

void EditCardScreenImpl::OnEditCardCancelClicked(wxCommandEvent& event) {}
