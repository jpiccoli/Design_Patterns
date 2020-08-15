#pragma once

#include <iostream>
#include <memory>
#include <string>

struct Device
{
  int volume{ 270 };
  bool enabled{ false };

  virtual bool is_enabled() const = 0;
  virtual void enable() = 0;
  virtual void disable() = 0;
  virtual int get_volume() const = 0;
  virtual void set_volume(int) = 0;
  virtual double get_channel() const = 0;
  virtual void set_channel(double) = 0;
};

struct Tv : public Device
{
  double channel{ 340.0 };

  virtual bool is_enabled() const;
  virtual void enable();
  virtual void disable();
  virtual int get_volume() const;
  virtual void set_volume(int);
  virtual double get_channel() const;
  virtual void set_channel(double);
};

struct Radio : public Device
{
  double dial_position{ 101.9 };

  virtual bool is_enabled() const;
  virtual void enable();
  virtual void disable();
  virtual int get_volume() const;
  virtual void set_volume(int);
  virtual double get_channel() const;
  virtual void set_channel(double);
};

struct RemoteControl
{
protected:
  std::shared_ptr<Device> device;

public:
  RemoteControl() {}
  RemoteControl(std::shared_ptr<Device> device_) : device(device_) {}

  void toggle_power();
  void volume_down();
  void volume_up();
  void channel_down();
  void channel_up();
};

struct AdvancedRemoteControl : public RemoteControl
{
  AdvancedRemoteControl() {}
  AdvancedRemoteControl(std::shared_ptr<Device> device_) : RemoteControl(device_) {}

  void mute();
};

