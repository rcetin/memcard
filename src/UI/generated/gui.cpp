///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.0.0-0-g0efcecf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

MainScreen::MainScreen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	welcome_title = new wxStaticText( this, wxID_ANY, wxT("Welcome to Memcard"), wxPoint( 0,0 ), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	welcome_title->Wrap( -1 );
	welcome_title->SetFont( wxFont( 20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	welcome_title->SetMinSize( wxSize( -1,40 ) );

	bSizer1->Add( welcome_title, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	create_deck_btn = new wxButton( this, wxID_ANY, wxT("Create Deck"), wxPoint( -1,-1 ), wxDefaultSize, 0 );
	bSizer2->Add( create_deck_btn, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	practice_btn = new wxButton( this, wxID_ANY, wxT("Practice"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( practice_btn, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	quit_btn = new wxButton( this, wxID_ANY, wxT("Quit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( quit_btn, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer1->Add( bSizer2, 0, wxALIGN_CENTER|wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	create_deck_btn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainScreen::onCreateDeckClicked ), NULL, this );
	practice_btn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainScreen::OnPracticeClicked ), NULL, this );
	quit_btn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainScreen::OnQuitClicked ), NULL, this );
}

MainScreen::~MainScreen()
{
	// Disconnect Events
	create_deck_btn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainScreen::onCreateDeckClicked ), NULL, this );
	practice_btn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainScreen::OnPracticeClicked ), NULL, this );
	quit_btn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainScreen::OnQuitClicked ), NULL, this );

}

CreateDeckScreen::CreateDeckScreen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	create_dec_title = new wxStaticText( this, wxID_ANY, wxT("Create Deck"), wxPoint( 0,0 ), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	create_dec_title->Wrap( -1 );
	create_dec_title->SetFont( wxFont( 15, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	create_dec_title->SetMinSize( wxSize( -1,25 ) );

	bSizer6->Add( create_dec_title, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	deckNameText = new wxStaticText( this, wxID_ANY, wxT("Deck Name"), wxDefaultPosition, wxDefaultSize, 0 );
	deckNameText->Wrap( -1 );
	bSizer3->Add( deckNameText, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	deckNameTextBox = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( deckNameTextBox, 1, wxALL, 5 );


	bSizer6->Add( bSizer3, 0, wxEXPAND, 5 );

	deckCreateBtn = new wxButton( this, wxID_ANY, wxT("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( deckCreateBtn, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	this->SetSizer( bSizer6 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	deckCreateBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CreateDeckScreen::OnDeckCreateClicked ), NULL, this );
}

CreateDeckScreen::~CreateDeckScreen()
{
	// Disconnect Events
	deckCreateBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CreateDeckScreen::OnDeckCreateClicked ), NULL, this );

}

EditCardScreen::EditCardScreen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	edit_card_title = new wxStaticText( this, wxID_ANY, wxT("Edit Card"), wxPoint( 0,0 ), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	edit_card_title->Wrap( -1 );
	edit_card_title->SetFont( wxFont( 15, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	edit_card_title->SetMinSize( wxSize( -1,25 ) );

	bSizer6->Add( edit_card_title, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	bSizer3->SetMinSize( wxSize( 200,-1 ) );
	cardFrontTextBox = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( cardFrontTextBox, 1, wxEXPAND, 5 );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	cardBackTextBox = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	bSizer3->Add( cardBackTextBox, 3, wxEXPAND, 5 );


	bSizer6->Add( bSizer3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 15 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	editCardSaveBtn = new wxButton( this, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( editCardSaveBtn, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	editCardCancelBtn = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( editCardCancelBtn, 0, wxALL, 5 );


	bSizer6->Add( bSizer11, 1, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer6 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	editCardSaveBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditCardScreen::OnEditCardSaveClicked ), NULL, this );
	editCardCancelBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditCardScreen::OnEditCardCancelClicked ), NULL, this );
}

EditCardScreen::~EditCardScreen()
{
	// Disconnect Events
	editCardSaveBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditCardScreen::OnEditCardSaveClicked ), NULL, this );
	editCardCancelBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EditCardScreen::OnEditCardCancelClicked ), NULL, this );

}
