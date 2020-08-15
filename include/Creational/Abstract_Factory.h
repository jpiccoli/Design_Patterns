#pragma once

#include <string>
#pragma once

#include <memory>
#include <string>

struct AbstractProductA
{
  virtual ~AbstractProductA() {};
  virtual std::string ProductFunctionA() const = 0;
};

struct AbstractProductC
{
  virtual ~AbstractProductC() {};
  virtual std::string ProductFunctionC() const = 0;
  virtual std::string AnotherProductFunctionC( AbstractProductA const& collaborator ) const = 0;
};

struct ConcreteProductA1 : public AbstractProductA
{
  virtual ~ConcreteProductA1() {};
  virtual std::string ProductFunctionA() const;
};

struct ConcreteProductA2 : public AbstractProductA
{
  virtual ~ConcreteProductA2() {};
  virtual std::string ProductFunctionA() const;
};

struct ConcreteProductC1 : public AbstractProductC
{
  virtual ~ConcreteProductC1() {};
  virtual std::string ProductFunctionC() const;
  std::string AnotherProductFunctionC( AbstractProductA const& collaborator ) const;
};

struct ConcreteProductC2 : public AbstractProductC
{
  virtual ~ConcreteProductC2() {};
  virtual std::string ProductFunctionC() const;
  std::string AnotherProductFunctionC( AbstractProductA const& collaborator ) const;
};

struct AbstractFactory
{
  virtual std::shared_ptr<AbstractProductA> CreateProductA() const = 0;
  virtual std::shared_ptr<AbstractProductC> CreateProductC() const = 0;
};

struct ConcreteFactory1 : public AbstractFactory
{
  std::shared_ptr<AbstractProductA> CreateProductA() const override;
  std::shared_ptr<AbstractProductC> CreateProductC() const override;
};

struct ConcreteFactory2 : public AbstractFactory
{
  std::shared_ptr<AbstractProductA> CreateProductA() const override;
  std::shared_ptr<AbstractProductC> CreateProductC() const override;
};


//enum Direction { North, South, East, West };
//
//struct MapSite
//{
//  virtual void Enter() = 0;
//};
//
//struct Room : public MapSite
//{
//  Room( int roomNo ) { _roomNumber = roomNo; }
//
//  virtual void Enter();
//
//private:
//  MapSite * _sides[ 4 ];
//  int _roomNumber;
//};
//
//struct Wall : public MapSite
//{
//  Wall() {};
//
//  virtual void Enter();
//};
//
//struct Door : public MapSite
//{
//  Door( Room* room1 = nullptr, Room* room2 = nullptr )
//  {
//    _room1 = room1;
//    _room2 = room2;
//  }
//
//  virtual void Enter();
//  Room* OtherSideFrom( Room* );
//  void SetSide( Direction direction, MapSite* map_site );
//
//private:
//  Room* _room1;
//  Room* _room2;
//  bool _isOpen;
//};
//
//struct Maze
//{
//  Maze() {}
//
//  void AddRoom( Room* );
//  Room* RoomNo( int ) const;
//};
//
//struct MazeFactory
//{
//  MazeFactory() {};
//
//  virtual Maze* MakeMaze() const {
//    return new Maze;
//  }
//
//  virtual Wall* MakeWall() const {
//    return new Wall;
//  }
//
//  virtual Room* MakeRoom(int n) const {
//    return new Room(n);
//  }
//
//  virtual Door* MakeDoor( Room* r1, Room* r2 ) const
//  {
//    return new Door( r1, r2 );
//  }
//};


