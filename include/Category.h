#ifndef INFORMATIONCATEGORY_H
#define INFORMATIONCATEGORY_H

#include <string>
#include <map>

namespace MyContacts
{

/**
* The contact details of a single contact are set to 'categories'.
* For example, e-mail address and phone number can go to the 'Contact details'
* category, while the professional and personal addresses might go to an
* 'addresses' category.
*
* Each contact detail belongs to a category, and the default category is Other.
*/
class Category
{
    std::string categoryName;
    std::map<std::string, std::string> contactDetails;

    public:
        /**
        * Default category's name ('Other').
        */
        static const std::string DefaultCategory;

    public:
        Category(const std::string& categoryName);

        /**
        * return the current category name.
        */
        inline const std::string& name() const
        {
            return categoryName;
        };

        /**
        * create a new contact detail in the category whose name is `name` and
        * value is `value`.
        */
        void setContactDetail(const std::string& name, const std::string& value);

        /**
        * return the value of the contact detail whose name is `name`.
        */
        const std::string& getContactDetail(const std::string& name) const;
};

inline bool operator==(const Category& lhs, const Category& rhs)
{
    return lhs.name() == rhs.name();
}

}

#endif // INFORMATIONCATEGORY_H
