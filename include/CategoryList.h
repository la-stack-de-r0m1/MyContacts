#ifndef CATEGORYLIST_H
#define CATEGORYLIST_H

#include <vector>

#include "InformationCategory.h"

namespace MyContacts
{

class CategoryList
{
    public:
        using CategoriesCtr = std::vector<Category>;
        using CategoriesCtrIter = std::vector<Category>::const_iterator;

        /**
        * return the INformationCategory whose name is `name`.
        *
        * Throw an std::out_of_range exception if it does not exist.
        */
        const Category& get(const std::string& name) const;


        /**
        * Add the InformationCategory `category` to the list.
        * Does nothing if an InformationCategory with the same name already
        * exist.
        */
        void add(const Category& category);

        /**
        * Update the category whose name is category.name().
        *
        * Does nothing if the category does not exist.
        */
        void update(const Category& category);

        /**
        * return true if the category whose name is `name` exists, false otherwise.
        */
        bool categoryExist(const std::string& name) const;

    private:
        CategoriesCtr categories;

    private:
        CategoriesCtrIter findCategoryPos(const std::string& name) const;
        const Category& findCategory(const std::string& name) const;
};

}

#endif // CATEGORYLIST_H
