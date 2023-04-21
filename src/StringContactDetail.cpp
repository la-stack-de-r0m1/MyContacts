#include "StringContactDetail.h"

namespace MyContacts
{


StringContactDetail::StringContactDetail(const std::string& name, const std::string& value)
    : ContactDetail(name, value)
{
}

const std::string StringContactDetail::toString() const
{
    return std::string(getDetailValue());
}

}
