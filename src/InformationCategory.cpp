#include <stdexcept>

#include "InformationCategory.h"

namespace MyContacts
{

const std::string Category::DefaultCategory{"Other"};

Category::Category(const std::string& categoryName)
    : categoryName{categoryName}
{
}

const std::string& Category::get(const std::string& name) const
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

void Category::set(const std::string& name, const std::string& value)
{
    contactDetails[name] = value;
}

}

