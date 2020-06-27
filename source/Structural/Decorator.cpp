#include "../../include/Structural/Decorator.h"

#include <iostream>

VisualComponent::VisualComponent()
{
}

void VisualComponent::Draw()
{
  std::cout << "VisualComponent::Draw()\n";
}

void VisualComponent::Resize()
{
  std::cout << "VisualComponent::Resize()\n";
}

Decorator::Decorator( VisualComponent* component )
{
  _component = component;
}

void Decorator::Draw()
{
  std::cout << "Decorator::Draw()\n";
  _component->Draw();
}

void Decorator::Resize()
{
  std::cout << "Decorator::Resize()\n";
  _component->Resize();
}

BorderDecorator::BorderDecorator(VisualComponent *component, int width)
{
  _component = component;
  _width = width;
}

void BorderDecorator::Draw()
{
  std::cout << "BorderDecorator::Draw()\n";
  Decorator::Draw();
  DrawBorder( _width );
}

void BorderDecorator::DrawBorder(int width)
{
  std::cout << "BorderDecorator::DrawBorder(): width = " << width << '\n';
}



