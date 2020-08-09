#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Car
{
  std::vector<std::string> parts;

  void ListParts() const;
};

struct Builder
{
  virtual ~Builder() {};
  virtual void SetSeats( std::string ) = 0;
  virtual void SetEngine( std::string ) = 0;
  virtual void SetTripComputer( std::string ) = 0;
  virtual void SetGPS( std::string ) = 0;
};

struct CarBuilder : public Builder
{
private:
  std::shared_ptr<Car> car;

public:
  CarBuilder();

  ~CarBuilder() {}

  void reset();
  void SetSeats(std::string seats_);
  void SetEngine(std::string engine_);
  void SetTripComputer(std::string trip_computer_);
  void SetGPS(std::string gps_);
  std::shared_ptr<Car> GetCar();
};

struct Director
{
  std::shared_ptr<CarBuilder> builder;

  void SetBuilder( std::shared_ptr<CarBuilder> builder_ );
  void ConstructSportsCar( std::shared_ptr<CarBuilder> builder );
  void ConstructSUV( std::shared_ptr<CarBuilder> builder );
};
