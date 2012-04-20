/**
 *
 */

#define BOOST_TEST_DYN_LINK
#include "../helper.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE( dont_be_afraid )

BOOST_AUTO_TEST_CASE( cpp_is_not_too_hard )
{
  BOOST_TEST_MESSAGE( "C++ is not too hard to learn!" );
  BOOST_TEST_MESSAGE( "Read the output of 'CppKoans' after you compiled it." );
  BOOST_TEST_MESSAGE( "Then go to the source file of the first error." );
  BOOST_TEST_MESSAGE( "And make the test pass." );
  BOOST_TEST_MESSAGE( "We start right here:" );
  BOOST_CHECK( false );
  BOOST_CHECK_MESSAGE( false, "That was easy, wasn't it?" );
  BOOST_TEST_MESSAGE( "Go on while you walk the path to enlightment ..." );
}

BOOST_AUTO_TEST_SUITE_END()                                 // End of dont_be_afraid

// EOF