#pragma once

#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <vector>

struct BasicClass
{
protected:
  void BaseOperation1() const;
  void BaseOperation2() const;
  void BaseOperation3() const;

  virtual void RequiredOperations1() const = 0;
  virtual void RequiredOperations2() const = 0;

  virtual void ExtraOperations1() const;
  virtual void ExtraOperations2() const;

public:
  void TemplateMethod() const;
};

struct ActionClass1 : public BasicClass
{
protected:
  void RequiredOperations1() const override;
  void RequiredOperations2() const override;
  void ExtraOperations1() const override;
};

struct ActionClass2 : public BasicClass
{
  void RequiredOperations1() const override;
  void RequiredOperations2() const override;
  void ExtraOperations2() const override;
};





