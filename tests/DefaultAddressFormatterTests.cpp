#include <boost/test/unit_test.hpp>
#include <sstream>

#include "DefaultAddressFormatter.h"
#include "ContactAddress.h"
#include "testHelpers.h"

using namespace MyContacts;

BOOST_AUTO_TEST_SUITE ( DefaultAddressFormatterTests )

BOOST_AUTO_TEST_CASE( testAddressFormat )
{
    ContactAddress ca{createTestContactAddress()};

    const std::string formattedAddr = DefaultAddressFormatter::format(ca);
    std::ostringstream expectedAddr;
    expectedAddr << "42 some lost street" << std::endl
        << "75000 Paris" << std::endl
        << "France" << std::endl
        << "Building: Bat. A" << std::endl
        << "Pin code: 8484A" << std::endl
        << "Floor: 2" << std::endl
        << "Additional information: Some info..." << std::endl;

    BOOST_TEST(expectedAddr.str() == formattedAddr);
}

BOOST_AUTO_TEST_SUITE_END( )
