#include <stdexcept>
#include <iostream>

#include "Contact.h"
#include "StringHelpers.h"

namespace MyContacts
{

Contact::Contact(const std::string& firstname,
                 const std::string& lastname,
                 const std::string& nickname)
    : identity{firstname, lastname, nickname}
    , addresses{"Addresses"}
{
}

const ContactIdentity& Contact::getIdentity() const
{
    return identity;
}

ContactIdentity& Contact::getIdentity()
{
    return identity;
}

const std::string Contact::getContactDetail(const std::string& category, const std::string& detailName) const
{
    return userCategories.getContactDetailFromCategory(category, detailName);
    //userDefinedCategories.get(category).getContactDetail(detailName);
}

void Contact::addContactDetail(const std::string& categoryName, const Contact::DetailKeyValue& detail)
{
    userCategories.addContactDetailToCategory(categoryName, detail);
    //createOrUpdateCategory(categoryName, detail);
}

void Contact::addContactDetail(const std::string& name, const std::string& value)
{

    userCategories.addContactDetailToDefault(name, value);
    //createOrUpdateCategory("Other", {name, value});
}

const std::string Contact::getContactDetail(const std::string& name) const
{
    return userCategories.getContactDetailFromDefault(name);
    //getContactDetail("Other", name);
}

/*void Contact::createOrUpdateCategory(const std::string& categoryName, const DetailKeyValue& detail)
{
    userDefinedCategories.categoryExist(categoryName)
        ? updateCategory(categoryName, detail)
        : createCategory(categoryName, detail);
}

void Contact::updateCategory(const std::string& categoryName, const DetailKeyValue& detail)
{
    auto category = userDefinedCategories.get(categoryName);
    category.setContactDetail(detail.first, detail.second);
    userDefinedCategories.update(category);
}

void Contact::createCategory(const std::string& categoryName, const DetailKeyValue& detail)
{
    Category<StringContactDetail> newCategory{categoryName};
    newCategory.setContactDetail(detail.first, detail.second);
    userDefinedCategories.add(newCategory);
}*/

}

