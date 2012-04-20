/**
 *
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE CppKoans
#include <boost/test/unit_test.hpp>
#include "helper.hpp"

BOOST_GLOBAL_FIXTURE( KoansConfig );

BOOST_AUTO_TEST_SUITE( dont_be_afraid )
// defined in koans/00_the_start.cpp
BOOST_AUTO_TEST_SUITE_END()                                 // End of dont_be_afraid

BOOST_AUTO_TEST_SUITE( variable_types )
// defined in koans/01_variable_types.cpp
BOOST_AUTO_TEST_SUITE_END()                                 // End of variable_types
