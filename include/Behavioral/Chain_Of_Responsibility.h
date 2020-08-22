#pragma once

#include <iostream>
#include <memory>
#include <string>

struct Handler
{
  virtual std::shared_ptr<Handler> SetNext(std::shared_ptr<Handler> handler) = 0;
  virtual std::string Handle(std::string const& request) = 0;
};

struct BaseHandler : public Handler
{
private:
  std::shared_ptr<Handler> next_handler;

public:
  BaseHandler() : next_handler(nullptr) {}
  std::shared_ptr<Handler> SetNext(std::shared_ptr<Handler> handler_) override;
  std::string Handle(std::string const& request) override;
};

struct CheckHandler : public BaseHandler
{
  std::string Handle(std::string const& request_) override;
};

struct CreditHandler : public BaseHandler
{
  std::string Handle(std::string const& request_) override;
};

struct CashHandler : public BaseHandler
{
  std::string Handle(std::string const& request_) override;
};
















