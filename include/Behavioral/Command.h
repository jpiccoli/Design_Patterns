#pragma once

#include <iostream>
#include <memory>
#include <string>

struct Command
{
  virtual ~Command() {}
  virtual void execute() const = 0;
};

struct SimpleCommand : public Command
{
private:
  std::string payload;

public:
  explicit SimpleCommand(std::string const& payload_);

  void execute() const override;
};

struct Receiver;

struct ComplexCommand : public Command
{
private:
  std::shared_ptr<Receiver> receiver;
  std::string action1;
  std::string action2;

public:
  ComplexCommand(std::shared_ptr<Receiver> receiver_, std::string const& action1_, std::string const& action2_);
  void execute() const override;
};

struct Receiver
{
  void DoSomething(std::string const& action1_);
  void DoSomethingElse(std::string const& action2_);
};

struct Invoker
{
private:
  std::shared_ptr<Command> on_start;
  std::shared_ptr<Command> on_finish;

public:
  void SetOnStart(std::shared_ptr<Command> command_);
  void SetOnFinish(std::shared_ptr<Command> command_);
  void DoSomethingImportant();

};

