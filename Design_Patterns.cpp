// Design_Patterns.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include "include/Behavioral/Chain_Of_Responsibility.h"
#include "include/Behavioral/Command.h"
#include "include/Behavioral/Interpreter.h"
#include "include/Behavioral/Iterator.h"
#include "include/Behavioral/Mediator.h"
#include "include/Behavioral/Memento.h"
#include "include/Behavioral/Observer.h"
#include "include/Behavioral/State.h"
#include "include/Behavioral/Strategy.h"
#include "include/Behavioral/Template_Method.h"
#include "include/Behavioral/Visitor.h"

#include "include/Creational/Abstract_Factory.h"
#include "include/Creational/Builder.h"
#include "include/Creational/Factory_Method.h"
#include "include/Creational/Prototype.h"

#include "include/Structural/Adapter.h"
#include "include/Structural/Bridge.h"
#include "include/Structural/Composite.h"
#include "include/Structural/Decorator.h"
#include "include/Structural/Facade.h"
#include "include/Structural/Flyweight.h"
#include "include/Structural/Proxy.h"

#include <iostream>

int main()
{
#if 0
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Creational Patterns\n";
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Abstract Factory...\n";

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Builder...\n";
  std::cout << "-----------------------------------\n";

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Factory Method...\n";
  std::cout << "-----------------------------------\n";

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Prototype...\n";
  std::cout << "-----------------------------------\n";

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Structural Patterns\n";
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Adapter...\n";

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Bridge...\n";
  std::cout << "-----------------------------------\n";

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Composite...\n";
  std::cout << "-----------------------------------\n";
#endif

  // Completed 06/27/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Decorator...\n";
  std::cout << "-----------------------------------\n";
  VisualComponent vc;
  BorderDecorator bd( &vc, 9 );
  bd.Draw();
  std::cout << "-----------------------------------\n";
  bd.Resize();

#if 0
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Facade...\n";
  std::cout << "-----------------------------------\n";

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Flyweight...\n";
  std::cout << "-----------------------------------\n";

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Proxy...\n";
  std::cout << "-----------------------------------\n";

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Abstract Factory...\n";
  std::cout << "-----------------------------------\n";

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Behavioral Patterns\n";
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Chain Of Responsibility...\n";

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Command...\n";
  std::cout << "-----------------------------------\n";

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Interpreter...\n";
  std::cout << "-----------------------------------\n";

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Iterator...\n";
  std::cout << "-----------------------------------\n";

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Mediator...\n";
  std::cout << "-----------------------------------\n";

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Memento...\n";
  std::cout << "-----------------------------------\n";

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Observer...\n";
  std::cout << "-----------------------------------\n";
#endif

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing State...\n";
  std::cout << "-----------------------------------\n";
  TCPConnection* tcp_connection = new TCPConnection();
  tcp_connection->ActiveOpen();
  tcp_connection->Send();
  tcp_connection->Close();
  std::cout << "-----------------------------------\n";
  tcp_connection->PassiveOpen();
  TCPOctetStream tcp_octet_stream( "This is an octet stream" );
  tcp_connection->ProcesOctet( &tcp_octet_stream );
  tcp_connection->Acknowledge();
  tcp_connection->Synchronize();
  tcp_connection->Close();

#if 0
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Strategy...\n";
  std::cout << "-----------------------------------\n";

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Template Method...\n";
  std::cout << "-----------------------------------\n";

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Visitor...\n";
  std::cout << "-----------------------------------\n";
#endif

  return 0;
}

