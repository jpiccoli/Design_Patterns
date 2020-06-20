#pragma once

enum Direction { North, South, East, West };

struct MapSite
{
  virtual void Enter() = 0;
};

struct Room : public MapSite
{
  Room( int roomNo ) { _roomNumber = roomNo; }

  virtual void Enter();

private:
  MapSite * _sides[ 4 ];
  int _roomNumber;
};

struct Wall : public MapSite
{
  Wall() {};

  virtual void Enter();
};

struct Door : public MapSite
{
  Door( Room* room1 = nullptr, Room* room2 = nullptr )
  {
    _room1 = room1;
    _room2 = room2;
  }

  virtual void Enter();
  Room* OtherSideFrom( Room* );
  void SetSide( Direction direction, MapSite* map_site );

private:
  Room* _room1;
  Room* _room2;
  bool _isOpen;
};

struct Maze
{
  Maze() {}

  void AddRoom( Room* );
  Room* RoomNo( int ) const;
};

struct MazeFactory
{
  MazeFactory() {};

  virtual Maze* MakeMaze() const {
    return new Maze;
  }

  virtual Wall* MakeWall() const {
    return new Wall;
  }

  virtual Room* MakeRoom(int n) const {
    return new Room(n);
  }

  virtual Door* MakeDoor( Room* r1, Room* r2 ) const
  {
    return new Door( r1, r2 );
  }


};


