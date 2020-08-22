#pragma once

#include <iostream>
#include <memory>
#include <string>

struct BaseComponent;

struct Mediator
{
  virtual void Notify(std::shared_ptr<BaseComponent> component, std::string const& event) const = 0;
};

struct BaseComponent
{
protected:
  std::shared_ptr<Mediator> mediator;

public:
  BaseComponent(std::shared_ptr<Mediator> mediator_ = nullptr) : mediator(mediator_) {}
  void set_mediator(std::shared_ptr<Mediator> mediator);
};

struct Component1 : public BaseComponent
{
  void DoA();
  void DoB();
};

struct Component2 : public BaseComponent
{
  void DoC();
  void DoD();
};

struct ConcreteMediator : public Mediator
{
private:
  std::shared_ptr<Component1> component1;
  std::shared_ptr<Component2> component2;

public:
  ConcreteMediator() {}
  ConcreteMediator(std::shared_ptr<Component1> component1_, std::shared_ptr<Component2> component2_);
  void Notify(std::shared_ptr<BaseComponent> component, std::string const& event) const override;
};
