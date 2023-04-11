#include <stdexcept>

#include "Contact.h"
#include "StringHelpers.h"

namespace MyContacts
{

Contact::Contact(const std::string& firstname,
                 const std::string& lastname,
                 const std::string& nickname)
    : identity{firstname, lastname, nickname}
{
}

const ContactIdentity& Contact::getIdentity() const
{
    return identity;
}

const std::string Contact::getPersonalInfo(const std::string& name) const
{
    try
    {
        return personalInformation.at(name);
    }
    catch (const std::out_of_range& e)
    {
        throw e;
    }
}

void Contact::setPersonalInfo(const std::string& name, const std::string& value)
{
    personalInformation[name] = value;
}

}

