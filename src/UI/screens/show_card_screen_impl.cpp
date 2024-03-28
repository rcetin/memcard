#include "show_card_screen_impl.hpp"

#include <wx/log.h>

ShowCardScreenImpl::ShowCardScreenImpl()
    : ShowCardScreen(nullptr, wxID_ANY, "Show Card", wxPoint(0, 0),
                     wxDefaultSize, 0) {}

void ShowCardScreenImpl::Show() { ShowCardScreen::Show(true); }

void ShowCardScreenImpl::OnShowCardNextClicked(wxCommandEvent& event) {}

void ShowCardScreenImpl::OnShowCardCancelClicked(wxCommandEvent& event) {}
