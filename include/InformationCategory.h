#ifndef INFORMATIONCATEGORY_H
#define INFORMATIONCATEGORY_H

#include <string>
#include <map>

namespace MyContacts
{

class InformationCategory
{
    std::string categoryName;
    std::map<std::string, std::string> information;

    public:
        InformationCategory(const std::string& categoryName);

        inline const std::string& name() const
        {
            return categoryName;
        };

        void set(const std::string& name, const std::string& value);
        const std::string& get(const std::string& name) const;
};

}

#endif // INFORMATIONCATEGORY_H
