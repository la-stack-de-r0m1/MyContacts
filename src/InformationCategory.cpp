#include <stdexcept>

#include "InformationCategory.h"

namespace MyContacts
{

InformationCategory::InformationCategory(const std::string& categoryName)
    : categoryName{categoryName}
{
}

const std::string& InformationCategory::get(const std::string& name) const
{
    try
    {
        return information.at(name);
    }
    catch (const std::out_of_range& e)
    {
        throw e;
    }
}

void InformationCategory::set(const std::string& name, const std::string& value)
{
    information[name] = value;
}

}
