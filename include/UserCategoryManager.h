#ifndef USERCATEGORYMANAGER_H
#define USERCATEGORYMANAGER_H

#include <string>

#include "CategoryList.h"
#include "StringContactDetail.h"

namespace MyContacts
{

class UserCategoryManager final
{
    CategoryList<StringContactDetail> userDefinedCategories;

    public:
        const std::string DefaultCategory{"Other"};
        using KeyValue =  std::pair<std::string, std::string>;

    public:
        UserCategoryManager() = default;
        UserCategoryManager(const UserCategoryManager& other) = delete;
        UserCategoryManager& operator=(const UserCategoryManager& other) = delete;

        void addContactDetailToDefault(const std::string& detailName, const std::string& detailValue);
        const std::string getContactDetailFromDefault(const std::string& detailName) const;

        void addContactDetailToCategory(const std::string& category, const KeyValue& detail);
        const std::string getContactDetailFromCategory(const std::string& category, const std::string& detailName) const;

    private:
        void createOrUpdateCategory(const std::string& categoryName, const KeyValue& detail);
        void createCategory(const std::string& categoryName, const KeyValue& detail);
        void updateCategory(const std::string& categoryName, const KeyValue& detail);
};

}

#endif // USERCATEGORYMANAGER_H
