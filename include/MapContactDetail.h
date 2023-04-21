#ifndef MAPCONTACTDETAIL_H
#define MAPCONTACTDETAIL_H

#include <map>
#include <vector>
#include <string>

#include <ContactDetail.h>

namespace MyContacts
{

class MapContactDetail final :
    public ContactDetail<std::map<std::string, std::string>>
{
    const std::vector<std::string> Fields{
        {"number"},
        {"street"},
        {"city"},
        {"zipcode"},
        {"country"},
    };

    public:
        using MapStrStr = std::map<std::string, std::string>;

    public:
        MapContactDetail(const std::string& name, const MapStrStr& value);

        const std::string toString() const override;
};

}

#endif // MAPCONTACTDETAIL_H
