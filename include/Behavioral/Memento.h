#pragma once

// https://refactoring.guru/design-patterns/memento/cpp/example#example-0

#include <string>
#include <ctime>
#include <time.h>
#include <vector>

#include <iostream>

#pragma warning(disable:4996)

struct Memento
{
  virtual std::string GetName() const = 0;
  virtual std::string date() const = 0;
  virtual std::string state() const = 0;
  virtual ~Memento() {}
};

struct ConcreteMemento : public Memento
{
  ConcreteMemento( std::string state )
  {
    this->state_ = state;
    std::time_t now = std::time( 0 );
    this->date_ = std::ctime( &now );
  }

  std::string state() const override { return this->state_; }

  std::string GetName() const override
  {
    return this->date_ + " / ( " + this->state_.substr( 0, 9 ) + "...)";
  }

  std::string date() const override { return this->date_; }

private:
  std::string state_;
  std::string date_;
};

struct Originator
{
  Originator( std::string state );
  std::string GenerateRandomString( int length = 10 );
  void DoSomething();
  Memento* Save();
  void Restore( Memento* memento );

private:
  std::string state_;
};

struct Caretaker
{
  Caretaker( Originator *originator ) : originator_( originator )
  { 
    this->originator_ = originator; 
  }

  void Backup();
  void Undo();
  void ShowHistory();

private:
  std::vector<Memento*> mementos_;
  Originator * originator_;
};
