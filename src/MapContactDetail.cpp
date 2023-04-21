#include <sstream>

#include "MapContactDetail.h"

namespace MyContacts
{

MapContactDetail::MapContactDetail(const std::string& name, const MapContactDetail::MapStrStr& value)
    : ContactDetail{name, value}
{
}

const std::string MapContactDetail::toString() const
{
    std::ostringstream formatted_addr;
    const auto& values = getDetailValue();
    for (const auto& fieldName : Fields) {
        auto pos = values.find(fieldName);
        if (pos != values.end())
            formatted_addr << pos->second << ", ";
    }
    auto address = formatted_addr.str();
    address.erase(address.end() - 2, address.end());

    return address;
}

}
