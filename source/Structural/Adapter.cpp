// A structural design pattern that allows objects with incompatible interfaces to collaborate.

#include "../../include/Structural/Adapter.h"

bool BasicProngSocket::fits( BasicProngPlug  const& plug ) const
{ 
  return this->get_radius() >= plug.get_radius();
}

double AdvancedProngPlugAdaptor::get_radius() const
{
  return advanced_prong_plug.get_width() * sqrt( 2 ) / 2;
}
