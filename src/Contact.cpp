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

ContactIdentity& Contact::getIdentity()
{
    return identity;
}

const std::string Contact::getDetail(const std::string& category, const std::string& detailName) const
{
    return userDefinedCategories.get(category).getContactDetail(detailName);
}

void Contact::setDetail(const std::string& categoryName, const Contact::DetailKeyValue& detail)
{
    createOrUpdateCategory(categoryName, detail);
}

const std::string Contact::getGenericDetail(const std::string& name) const
{
    return getDetail("Other", name);
}

void Contact::setGenericDetail(const std::string& name, const std::string& value)
{
    createOrUpdateCategory("Other", {name, value});
}

void Contact::createOrUpdateCategory(const std::string& categoryName, const DetailKeyValue& detail)
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
}

}

