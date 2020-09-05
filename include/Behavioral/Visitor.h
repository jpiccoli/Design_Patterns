#pragma once

#include <array>
#include <iostream>
#include <memory>
#include <string>

struct ConcreteComponentA;
struct ConcreteComponentB;

struct Visitor
{
  virtual void VisitConcreteComponentA(const std::shared_ptr<ConcreteComponentA> element) const = 0;
  virtual void VisitConcreteComponentB(const std::shared_ptr<ConcreteComponentB> element) const = 0;
};

struct Visitor_Component
{
  virtual ~Visitor_Component() {}
  virtual void Accept(const std::shared_ptr<Visitor> visitor) const = 0;
};

struct ConcreteComponentA : public Visitor_Component
{
  void Accept(std::shared_ptr<Visitor> const visitor) const override;
  std::string ExclusiveComponentA() const;
};

struct ConcreteComponentB : public Visitor_Component
{
  void Accept(std::shared_ptr<Visitor> const visitor) const override;
  std::string ExclusiveComponentB() const;
};

struct ConcreteVisitor1 : public Visitor
{
  void VisitConcreteComponentA(const std::shared_ptr<ConcreteComponentA> element_) const override;
  void VisitConcreteComponentB(const std::shared_ptr<ConcreteComponentB> element_) const override;
};

struct ConcreteVisitor2 : public Visitor
{
  void VisitConcreteComponentA(const std::shared_ptr<ConcreteComponentA> element_) const override;
  void VisitConcreteComponentB(const std::shared_ptr<ConcreteComponentB> element_) const override;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//class ConcreteComponentA1;
//class ConcreteComponentB1;
//
//class Visitor1 {
//public:
//  virtual void VisitConcreteComponentA1(const ConcreteComponentA1 *element) const = 0;
//  virtual void VisitConcreteComponentB1(const ConcreteComponentB1 *element) const = 0;
//};
//
//class Component1 {
//public:
//  virtual ~Component1() {}
//  virtual void Accept(Visitor1 *visitor) const = 0;
//};
//
//class ConcreteComponentA1 : public Component1 {
//public:
//  void Accept(Visitor1 *visitor) const override {
//    visitor->VisitConcreteComponentA1(this);
//  }
//  std::string ExclusiveMethodOfConcreteComponentA() const {
//    return "A";
//  }
//};
