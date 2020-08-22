// A behavioral design pattern that lets you traverse elements of a collection without 
// exposing its underlying representation (list, stack, tree, etc.).

#include "../../include/Behavioral/Iterator.h"

NetworkData::NetworkData(int m_data_) : m_data(m_data_)
{
}

int NetworkData::get_data() const
{
  return m_data;
}
