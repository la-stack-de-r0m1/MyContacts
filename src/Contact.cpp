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

const std::string& Contact::getDetail(const std::string& category, const std::string& detailName) const
{
    return categories.get(category).get(detailName);
}

void Contact::setDetail(const std::string& categoryName, const Contact::ContactDetail& detail)
{
    createOrUpdateCategory(categoryName, detail);
}

const std::string& Contact::getGenericDetail(const std::string& name) const
{
    return getDetail(InformationCategory::DefaultCategory, name);
}

void Contact::setGenericDetail(const std::string& name, const std::string& value)
{
    createOrUpdateCategory(InformationCategory::DefaultCategory, {name, value});
}

void Contact::createOrUpdateCategory(const std::string& categoryName, const ContactDetail& detail)
{
    categories.categoryExist(categoryName)
        ? updateCategory(categoryName, detail)
        : createCategory(categoryName, detail);
}

void Contact::updateCategory(const std::string& categoryName, const ContactDetail& detail)
{
    auto category = categories.get(categoryName);
    category.set(detail.first, detail.second);
    categories.update(category);
}

void Contact::createCategory(const std::string& categoryName, const ContactDetail& detail)
{
    InformationCategory newCategory{categoryName};
    newCategory.set(detail.first, detail.second);
    categories.add(newCategory);
}

}

