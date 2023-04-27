#include <boost/test/unit_test.hpp>

#include "AddressContactDetail.h"
#include "DefaultAddressFormatter.h"
#include "testHelpers.h"

using namespace MyContacts;

struct FakeFormatter
{
    static std::string format(const ContactAddress&) { return ""; }
};

BOOST_AUTO_TEST_SUITE ( AddressContactDetailTests )

BOOST_AUTO_TEST_CASE( testSetAddressNameWithCtors )
{
    ContactAddress addr{createTestContactAddress()};

    AddressContactDetail<FakeFormatter> acd1{"home", addr};
    BOOST_TEST("home" == acd1.getDetailName());

    AddressContactDetail<FakeFormatter> acd2{"home"};
    BOOST_TEST("home" == acd2.getDetailName());
}

BOOST_AUTO_TEST_CASE( testSetAddressWithCtor )
{
    ContactAddress addr{createTestContactAddress()};
    AddressContactDetail<FakeFormatter> acd{"home", addr};

    const auto& ca = acd.getDetailValue();

    BOOST_TEST(42 == ca.getStreetNumber());
    BOOST_TEST("some lost street" == ca.getStreetName());
    BOOST_TEST("Bat. A" == ca.getBuilding());
    BOOST_TEST("8484A" == ca.getDoorPinCode());
    BOOST_TEST(2 == ca.getFloorNumber());
    BOOST_TEST("Some info..." == ca.getAdditionalInfo());
    BOOST_TEST("75000" == ca.getZipcode());
    BOOST_TEST("Paris" == ca.getCityName());
    BOOST_TEST("France" == ca.getCountry());
}

BOOST_AUTO_TEST_CASE( testSetAddressWithSetter )
{
    AddressContactDetail<FakeFormatter> acd{"home", createTestContactAddress()};
    const auto& ca = acd.getDetailValue();

    BOOST_TEST(42 == ca.getStreetNumber());
    BOOST_TEST("some lost street" == ca.getStreetName());
    BOOST_TEST("Bat. A" == ca.getBuilding());
    BOOST_TEST("8484A" == ca.getDoorPinCode());
    BOOST_TEST(2 == ca.getFloorNumber());
    BOOST_TEST("Some info..." == ca.getAdditionalInfo());
    BOOST_TEST("75000" == ca.getZipcode());
    BOOST_TEST("Paris" == ca.getCityName());
    BOOST_TEST("France" == ca.getCountry());
}

BOOST_AUTO_TEST_CASE( testFormatAddress )
{
    AddressContactDetail<DefaultAddressFormatter> acd{"home", createTestContactAddress()};

    std::ostringstream expectedAddr;
    expectedAddr << "42 some lost street" << std::endl
        << "75000 Paris" << std::endl
        << "France" << std::endl
        << "Building: Bat. A" << std::endl
        << "Pin code: 8484A" << std::endl
        << "Floor: 2" << std::endl
        << "Additional information: Some info..." << std::endl;

    BOOST_TEST(expectedAddr.str() == acd.toString());
}

BOOST_AUTO_TEST_SUITE_END( )
