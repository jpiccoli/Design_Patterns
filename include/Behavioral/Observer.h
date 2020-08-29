#pragma once

#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <vector>

struct ISubscriber // Observer
{
  virtual ~ISubscriber() {}
  virtual void Update(std::string const& message_from_subject_) = 0;
};

struct IPublisher // Subject
{
  virtual ~IPublisher() {}
  virtual void Attach(std::shared_ptr<ISubscriber> observer) = 0;
  virtual void Detach(std::shared_ptr<ISubscriber> observer) = 0;
  virtual void Notify() = 0;
};

struct Publisher : public IPublisher
{
private:
  std::list<std::shared_ptr<ISubscriber>> list_subscribers;
  std::string message;

public:
  virtual ~Publisher();
  void Attach(std::shared_ptr<ISubscriber> observer) override;
  void Detach(std::shared_ptr<ISubscriber> observer) override;
  void Notify() override;
  void CreateMessage(std::string message_ = "Empty");
  void HowManyObservers();
  void BusinessLogic();
};

struct Subscriber : public ISubscriber
{
private:
  std::string message_from_subject;
  Publisher &publisher;
  static int static_number;

public:
  Subscriber(Publisher &publisher_);
  virtual ~Subscriber();
  void Update(std::string const& message_from_subject_) override;
  void RemoveFromList();
  void PrintInfo();
  int number;
};
