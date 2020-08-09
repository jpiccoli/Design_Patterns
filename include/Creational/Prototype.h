#pragma once

#include <string>
#include <unordered_map>

enum Designator { DESIGNATOR_1 = 0, DESIGNATOR_2 = 1 };

struct Prototype
{
protected:
  std::string prototype_name;
  double prototype_field;

public:
  Prototype();

  Prototype( std::string prototype_name_ );

  virtual ~Prototype() {}

  virtual Prototype *Clone() const = 0;

  virtual void SetOperation( double prototype_field_ );
};

struct ConcretePrototype1 : public Prototype
{
private:
  double concrete_prototype_field1;

public:
  Prototype* Clone() const override;

  ConcretePrototype1( std::string prototype_name_, double concrete_prototype_field_ );

};

struct ConcretePrototype2 : public Prototype
{
private:
  double concrete_prototype_field2;

public:
  Prototype * Clone() const override;

  ConcretePrototype2( std::string prototype_name_, double concrete_prototype_field_ );

};

struct PrototypeFactory
{
private:
  std::unordered_map<Designator, Prototype *, std::hash<int>> prototypes;

public:
  PrototypeFactory();

  ~PrototypeFactory();

  Prototype* CreatePrototype( Designator designator );
  //{
  //  return prototypes[ designator ]->Clone();
  //}
};
