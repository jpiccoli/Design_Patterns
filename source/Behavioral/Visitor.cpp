// A behavioral design pattern that lets you separate algorithms from the objects on which they operate.

#include "../../include/Behavioral/Visitor.h"

void ConcreteComponentA::Accept(const std::shared_ptr<Visitor> visitor) const
{
  visitor->VisitConcreteComponentA(std::make_shared<ConcreteComponentA>(*this));
}

std::string ConcreteComponentA::ExclusiveComponentA() const
{
  return "A";
}

void ConcreteComponentB::Accept(const std::shared_ptr<Visitor> visitor) const
{
  visitor->VisitConcreteComponentB(std::make_shared<ConcreteComponentB>(*this));
}

std::string ConcreteComponentB::ExclusiveComponentB() const
{
  return "B";
}

void ConcreteVisitor1::VisitConcreteComponentA(const std::shared_ptr<ConcreteComponentA> element) const
{
  std::cout << element->ExclusiveComponentA() << " + ConcreteVisitor1\n";
}

void ConcreteVisitor1::VisitConcreteComponentB(const std::shared_ptr<ConcreteComponentB> element) const
{
  std::cout << element->ExclusiveComponentB() << " + ConcreteVisitor1\n";
}

void ConcreteVisitor2::VisitConcreteComponentA(const std::shared_ptr<ConcreteComponentA> element) const
{
  std::cout << element->ExclusiveComponentA() << " + ConcreteVisitor2\n";
}

void ConcreteVisitor2::VisitConcreteComponentB(const std::shared_ptr<ConcreteComponentB> element) const
{
  std::cout << element->ExclusiveComponentB() << " + ConcreteVisitor2\n";
}
