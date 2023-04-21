#ifndef INFORMATIONCATEGORY_H
#define INFORMATIONCATEGORY_H

#include <string>
#include <list>
#include <memory>
#include <stdexcept>

#include "StringContactDetail.h"

namespace MyContacts
{

template <typename T>
class ContactDetail;

/**
* The contact details of a single contact are set to 'categories'.
* For example, e-mail address and phone number can go to the 'Contact details'
* category, while the professional and personal addresses might go to an
* 'addresses' category.
*
* Each contact detail belongs to a category, and the default category is Other.
*/
template <typename T>
class Category
{
public:
    using ContactDetailPtr = std::shared_ptr<T>;
    using ContactDetailList = std::list<ContactDetailPtr>;

private:
    std::string categoryName;
    ContactDetailList contactDetails;

    // public:
    /**
    * Default category's name ('Other').
    */
    // static const std::string DefaultCategory;

public:
    Category(const std::string& categoryName)
        : categoryName{categoryName}
    {
    }

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
    void setContactDetail(const std::string& name, const std::string& value)
    {
        contactDetails.emplace_back(std::make_shared<T>(name, value));
    }

    /**
    * return the value of the contact detail whose name is `name`.
    */
    const std::string getContactDetail(const std::string& name) const
    {
        try
        {
            auto pos = std::find_if(
               std::begin(contactDetails),
               std::end(contactDetails),
               [&name](const auto& ptr)
                {
                    return ptr->getDetailName() == name;
                });
            if (pos == std::end(contactDetails))
                throw std::out_of_range{"detail not found"};

            return (*pos)->toString();
        }
        catch (const std::out_of_range& e)
        {
            throw e;
        }
    }
};

template <typename T>
inline bool operator==(const Category<T>& lhs, const Category<T>& rhs)
{
    return lhs.name() == rhs.name();
}

}


#endif // INFORMATIONCATEGORY_H
