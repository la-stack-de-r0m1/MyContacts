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
        static const std::string DefaultCategory;

    public:
        InformationCategory(const std::string& categoryName);

        inline const std::string& name() const
        {
            return categoryName;
        };

        void set(const std::string& name, const std::string& value);
        const std::string& get(const std::string& name) const;
};

inline bool operator==(const InformationCategory& lhs, const InformationCategory& rhs)
{
    return lhs.name() == rhs.name();
}

}

#endif // INFORMATIONCATEGORY_H
