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
	welcome_title->SetFont( wxFont( 25, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Monospace") ) );

	bSizer1->Add( welcome_title, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 50 );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	create_deck_btn = new wxButton( this, wxID_ANY, wxT("Create Deck"), wxPoint( -1,-1 ), wxDefaultSize, 0 );
	bSizer2->Add( create_deck_btn, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	browse_decks_btn = new wxButton( this, wxID_ANY, wxT("Browse"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( browse_decks_btn, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	quit_btn = new wxButton( this, wxID_ANY, wxT("Quit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( quit_btn, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer1->Add( bSizer2, 6, wxALIGN_CENTER|wxALL, 0 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	create_deck_btn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainScreen::onCreateDeckClicked ), NULL, this );
	browse_decks_btn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainScreen::OnBrowseDecksClicked ), NULL, this );
	quit_btn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainScreen::OnQuitClicked ), NULL, this );
}

MainScreen::~MainScreen()
{
	// Disconnect Events
	create_deck_btn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainScreen::onCreateDeckClicked ), NULL, this );
	browse_decks_btn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainScreen::OnBrowseDecksClicked ), NULL, this );
	quit_btn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainScreen::OnQuitClicked ), NULL, this );

}

CreateDeckScreen::CreateDeckScreen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	create_dec_title = new wxStaticText( this, wxID_ANY, wxT("Create Deck"), wxPoint( 0,0 ), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	create_dec_title->Wrap( -1 );
	create_dec_title->SetFont( wxFont( 25, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Monospace") ) );

	bSizer6->Add( create_dec_title, 0, wxALL|wxEXPAND, 50 );

	wxBoxSizer* bSizer311;
	bSizer311 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	deckNameText = new wxStaticText( this, wxID_ANY, wxT("Deck Name"), wxDefaultPosition, wxDefaultSize, 0 );
	deckNameText->Wrap( -1 );
	bSizer3->Add( deckNameText, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	deckNameTextBox = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( deckNameTextBox, 3, wxALL, 5 );


	bSizer311->Add( bSizer3, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );

	deckCreateBtn = new wxButton( this, wxID_ANY, wxT("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( deckCreateBtn, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	createDeckCancelBtn = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( createDeckCancelBtn, 0, wxALL, 5 );


	bSizer311->Add( bSizer31, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer6->Add( bSizer311, 0, wxALIGN_CENTER_HORIZONTAL, 0 );


	this->SetSizer( bSizer6 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	deckCreateBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CreateDeckScreen::OnDeckCreateClicked ), NULL, this );
	createDeckCancelBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CreateDeckScreen::OnCreateDeckCancelClicked ), NULL, this );
}

CreateDeckScreen::~CreateDeckScreen()
{
	// Disconnect Events
	deckCreateBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CreateDeckScreen::OnDeckCreateClicked ), NULL, this );
	createDeckCancelBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CreateDeckScreen::OnCreateDeckCancelClicked ), NULL, this );

}

SelectDeckScreen::SelectDeckScreen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	select_deck_title = new wxStaticText( this, wxID_ANY, wxT("Decks"), wxPoint( 0,0 ), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	select_deck_title->Wrap( -1 );
	select_deck_title->SetFont( wxFont( 25, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Monospace") ) );

	bSizer6->Add( select_deck_title, 0, wxALL|wxEXPAND, 50 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	selectDeckListCtrlr = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL );
	selectDeckListCtrlr->SetFont( wxFont( 15, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Noto Serif Georgian") ) );

	bSizer3->Add( selectDeckListCtrlr, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 0 );


	bSizer6->Add( bSizer3, 0, wxALIGN_CENTER_HORIZONTAL|wxLEFT|wxRIGHT, 20 );

	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );

	SelectDeckPracticeBtn = new wxButton( this, wxID_ANY, wxT("Practice"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( SelectDeckPracticeBtn, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	SelectDeckBrowseBtn = new wxButton( this, wxID_ANY, wxT("Browse"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( SelectDeckBrowseBtn, 0, wxALL, 5 );

	SelectDeckCancelBtn = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( SelectDeckCancelBtn, 0, wxALL, 5 );


	bSizer6->Add( bSizer31, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer6 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	selectDeckListCtrlr->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( SelectDeckScreen::OnItemSelected ), NULL, this );
	SelectDeckPracticeBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelectDeckScreen::OnSelectDeckPracticeClicked ), NULL, this );
	SelectDeckBrowseBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelectDeckScreen::OnSelectDeckBrowseClicked ), NULL, this );
	SelectDeckCancelBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelectDeckScreen::OnSelectDeckCancelClicked ), NULL, this );
}

SelectDeckScreen::~SelectDeckScreen()
{
	// Disconnect Events
	selectDeckListCtrlr->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( SelectDeckScreen::OnItemSelected ), NULL, this );
	SelectDeckPracticeBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelectDeckScreen::OnSelectDeckPracticeClicked ), NULL, this );
	SelectDeckBrowseBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelectDeckScreen::OnSelectDeckBrowseClicked ), NULL, this );
	SelectDeckCancelBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SelectDeckScreen::OnSelectDeckCancelClicked ), NULL, this );

}

BrowseCardsScreen::BrowseCardsScreen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	browse_cards_title = new wxStaticText( this, wxID_ANY, wxT("Cards"), wxPoint( 0,0 ), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	browse_cards_title->Wrap( -1 );
	browse_cards_title->SetFont( wxFont( 25, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Monospace") ) );

	bSizer6->Add( browse_cards_title, 0, wxALL|wxEXPAND, 50 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	browseCardsListCtrlr = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL );
	browseCardsListCtrlr->SetFont( wxFont( 15, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Noto Serif Georgian") ) );

	bSizer3->Add( browseCardsListCtrlr, 0, wxEXPAND, 0 );


	bSizer6->Add( bSizer3, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxLEFT|wxRIGHT, 20 );

	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );

	BrowseCardsShowBtn = new wxButton( this, wxID_ANY, wxT("Show"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( BrowseCardsShowBtn, 0, wxALL, 5 );

	BrowseCardsEditBtn = new wxButton( this, wxID_ANY, wxT("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( BrowseCardsEditBtn, 0, wxALL, 5 );

	BrowseCardsDeleteBtn = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( BrowseCardsDeleteBtn, 0, wxALL, 5 );


	bSizer6->Add( bSizer31, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer6 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( BrowseCardsScreen::OnWindowSizeChanged ) );
	browseCardsListCtrlr->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( BrowseCardsScreen::OnCardSelected ), NULL, this );
	browseCardsListCtrlr->Connect( wxEVT_SIZE, wxSizeEventHandler( BrowseCardsScreen::OnListSizeChanged ), NULL, this );
	BrowseCardsShowBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BrowseCardsScreen::OnBrowseCardsShowClicked ), NULL, this );
	BrowseCardsEditBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BrowseCardsScreen::OnBrowseCardsEditClicked ), NULL, this );
	BrowseCardsDeleteBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BrowseCardsScreen::OnBrowseCardsDeleteClicked ), NULL, this );
}

BrowseCardsScreen::~BrowseCardsScreen()
{
	// Disconnect Events
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( BrowseCardsScreen::OnWindowSizeChanged ) );
	browseCardsListCtrlr->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( BrowseCardsScreen::OnCardSelected ), NULL, this );
	browseCardsListCtrlr->Disconnect( wxEVT_SIZE, wxSizeEventHandler( BrowseCardsScreen::OnListSizeChanged ), NULL, this );
	BrowseCardsShowBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BrowseCardsScreen::OnBrowseCardsShowClicked ), NULL, this );
	BrowseCardsEditBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BrowseCardsScreen::OnBrowseCardsEditClicked ), NULL, this );
	BrowseCardsDeleteBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BrowseCardsScreen::OnBrowseCardsDeleteClicked ), NULL, this );

}

AddEditCardScreen::AddEditCardScreen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	add_edit_card_title = new wxStaticText( this, wxID_ANY, wxT("Edit Card"), wxPoint( 0,0 ), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	add_edit_card_title->Wrap( -1 );
	add_edit_card_title->SetFont( wxFont( 25, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer6->Add( add_edit_card_title, 1, wxALL|wxEXPAND, 50 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );

	staticTextCardFront = new wxStaticText( this, wxID_ANY, wxT("Front:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	staticTextCardFront->Wrap( -1 );
	bSizer26->Add( staticTextCardFront, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	cardFrontTextBox = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( cardFrontTextBox, 1, 0, 5 );


	bSizer3->Add( bSizer26, 0, wxEXPAND, 5 );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxHORIZONTAL );

	staticTextCardBack = new wxStaticText( this, wxID_ANY, wxT("Back:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	staticTextCardBack->Wrap( -1 );
	bSizer27->Add( staticTextCardBack, 0, wxALL, 5 );

	cardBackTextBox = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	bSizer27->Add( cardBackTextBox, 3, wxEXPAND, 5 );


	bSizer3->Add( bSizer27, 3, wxEXPAND, 5 );


	bSizer6->Add( bSizer3, 3, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 15 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	addEditCardSaveBtn = new wxButton( this, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( addEditCardSaveBtn, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	addEditCardCancelBtn = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( addEditCardCancelBtn, 0, wxALL, 5 );


	bSizer6->Add( bSizer11, 1, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer6 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	addEditCardSaveBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddEditCardScreen::OnAddEditCardSaveClicked ), NULL, this );
	addEditCardCancelBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddEditCardScreen::OnAddEditCardCancelClicked ), NULL, this );
}

AddEditCardScreen::~AddEditCardScreen()
{
	// Disconnect Events
	addEditCardSaveBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddEditCardScreen::OnAddEditCardSaveClicked ), NULL, this );
	addEditCardCancelBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddEditCardScreen::OnAddEditCardCancelClicked ), NULL, this );

}

ShowCardScreen::ShowCardScreen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	show_card_title = new wxStaticText( this, wxID_ANY, wxT("Card"), wxPoint( 0,0 ), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	show_card_title->Wrap( -1 );
	show_card_title->SetFont( wxFont( 25, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer6->Add( show_card_title, 0, wxALL|wxEXPAND, 50 );

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

	showCardNextBtn = new wxButton( this, wxID_ANY, wxT("Next"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( showCardNextBtn, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	showCardCancelBtn = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( showCardCancelBtn, 0, wxALL, 5 );


	bSizer6->Add( bSizer11, 1, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer6 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	showCardNextBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ShowCardScreen::OnShowCardNextClicked ), NULL, this );
	showCardCancelBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ShowCardScreen::OnShowCardCancelClicked ), NULL, this );
}

ShowCardScreen::~ShowCardScreen()
{
	// Disconnect Events
	showCardNextBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ShowCardScreen::OnShowCardNextClicked ), NULL, this );
	showCardCancelBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ShowCardScreen::OnShowCardCancelClicked ), NULL, this );

}

PracticeScreen::PracticeScreen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	practice_title = new wxStaticText( this, wxID_ANY, wxT("Practice"), wxPoint( 0,0 ), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	practice_title->Wrap( -1 );
	practice_title->SetFont( wxFont( 25, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Monospace") ) );

	bSizer6->Add( practice_title, 0, wxALL|wxEXPAND, 50 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	cardFrontTextBox = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	cardFrontTextBox->Wrap( -1 );
	cardFrontTextBox->SetFont( wxFont( 15, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Noto Sans Georgian") ) );

	bSizer3->Add( cardFrontTextBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND|wxLEFT|wxRIGHT, 80 );


	bSizer6->Add( bSizer3, 2, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 0 );

	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* boxSizerAddBtn;
	boxSizerAddBtn = new wxBoxSizer( wxVERTICAL );

	addCardPracticeBtn = new wxButton( this, wxID_ANY, wxT("+"), wxDefaultPosition, wxDefaultSize, 0 );
	addCardPracticeBtn->SetMaxSize( wxSize( 50,50 ) );

	boxSizerAddBtn->Add( addCardPracticeBtn, 0, wxALIGN_CENTER|wxEXPAND, 5 );


	bSizer37->Add( boxSizerAddBtn, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	practiceShowBtn = new wxButton( this, wxID_ANY, wxT("Show"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( practiceShowBtn, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	practiceCancelBtn = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( practiceCancelBtn, 1, wxALL, 5 );


	bSizer37->Add( bSizer11, 3, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* boxSizerNextBtn;
	boxSizerNextBtn = new wxBoxSizer( wxVERTICAL );

	practiceNextBtn = new wxButton( this, wxID_ANY, wxT("Next"), wxDefaultPosition, wxDefaultSize, 0 );
	boxSizerNextBtn->Add( practiceNextBtn, 1, wxALIGN_CENTER, 5 );


	bSizer37->Add( boxSizerNextBtn, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxRESERVE_SPACE_EVEN_IF_HIDDEN, 5 );


	bSizer6->Add( bSizer37, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer6 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	cardFrontTextBox->Connect( wxEVT_SIZE, wxSizeEventHandler( PracticeScreen::OnSizeChanged ), NULL, this );
	addCardPracticeBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PracticeScreen::OnPracticeAddCardClicked ), NULL, this );
	practiceShowBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PracticeScreen::OnPracticeShowClicked ), NULL, this );
	practiceCancelBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PracticeScreen::OnPracticeCancelClicked ), NULL, this );
	practiceNextBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PracticeScreen::OnPracticeNextClicked ), NULL, this );
}

PracticeScreen::~PracticeScreen()
{
	// Disconnect Events
	cardFrontTextBox->Disconnect( wxEVT_SIZE, wxSizeEventHandler( PracticeScreen::OnSizeChanged ), NULL, this );
	addCardPracticeBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PracticeScreen::OnPracticeAddCardClicked ), NULL, this );
	practiceShowBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PracticeScreen::OnPracticeShowClicked ), NULL, this );
	practiceCancelBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PracticeScreen::OnPracticeCancelClicked ), NULL, this );
	practiceNextBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PracticeScreen::OnPracticeNextClicked ), NULL, this );

}

AddCardBoardingScreen::AddCardBoardingScreen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer361;
	bSizer361 = new wxBoxSizer( wxVERTICAL );

	dummy = new wxStaticText( this, wxID_ANY, wxEmptyString, wxPoint( 0,0 ), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	dummy->Wrap( -1 );
	dummy->SetFont( wxFont( 15, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	dummy->SetMinSize( wxSize( -1,25 ) );

	bSizer361->Add( dummy, 0, wxALL|wxEXPAND, 5 );


	bSizer6->Add( bSizer361, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3611;
	bSizer3611 = new wxBoxSizer( wxVERTICAL );

	addCardOnboardingText = new wxStaticText( this, wxID_ANY, wxT("There are no cards in deck, Please add card to start practice :)"), wxPoint( 0,0 ), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL|wxST_NO_AUTORESIZE );
	addCardOnboardingText->Wrap( -1 );
	addCardOnboardingText->SetFont( wxFont( 25, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer3611->Add( addCardOnboardingText, 0, wxALL|wxEXPAND, 5 );


	bSizer6->Add( bSizer3611, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	addCardAddBtn = new wxButton( this, wxID_ANY, wxT("Add Card"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( addCardAddBtn, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	addCardCancelBtn = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( addCardCancelBtn, 0, wxALL, 5 );


	bSizer6->Add( bSizer11, 1, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer6 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	addCardOnboardingText->Connect( wxEVT_SIZE, wxSizeEventHandler( AddCardBoardingScreen::OnSizeChanged ), NULL, this );
	addCardAddBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddCardBoardingScreen::OnAddCardAddClicked ), NULL, this );
	addCardCancelBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddCardBoardingScreen::OnAddCardCancelClicked ), NULL, this );
}

AddCardBoardingScreen::~AddCardBoardingScreen()
{
	// Disconnect Events
	addCardOnboardingText->Disconnect( wxEVT_SIZE, wxSizeEventHandler( AddCardBoardingScreen::OnSizeChanged ), NULL, this );
	addCardAddBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddCardBoardingScreen::OnAddCardAddClicked ), NULL, this );
	addCardCancelBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddCardBoardingScreen::OnAddCardCancelClicked ), NULL, this );

}
