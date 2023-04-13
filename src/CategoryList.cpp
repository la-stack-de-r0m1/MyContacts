#include <algorithm>

#include "CategoryList.h"

namespace MyContacts
{

CategoryList::CategoryList()
{
}

const InformationCategory& CategoryList::get(const std::string& name) const
{
    return findCategory(name);
}

void CategoryList::add(const InformationCategory& category)
{
    if (!categoryExist(category.name()))
        categories.push_back(category);
}

void CategoryList::update(const InformationCategory& category)
{
    std::replace_if(
        categories.begin(),
        categories.end(),
        [&category](const auto& c) { return c.name() == category.name(); },
        category
    );
}

const InformationCategory& CategoryList::findCategory(const std::string& name) const
{
    auto categoryIt = std::find_if(
        std::begin(categories),
        std::end(categories),
        [&name](const auto& category) { return category.name() == name; }
    );
    if (categoryIt == std::end(categories))
        throw std::out_of_range("Category does not exist");

    return *categoryIt;
}

bool CategoryList::categoryExist(const std::string& name) const
{
    auto categoryIt = std::find_if(
        std::begin(categories),
        std::end(categories),
        [&name](const auto& category) { return category.name() == name; }
    );

    return categoryIt != std::end(categories);
}

}
