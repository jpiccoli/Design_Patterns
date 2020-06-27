#pragma once

struct VisualComponent
{
  VisualComponent();

  virtual void Draw();
  virtual void Resize();
};

struct Decorator : public VisualComponent
{
  Decorator() = default;

  Decorator( VisualComponent * );

  virtual void Draw();
  virtual void Resize();

protected:
  VisualComponent * _component;
};

struct BorderDecorator : public Decorator
{
  BorderDecorator() = default;

  BorderDecorator( VisualComponent *, int borderWidth );

  virtual void Draw();

private:
  void DrawBorder( int );
  int _width;
};
