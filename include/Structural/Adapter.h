#pragma once

#include <iostream>
#include <string>
#include <math.h>

struct BasicProngPlug // Target
{
private:
  double radius;

public:
  BasicProngPlug() {}
  BasicProngPlug( double radius_ ) : radius( radius_ ) {}
  virtual double get_radius() const { return radius; }
};

struct BasicProngSocket
{
private:
  double radius;

public:
  BasicProngSocket( double radius_ ) : radius( radius_ ) {}
  double get_radius() const { return radius; }
  bool fits( BasicProngPlug  const& plug ) const;
};

struct AdvancedProngPlug // Adaptee
{
private:
  double width;

public:
  AdvancedProngPlug( double width_ ) : width( width_ ) {}
  double get_width() const { return width; }
};

struct AdvancedProngPlugAdaptor : public BasicProngPlug
{
private:
  AdvancedProngPlug advanced_prong_plug;

public:
  AdvancedProngPlugAdaptor( AdvancedProngPlug advanced_prong_plug_ ) : advanced_prong_plug( advanced_prong_plug_ ) {}
  virtual double get_radius() const override;
};

