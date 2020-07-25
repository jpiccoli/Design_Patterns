#pragma once

#include <string>

struct Subsystem1
{
  std::string Operation1() const
  {
    return "Subsystem1: Ready!\n";
  }

  std::string OperationN() const
  {
    return "Subsystem1: Go!\n";
  }
};

struct Subsystem2
{
  std::string Operation1() const
  {
    return "Subsystem2: Get ready!\n";
  }

  std::string OperationZ() const
  {
    return "Subsystem2: Shoot!\n";
  }
};

struct Facade
{
protected:
  Subsystem1 * subsystem1_;
  Subsystem2 * subsystem2_;

public:
  Facade( Subsystem1 *subsystem1 = nullptr, Subsystem2 *subsystem2 = nullptr );
  ~Facade();

  std::string Operation();
};

