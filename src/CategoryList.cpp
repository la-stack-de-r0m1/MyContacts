#include <algorithm>

#include "CategoryList.h"

namespace MyContacts
{

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
    std::replace(
        categories.begin(),
        categories.end(),
        category,
        category
    );
}

const InformationCategory& CategoryList::findCategory(const std::string& name) const
{
    auto categoryIt = findCategoryPos(name);
    if (categoryIt == std::end(categories))
        throw std::out_of_range("Category does not exist");

    return *categoryIt;
}

bool CategoryList::categoryExist(const std::string& name) const
{
    auto categoryIt = findCategoryPos(name);

    return categoryIt != std::end(categories);
}

CategoryList::CategoriesCtrIter CategoryList::findCategoryPos(const std::string& name) const
{
    return std::find(
        std::begin(categories),
        std::end(categories),
       name
    );
}

}
