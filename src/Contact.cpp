#include <stdexcept>

#include "Contact.h"
#include "StringHelpers.h"

namespace MyContacts
{

Contact::Contact(const std::string& firstname,
                 const std::string& lastname,
                 const std::string& nickname)
    : firstname{std::move(StringHelpers::cleanString(firstname))}
    , lastname{std::move(StringHelpers::cleanString(lastname))}
    , nickname{std::move(StringHelpers::cleanString(nickname))}
{
    if (!areParametersValid())
        throw std::logic_error{"Personal information not set."};
}

const std::string& Contact::get_firstname() const
{
    return firstname;
}

const std::string& Contact::get_lastname() const
{
    return lastname;
}

const std::string& Contact::get_nickname() const
{
    return nickname;
}

bool Contact::areParametersValid() const
{
    return
        !firstname.empty() ||
        !lastname.empty() ||
        !nickname.empty();
}

}

