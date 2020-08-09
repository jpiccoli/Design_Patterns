// Memento allows for capture and externalization of an object's internal state
// so that object may be restored to this state later without revealing the
// details of its implementation.

#include "../../include/Behavioral/Memento.h"

#include <iostream>

Originator::Originator( std::string state ) : state_( state )
{
  std::cout << "Originator: My initial state is: " << this->state_ << "\n";
}

std::string Originator::GenerateRandomString( int length )
{
  const char alphanum[] =
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";
  int stringLength = sizeof( alphanum ) - 1;

  std::string random_string;
  for( int i = 0; i < length; i++ )
  {
    random_string += alphanum[ std::rand() % stringLength ];
  }
  
  return random_string;
}

void Originator::DoSomething()
{
  std::cout << "Originator: I'm doing something important.\n";
  this->state_ = this->GenerateRandomString( 30 );
  std::cout << "Originator: and my state has changed to: " << this->state_ << "\n";
}

Memento* Originator::Save()
{ 
  return new ConcreteMemento( this->state_ );

}
void Originator::Restore( Memento* memento )
{
  this->state_ = memento->state();
}

void Caretaker::Backup()
{
  std::cout << "\nCaretaker: Saving Originator's state...\n";
  this->mementos_.push_back( this->originator_->Save() );
}

void Caretaker::Undo()
{
  if( !this->mementos_.size() )
  {
    std::cout << "Nothing to undo.\n";
    return;
  }
  Memento *memento = this->mementos_.back();
  this->mementos_.pop_back();
  std::cout << "Caretaker: Restoring state to: " << memento->GetName() << "\n";
  try 
  {
    this->originator_->Restore( memento );
  }
  catch( ... )
  {
    this->Undo();
  }
}

void Caretaker::ShowHistory()
{
  std::cout << "Caretaker: Here's the list of mementos:\n";
  for( Memento *memento : this->mementos_ )
  {
    std::cout << memento->GetName() << "\n";
  }
}
