#include <wx/wx.h>

#include "gui_manager.hpp"

class MyApp : public wxApp {
 public:
  bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

std::unique_ptr<GUIManager> gui;

bool MyApp::OnInit() {
  gui = CreateGUIManager();
  gui->StartApplication();

  return true;
}
