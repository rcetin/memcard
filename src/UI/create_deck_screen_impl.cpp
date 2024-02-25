#include <wx/log.h>

#include "main_screen_impl.hpp"

CreateDeckScreenImpl::CreateDeckScreenImpl()
    : CreateDeckScreen(nullptr, wxID_ANY, "Create Deck", wxPoint(0, 0),
                       wxDefaultSize, 0) {}

void CreateDeckScreenImpl::Show() { CreateDeckScreen::Show(true); }

void CreateDeckScreenImpl::OnDeckCreateClicked(wxCommandEvent& event) {}
