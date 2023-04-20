#include "StringContactDetail.h"

namespace MyContacts
{


StringContactDetail::StringContactDetail(const std::string& name, const std::string& value)
    : ContactDetail(name, "")
    , value{value}
{
}

void StringContactDetail::setDetailValue(const std::string& value)
{
    this->value = value;
}

const std::string& StringContactDetail::toString() const
{
    return value;
}

}
