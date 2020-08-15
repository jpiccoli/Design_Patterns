// A structural design pattern that provides a simplified interface to a library, a framework, or any other complex set of classes.

#include "../../include/Structural/Facade.h"

Facade::Facade(Subsystem1 *subsystem1, Subsystem2 *subsystem2)
{
  this->subsystem1_ = subsystem1 ? subsystem1 : new Subsystem1;
  this->subsystem2_ = subsystem2 ? subsystem2 : new Subsystem2;
}

Facade::~Facade()
{
  delete subsystem1_;
  delete subsystem2_;
}

std::string Facade::Operation()
{
  std::string result = "Facade initializes subsystems:\n";
  result += this->subsystem1_->Operation1();
  result += this->subsystem2_->Operation1();
  result += "Facade orders subsystems to perform the action:\n";
  result += this->subsystem1_->OperationN();
  result += this->subsystem2_->OperationZ();
  return result;
}

