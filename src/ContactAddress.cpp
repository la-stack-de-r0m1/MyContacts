#include "ContactAddress.h"

namespace MyContacts
{

ContactAddress& ContactAddress::setStreetNumber(unsigned int streetNumber)
{
    this->streetNumber = streetNumber;
    return *this;
}

ContactAddress& ContactAddress::setStreetName(const std::string& streetName)
{
    this->streetName = streetName;
    return *this;
}

ContactAddress& ContactAddress::setBuilding(const std::string& building)
{
    this->building = building;
    return *this;
}

ContactAddress& ContactAddress::setDoorPinCode(const std::string& doorPinCode)
{
    this->doorPinCode = doorPinCode;
    return *this;
}

ContactAddress& ContactAddress::setFloorNumber(int floorNumber)
{
    this->floorNumber = floorNumber;
    return *this;
}

ContactAddress& ContactAddress::setAdditionalInfo(const std::string& additionalInfo)
{
    this->additionalInfo = additionalInfo;
    return *this;
}

ContactAddress& ContactAddress::setZipcode(const std::string& zipcode)
{
    this->zipcode = zipcode;
    return *this;
}

ContactAddress&  ContactAddress::setCityName(const std::string& cityName)
{
    this->cityName = cityName;
    return *this;
}

ContactAddress& ContactAddress::setCountry(const std::string& country)
{
    this->country = country;
    return *this;
}

}
