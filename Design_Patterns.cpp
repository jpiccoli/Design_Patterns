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
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Creational Patterns\n";
  std::cout << "-----------------------------------\n";
#if 0

  std::cout << "Testing Abstract Factory...\n";

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Builder...\n";
  std::cout << "-----------------------------------\n";

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Factory Method...\n";
  std::cout << "-----------------------------------\n";

#endif
  // Completed 08/09/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Prototype...\n";
  std::cout << "-----------------------------------\n";
  PrototypeFactory *pf = new PrototypeFactory();
  std::cout << "Let's create a Prototype 1\n";
  auto *p1 = pf->CreatePrototype( Designator::DESIGNATOR_1 );
  p1->SetOperation( 95 );

  std::cout << "Let's create a Prototype 2\n";
  auto *p2 = pf->CreatePrototype( Designator::DESIGNATOR_2 );
  p2->SetOperation( 17 );

  delete p1;
  delete p2;
  delete pf;

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Structural Patterns\n";
  std::cout << "-----------------------------------\n";

#if 0
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

  // Completed 07/25/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Facade...\n";
  std::cout << "-----------------------------------\n";
  Subsystem1 *subsystem1 = new Subsystem1;
  Subsystem2 *subsystem2 = new Subsystem2;
  Facade *facade = new Facade( subsystem1, subsystem2 );
  std::cout << facade->Operation();
  delete facade;

  // Completed 07/25/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Flyweight...\n";
  std::cout << "-----------------------------------\n";
  FlyweightFactory *factory = new FlyweightFactory( { { "Chevrolet", "Trax2019", "pink" },
                                                      { "Mercedes Benz", "E300", "black" },
                                                      { "Mercedes Benz", "S500", "red" },
                                                      { "BMW", "M5", "red" },
                                                      { "BMW", "X6", "white" } } );
  factory->ListFlyweights();
  AddCarToDatabase( *factory, "CL234IR", "James Doe", "BMW", "M5", "red" );
  AddCarToDatabase( *factory, "CL234IT", "James Doe", "BMW", "X1", "red");
  factory->ListFlyweights();
  delete factory;

#if 0
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Proxy...\n";
  std::cout << "-----------------------------------\n";

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Abstract Factory...\n";
  std::cout << "-----------------------------------\n";
#endif

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Behavioral Patterns\n";
  std::cout << "-----------------------------------\n";
#if 0
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
#endif

  // Completed 07/04/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Memento...\n";
  std::cout << "-----------------------------------\n";
  Originator *originator = new Originator( "String1-String2-String3-String4-String5-String6." );
  Caretaker* caretaker = new Caretaker( originator );
  caretaker->Backup();
  originator->DoSomething();
  caretaker->Backup();
  originator->DoSomething();
  caretaker->Backup();
  originator->DoSomething();
  std::cout << '\n';
  caretaker->ShowHistory();
  std::cout << '\n';
  std::cout << "Rollback #1\n";
  caretaker->Undo();
  std::cout << '\n';
  std::cout << "Rollback #2\n";
  caretaker->Undo();
  std::cout << '\n';
  std::cout << "Rollback #3\n";
  caretaker->Undo();
  std::cout << '\n';
  std::cout << "Rollback #4\n";
  caretaker->Undo();

  delete originator;
  delete caretaker;

#if 0
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Observer...\n";
  std::cout << "-----------------------------------\n";
#endif

  // Completed 06/27/2020
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

  // Completed 07/04/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Strategy...\n";
  std::cout << "-----------------------------------\n";
  std::vector<std::string> data_to_process{ "2", "4", "5", "1", "3" };
  Context* context = new Context( new ConcreteStrategyA );
  context->DoSomeBusinessLogic( data_to_process );
  std::cout << '\n';
  context->set_strategy( new ConcreteStrategyB );
  context->DoSomeBusinessLogic( data_to_process );
  delete context;

  std::cout << '\n';

#if 0
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

