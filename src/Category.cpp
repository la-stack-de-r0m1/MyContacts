#include <stdexcept>
#include <algorithm>

#include "Category.h"
#include "StringContactDetail.h"

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
        auto pos = std::find_if(
            std::begin(contactDetails),
            std::end(contactDetails),
            [&name](const auto& ptr) { return ptr->getDetailName() == name; }
        );
        if (pos == std::end(contactDetails))
            throw std::out_of_range{"detail not found"};

        return (*pos)->toString();
    }
    catch (const std::out_of_range& e)
    {
        throw e;
    }
}

void Category::setContactDetail(const std::string& name, const std::string& value)
{
    contactDetails.emplace_back(std::make_shared<StringContactDetail>(name, value));
}

}

