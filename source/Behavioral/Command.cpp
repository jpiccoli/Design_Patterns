// A behavioral design pattern that turns a request into a stand-alone object that contains all 
// information about the request. This transformation lets you parameterize methods with different 
// requests, delay or queue a request’s execution, and support undoable operations.

#include "../../include/Behavioral/Command.h"

SimpleCommand::SimpleCommand(std::string const& payload_) : payload(payload_)
{
}

void SimpleCommand::execute() const
{
  std::cout << "SimpleCommand: I can do simple things like printing (" << this->payload << ").\n";
}

void Receiver::DoSomething(std::string const& action1_)
{
  std::cout << "Receiver: Working on (" << action1_ << ".)\n";
}

void Receiver::DoSomethingElse(std::string const& action2_)
{
  std::cout << "Receiver: Also working on (" << action2_ << ".)\n";
}

ComplexCommand::ComplexCommand(std::shared_ptr<Receiver> receiver_, std::string const& action1_, std::string const& action2_)
  : receiver(receiver_), action1(action1_), action2(action2_)
{
}

void ComplexCommand::execute() const
{
  std::cout << "ComplexCommand: Should be done by Receiver object.\n";
  this->receiver->DoSomething(action1);
  this->receiver->DoSomethingElse(action2);
}

void Invoker::SetOnStart(std::shared_ptr<Command> command_)
{
  on_start = command_;
}

void Invoker::SetOnFinish(std::shared_ptr<Command> command_)
{
  on_finish = command_;
}

void Invoker::DoSomethingImportant()
{
  std::cout << "Invoker: Prior to starting.\n";
  if(on_start)
    on_start->execute();

  std::cout << "Invoker: ...Doing something important...\n";
  std::cout << "Invoker: Prior to finishing.\n";
  if(on_finish)
    on_finish->execute();
}
