/**
 *
 */

#define BOOST_TEST_DYN_LINK
#include "../helper.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE( variable_types )


BOOST_AUTO_TEST_SUITE( integers_are_standard )

BOOST_AUTO_TEST_CASE( simple_integer_numbers )
{
  int an_integer = 42;
  // You should replace 'FILL_THE_NUMBER_IN' with the propper value to satisfy the equation
  BOOST_CHECK_MESSAGE( an_integer == FILL_THE_NUMBER_IN, "This equality should be satisfied." );
}

BOOST_AUTO_TEST_CASE( integers_have_a_size )
{
  int an_integer = 1;
  BOOST_CHECK_MESSAGE( sizeof( int ) == FILL_THE_NUMBER_IN, "How big is an integer?" );
  BOOST_CHECK_MESSAGE( sizeof( an_integer ) == FILL_THE_NUMBER_IN, "How big is an_integer?" );
}

BOOST_AUTO_TEST_CASE( integers_can_be_negative )
{
  int an_integer = 42;
  int another_integer = -42;
  BOOST_CHECK_MESSAGE( an_integer < another_integer, "Which is bigger?" );
}

BOOST_AUTO_TEST_SUITE_END()                                 // End of integers_are_standard


BOOST_AUTO_TEST_SUITE( floating_points )

BOOST_AUTO_TEST_CASE( simple_floats )
{
  float a_float = 4.2;
  BOOST_CHECK_MESSAGE( a_float == FILL_THE_NUMBER_IN, "This equality should be satisfied." );
}

BOOST_AUTO_TEST_CASE( floats_have_a_size )
{
  int a_float = 4.2;
  BOOST_CHECK_MESSAGE( sizeof( float ) == FILL_THE_NUMBER_IN, "How big is a float?" );
  BOOST_CHECK_MESSAGE( sizeof( a_float ) == FILL_THE_NUMBER_IN, "How big is a_float?" );
}

BOOST_AUTO_TEST_SUITE_END()                                 // End of floating_points


BOOST_AUTO_TEST_SUITE( bigger_numbers )

BOOST_AUTO_TEST_CASE( going_double_precision ) {
  
}

BOOST_AUTO_TEST_CASE( doubles_have_a_size )
{
  int a_double = 4.2;
  BOOST_CHECK_MESSAGE( sizeof( double ) == FILL_THE_NUMBER_IN, "How big is a double?" );
  BOOST_CHECK_MESSAGE( sizeof( a_double ) == FILL_THE_NUMBER_IN, "How big is a_double?" );
}

BOOST_AUTO_TEST_SUITE_END()                                 // End of  bigger_numbers 


BOOST_AUTO_TEST_SUITE( going_even_bigger )

BOOST_AUTO_TEST_CASE( size_of_biggest_number )
{
  BOOST_TEST_MESSAGE("The size of long doubles vary from system to system.");
  long double a_long_double = 4.2;
  BOOST_CHECK_MESSAGE( sizeof( long double ) == FILL_THE_NUMBER_IN, "How big is a long double on your machine?" );
  BOOST_CHECK_MESSAGE( sizeof( a_long_double ) == FILL_THE_NUMBER_IN, "How big is a_long_double?" );
}

BOOST_AUTO_TEST_SUITE_END()                                 // End of  going_even_bigger 


BOOST_AUTO_TEST_SUITE_END()                                 // End of variable_types

// EOF