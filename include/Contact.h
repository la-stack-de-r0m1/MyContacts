#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <map>
#include <vector>

#include "ContactIdentity.h"
#include "UserCategoryManager.h"
#include "CategoryList.h"
#include "MapContactDetail.h"

namespace MyContacts
{

/**
* This class represent a single contact.
*
* Each contact detail belongs to a category. For examples:
*  - 'E-mail' and 'Phone number' would be in the 'Contact details' category.
*  - 'Street name', 'Street number', etc, would be in the 'Address' category.
*
* The default category is 'Others'.
*/
class Contact
{
    ContactIdentity identity;
    Category<MapContactDetail> addresses;
    UserCategoryManager userCategories;

    public:
        using DetailKeyValue =  std::pair<std::string, std::string>;

        Contact(const std::string& firstname,
                const std::string& lastname = "",
                const std::string& nickname = "");

        const ContactIdentity& getIdentity() const;
        ContactIdentity& getIdentity();

        void addContactDetail(const std::string& name, const std::string& value);
        const std::string getContactDetail(const std::string& detailName) const;

        void addContactDetail(const std::string& category, const DetailKeyValue& detail);
        const std::string getContactDetail(const std::string& category, const std::string& detailName) const;
};


} //namespace MyContacts

#endif // CONTACT_H
