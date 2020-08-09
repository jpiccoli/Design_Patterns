#include "../../include/Creational/Prototype.h"

#include <iostream>

// Provides for copying of existing objects without making your code dependent on their classes.

Prototype::Prototype()
{
}

Prototype::Prototype( std::string prototype_name_ ) : prototype_name( prototype_name_ )
{
}

void Prototype::SetOperation( double prototype_field_ )
{
  prototype_field = prototype_field_;
  std::cout << "Call SetOperation from " << prototype_name << " with " << prototype_field << '\n';
}

ConcretePrototype1::ConcretePrototype1( std::string prototype_name_, double concrete_prototype_field_ )
  : Prototype( prototype_name_ ), concrete_prototype_field1( concrete_prototype_field_ )
{
}

Prototype* ConcretePrototype1::Clone() const
{
  return new ConcretePrototype1(*this );
}

ConcretePrototype2::ConcretePrototype2( std::string prototype_name_, double concrete_prototype_field_ )
  : Prototype( prototype_name_ ), concrete_prototype_field2( concrete_prototype_field_ )
{
}

Prototype* ConcretePrototype2::Clone() const
{
  return new ConcretePrototype2( *this );
}

PrototypeFactory::PrototypeFactory()
{
  prototypes[ Designator::DESIGNATOR_1 ] = new ConcretePrototype1( "DESIGNATOR_1 ", 50.0 );
  prototypes[ Designator::DESIGNATOR_2 ] = new ConcretePrototype2( "DESIGNATOR_2 ", 60.0 );
}

PrototypeFactory::~PrototypeFactory()
{
  delete prototypes[ Designator::DESIGNATOR_1 ];
  delete prototypes[ Designator::DESIGNATOR_2 ];
}

Prototype* PrototypeFactory::CreatePrototype( Designator designator )
{
  return prototypes[ designator ]->Clone();
}
