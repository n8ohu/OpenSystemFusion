/*
 *   Copyright (C) 2014 by Jonathan Naylor G4KLX
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "DStarRepeaterConfigSplitSet.h"

const unsigned int BORDER_SIZE     = 5U;

const unsigned int ADDRESS_WIDTH   = 120U;
const unsigned int PORT_WIDTH      = 80U;

const unsigned int ADDRESS_LENGTH  = 15U;
const unsigned int PORT_LENGTH     = 5U;

const unsigned int SLIDER_WIDTH    = 200U;

CDStarRepeaterConfigSplitSet::CDStarRepeaterConfigSplitSet(wxWindow* parent, int id, const wxString& localAddress, unsigned int localPort, const wxString& transmitter1Address, unsigned int transmitter1Port, const wxString& transmitter2Address, unsigned int transmitter2Port, const wxString& transmitter3Address, unsigned int transmitter3Port, const wxString& receiver1Address, unsigned int receiver1Port, const wxString& receiver2Address, unsigned int receiver2Port, const wxString& receiver3Address, unsigned int receiver3Port, unsigned int timeout) :
wxDialog(parent, id, wxString(_("Split Settings"))),
m_localAddress(NULL),
m_localPort(NULL),
m_transmitter1Address(NULL),
m_transmitter1Port(NULL),
m_transmitter2Address(NULL),
m_transmitter2Port(NULL),
m_transmitter3Address(NULL),
m_transmitter3Port(NULL),
m_receiver1Address(NULL),
m_receiver1Port(NULL),
m_receiver2Address(NULL),
m_receiver2Port(NULL),
m_receiver3Address(NULL),
m_receiver3Port(NULL),
m_timeout(NULL)
{
	wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);

	wxFlexGridSizer* sizer = new wxFlexGridSizer(2);

	wxStaticText* localLabel = new wxStaticText(this, -1, _("Local"));
	sizer->Add(localLabel, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	wxBoxSizer* localSizer = new wxBoxSizer(wxHORIZONTAL);

	m_localAddress = new CAddressTextCtrl(this, -1, localAddress, wxDefaultPosition, wxSize(ADDRESS_WIDTH, -1));
	m_localAddress->SetMaxLength(ADDRESS_LENGTH);
	localSizer->Add(m_localAddress, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	wxString buffer;
	buffer.Printf(wxT("%u"), localPort);

	m_localPort = new CPortTextCtrl(this, -1, buffer, wxDefaultPosition, wxSize(PORT_WIDTH, -1));
	m_localPort->SetMaxLength(PORT_LENGTH);
	localSizer->Add(m_localPort, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	sizer->Add(localSizer);

	wxStaticText* transmitter1Label = new wxStaticText(this, -1, _("Transmitter 1"));
	sizer->Add(transmitter1Label, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	wxBoxSizer* tx1Sizer = new wxBoxSizer(wxHORIZONTAL);

	m_transmitter1Address = new CAddressTextCtrl(this, -1, transmitter1Address, wxDefaultPosition, wxSize(ADDRESS_WIDTH, -1));
	m_transmitter1Address->SetMaxLength(ADDRESS_LENGTH);
	tx1Sizer->Add(m_transmitter1Address, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	buffer.Printf(wxT("%u"), transmitter1Port);

	m_transmitter1Port = new CPortTextCtrl(this, -1, buffer, wxDefaultPosition, wxSize(PORT_WIDTH, -1));
	m_transmitter1Port->SetMaxLength(PORT_LENGTH);
	tx1Sizer->Add(m_transmitter1Port, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	sizer->Add(tx1Sizer);

	wxStaticText* transmitter2Label = new wxStaticText(this, -1, _("Transmitter 2"));
	sizer->Add(transmitter2Label, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	wxBoxSizer* tx2Sizer = new wxBoxSizer(wxHORIZONTAL);

	m_transmitter2Address = new CAddressTextCtrl(this, -1, transmitter2Address, wxDefaultPosition, wxSize(ADDRESS_WIDTH, -1));
	m_transmitter2Address->SetMaxLength(ADDRESS_LENGTH);
	tx2Sizer->Add(m_transmitter2Address, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	buffer.Printf(wxT("%u"), transmitter2Port);

	m_transmitter2Port = new CPortTextCtrl(this, -1, buffer, wxDefaultPosition, wxSize(PORT_WIDTH, -1));
	m_transmitter2Port->SetMaxLength(PORT_LENGTH);
	tx2Sizer->Add(m_transmitter2Port, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	sizer->Add(tx2Sizer);

	wxStaticText* transmitter3Label = new wxStaticText(this, -1, _("Transmitter 3"));
	sizer->Add(transmitter3Label, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	wxBoxSizer* tx3Sizer = new wxBoxSizer(wxHORIZONTAL);

	m_transmitter3Address = new CAddressTextCtrl(this, -1, transmitter3Address, wxDefaultPosition, wxSize(ADDRESS_WIDTH, -1));
	m_transmitter3Address->SetMaxLength(ADDRESS_LENGTH);
	tx3Sizer->Add(m_transmitter3Address, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	buffer.Printf(wxT("%u"), transmitter3Port);

	m_transmitter3Port = new CPortTextCtrl(this, -1, buffer, wxDefaultPosition, wxSize(PORT_WIDTH, -1));
	m_transmitter3Port->SetMaxLength(PORT_LENGTH);
	tx3Sizer->Add(m_transmitter3Port, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	sizer->Add(tx3Sizer);

	wxStaticText* receiver1Label = new wxStaticText(this, -1, _("Receiver 1"));
	sizer->Add(receiver1Label, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	wxBoxSizer* rx1Sizer = new wxBoxSizer(wxHORIZONTAL);

	m_receiver1Address = new CAddressTextCtrl(this, -1, receiver1Address, wxDefaultPosition, wxSize(ADDRESS_WIDTH, -1));
	m_receiver1Address->SetMaxLength(ADDRESS_LENGTH);
	rx1Sizer->Add(m_receiver1Address, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	buffer.Printf(wxT("%u"), receiver1Port);

	m_receiver1Port = new CPortTextCtrl(this, -1, buffer, wxDefaultPosition, wxSize(PORT_WIDTH, -1));
	m_receiver1Port->SetMaxLength(PORT_LENGTH);
	rx1Sizer->Add(m_receiver1Port, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	sizer->Add(rx1Sizer);

	wxStaticText* receiver2Label = new wxStaticText(this, -1, _("Receiver 2"));
	sizer->Add(receiver2Label, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	wxBoxSizer* rx2Sizer = new wxBoxSizer(wxHORIZONTAL);

	m_receiver2Address = new CAddressTextCtrl(this, -1, receiver2Address, wxDefaultPosition, wxSize(ADDRESS_WIDTH, -1));
	m_receiver2Address->SetMaxLength(ADDRESS_LENGTH);
	rx2Sizer->Add(m_receiver2Address, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	buffer.Printf(wxT("%u"), receiver2Port);

	m_receiver2Port = new CPortTextCtrl(this, -1, buffer, wxDefaultPosition, wxSize(PORT_WIDTH, -1));
	m_receiver2Port->SetMaxLength(PORT_LENGTH);
	rx2Sizer->Add(m_receiver2Port, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	sizer->Add(rx2Sizer);

	wxStaticText* receiver3Label = new wxStaticText(this, -1, _("Receiver 3"));
	sizer->Add(receiver3Label, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	wxBoxSizer* rx3Sizer = new wxBoxSizer(wxHORIZONTAL);

	m_receiver3Address = new CAddressTextCtrl(this, -1, receiver3Address, wxDefaultPosition, wxSize(ADDRESS_WIDTH, -1));
	m_receiver3Address->SetMaxLength(ADDRESS_LENGTH);
	rx3Sizer->Add(m_receiver3Address, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	buffer.Printf(wxT("%u"), receiver3Port);

	m_receiver3Port = new CPortTextCtrl(this, -1, buffer, wxDefaultPosition, wxSize(PORT_WIDTH, -1));
	m_receiver3Port->SetMaxLength(PORT_LENGTH);
	rx3Sizer->Add(m_receiver3Port, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	sizer->Add(rx3Sizer);

	wxStaticText* timeoutLabel = new wxStaticText(this, -1, _("Packet timeout (ms)"));
	sizer->Add(timeoutLabel, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	m_timeout = new wxSlider(this, -1, timeout, 10, 300, wxDefaultPosition, wxSize(SLIDER_WIDTH, -1), wxSL_HORIZONTAL | wxSL_LABELS);
	sizer->Add(m_timeout, 0, wxALL | wxALIGN_LEFT, BORDER_SIZE);

	topSizer->Add(sizer);

	topSizer->Add(CreateButtonSizer(wxOK | wxCANCEL), 0, wxALL | wxALIGN_RIGHT, BORDER_SIZE);

	SetAutoLayout(true);

	topSizer->Fit(this);
	topSizer->SetSizeHints(this);

	SetSizer(topSizer);
}

CDStarRepeaterConfigSplitSet::~CDStarRepeaterConfigSplitSet()
{
}

bool CDStarRepeaterConfigSplitSet::Validate()
{
	return true;
}

wxString CDStarRepeaterConfigSplitSet::getTransmitter1Address() const
{
	return m_transmitter1Address->GetValue();
}

unsigned int CDStarRepeaterConfigSplitSet::getTransmitter1Port() const
{
	unsigned long n;

	m_transmitter1Port->GetValue().ToULong(&n);

	return n;
}

wxString CDStarRepeaterConfigSplitSet::getLocalAddress() const
{
	return m_localAddress->GetValue();
}

unsigned int CDStarRepeaterConfigSplitSet::getLocalPort() const
{
	unsigned long n;

	m_localPort->GetValue().ToULong(&n);

	return n;
}

wxString CDStarRepeaterConfigSplitSet::getTransmitter2Address() const
{
	return m_transmitter2Address->GetValue();
}

unsigned int CDStarRepeaterConfigSplitSet::getTransmitter2Port() const
{
	unsigned long n;

	m_transmitter2Port->GetValue().ToULong(&n);

	return n;
}

wxString CDStarRepeaterConfigSplitSet::getTransmitter3Address() const
{
	return m_transmitter3Address->GetValue();
}

unsigned int CDStarRepeaterConfigSplitSet::getTransmitter3Port() const
{
	unsigned long n;

	m_transmitter3Port->GetValue().ToULong(&n);

	return n;
}

wxString CDStarRepeaterConfigSplitSet::getReceiver1Address() const
{
	return m_receiver1Address->GetValue();
}

unsigned int CDStarRepeaterConfigSplitSet::getReceiver1Port() const
{
	unsigned long n;

	m_receiver1Port->GetValue().ToULong(&n);

	return n;
}

wxString CDStarRepeaterConfigSplitSet::getReceiver2Address() const
{
	return m_receiver2Address->GetValue();
}

unsigned int CDStarRepeaterConfigSplitSet::getReceiver2Port() const
{
	unsigned long n;

	m_receiver2Port->GetValue().ToULong(&n);

	return n;
}

wxString CDStarRepeaterConfigSplitSet::getReceiver3Address() const
{
	return m_receiver3Address->GetValue();
}

unsigned int CDStarRepeaterConfigSplitSet::getReceiver3Port() const
{
	unsigned long n;

	m_receiver3Port->GetValue().ToULong(&n);

	return n;
}

unsigned int CDStarRepeaterConfigSplitSet::getTimeout() const
{
	return (unsigned int)m_timeout->GetValue();
}
