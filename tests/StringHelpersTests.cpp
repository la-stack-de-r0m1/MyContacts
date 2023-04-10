#include <boost/test/unit_test.hpp>

#include <string>

#include "StringHelpers.h"

using namespace MyContacts;

BOOST_AUTO_TEST_SUITE ( StringHelpersTests )

BOOST_AUTO_TEST_CASE( testRemovesSpaces )
{
    const std::string text_to_clean{"\ttext   \n"};
    const auto clean_text = StringHelpers::cleanString(text_to_clean);
    BOOST_TEST("text" == clean_text);
}

BOOST_AUTO_TEST_SUITE_END( )
