// Allows for production families of related objects without specifying their concrete classes.

#include "../../include/Creational/Abstract_Factory.h"

std::string ConcreteProductA1::ProductFunctionA() const
{
  return "The result of product A1.";
}

std::string ConcreteProductA2::ProductFunctionA() const
{
  return "The result of product A2.";
}

std::string ConcreteProductC1::ProductFunctionC() const
{
  return "The result of product C1.";
}

std::string ConcreteProductC1::AnotherProductFunctionC( AbstractProductA const& collaborator ) const
{
  const std::string result = collaborator.ProductFunctionA();
  return "The result of C1 collaborating with ( " + result + " )";
}

std::string ConcreteProductC2::ProductFunctionC() const
{
  return "The result of product C2.";
}

std::string ConcreteProductC2::AnotherProductFunctionC( AbstractProductA const& collaborator ) const
{
  const std::string result = collaborator.ProductFunctionA();
  return "The result of C2 collaborating with ( " + result + " )";
}

std::shared_ptr<AbstractProductA> ConcreteFactory1::CreateProductA() const
{
  return std::make_shared<ConcreteProductA1>();
}

std::shared_ptr<AbstractProductC> ConcreteFactory1::CreateProductC() const
{
  return std::make_shared<ConcreteProductC1>();
}

std::shared_ptr<AbstractProductA> ConcreteFactory2::CreateProductA() const
{
  return std::make_shared<ConcreteProductA2>();
}

std::shared_ptr<AbstractProductC> ConcreteFactory2::CreateProductC() const
{
  return std::make_shared<ConcreteProductC2>();
}

//void Room::Enter()
//{
//  // TODO: 06/20/2020
//}
//
//void Wall::Enter()
//{
//  // TODO: 06/20/2020
//}
//
//void Door::Enter()
//{
//  // TODO: 06/20/2020
//}
//
//Room*  Door::OtherSideFrom( Room* )
//{
//  // TODO: 06/20/2020
//  return nullptr;
//}
//
//void Door::SetSide( Direction direction, MapSite* map_site )
//{
//  // TODO: 06/20/2020
//}
//
//void Maze::AddRoom( Room* )
//{
//  // TODO: 06/20/2020
//}
//
//Room* Maze::RoomNo( int ) const
//{
//  // TODO: 06/20/2020
//  return nullptr;
//}

