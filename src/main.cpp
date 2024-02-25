#include <wx/wx.h>

#include "UI/main_screen_impl.hpp"

class MyApp : public wxApp {
 public:
  bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
  MainScreenImpl* main_screen = new MainScreenImpl();
  main_screen->Show();

  return true;
}
