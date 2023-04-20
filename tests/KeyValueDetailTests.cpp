#include <boost/test/unit_test.hpp>

#include "StringContactDetail.h"

using namespace MyContacts;

BOOST_AUTO_TEST_SUITE ( StringDetailTests )

BOOST_AUTO_TEST_CASE( testSetValue )
{
   StringContactDetail scd{"E-mail", "mail@example.com"};

   BOOST_TEST("mail@example.com" == scd.toString());
}

BOOST_AUTO_TEST_CASE( testUpdateValue )
{
   StringContactDetail scd{"E-mail", "mail@example.com"};

   scd.setDetailValue("r0m1@example.com");

   BOOST_TEST("r0m1@example.com" == scd.toString());
}

BOOST_AUTO_TEST_SUITE_END( )
