#pragma once

#include <string>
#include <vector>
#include <algorithm>

// https://refactoring.guru/design-patterns/strategy/cpp/example

struct Strategy
{
  virtual ~Strategy() {}
  virtual std::string DoAlgorithm( const std::vector<std::string> &data ) const = 0;
};

struct Context
{

  Context( Strategy* strategy = nullptr ) : strategy_( strategy )
  {
  }

  ~Context()
  {
    delete this->strategy_;
  }

  void set_strategy( Strategy* strategy );

  void DoSomeBusinessLogic( std::vector<std::string> &data ) const;

private:
  Strategy * strategy_;

};

struct ConcreteStrategyA : public Strategy
{
  std::string DoAlgorithm( const std::vector<std::string> &data ) const;
};

struct ConcreteStrategyB : public Strategy
{
  std::string DoAlgorithm( const std::vector<std::string> &data ) const;
};
