#include <boost/test/unit_test.hpp>

#include <string>

#include "ContactIdentity.h"

using namespace MyContacts;

BOOST_AUTO_TEST_SUITE ( ContactIdentityTests )

BOOST_AUTO_TEST_CASE( testGetFirstName )
{
    ContactIdentity ci{"Romain"};
    const auto firstname = ci.getFirstname();
    BOOST_TEST(firstname == "Romain");
}

BOOST_AUTO_TEST_CASE( testGetLastName )
{
    ContactIdentity ci{"", "Bertholon"};
    const auto lastname = ci.getLastname();
    BOOST_TEST(lastname == "Bertholon");
}

BOOST_AUTO_TEST_CASE( testGetNickName )
{
    ContactIdentity ci{"", "", "r0m1"};
    const auto nickname = ci.getNickname();
    BOOST_TEST(nickname == "r0m1");
}

BOOST_AUTO_TEST_CASE( testThrowIfEmptyPersonalInfo )
{
    BOOST_CHECK_THROW(ContactIdentity("", "", ""), std::logic_error);
}

BOOST_AUTO_TEST_CASE( testTrimSpacesCharacters )
{
    ContactIdentity ci{" Romain\t", "  Bertholon  ", "\tr0m1  "};

    BOOST_TEST("Romain" == ci.getFirstname());
    BOOST_TEST("Bertholon" == ci.getLastname());
    BOOST_TEST("r0m1" == ci.getNickname());
}

BOOST_AUTO_TEST_CASE( testUpdateFirstname)
{
    ContactIdentity ci{"Romain", "Bertholon", "r0m1"};
    ci.setFirstname("Jean");
    BOOST_TEST("Jean" == ci.getFirstname());
}

BOOST_AUTO_TEST_CASE( testThrowIfUpdateFirstnameIsEmpty)
{
    ContactIdentity ci{"Romain", "", ""};

    BOOST_CHECK_THROW(ci.setFirstname(""), std::logic_error);
    BOOST_TEST("Romain" == ci.getFirstname());

    BOOST_CHECK_THROW(ci.setFirstname("   \t\n"), std::logic_error);
    BOOST_TEST("Romain" == ci.getFirstname());
}

BOOST_AUTO_TEST_CASE( testUpdateLastname)
{
    ContactIdentity ci{"Romain", "Bertholon", "r0m1"};
    ci.setLastname("Dupont");
    BOOST_TEST("Dupont" == ci.getLastname());
}

BOOST_AUTO_TEST_CASE( testThrowIfUpdateLastnameIsEmpty)
{
    ContactIdentity ci{"", "Bertholon", ""};

    BOOST_CHECK_THROW(ci.setLastname(""), std::logic_error);
    BOOST_TEST("Bertholon" == ci.getLastname());

    BOOST_CHECK_THROW(ci.setLastname("   \t\n"), std::logic_error);
    BOOST_TEST("Bertholon" == ci.getLastname());
}

BOOST_AUTO_TEST_CASE( testUpdateNickname)
{
    ContactIdentity ci{"Romain", "Bertholon", "r0m1"};
    ci.setNickname("m1r0");
    BOOST_TEST("m1r0" == ci.getNickname());

}

BOOST_AUTO_TEST_CASE( testThrowIfUpdateNicknameIsEmpty)
{
    ContactIdentity ci{"", "", "r0m1"};

    BOOST_CHECK_THROW(ci.setNickname(""), std::logic_error);
    BOOST_TEST("r0m1" == ci.getNickname());

    BOOST_CHECK_THROW(ci.setNickname("   \t\n"), std::logic_error);
    BOOST_TEST("r0m1" == ci.getNickname());

}

BOOST_AUTO_TEST_SUITE_END( )
