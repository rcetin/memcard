///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.0.0-0-g0efcecf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/listctrl.h>
#include <wx/statline.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainScreen
///////////////////////////////////////////////////////////////////////////////
class MainScreen : public wxFrame
{
	private:

	protected:
		wxStaticText* welcome_title;
		wxButton* create_deck_btn;
		wxButton* practice_btn;
		wxButton* quit_btn;

		// Virtual event handlers, override them in your derived class
		virtual void onCreateDeckClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPracticeClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnQuitClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainScreen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("MemCard"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainScreen();

};

///////////////////////////////////////////////////////////////////////////////
/// Class CreateDeckScreen
///////////////////////////////////////////////////////////////////////////////
class CreateDeckScreen : public wxFrame
{
	private:

	protected:
		wxStaticText* create_dec_title;
		wxStaticText* deckNameText;
		wxTextCtrl* deckNameTextBox;
		wxButton* deckCreateBtn;
		wxButton* createDeckCancelBtn;

		// Virtual event handlers, override them in your derived class
		virtual void OnDeckCreateClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCreateDeckCancelClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		CreateDeckScreen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~CreateDeckScreen();

};

///////////////////////////////////////////////////////////////////////////////
/// Class SelectDeckScreen
///////////////////////////////////////////////////////////////////////////////
class SelectDeckScreen : public wxFrame
{
	private:

	protected:
		wxStaticText* select_deck_title;
		wxListCtrl* selectDeckListCtrlr;
		wxButton* SelectDeckSelectBtn;
		wxButton* SelectDeckCancelBtn;

		// Virtual event handlers, override them in your derived class
		virtual void OnItemSelected( wxListEvent& event ) { event.Skip(); }
		virtual void OnSelectDeckClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectDeckCancelClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		SelectDeckScreen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~SelectDeckScreen();

};

///////////////////////////////////////////////////////////////////////////////
/// Class AddEditCardScreen
///////////////////////////////////////////////////////////////////////////////
class AddEditCardScreen : public wxFrame
{
	private:

	protected:
		wxStaticText* add_edit_card_title;
		wxTextCtrl* cardFrontTextBox;
		wxStaticLine* m_staticline1;
		wxTextCtrl* cardBackTextBox;
		wxButton* addEditCardSaveBtn;
		wxButton* addEditCardCancelBtn;

		// Virtual event handlers, override them in your derived class
		virtual void OnAddEditCardSaveClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddEditCardCancelClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		AddEditCardScreen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~AddEditCardScreen();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ShowCardScreen
///////////////////////////////////////////////////////////////////////////////
class ShowCardScreen : public wxFrame
{
	private:

	protected:
		wxStaticText* show_card_title;
		wxTextCtrl* cardFrontTextBox;
		wxStaticLine* m_staticline1;
		wxTextCtrl* cardBackTextBox;
		wxButton* showCardNextBtn;
		wxButton* showCardCancelBtn;

		// Virtual event handlers, override them in your derived class
		virtual void OnShowCardNextClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnShowCardCancelClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		ShowCardScreen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~ShowCardScreen();

};

///////////////////////////////////////////////////////////////////////////////
/// Class PracticeScreen
///////////////////////////////////////////////////////////////////////////////
class PracticeScreen : public wxFrame
{
	private:

	protected:
		wxStaticText* practice_title;
		wxStaticText* cardFrontTextBox;
		wxButton* addCardPracticeBtn;
		wxButton* practiceShowBtn;
		wxButton* practiceCancelBtn;
		wxButton* practiceNextBtn;

		// Virtual event handlers, override them in your derived class
		virtual void OnSizeChanged( wxSizeEvent& event ) { event.Skip(); }
		virtual void OnPracticeAddCardClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPracticeShowClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPracticeCancelClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPracticeNextClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		PracticeScreen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~PracticeScreen();

};

///////////////////////////////////////////////////////////////////////////////
/// Class AddCardBoardingScreen
///////////////////////////////////////////////////////////////////////////////
class AddCardBoardingScreen : public wxFrame
{
	private:

	protected:
		wxStaticText* dummy;
		wxStaticText* addCardOnboardingText;
		wxButton* addCardAddBtn;
		wxButton* addCardCancelBtn;

		// Virtual event handlers, override them in your derived class
		virtual void OnSizeChanged( wxSizeEvent& event ) { event.Skip(); }
		virtual void OnAddCardAddClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddCardCancelClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		AddCardBoardingScreen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~AddCardBoardingScreen();

};

