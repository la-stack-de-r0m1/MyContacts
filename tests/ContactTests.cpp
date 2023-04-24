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

BOOST_AUTO_TEST_CASE( testSetFirstName )
{
    Contact c{"Romain", ""};
    c.getIdentity().setFirstname("Jean");
    const auto firstname = c.getIdentity().getFirstname();
    BOOST_TEST(firstname == "Jean");
}

BOOST_AUTO_TEST_CASE( testSetLastName )
{
    Contact c{"", "Bertholon"};
    c.getIdentity().setLastname("Dupont");
    const auto lastname = c.getIdentity().getLastname();
    BOOST_TEST(lastname == "Dupont");
}

BOOST_AUTO_TEST_CASE( testSetNickName )
{
    Contact c{"", "", "r0m1"};
    c.getIdentity().setNickname("m0r1");
    const auto nickname = c.getIdentity().getNickname();
    BOOST_TEST(nickname == "m0r1");
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
    c.addContactDetail("Phone Number", "0123456789");
    auto phone_number = c.getContactDetail("Phone Number");

    BOOST_TEST("0123456789" == phone_number);
}

BOOST_AUTO_TEST_CASE( testThrowIfPersonalInfoNotFound )
{
    Contact c{"romain"};
    BOOST_CHECK_THROW(c.getContactDetail("Phone Number"), std::out_of_range);
}

BOOST_AUTO_TEST_CASE( testThrowIfCategoryIfNotExist )
{
    Contact contact{"romain"};
    BOOST_CHECK_THROW(contact.getContactDetail("category", "name"), std::out_of_range);
}

BOOST_AUTO_TEST_CASE( testCreateCategoryIfNotExist )
{
    Contact contact{"romain"};
    contact.addContactDetail("Contacts", Contact::DetailKeyValue{"E-mail", "r0m1@me.com"});

    const auto email = contact.getContactDetail("Contacts", "E-mail");
    BOOST_TEST("r0m1@me.com" == email);
}

BOOST_AUTO_TEST_CASE( testAddAddress )
{

}

BOOST_AUTO_TEST_SUITE_END( )
