// A behavioral design pattern that lets you pass requests along a chain of handlers. Upon receiving a 
// request, each handler decides either to process the request or to pass it to the next handler in 
// the chain.

#include "../../include/Behavioral/Chain_Of_Responsibility.h"

std::shared_ptr<Handler> BaseHandler::SetNext(std::shared_ptr<Handler> handler_)
{
  this->next_handler = handler_;
  return handler_;
}

std::string BaseHandler::Handle(std::string const& request)
{
  if(this->next_handler)
    return this->next_handler->Handle(request);

  return "";
}

std::string CheckHandler::Handle(std::string const& request_)
{
  if(request_ == "WriteCheck")
    return "CheckHandler: Doing operation " + request_ + ".\n";
  else
    return BaseHandler::Handle(request_);
}

std::string CreditHandler::Handle(std::string const& request_)
{
  if(request_ == "InputCreditCard")
    return "CreditHandler: Doing operation " + request_ + ".\n";
  else
    return BaseHandler::Handle(request_);
}

std::string CashHandler::Handle(std::string const& request_)
{
  if(request_ == "PayWithCash")
    return "CashHandler: Doing operation " + request_ + ".\n";
  else
    return BaseHandler::Handle(request_);
}


