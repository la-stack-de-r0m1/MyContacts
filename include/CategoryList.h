#ifndef CATEGORYLIST_H
#define CATEGORYLIST_H

#include <vector>
#include <algorithm>

#include "Category.h"

namespace MyContacts
{

template <typename T>
class CategoryList
{
public:
    using CategoriesCtr = std::vector<Category<T>>;
    using CategoriesCtrIter = typename std::vector<Category<T>>::const_iterator;

    /**
    * return the INformationCategory whose name is `name`.
    *
    * Throw an std::out_of_range exception if it does not exist.
    */
    const Category<T>& get(const std::string& name) const
    {
        return findCategory(name);
    }

    /**
    * Add the InformationCategory `category` to the list.
    * Does nothing if an InformationCategory with the same name already
    * exist.
    */
    void add(const Category<T>& category)
    {
        if (!categoryExist(category.name()))
            categories.push_back(category);
    }


    /**
    * Update the category whose name is category.name().
    *
    * Does nothing if the category does not exist.
    */
    void update(const Category<T>& category)
    {
        std::replace(
            categories.begin(),
            categories.end(),
            category,
            category
        );
    }

    /**
    * return true if the category whose name is `name` exists, false otherwise.
    */
    bool categoryExist(const std::string& name) const
    {
        auto categoryIt = findCategoryPos(name);

        return categoryIt != std::end(categories);
    }

private:
    CategoriesCtr categories;

private:
    CategoriesCtrIter findCategoryPos(const std::string& name) const
    {
        Category<T> tmp{name};

        return std::find(
                   std::begin(categories),
                   std::end(categories),
                   tmp
               );
    }

    const Category<T>& findCategory(const std::string& name) const
    {
        auto categoryIt = findCategoryPos(name);
        if (categoryIt == std::end(categories))
            throw std::out_of_range("Category does not exist");

        return *categoryIt;
    }
};

}

#endif // CATEGORYLIST_H
