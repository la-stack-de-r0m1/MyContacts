#include <boost/test/unit_test.hpp>

#include <string>
#include <stdexcept>

#include "CategoryList.h"
#include "StringContactDetail.h"

using namespace MyContacts;

BOOST_AUTO_TEST_SUITE ( CategoryListTests )

BOOST_AUTO_TEST_CASE( testFindCategoryByName )
{
    CategoryList<StringContactDetail> catList;
    catList.add({"Contact details"});
    auto category = catList.get("Contact details");
    BOOST_TEST("Contact details" == category.name());
}

BOOST_AUTO_TEST_CASE( testThrowIfNoCategoryFound )
{
    CategoryList<StringContactDetail> catList;
    BOOST_CHECK_THROW(catList.get("Contact details"), std::out_of_range);
}

BOOST_AUTO_TEST_CASE( testUpdate )
{
    CategoryList<StringContactDetail> catList;
    catList.add({"Contact details"});
    auto category = catList.get("Contact details");
    category.setContactDetail("E-mail", "rom@1.fr");

    catList.update(category);
    auto updatedCategory = catList.get("Contact details");
    BOOST_TEST("rom@1.fr" == updatedCategory.getContactDetail("E-mail"));
}

BOOST_AUTO_TEST_CASE( testExist )
{
    CategoryList<StringContactDetail> catList;
    BOOST_TEST(false == catList.categoryExist("Contact details"));

    catList.add({"Contact details"});
    BOOST_TEST(true == catList.categoryExist("Contact details"));
}

BOOST_AUTO_TEST_SUITE_END( )
