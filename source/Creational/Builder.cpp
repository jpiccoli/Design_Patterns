// Allows for construction of complex objects step by step. That pattern
// provides for producing different types and representations of an object
// using the same construction code.

#include "../../include/Creational/Builder.h"

void Car::ListParts() const
{
  std::cout << "Parts:\n";
  for( auto const& part : parts )
  {
    std::cout << part << ",";
  }
  std::cout << '\n';
}

CarBuilder::CarBuilder()
{
  this->reset();
}

void CarBuilder::reset()
{
  car = std::make_shared<Car>();
}

void CarBuilder::SetSeats(std::string seats_)
{
  this->car->parts.push_back(seats_);
}

void CarBuilder::SetEngine(std::string engine_)
{
  this->car->parts.push_back(engine_);
}

void CarBuilder::SetTripComputer(std::string trip_computer_)
{
  this->car->parts.push_back( trip_computer_ );
}

void CarBuilder::SetGPS(std::string gps_)
{
  this->car->parts.push_back( gps_ );
}

std::shared_ptr<Car> CarBuilder::GetCar()
{
  //Car* result = this->car;
  std::shared_ptr<Car> result = this->car;
  this->reset();
  return result;
}

void Director::SetBuilder( std::shared_ptr<CarBuilder> builder_ )
{
  builder = builder_;
}

void Director::ConstructSportsCar( std::shared_ptr<CarBuilder> builder )
{
  builder->SetEngine( "V8" );
  builder->SetSeats( "Buckets" );
  builder->SetTripComputer( "true" );
  builder->SetGPS( "Standalone" );
}

void Director::ConstructSUV( std::shared_ptr<CarBuilder> builder )
{
  builder->SetEngine( "V6" );
  builder->SetSeats( "Bench" );
  builder->SetTripComputer( "false" );
  builder->SetGPS( "Integrated" );
}

