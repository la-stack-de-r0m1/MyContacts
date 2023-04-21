#include <boost/test/unit_test.hpp>

#include <string>
#include <stdexcept>

#include "Category.h"
#include "StringContactDetail.h"

using namespace MyContacts;

BOOST_AUTO_TEST_SUITE ( InformationCategoryTests )

BOOST_AUTO_TEST_CASE( testCategoryName )
{
    Category<StringContactDetail> ic{"Contact details"};

    BOOST_TEST("Contact details" == ic.name());
}

BOOST_AUTO_TEST_CASE( testSetEmail )
{
    Category<StringContactDetail> ic{"Contact details"};
    ic.setContactDetail("E-mail", "r0m1@me.com");
    const auto& email = ic.getContactDetail("E-mail");
    BOOST_TEST("r0m1@me.com" == email);
}

BOOST_AUTO_TEST_CASE( testGetThrowIfInfoNotExist )
{
    Category<StringContactDetail> ic{"Contact details"};

    BOOST_CHECK_THROW(ic.getContactDetail("E-mail"), std::out_of_range);
}

BOOST_AUTO_TEST_CASE( testEqualOperatorIsEqual )
{
    Category<StringContactDetail> lhs{"Contact details"};
    Category<StringContactDetail> rhs{"Contact details"};

    bool res = (lhs == rhs);
    BOOST_TEST(true == res);
}

BOOST_AUTO_TEST_CASE( testEqualOperatorIsDifferent )
{
    Category<StringContactDetail> lhs{"Contact details"};
    Category<StringContactDetail> rhs{"Stuff"};

    bool res = (lhs == rhs);
    BOOST_TEST(false == res);
}


BOOST_AUTO_TEST_CASE( testEqualOperatorCompareName )
{
   /* Category<StringContactDetail> lhs{"Contact details"};

    bool res = (lhs == std::string("Contact details"));
    BOOST_TEST(true == res);*/
}


BOOST_AUTO_TEST_SUITE_END( )
