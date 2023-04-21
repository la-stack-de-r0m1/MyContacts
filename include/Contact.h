#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <map>
#include <vector>

#include "ContactIdentity.h"
#include "CategoryList.h"
#include "StringContactDetail.h"

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

    CategoryList<StringContactDetail> userDefinedCategories;

    public:
        using DetailKeyValue =  std::pair<std::string, std::string>;

        Contact(const std::string& firstname,
                const std::string& lastname = "",
                const std::string& nickname = "");

        const ContactIdentity& getIdentity() const;
        ContactIdentity& getIdentity();

        const std::string getDetail(const std::string& category, const std::string& detailName) const;
        void setDetail(const std::string& category, const DetailKeyValue& detail);

        void setGenericDetail(const std::string& name, const std::string& value);
        const std::string getGenericDetail(const std::string& name) const;

    private:
        void createOrUpdateCategory(const std::string& categoryName, const DetailKeyValue& detail);
        void createCategory(const std::string& categoryName, const DetailKeyValue& detail);
        void updateCategory(const std::string& categoryName, const DetailKeyValue& detail);
};

} //namespace MyContacts

#endif // CONTACT_H
