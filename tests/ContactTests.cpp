#include <boost/test/unit_test.hpp>

#include "Contact.h"

using namespace MyContacts;

BOOST_AUTO_TEST_SUITE ( ContactTests )

BOOST_AUTO_TEST_CASE( testGetFirstName )
{
    Contact c{"Romain", ""};
    const auto firstname = c.get_firstname();
    BOOST_TEST(firstname == "Romain");
}

BOOST_AUTO_TEST_CASE( testGetLastName )
{
    Contact c{"", "Bertholon"};
    const auto lastname = c.get_lastname();
    BOOST_TEST(lastname == "Bertholon");
}

BOOST_AUTO_TEST_CASE( testGetNickName )
{
    Contact c{"", "", "r0m1"};
    const auto nicktname = c.get_nickname();
    BOOST_TEST(nicktname == "r0m1");
}

BOOST_AUTO_TEST_CASE( testThrowIfEmptyPersonalInfo )
{
    BOOST_CHECK_THROW(Contact("", "", ""), std::logic_error);
}

BOOST_AUTO_TEST_SUITE_END( )
