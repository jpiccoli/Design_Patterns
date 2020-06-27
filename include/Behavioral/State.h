#pragma once

#include <string>

struct TCPState;
struct TCPOctetStream;

struct TCPConnection
{
  TCPConnection();

  void ActiveOpen();
  void PassiveOpen();
  void Close();
  void Send();
  void Acknowledge();
  void Synchronize();
  void ProcesOctet( TCPOctetStream* );

private:
  friend struct TCPState;
  void ChangeState( TCPState * );
  TCPState* _state;
};

struct TCPState
{
  virtual void Transmit( TCPConnection*, TCPOctetStream* );
  virtual void ActiveOpen( TCPConnection *);
  virtual void PassiveOpen( TCPConnection * );
  virtual void Close( TCPConnection * );
  virtual void Synchronize( TCPConnection * );
  virtual void Acknowledge( TCPConnection * );
  virtual void Send( TCPConnection * );

protected:
  void ChangeState( TCPConnection *, TCPState* );
};

struct TCPOctetStream
{
  TCPOctetStream() = default;
  TCPOctetStream( std::string octetStream ) { _octetStream = octetStream; }
  
  std::string GetOctetStream() const { return _octetStream; }

private:
  std::string _octetStream;
};

struct TCPEstablished : public TCPState
{
  static TCPState* Instance();

  virtual void Transmit( TCPConnection*, TCPOctetStream* );
  virtual void Close( TCPConnection* );

private:
  TCPEstablished() {}
};

struct TCPListen : public TCPState
{
  static TCPState* Instance();

  virtual void Send( TCPConnection* );

private:
  TCPListen() {}
};

struct TCPClosed : public TCPState
{
  static TCPState* Instance();

  virtual void ActiveOpen( TCPConnection * );
  virtual void PassiveOpen( TCPConnection * );

private:
  TCPClosed() {}
};

