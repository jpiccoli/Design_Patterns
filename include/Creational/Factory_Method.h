#pragma once

#include <iostream>
#include <memory>
#include <string>

struct Button
{
  virtual ~Button() {}

  virtual void render( std::string ) = 0;
  virtual void onClick( std::string ) = 0;
};

struct WindowsButton : public Button
{
  void render( std::string item_ );
  void onClick( std::string );
};

struct HTMLButton : public Button
{
  void render( std::string item_ );
  void onClick( std::string );
};

struct Dialog
{
  virtual std::shared_ptr<Button> createButton() = 0;
  void render(std::string);
};

struct WindowsDialog : public Dialog
{
  std::shared_ptr<Button> createButton();
};

struct WebDialog : public Dialog
{
  std::shared_ptr<Button> createButton();
};


