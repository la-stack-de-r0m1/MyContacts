#include <stdexcept>

#include "Category.h"

namespace MyContacts
{

const std::string Category::DefaultCategory{"Other"};

Category::Category(const std::string& categoryName)
    : categoryName{categoryName}
{
}

const std::string& Category::getContactDetail(const std::string& name) const
{
    try
    {
        return contactDetails.at(name);
    }
    catch (const std::out_of_range& e)
    {
        throw e;
    }
}

void Category::setContactDetail(const std::string& name, const std::string& value)
{
    contactDetails[name] = value;
}

}

