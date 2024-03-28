#include <wx/wx.h>

class Message : public wxFrame {
 public:
  Message(const wxString& title);

  void ShowInfo(const std::string&) const;
  void ShowWarning(const std::string&) const;
  void ShowError(const std::string&) const;
};
