#include <boost/test/unit_test.hpp>

#include "ContactAddress.h"

using namespace MyContacts;

BOOST_AUTO_TEST_SUITE ( ContactAddressTests )

BOOST_AUTO_TEST_CASE( testSetGetValues )
{
    ContactAddress ca;

    ca.setStreetNumber(42)
        .setStreetName("some lost street")
        .setBuilding("Bat. A")
        .setDoorPinCode("8484A")
        .setFloorNumber(2)
        .setAdditionalInfo("Some info...")
        .setZipcode("75000")
        .setCityName("Paris")
        .setCountry("France");

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

BOOST_AUTO_TEST_SUITE_END( )
