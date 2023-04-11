#include <boost/test/unit_test.hpp>

#include "Contact.h"

using namespace MyContacts;

BOOST_AUTO_TEST_SUITE ( ContactTests )

BOOST_AUTO_TEST_CASE( testGetFirstName )
{
    Contact c{"Romain", ""};
    const auto firstname = c.getIdentity().getFirstname();
    BOOST_TEST(firstname == "Romain");
}

BOOST_AUTO_TEST_CASE( testGetLastName )
{
    Contact c{"", "Bertholon"};
    const auto lastname = c.getIdentity().getLastname();
    BOOST_TEST(lastname == "Bertholon");
}

BOOST_AUTO_TEST_CASE( testGetNickName )
{
    Contact c{"", "", "r0m1"};
    const auto nicktname = c.getIdentity().getNickname();
    BOOST_TEST(nicktname == "r0m1");
}

BOOST_AUTO_TEST_CASE( testThrowIfEmptyPersonalInfo )
{
    BOOST_CHECK_THROW(Contact("", "", ""), std::logic_error);
}

BOOST_AUTO_TEST_CASE( testTrimSpacesCharacters )
{
    Contact c{" Romain\t", "  Bertholon  ", "\tr0m1  "};

    BOOST_TEST("Romain" == c.getIdentity().getFirstname());
    BOOST_TEST("Bertholon" == c.getIdentity().getLastname());
    BOOST_TEST("r0m1" == c.getIdentity().getNickname());
}

BOOST_AUTO_TEST_CASE( testAddPersonalInfo )
{
    Contact c{"romain"};
    c.setPersonalInfo("Phone Number", "0123456789");
    auto phone_number = c.getPersonalInfo("Phone Number");

    BOOST_TEST("0123456789" == phone_number);
}

BOOST_AUTO_TEST_CASE( testThrowIfPersonalInfoNotFound )
{
    Contact c{"romain"};
    BOOST_CHECK_THROW(c.getPersonalInfo("Phone Number"), std::out_of_range);
}


BOOST_AUTO_TEST_SUITE_END( )
