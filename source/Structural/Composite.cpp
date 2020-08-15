// A structural design pattern that lets you compose objects into tree structures and then work 
// with these structures as if they were individual objects.

#include "../../include/Structural/Composite.h"

std::string Leaf::operation() const
{
  return "Leaf";
}

void Composite::add(std::shared_ptr<Component> component)
{
  elements.push_back(component);
  component->set_parent(std::make_shared<Composite>(*this));
}

void Composite::remove(std::shared_ptr<Component> component)
{
  elements.remove(component);
  component->set_parent(nullptr);
}

std::string Composite::operation() const
{
  std::string result;

  for(auto const c : elements)
  {
    if(c == elements.back())
    {
      result += c->operation();
    }
    else
    {
      result += c->operation() + "+";
    }
  }

  return "Branch(" + result + ")";
}

