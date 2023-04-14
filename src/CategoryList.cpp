#include <algorithm>

#include "CategoryList.h"

namespace MyContacts
{

const Category& CategoryList::get(const std::string& name) const
{
    return findCategory(name);
}

void CategoryList::add(const Category& category)
{
    if (!categoryExist(category.name()))
        categories.push_back(category);
}

void CategoryList::update(const Category& category)
{
    std::replace(
        categories.begin(),
        categories.end(),
        category,
        category
    );
}

const Category& CategoryList::findCategory(const std::string& name) const
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
