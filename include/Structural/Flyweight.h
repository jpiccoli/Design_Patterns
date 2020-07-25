#pragma once

#include <string>
#include <ostream>
#include <map>
#include <unordered_map>

#include <iostream>

struct SharedState
{
  std::string brand_;
  std::string model_;
  std::string color_;

  SharedState( std::string const& brand, std::string const& model, std::string const& color ) : brand_( brand ), model_( model ), color_( color )
  {}

  friend std::ostream &operator<<( std::ostream &os, SharedState const& ss )
  {
    return os << "[ " << ss.brand_ << " , " << ss.model_ << " , " << ss.color_ << " ]";
  }

  void PrintSharedState() const
  {
    std::cout << brand_ << " , " << model_ << " , " << color_;
  }
};

struct UniqueState
{
  std::string owner_;
  std::string plates_;
  SharedState *shared_state_;

  UniqueState( std::string const& owner, std::string const& plates ) : owner_( owner ), plates_( plates )
  {}

  friend std::ostream &operator<<( std::ostream &os, UniqueState const& us )
  {
    return os << "[ " << us.owner_ << " , " << us.plates_ << " ]";
  }

  void PrintUniqueState() const
  {
    std::cout << owner_ << " , " << plates_;
  }
};

struct Flyweight
{
  Flyweight( const SharedState *shared_state ) : shared_state_( new SharedState( *shared_state ) )
  {
  }

  Flyweight( const Flyweight &other ) : shared_state_( new SharedState( *other.shared_state_ ) )
  {
  }

  ~Flyweight()
  {
    delete shared_state_;
  }

  SharedState *shared_state_ptr() const
  {
    return shared_state_;
  }

  SharedState shared_state() const
  {
    return *shared_state_;
  }

  void Operation( UniqueState const& unique_state ) const;

private:
  SharedState * shared_state_;
};

struct FlyweightFactory
{
  FlyweightFactory() {}

  FlyweightFactory( std::initializer_list<SharedState> share_states );

  Flyweight GetFlyweight( SharedState const& shared_state );

  void ListFlyweights() const;

private:
  std::unordered_map<std::string, Flyweight> flyweights_;

  std::string GetKey( SharedState const& ss ) const;
};

//struct FlyweightStorage
//{
//  std::vector<UniqueState> unique_states_;
//
//  FlyweightStorage( FlyweightFactory * flyweight_factory )
//  {
//    flyweight_factory_ = flyweight_factory;
//  }
//
//  void AddStorageItem( const std::string &brand, const std::string &model, const std::string &color, const std::string &plates, const std::string &owner )
//  {
//    Flyweight flyweight = flyweight_factory_->GetFlyweight( { brand, model, color } );
//    UniqueState us( owner, plates );
//    us.shared_state_ = &flyweight.shared_state();
//    unique_states_.push_back( us );
//  }
//
//  void ListStorage()
//  {
//    for( auto item : unique_states_ )
//    {
//      item.shared_state_->PrintSharedState();
//      std::cout << " - ";
//      item.PrintUniqueState();
//      std::cout << '\n';
//    }
//  }
//
//private:
//  FlyweightFactory * flyweight_factory_;
//};

void AddCarToDatabase(
  FlyweightFactory &ff, const std::string &plates, const std::string &owner,
  const std::string &brand, const std::string &model, const std::string &color );
