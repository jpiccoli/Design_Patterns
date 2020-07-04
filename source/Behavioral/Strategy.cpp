#include "../../include/Behavioral/Strategy.h"

#include <iostream>

// Strategy pattern lets the algorithm vary independently from clients that use it.

void Context::set_strategy( Strategy* strategy )
{
  delete this->strategy_;
  this->strategy_ = strategy;
}

void Context::DoSomeBusinessLogic(std::vector<std::string> &data) const
{
  std::cout << "Context: Sorting the data using the strategy (not sure how it'll do it)" << '\n';
  std::string result = this->strategy_->DoAlgorithm( data );
  std::cout << result << '\n';
}

std::string ConcreteStrategyA::DoAlgorithm( const std::vector<std::string> &data ) const
{
  std::cout << "ConcreteStrategyA::DoAlgorithm()\n";

  std::string result;
  std::for_each( std::begin( data ), std::end( data ), [ &result ]( const std::string &number ) {
    result += number;
  });

  std::sort( std::begin( result ), std::end( result ) );

  return result;
}

std::string ConcreteStrategyB::DoAlgorithm( const std::vector<std::string> &data ) const
{
  std::cout << "ConcreteStrategyB::DoAlgorithm()\n";

  std::string result;
  std::for_each( std::begin( data ), std::end( data ), [&result] ( const std::string &number ) {
    result += number;
  } );

  std::sort( std::begin( result ), std::end( result ) );
  for( unsigned i = 0; i < result.size() / 2; i++ )
  {
    std::swap( result[ i ], result[ result.size() - i - 1 ] );
  }

  return result;
}
