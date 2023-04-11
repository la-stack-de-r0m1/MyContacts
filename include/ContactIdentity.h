#ifndef CONTACTIDENTITY_H
#define CONTACTIDENTITY_H

#include <string>

namespace MyContacts
{

class ContactIdentity
{
    std::string firstname;
    std::string lastname;
    std::string nickname;

    public:
        ContactIdentity(const std::string& firstname,
                        const std::string& lastname = "",
                        const std::string& nickname = "");

        const std::string& getFirstname() const;
        void setFirstname(const std::string& newFirstname);

        const std::string& getLastname() const;
        void setLastname(const std::string& newLastname);

        const std::string& getNickname() const;
        void setNickname(const std::string& newNickname);

    private:
        bool isIdentityValid() const;
        std::string& updateIdentityIfValid(std::string& oldName, const std::string& newName);

};

}

#endif // CONTACTIDENTITY_H
