// A behavioral design pattern that lets you reduce chaotic dependencies between objects. The pattern 
// restricts direct communications between the objects and forces them to collaborate only via a mediator 
// object.

#include "../../include/Behavioral/Mediator.h"

void BaseComponent::set_mediator(std::shared_ptr<Mediator> mediator_)
{
  this->mediator = mediator_;
}

void Component1::DoA()
{
  std::cout << "Component 1 does A\n";
  this->mediator->Notify(std::make_shared<Component1>(*this), "A");
}

void Component1:: DoB()
{
  std::cout << "Component 1 does B\n";
  this->mediator->Notify(std::make_shared<Component1>(*this), "B");
}

void Component2::DoC()
{
  std::cout << "Component 2 does C\n";
  this->mediator->Notify(std::make_shared<Component2>(*this), "C");
}

void Component2::DoD()
{
  std::cout << "Component 2 does D\n";
  this->mediator->Notify(std::make_shared<Component2>(*this), "D");
}

ConcreteMediator::ConcreteMediator(std::shared_ptr<Component1> component1_, std::shared_ptr<Component2> component2_)
  : component1(component1_), component2(component2_)
{
  this->component1->set_mediator(std::make_shared<ConcreteMediator>(*this));
  this->component2->set_mediator(std::make_shared<ConcreteMediator>(*this));
}

void ConcreteMediator::Notify(std::shared_ptr<BaseComponent> component, std::string const& event) const
{
  if(event == "A")
  {
    std::cout << "Mediator reacts on A and triggers the following operations:\n";
    component2->DoC();
  }
  if(event == "D")
  {
    std::cout << "Mediator reacts on D and triggers the following operations:\n";
    component1->DoB();
    component2->DoC();
  }
}
