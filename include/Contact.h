#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <map>

#include "ContactIdentity.h"

namespace MyContacts
{

class Contact
{
    ContactIdentity identity;
    std::map<std::string, std::string> personalInformation;

    public:
        Contact(const std::string& firstname,
                const std::string& lastname = "",
                const std::string& nickname = "");

        const ContactIdentity& getIdentity() const;
        void setPersonalInfo(const std::string& name, const std::string& value);
        const std::string getPersonalInfo(const std::string& name) const;
};

} //namespace MyContacts

#endif // CONTACT_H
