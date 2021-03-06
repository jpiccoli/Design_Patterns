// Design_Patterns.cpp : Defines the entry point for the console application.
//

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
#include "include/Structural/Singleton.h"

#include <iostream>

int Subscriber::static_number = 0;

int main()
{
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Behavioral Patterns\n";
  std::cout << "-----------------------------------\n";

  // Completed 08/22/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Chain Of Responsibility...\n";
  std::cout << "-----------------------------------\n";
  auto check_handler = std::make_shared<CheckHandler>();
  auto credit_handler = std::make_shared<CreditHandler>();
  auto cash_handler = std::make_shared<CashHandler>();
  check_handler->SetNext(credit_handler)->SetNext(cash_handler);

  std::vector<std::string> payments{ "WriteCheck", "InputCreditCard", "PayWithCash", "PayByPurchaseOrder" };

  std::cout << "Chain: Check => Credit => Cash\n";
  for(std::string const& transaction : payments)
  {
    std::cout << "Client: The transaction is: " << transaction << ".\n";
    const std::string result = check_handler->Handle(transaction);
    if(!result.empty())
      std::cout << "  " << result;
    else
      std::cout << "  " << transaction << " was not performed.\n";
  }

  std::cout << '\n';
  std::cout << "Chain: Credit => Cash\n";
  for(std::string const& transaction : payments)
  {
    std::cout << "Client: The transaction is: " << transaction << ".\n";
    const std::string result = credit_handler->Handle(transaction);
    if(!result.empty())
      std::cout << "  " << result;
    else
      std::cout << "  " << transaction << " was not performed.\n";
  }

  // Completed 08/22/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Command...\n";
  std::cout << "-----------------------------------\n";
  auto invoker = std::make_shared<Invoker>();
  invoker->SetOnStart(std::make_shared<SimpleCommand>("Starting"));
  auto receiver = std::make_shared<Receiver>();
  invoker->SetOnFinish(std::make_shared<ComplexCommand>(receiver, "Send email", "Save report"));
  invoker->DoSomethingImportant();

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Interpreter (DEFERRED)...\n";
  std::cout << "-----------------------------------\n";

  // Deferred 08/22/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Iterator...\n";
  std::cout << "-----------------------------------\n";

  std::cout << "Iterator with int:\n";
  NetworkContainer<int> container;
  for(int i = 0; i < 9; ++i)
    container.Add(i);

  std::shared_ptr<NetworkIterator<int, NetworkContainer<int>>> it = container.CreateIterator();
  for(it->First(); !it->IsDone(); it->Next()) {
    std::cout << *it->Current() << '\n';
  }

  std::cout << '\n';

  NetworkContainer<NetworkData> container2;
  NetworkData a(27), b(29), c(31);
  container2.Add(a);
  container2.Add(b);
  container2.Add(c);

  std::cout << "Iterator with custom class:\n";

  std::shared_ptr<NetworkIterator<NetworkData, NetworkContainer<NetworkData>>> it2 = container2.CreateIterator();
  for(it2->First(); !it2->IsDone(); it2->Next()) {
    std::cout << it2->Current()->get_data() << '\n';
  }

  // Completed 08/22/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Mediator...\n";
  std::cout << "-----------------------------------\n";
  auto comp1 = std::make_shared<Component1>();
  auto comp2 = std::make_shared<Component2>();
  auto mediator = std::make_shared<ConcreteMediator>(comp1, comp2);
  std::cout << "Client triggers operation A.\n";
  comp1->DoA();
  std::cout << '\n';
  std::cout << "Client triggers operation D.\n";
  comp2->DoD();
  std::cout << '\n';

  // Completed 07/04/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Memento...\n";
  std::cout << "-----------------------------------\n";
  Originator *originator = new Originator("String1-String2-String3-String4-String5-String6.");
  Caretaker* caretaker = new Caretaker(originator);
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

  // Completed 08/29/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Observer...\n";
  std::cout << "-----------------------------------\n";
  { // Scope operator required to invoke destructor on publisher immediately
    std::shared_ptr<Publisher> publisher = std::make_shared<Publisher>();
    std::shared_ptr<Subscriber> subscriber1 = std::make_shared<Subscriber>(*publisher);
    std::shared_ptr<Subscriber> subscriber2 = std::make_shared<Subscriber>(*publisher);
    std::shared_ptr<Subscriber> subscriber3 = std::make_shared<Subscriber>(*publisher);
    std::shared_ptr<Subscriber> subscriber4;
    std::shared_ptr<Subscriber> subscriber5;

    publisher->CreateMessage("Message 1 :D");
    subscriber3->RemoveFromList();
    publisher->CreateMessage("Message 2 :p");
    subscriber4 = std::make_shared<Subscriber>(*publisher);
    subscriber2->RemoveFromList();
    subscriber5 = std::make_shared<Subscriber>(*publisher);
    publisher->CreateMessage("Message 3 ;");
    subscriber5->RemoveFromList();
    subscriber4->RemoveFromList();
    subscriber1->RemoveFromList();
  }

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
  TCPOctetStream tcp_octet_stream("This is an octet stream");
  tcp_connection->ProcesOctet(&tcp_octet_stream);
  tcp_connection->Acknowledge();
  tcp_connection->Synchronize();
  tcp_connection->Close();

  // Completed 07/04/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Strategy...\n";
  std::cout << "-----------------------------------\n";
  std::vector<std::string> data_to_process{ "2", "4", "5", "1", "3" };
  Context* context = new Context(new ConcreteStrategyA);
  context->DoSomeBusinessLogic(data_to_process);
  std::cout << '\n';
  context->set_strategy(new ConcreteStrategyB);
  context->DoSomeBusinessLogic(data_to_process);
  delete context;

  // Completed 08/29/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Template Method...\n";
  std::cout << "-----------------------------------\n";
  std::shared_ptr<ActionClass1> action1 = std::make_shared<ActionClass1>();
  action1->TemplateMethod();
  std::cout << '\n';
  std::shared_ptr<ActionClass2> action2 = std::make_shared<ActionClass2>();
  action2->TemplateMethod();

  // Completed 09/05/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Visitor...\n";
  std::cout << "-----------------------------------\n";
  std::array<const std::shared_ptr<Visitor_Component>, 2> components = { std::make_shared<ConcreteComponentA>(), std::make_shared<ConcreteComponentB>() };
  std::cout << "The client code works with all visitors via the base Visitor interface:\n";
  std::shared_ptr<ConcreteVisitor1> visitor1 = std::make_shared<ConcreteVisitor1>();
  for(const std::shared_ptr<Visitor_Component> comp : components)
  {
    comp->Accept(visitor1);
  }
  std::cout << '\n';
  std::cout << "It allows the same client code to work with different types of visitors:\n";
  std::shared_ptr<ConcreteVisitor2> visitor2 = std::make_shared<ConcreteVisitor2>();
  for(const std::shared_ptr<Visitor_Component> comp : components)
  {
    comp->Accept(visitor2);
  }

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Creational Patterns\n";
  std::cout << "-----------------------------------\n";

  // Completed 08/15/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Abstract Factory...\n";
  std::cout << "-----------------------------------\n";
  std::shared_ptr<ConcreteFactory1> f1 = std::make_shared<ConcreteFactory1>();
  std::cout << "Testing with the first factory type:\n";
  const std::shared_ptr<AbstractProductA> product_a1 = f1->CreateProductA();
  const std::shared_ptr<AbstractProductC> product_c1 = f1->CreateProductC();
  std::cout << product_c1->ProductFunctionC() << '\n';
  std::cout << product_c1->AnotherProductFunctionC( *product_a1 ) << '\n';
  std::cout << '\n';
  std::shared_ptr<ConcreteFactory2> f2 = std::make_shared<ConcreteFactory2>();
  std::cout << "Testing with the second factory type:\n";
  const std::shared_ptr<AbstractProductA> product_a2 = f2->CreateProductA();
  const std::shared_ptr<AbstractProductC> product_c2 = f2->CreateProductC();
  std::cout << product_c2->ProductFunctionC() << '\n';
  std::cout << product_c2->AnotherProductFunctionC( *product_a2 ) << '\n';

  // Completed 08/09/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Builder...\n";
  std::cout << "-----------------------------------\n";
  Director director;
  std::shared_ptr<CarBuilder> car_builder = std::make_shared<CarBuilder>();
  director.ConstructSportsCar( car_builder );
  std::cout << "Sports Car:\n";
  std::shared_ptr<Car> c1 = car_builder->GetCar();
  c1->ListParts();
  
  std::cout << '\n';

  director.ConstructSUV( car_builder );
  std::cout << "SUV:\n";
  std::shared_ptr<Car> c2 = car_builder->GetCar();
  c2->ListParts();

  // Completed 08/09/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Factory Method...\n";
  std::cout << "-----------------------------------\n";
  std::shared_ptr<Dialog> windows_dialog, web_dialog;
  windows_dialog = std::make_shared<WindowsDialog>();
  windows_dialog->render("Windows Dialog");

  web_dialog = std::make_shared<WebDialog>();
  web_dialog->render( "Web Dialog" );

  // Completed 08/09/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Prototype...\n";
  std::cout << "-----------------------------------\n";
  std::shared_ptr<PrototypeFactory> pf = std::make_shared<PrototypeFactory>();
  std::cout << "Let's create a Prototype 1\n";
  std::shared_ptr<Prototype> p1 = pf->CreatePrototype(Designator::DESIGNATOR_1);
  p1->SetOperation(95);

  std::cout << "Let's create a Prototype 2\n";
  std::shared_ptr<Prototype> p2 = pf->CreatePrototype(Designator::DESIGNATOR_2);
  p2->SetOperation(17);

  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Structural Patterns\n";
  std::cout << "-----------------------------------\n";

  // Completed 08/15/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Adapter...\n";
  std::cout << "-----------------------------------\n";
  std::shared_ptr<BasicProngSocket> socket = std::make_shared<BasicProngSocket>(5);
  std::shared_ptr<BasicProngPlug> plug = std::make_shared<BasicProngPlug>(5);
  std::cout << "Test #1: " << std::boolalpha << socket->fits(*plug) << '\n';

  std::shared_ptr<AdvancedProngPlug> small_plug = std::make_shared<AdvancedProngPlug>(5);
  std::shared_ptr<AdvancedProngPlug> large_plug = std::make_shared<AdvancedProngPlug>(11);

  std::shared_ptr<AdvancedProngPlugAdaptor> small_adapter = std::make_shared<AdvancedProngPlugAdaptor>(*small_plug);
  std::shared_ptr<AdvancedProngPlugAdaptor> large_adapter = std::make_shared<AdvancedProngPlugAdaptor>(*large_plug);
  std::cout << "Test #2: " << std::boolalpha << socket->fits(*small_adapter) << '\n';
  std::cout << "Test #3: " << std::boolalpha << socket->fits(*large_adapter) << '\n';

  // Completed 08/15/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Bridge...\n";
  std::cout << "-----------------------------------\n";
  std::shared_ptr<Tv> tv = std::make_shared<Tv>();
  std::shared_ptr<RemoteControl> tv_remote = std::make_shared<RemoteControl>(tv);
  tv_remote->toggle_power();
  tv_remote->toggle_power();
  tv_remote->channel_up();
  tv_remote->channel_down();
  tv_remote->volume_up();
  tv_remote->volume_down();
  std::cout << '\n';
  std::shared_ptr<Radio> radio = std::make_shared<Radio>();
  std::shared_ptr<AdvancedRemoteControl> radio_remote = std::make_shared<AdvancedRemoteControl>(radio);
  radio_remote->toggle_power();
  radio_remote->toggle_power();
  radio_remote->channel_up();
  radio_remote->channel_down();
  radio_remote->volume_up();
  radio_remote->volume_down();
  radio_remote->mute();

  // Completed 08/15/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Composite...\n";
  std::cout << "-----------------------------------\n";
  std::shared_ptr<Component> simple = std::make_shared<Leaf>();
  std::cout << "Main: Simple Component\n";
  std::cout << '\n';
  std::shared_ptr<Composite> tree = std::make_shared<Composite>();
  std::shared_ptr<Composite> branch1 = std::make_shared<Composite>();
  std::shared_ptr<Component> leaf1 = std::make_shared<Leaf>();
  std::shared_ptr<Component> leaf2 = std::make_shared<Leaf>();
  std::shared_ptr<Component> leaf3 = std::make_shared<Leaf>();
  branch1->add(leaf1);
  branch1->add(leaf2);
  std::shared_ptr<Composite> branch2 = std::make_shared<Composite>();
  branch2->add(leaf3);
  tree->add(branch1);
  tree->add(branch2);
  std::cout << "Now have composite tree\n";
  std::cout << "RESULT: " << tree->operation() << "\n\n";
  std::cout << "I don't need to check the components classes even when managing the tree:\n";
  if(tree->is_composite())
  {
    tree->add(simple);
  }
  std::cout << "RESULT: " << tree->operation() << "\n";
  
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

  // Completed 08/15/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Proxy...\n";
  std::cout << "-----------------------------------\n";
  std::vector<VideoInfo> video_info = { { 1, "WWWWWWWW" },{ 2, "XXXXXXX" },{ 3, "YYYYYYY" },{ 4, "ZZZZZZZ" } };
  std::shared_ptr<ThirdPartyVideoClass> video_service = std::make_shared<ThirdPartyVideoClass>(video_info);
  std::shared_ptr<Proxy> proxy = std::make_shared<Proxy>(video_service);

  std::cout << "Proxy Operations:\n";
  proxy->react_on_user_input(3);

  std::cout << "\nVideo Manager Operations:\n";
  std::shared_ptr<VideoManager> video_manager = std::make_shared<VideoManager>(proxy);
  video_manager->react_on_user_input(4);

  // Completed 08/15/2020
  std::cout << '\n';
  std::cout << "-----------------------------------\n";
  std::cout << "Testing Singleton...\n";
  std::cout << "-----------------------------------\n";
  std::thread t1(Thread1);
  std::thread t2(Thread2);
  t1.join();
  t2.join();

  std::cout << '\n';

  return 0;
}

