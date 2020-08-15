// A structural design pattern that lets you provide a substitute or placeholder for another object. 
// A proxy controls access to the original object, allowing you to perform something either before or 
// after the request gets through to the original object.

#include "../../include/Structural/Singleton.h"

std::shared_ptr<Singleton> Singleton::get_instance(std::string const& value)
{
  static std::shared_ptr<Singleton> singleton{ new Singleton(value) };
  return singleton;
}

void Thread1()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  std::shared_ptr<Singleton> singleton = Singleton::get_instance("THREAD1");
  std::cout << singleton->get_value() << '\n';
}

// Static item-based
void Thread2()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  std::shared_ptr<Singleton> singleton = Singleton::get_instance("THREAD2");
  std::cout << singleton->get_value() << '\n';
}

