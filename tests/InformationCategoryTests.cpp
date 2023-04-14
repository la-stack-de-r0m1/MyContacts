#include <boost/test/unit_test.hpp>

#include <string>
#include <stdexcept>

#include "InformationCategory.h"

using namespace MyContacts;

BOOST_AUTO_TEST_SUITE ( InformationCategoryTests )

BOOST_AUTO_TEST_CASE( testCategoryName )
{
    Category ic{"Contact details"};

    BOOST_TEST("Contact details" == ic.name());
}

BOOST_AUTO_TEST_CASE( testSetEmail )
{
    Category ic{"Contact details"};
    ic.set("E-mail", "r0m1@me.com");
    const auto& email = ic.get("E-mail");
    BOOST_TEST("r0m1@me.com" == email);
}

BOOST_AUTO_TEST_CASE( testGetThrowIfInfoNotExist )
{
    Category ic{"Contact details"};

    BOOST_CHECK_THROW(ic.get("E-mail"), std::out_of_range);
}

BOOST_AUTO_TEST_CASE( testEqualOperatorIsEqual )
{
    Category lhs{"Contact details"};
    Category rhs{"Contact details"};

    bool res = (lhs == rhs);
    BOOST_TEST(true == res);
}

BOOST_AUTO_TEST_CASE( testEqualOperatorIsDifferent )
{
    Category lhs{"Contact details"};
    Category rhs{"Stuff"};

    bool res = (lhs == rhs);
    BOOST_TEST(false == res);
}


BOOST_AUTO_TEST_CASE( testEqualOperatorCompareName )
{
    Category lhs{"Contact details"};

    bool res = (lhs == std::string("Contact details"));
    BOOST_TEST(true == res);
}


BOOST_AUTO_TEST_SUITE_END( )
