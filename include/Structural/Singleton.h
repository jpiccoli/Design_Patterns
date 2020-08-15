#pragma once

#include <chrono>
#include <iostream>
#include <memory>
#include <ostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

void Thread1();
void Thread2();

// Reference: https://stackoverflow.com/questions/1008019/c-singleton-design-pattern

struct Singleton
{
protected:
  std::string value_;

  Singleton(std::string const& value) : value_(value) {}

public:
  Singleton(Singleton &other) = delete;
  void operator=(Singleton &other) = delete;
  static std::shared_ptr<Singleton> get_instance(std::string const&);
  std::string get_value() const { return value_; }
};
