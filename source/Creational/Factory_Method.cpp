// Provides an interface for creating objects in a superclass, but allows subclasses 
// to alter the type of objects that will be created.

#include "../../include/Creational/Factory_Method.h"

void Dialog::render( std::string control )
{
  std::cout << "Rendering " << control << "...\n";;
  std::shared_ptr<Button> okButton = createButton();
  okButton->onClick( "Closing dialog" );
  okButton->render( "Dimensions: 7 x 7" );
}

void WindowsButton::render( std::string item )
{
  std::cout << "Rendering Windows button - " << item << '\n';
}

void WindowsButton::onClick( std::string click_event )
{
  std::cout << "Windows button click event - " << click_event << '\n';
}

void HTMLButton::render( std::string item )
{
  std::cout << "Rendering Web button - " << item << '\n';
}

void HTMLButton::onClick( std::string click_event )
{
  std::cout << "Web button click event - " << click_event << '\n';
}

std::shared_ptr<Button> WindowsDialog::createButton()
{
  return std::make_shared<WindowsButton>();
}

std::shared_ptr<Button> WebDialog::createButton()
{
  return std::make_shared<HTMLButton>();
}












