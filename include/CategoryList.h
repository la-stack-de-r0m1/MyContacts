#ifndef CATEGORYLIST_H
#define CATEGORYLIST_H

#include <vector>

#include "InformationCategory.h"

namespace MyContacts
{

class CategoryList
{
    std::vector<InformationCategory> categories;

    public:
        CategoryList();

        /**
        * return the INformationCategory whose name is `name`.
        *
        * Throw an std::out_of_range exception if it does not exist.
        */
        const InformationCategory& get(const std::string& name) const;


        /**
        * Add the InformationCategory `category` to the list.
        * Does nothing if an InformationCategory with the same name already
        * exist.
        */
        void add(const InformationCategory& category);

        /**
        * Update the category whose name is category.name().
        *
        * Does nothing if the category does not exist.
        */
        void update(const InformationCategory& category);

        bool categoryExist(const std::string& name) const;

    private:
        const InformationCategory& findCategory(const std::string& name) const;
};

}

#endif // CATEGORYLIST_H
