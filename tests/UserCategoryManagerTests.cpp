#include <boost/test/unit_test.hpp>

#include "UserCategoryManager.h"

using namespace MyContacts;

BOOST_AUTO_TEST_SUITE ( UserCategoryManagerTests )

BOOST_AUTO_TEST_CASE( testThrowIfDefaultDetailDontExist )
{
    UserCategoryManager ucm;

    BOOST_CHECK_THROW(ucm.getContactDetailFromDefault("not_exist"), std::out_of_range);
}

BOOST_AUTO_TEST_CASE( testAddAParameterToDefault )
{
    UserCategoryManager ucm;
    ucm.addContactDetailToDefault("skype number", "123456789");

    BOOST_TEST("123456789" == ucm.getContactDetailFromDefault("skype number"));
}

BOOST_AUTO_TEST_CASE( testThrowIfCategoryIfNotExist )
{
    UserCategoryManager ucm;
    BOOST_CHECK_THROW(ucm.getContactDetailFromCategory("category", "name"), std::out_of_range);
}

BOOST_AUTO_TEST_CASE( testCreateCategoryIfNotExist )
{
    UserCategoryManager ucm;
    ucm.addContactDetailToCategory("Contacts", {"E-mail", "r0m1@me.com"});

    const auto email = ucm.getContactDetailFromCategory("Contacts", "E-mail");
    BOOST_TEST("r0m1@me.com" == email);
}

BOOST_AUTO_TEST_SUITE_END( )
