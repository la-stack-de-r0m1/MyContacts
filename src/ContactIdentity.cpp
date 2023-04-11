#include <stdexcept>

#include "ContactIdentity.h"
#include "StringHelpers.h"

namespace MyContacts
{

ContactIdentity::ContactIdentity(const std::string& firstname,
                                 const std::string& lastname,
                                 const std::string& nickname)
    : firstname{std::move(StringHelpers::cleanString(firstname))}
    , lastname{std::move(StringHelpers::cleanString(lastname))}
    , nickname{std::move(StringHelpers::cleanString(nickname))}
{
    if (!isIdentityValid())
        throw std::logic_error{"Bad identity."};
}

const std::string& ContactIdentity::getFirstname() const
{
    return firstname;
}

void ContactIdentity::setFirstname(const std::string& newFirstname)
{
    firstname = updateIdentityIfValid(firstname, newFirstname);
}

const std::string& ContactIdentity::getLastname() const
{
    return lastname;
}

void ContactIdentity::setLastname(const std::string& newLastname)
{
    lastname = updateIdentityIfValid(lastname, newLastname);
}

const std::string& ContactIdentity::getNickname() const
{
    return nickname;
}

void ContactIdentity::setNickname(const std::string& newNickname)
{
    nickname = updateIdentityIfValid(nickname, newNickname);
}

bool ContactIdentity::isIdentityValid() const
{
    return
        !firstname.empty() ||
        !lastname.empty() ||
        !nickname.empty();
}

std::string& ContactIdentity::updateIdentityIfValid(std::string& name, const std::string& newName)
{
    const std::string oldName{name};
    name = std::move(StringHelpers::cleanString(newName));
    if (!isIdentityValid()) {
        name = oldName;
        throw std::logic_error{"Bad identity."};
    }

    return name;
}

}
