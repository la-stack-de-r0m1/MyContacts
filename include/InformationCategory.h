#ifndef INFORMATIONCATEGORY_H
#define INFORMATIONCATEGORY_H

#include <string>
#include <map>

namespace MyContacts
{

class Category
{
    std::string categoryName;
    std::map<std::string, std::string> information;

    public:
        static const std::string DefaultCategory;

    public:
        Category(const std::string& categoryName);

        inline const std::string& name() const
        {
            return categoryName;
        };

        void set(const std::string& name, const std::string& value);
        const std::string& get(const std::string& name) const;
};

inline bool operator==(const Category& lhs, const Category& rhs)
{
    return lhs.name() == rhs.name();
}

}

#endif // INFORMATIONCATEGORY_H
