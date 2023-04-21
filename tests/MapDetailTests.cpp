#include <boost/test/unit_test.hpp>

#include "MapContactDetail.h"

using namespace MyContacts;

BOOST_AUTO_TEST_SUITE ( MapDetailTests )

BOOST_AUTO_TEST_CASE( testSetValue )
{
   MapContactDetail mcd{"Address", {
        {"street", "Street Name"},
        {"number", "42"},
        {"country", "fr" }
    }};

   BOOST_TEST("42, Street Name, fr" == mcd.toString());
}

BOOST_AUTO_TEST_CASE( testUpdateValue )
{

}

BOOST_AUTO_TEST_SUITE_END( )
