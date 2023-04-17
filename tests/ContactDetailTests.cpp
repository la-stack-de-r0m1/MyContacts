#include <boost/test/unit_test.hpp>

#include "ContactDetail.h"

using namespace MyContacts;

BOOST_AUTO_TEST_SUITE ( ContactDetailTests )

BOOST_AUTO_TEST_CASE( testDetailName )
{
    ContactDetail cd{"E-mail", ""};

    BOOST_TEST("E-mail" == cd.getDetailName());
}

BOOST_AUTO_TEST_CASE( testDetailValue )
{
    ContactDetail cd{"E-mail", "mail@example.com"};

    BOOST_TEST("mail@example.com" == cd.getDetailValue());
}

BOOST_AUTO_TEST_CASE( testDetailValueUpdate )
{
    ContactDetail cd{"E-mail", "mail@example.com"};
    cd.setDetailValue("r0m1@pm.me");

    BOOST_TEST("r0m1@pm.me" == cd.getDetailValue());
}

BOOST_AUTO_TEST_CASE( testDetailLabel )
{
    ContactDetail cd{"E-mail", "r0m1@pm.me"};

    cd.setLabel("Domicile");

    BOOST_TEST("Domicile" == cd.getLabel());
}

BOOST_AUTO_TEST_SUITE_END( )
