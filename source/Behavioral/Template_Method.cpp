// A behavioral design pattern that defines the skeleton of an algorithm in the superclass 
// but lets subclasses override specific steps of the algorithm without changing its structure.

#include "../../include/Behavioral/Template_Method.h"

void BasicClass::BaseOperation1() const
{
  std::cout << "BaseClass: BaseOperation1\n";
}

void BasicClass::BaseOperation2() const
{
  std::cout << "BaseClass: BaseOperation2\n";
}

void BasicClass::BaseOperation3() const
{
  std::cout << "BaseClass: BaseOperation3\n";
}

void BasicClass::ExtraOperations1() const
{
  std::cout << "BaseClass: ExtraOperation1\n";
}

void BasicClass::ExtraOperations2() const
{
  std::cout << "BaseClass: ExtraOperation2\n";
}

void BasicClass::TemplateMethod() const
{
  this->BaseOperation1();
  this->RequiredOperations1();
  this->BaseOperation2();
  this->ExtraOperations1();
  this->RequiredOperations2();
  this->BaseOperation3();
  this->ExtraOperations2();
}

void ActionClass1::RequiredOperations1() const
{
  std::cout << "ActionClass1: RequiredOperations1\n";
}

void ActionClass1::RequiredOperations2() const
{
  std::cout << "ActionClass1: RequiredOperations2\n";
}

void ActionClass1::ExtraOperations1() const
{
  std::cout << "ActionClass1: ExtraOperations1\n";
}

void ActionClass2::RequiredOperations1() const
{
  std::cout << "ActionClass2: RequiredOperations1\n";
}

void ActionClass2::RequiredOperations2() const
{
  std::cout << "ActionClass2: RequiredOperations1\n";
}

void ActionClass2::ExtraOperations2() const
{
  std::cout << "ActionClass2: ExtraOperations2\n";
}
