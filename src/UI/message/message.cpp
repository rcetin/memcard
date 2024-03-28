#include "message.hpp"

Message::Message(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(210, 110)) {
  wxPanel *panel = new wxPanel(this, wxID_ANY);

  wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
  wxGridSizer *gs = new wxGridSizer(2, 2, 2, 2);

  hbox->Add(gs, 0, wxALL, 15);
  panel->SetSizer(hbox);

  Center();
}

void Message::ShowInfo(const std::string &message) const {
  wxMessageDialog *dial = new wxMessageDialog(NULL, message, wxT("Info"), wxOK);
  dial->ShowModal();
}

void Message::ShowError(const std::string &message) const {
  wxMessageDialog *dial =
      new wxMessageDialog(NULL, message, wxT("Error"), wxOK | wxICON_ERROR);
  dial->ShowModal();
}

void Message::ShowWarning(const std::string &message) const {
  wxMessageDialog *dial = new wxMessageDialog(NULL, message, wxT("Exclamation"),
                                              wxOK | wxICON_EXCLAMATION);
  dial->ShowModal();
}
