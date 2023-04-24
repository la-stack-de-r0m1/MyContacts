#include "UserCategoryManager.h"

#include <stdexcept>

namespace MyContacts
{

void UserCategoryManager::addContactDetailToDefault(const std::string& detailName, const std::string& detailValue)
{
    addContactDetailToCategory(UserCategoryManager::DefaultCategory, {detailName, detailValue});
}

const std::string UserCategoryManager::getContactDetailFromDefault(const std::string& detailName) const
{
    return getContactDetailFromCategory(UserCategoryManager::DefaultCategory, detailName);
}

void UserCategoryManager::addContactDetailToCategory(const std::string& categoryName, const UserCategoryManager::KeyValue& detail)
{
    createOrUpdateCategory(categoryName, detail);
}

const std::string UserCategoryManager::getContactDetailFromCategory(const std::string& category, const std::string& detailName) const
{
    return userDefinedCategories.get(category).getContactDetail(detailName);
}

void UserCategoryManager::createOrUpdateCategory(const std::string& categoryName, const KeyValue& detail)
{
    userDefinedCategories.categoryExist(categoryName)
        ? updateCategory(categoryName, detail)
        : createCategory(categoryName, detail);
}

void UserCategoryManager::updateCategory(const std::string& categoryName, const KeyValue& detail)
{
    auto category = userDefinedCategories.get(categoryName);
    category.setContactDetail(detail.first, detail.second);
    userDefinedCategories.update(category);
}

void UserCategoryManager::createCategory(const std::string& categoryName, const KeyValue& detail)
{
    Category<StringContactDetail> newCategory{categoryName};
    newCategory.setContactDetail(detail.first, detail.second);
    userDefinedCategories.add(newCategory);
}

}
