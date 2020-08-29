// A behavioral design pattern that lets you define a subscription mechanism to notify multiple 
// objects about any events that happen to the object they’re observing. Also known with the
// names "Event-Subscriber" and "Listener".

#include "../../include/Behavioral/Observer.h"

Publisher::~Publisher()
{
  std::cout << "This was a publisher\n";
}

void Publisher::Attach(std::shared_ptr<ISubscriber> observer)
{
  list_subscribers.push_back(observer);
}

void Publisher::Detach(std::shared_ptr<ISubscriber> observer)
{
  auto observer_ptr = std::dynamic_pointer_cast<Subscriber>(observer);
  for(auto const& item : list_subscribers)
  {
    auto ptr = std::dynamic_pointer_cast<Subscriber>(item);
    if(ptr->number == observer_ptr->number)
    {
      list_subscribers.remove(item);
      break;
    }
  }
}

void Publisher::Notify()
{
  std::list<std::shared_ptr<ISubscriber>>::iterator iterator = list_subscribers.begin();
  HowManyObservers();
  while(iterator != list_subscribers.end())
  {
    (*iterator)->Update(message);
    ++iterator;
  }
}

void Publisher::CreateMessage(std::string message_)
{
  message = message_;
  Notify();
}

void Publisher::HowManyObservers()
{
  std::cout << "There are " << list_subscribers.size() << " subscribers in the list.\n";
}

void Publisher::BusinessLogic()
{
  message = "change message message";
  Notify();
  std::cout << "About to do something\n";
}

Subscriber::Subscriber(Publisher &publisher_) : publisher(publisher_)
{
  //this->publisher.Attach(std::make_shared<Subscriber>(*this));
  std::cout << "I am the Observer \"" << ++Subscriber::static_number << "\".\n";
  this->number = Subscriber::static_number;
  this->publisher.Attach(std::make_shared<Subscriber>(*this));
}

void Subscriber::Update(std::string const& message_from_subject_)
{
  message_from_subject = message_from_subject_;
  PrintInfo();
}

Subscriber::~Subscriber()
{
  std::cout << "This was a subscriber\n";
}

void Subscriber::RemoveFromList()
{
  publisher.Detach(std::make_shared<Subscriber>(*this));
  std::cout << "Subscriber \"" << number << "\" removed from the list.\n";
}

void Subscriber::PrintInfo()
{
  std::cout << "Subscriber \"" << this->number << "\": a new message is available --> " << this->message_from_subject << "\n";
}
