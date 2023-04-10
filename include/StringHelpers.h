#ifndef STRINGHELPERS_H
#define STRINGHELPERS_H

#include <string>

namespace MyContacts
{

class StringHelpers
{
    public:
        StringHelpers() = delete;
        StringHelpers(const StringHelpers&) = delete;
        StringHelpers& operator=(const StringHelpers&) = delete;

        static const std::string cleanString(std::string text_to_clean);
};

}

#endif // STRINGHELPERS_H
