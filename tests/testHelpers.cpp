#include "testHelpers.h"



namespace MyContacts
{

ContactAddress createTestContactAddress()
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

    return ca;
}

}
