#include "../../include/Behavioral/State.h"

#include <iostream>

void TCPState::Transmit( TCPConnection*, TCPOctetStream* ) { std::cout << "TCPState::Transmit() " << '\n'; }
void TCPState::ActiveOpen( TCPConnection * ) { std::cout << "TCPState::ActiveOpen() " << '\n'; }
void TCPState::PassiveOpen( TCPConnection * ) { std::cout << "TCPState::PassiveOpen() " << '\n'; }
void TCPState::Close( TCPConnection * ) { std::cout << "TCPState::Close() " << '\n'; }
void TCPState::Synchronize( TCPConnection * ) { std::cout << "TCPState::Synchronize() " << '\n'; }
void TCPState::Acknowledge( TCPConnection * ) { std::cout << "TCPState::Acknowledge() " << '\n'; }
void TCPState::Send( TCPConnection * ) { std::cout << "TCPState::Send() " << '\n'; }

void TCPState::ChangeState( TCPConnection* t, TCPState* s)
{
  t->ChangeState(s);
}

void TCPConnection::ChangeState( TCPState* s )
{
  _state = s;
}

TCPConnection::TCPConnection()
{
  std::cout << "TCPConnection Constructor: Changing state to Closed\n";
  _state = TCPClosed::Instance();
}

void TCPConnection::ActiveOpen()
{
  std::cout << "TCPConnection::ActiveOpen() Changing state to ActiveOpen\n";
  _state->ActiveOpen( this );
}

void TCPConnection::PassiveOpen()
{
  std::cout << "TCPConnection::PassiveOpen() Changing state to Passive Open\n";
  _state->PassiveOpen( this );
}

void TCPConnection::Close()
{
  std::cout << "TCPConnection::Close() Changing state to Close\n";
  _state->Close( this );
}

void TCPConnection::Send()
{
  std::cout << "TCPConnection::Send()\n";
  _state->Send( this );
}

void TCPConnection::Acknowledge()
{
  std::cout << "TCPConnection::Acknowledge() Changing state to Acknowledge\n";
  _state->Acknowledge( this );
}

void TCPConnection::Synchronize()
{
  std::cout << "TCPConnection::Synchronize() Changing state to Synchronize\n";
  _state->Synchronize( this );
}

void TCPConnection::ProcesOctet( TCPOctetStream* o )
{
  std::cout << "Process Octet: " << o->GetOctetStream() << '\n';
}

TCPState* TCPEstablished::Instance()
{
  std::cout << "Creating TCPEstablished instance()\n";
  return new TCPEstablished();
}

TCPState* TCPListen::Instance()
{
  std::cout << "Creating TCPListen instance()\n";
  return new TCPListen();
}

TCPState* TCPClosed::Instance()
{
  std::cout << "Creating TCPClosed instance()\n";
  return new TCPClosed();
}

void TCPClosed::ActiveOpen( TCPConnection* t )
{
  std::cout << "TCPClosed::ActiveOpen()\n";
  ChangeState( t, TCPEstablished::Instance() );
}

void TCPClosed::PassiveOpen( TCPConnection* t )
{
  std::cout << "TCPClosed::PassiveOpen()\n";
  ChangeState( t, TCPListen::Instance() );
}

void TCPEstablished::Close( TCPConnection* t )
{
  std::cout << "TCPEstablished::Close()\n";
  ChangeState( t, TCPListen::Instance() );
}

void TCPEstablished::Transmit( TCPConnection* t, TCPOctetStream* o )
{
  std::cout << "TCPEstablished::Transmit()\n";
  t->ProcesOctet( o );
}

void TCPListen::Send( TCPConnection* t )
{
  ChangeState( t, TCPEstablished::Instance() );
}
