//  Structural design pattern that supports splitting a large class or a set of closely related classes 
// into two separate hierarchies—abstraction and implementation—which can be developed independently of
// each other.

#include "../../include/Structural/Bridge.h"

void RemoteControl::toggle_power()
{
  std::cout << "RemoteControl::toggle_power()\n";
  if(device->is_enabled())
  {
    std::cout << "RemoteControl::disable()\n";
    device->disable();
  }
  else
  {
    std::cout << "RemoteControl::enable()\n";
    device->enable();
  }
}

void RemoteControl::volume_down()
{
  device->set_volume(device->get_volume() - 9);
  std::cout << "RemoteControl::volume_down() => " << device->get_volume() << "\n";
}

void RemoteControl::volume_up()
{
  device->set_volume(device->get_volume() + 9);
  std::cout << "RemoteControl::volume_down() => " << device->get_volume() << "\n";
}

void RemoteControl::channel_down()
{
  device->set_channel(device->get_channel() - 1);
  std::cout << "RemoteControl::volume_down() => " << device->get_channel() << "\n";
}

void RemoteControl::channel_up()
{
  device->set_channel(device->get_channel() + 1);
  std::cout << "RemoteControl::volume_down() => " << device->get_channel() << "\n";
}

void AdvancedRemoteControl::mute()
{
  std::cout << "AdvanceRemoteControl::mute()\n";
  device->set_volume(0);
}

bool Tv::is_enabled() const
{
  std::cout << "Tv::is_enabled()\n";
  return enabled;
}

void Tv::enable()
{
  std::cout << "Tv::enable()\n";
  enabled = true;
}

void Tv::disable()
{
  std::cout << "Tv::disable()\n";
  enabled = false;
}

int Tv::get_volume() const
{
  std::cout << "Tv::get_volume()\n";
  return volume;
}

void Tv::set_volume(int volume_)
{
  std::cout << "Tv::set_volume()\n";
  volume = volume_;
}

double Tv::get_channel() const
{
  std::cout << "Tv::get_channel()\n";
  return channel;
}

void Tv::set_channel(double channel_)
{
  std::cout << "Tv::set_channel()\n";
  channel = channel_;
}

bool Radio::is_enabled() const
{
  std::cout << "Radio::is_enabled()\n";
  return enabled;
}

void Radio::enable()
{
  std::cout << "Radio::enable()\n";
  enabled = true;
}

void Radio::disable()
{
  std::cout << "Radio::disable()\n";
  enabled = false;
}

int Radio::get_volume() const
{
  std::cout << "Radio::get_volume()\n";
  return volume;
}

void Radio::set_volume(int volume_)
{
  std::cout << "Radio::set_volume()\n";
  volume = volume_;
}

double Radio::get_channel() const
{
  std::cout << "Radio::get_channel()\n";
  return dial_position;
}

void Radio::set_channel(double dial_position_)
{
  std::cout << "Radio::set_channel()\n";
  dial_position = dial_position_;
}


