#ifndef CONTACT_H
#define CONTACT_H

#include <string>

namespace MyContacts
{

class Contact
{
    std::string firstname;
    std::string lastname;
    std::string nickname;

    public:
        Contact(const std::string& firstname,
                const std::string& lastname = "",
                const std::string& nickname = "");

        const std::string& get_firstname() const;
        const std::string& get_lastname() const;
        const std::string& get_nickname() const;

    private:
        bool areParametersValid() const;
        void clearPersonalInfo();

};

} //namespace MyContacts

#endif // CONTACT_H
