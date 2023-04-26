#ifndef CONTACTADDRESS_H
#define CONTACTADDRESS_H

#include <string>

namespace MyContacts
{

class ContactAddress
{
    unsigned int streetNumber{0};
    std::string streetName;
    std::string building;
    std::string doorPinCode;
    int floorNumber{0};
    std::string additionalInfo;

    std::string zipcode;
    std::string cityName;
    std::string country;

    public:
        inline unsigned int getStreetNumber() const { return streetNumber;}
        ContactAddress& setStreetNumber(unsigned int streetNumber);

        inline const std::string& getStreetName() const { return streetName;}
        ContactAddress& setStreetName(const std::string& streetName);

        inline const std::string& getBuilding() const { return building;}
        ContactAddress& setBuilding(const std::string& building);

        inline const std::string getDoorPinCode() const { return doorPinCode;}
        ContactAddress& setDoorPinCode(const std::string& doorPinCode);

        inline int getFloorNumber() const { return floorNumber;}
        ContactAddress& setFloorNumber(int floorNumber);

        inline const std::string getAdditionalInfo() const { return additionalInfo;}
        ContactAddress& setAdditionalInfo(const std::string& additionalInfo);

        inline const std::string getZipcode() const { return zipcode;}
        ContactAddress& setZipcode(const std::string& zipcode);

        inline const std::string getCityName() const { return cityName;}
        ContactAddress&  setCityName(const std::string& cityName);

        inline const std::string getCountry() const { return country;}
        ContactAddress& setCountry(const std::string& country);
};

}

#endif // CONTACTADDRESS_H
