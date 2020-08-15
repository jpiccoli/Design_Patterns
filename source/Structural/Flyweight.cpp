#include "../../include/Structural/Flyweight.h"

#include <iostream>

void Flyweight::Operation( UniqueState const& unique_state ) const
{
  std::cout << "Flyweight: Displaying shared (" << *shared_state_ << ") and unique (" << unique_state << ") state.\n";
}

std::string FlyweightFactory::GetKey( SharedState const& ss ) const
{
  return ss.brand_ +"_" + ss.model_ + "_" + ss.color_;
}

FlyweightFactory::FlyweightFactory( std::initializer_list<SharedState> share_states )
{
  for( const SharedState &ss : share_states )
  {
    this->flyweights_.insert( std::make_pair<std::string, Flyweight>( this->GetKey( ss ), Flyweight( &ss ) ) );
  }
}

Flyweight FlyweightFactory::GetFlyweight( SharedState const& shared_state )
{
  std::string key = this->GetKey( shared_state );
  if( this->flyweights_.find( key ) == this->flyweights_.end() )
  {
    std::cout << "FlyweightFactory: Can't find a flyweight, creating new one.\n";
    this->flyweights_.insert( std::make_pair( key, Flyweight( &shared_state ) ) );
  }
  else
  {
    std::cout << "FlyweightFactory: Reusing existing flyweight.\n";
  }
  return this->flyweights_.at( key );
}

// Prints keys
void FlyweightFactory::ListFlyweights() const
{
  size_t count = this->flyweights_.size();

  std::cout << "FlyweightFactory: I have " << count << " flyweights:\n";
  for( auto pair : this->flyweights_ )
  {
    std::cout << pair.first << '\n';
  }
}

void AddCarToDatabase(
  FlyweightFactory &ff, const std::string &plates, const std::string &owner,
  const std::string &brand, const std::string &model, const std::string &color )
{
  std::cout << "\nClient: Adding a car to database.\n";
  const Flyweight &flyweight = ff.GetFlyweight( { brand, model, color } );

  // The client code either stores or calculates extrinsic state and passes it
  // to the flyweight's methods.
  flyweight.Operation( { plates, owner } );
}
