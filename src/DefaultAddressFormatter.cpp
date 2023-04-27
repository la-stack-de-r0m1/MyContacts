#include <sstream>

#include "DefaultAddressFormatter.h"
#include "ContactAddress.h"

namespace MyContacts
{

std::string DefaultAddressFormatter::format(const ContactAddress& address)
{
    std::ostringstream formattedAddr;

    formattedAddr
        << address.getStreetNumber() << " " << address.getStreetName() << std::endl
        << address.getZipcode() << " " << address.getCityName() << std::endl
        << address.getCountry() << std::endl
        << "Building: " << address.getBuilding() << std::endl
        << "Pin code: " << address.getDoorPinCode() << std::endl
        << "Floor: " << address.getFloorNumber() << std::endl
        << "Additional information: " << address.getAdditionalInfo() << std::endl;

    return formattedAddr.str();
}

}
