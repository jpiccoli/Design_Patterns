#pragma once

#include "../../include/Creational/Abstract_Factory.h"

void Room::Enter()
{
  // TODO: 06/20/2020
}

void Wall::Enter()
{
  // TODO: 06/20/2020
}

void Door::Enter()
{
  // TODO: 06/20/2020
}

Room*  Door::OtherSideFrom( Room* )
{
  // TODO: 06/20/2020
  return nullptr;
}

void Door::SetSide( Direction direction, MapSite* map_site )
{
  // TODO: 06/20/2020
}

void Maze::AddRoom( Room* )
{
  // TODO: 06/20/2020
}

Room* Maze::RoomNo( int ) const
{
  // TODO: 06/20/2020
  return nullptr;
}

