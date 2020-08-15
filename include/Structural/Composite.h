#pragma once

#include <iostream>
#include <list>
#include <memory>
#include <string>

struct Component
{
protected:
  std::shared_ptr<Component> parent;

public:
  virtual ~Component() {};
  void set_parent(std::shared_ptr<Component> parent_) { parent = parent_; }
  std::shared_ptr<Component> get_parent() const { return parent; }

  virtual void add(std::shared_ptr<Component>) {}
  virtual void remove(std::shared_ptr<Component>) {}
  virtual bool is_composite() const { return false; }
  virtual std::string operation() const = 0;
};

struct Leaf : public Component
{
  std::string operation() const override;
};

struct Composite : public Component
{
protected:
  std::list<std::shared_ptr<Component>> elements;

public:
  void add(std::shared_ptr<Component>);
  void remove(std::shared_ptr<Component>);
  bool is_composite() const { return true; }
  std::string operation() const;
};

