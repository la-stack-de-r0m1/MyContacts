#include <algorithm>

#include "StringHelpers.h"

namespace MyContacts
{

const std::string StringHelpers::cleanString(std::string text_to_clean)
{
    text_to_clean.erase(
        std::remove_if(
            text_to_clean.begin(),
            text_to_clean.end(),
            [](unsigned char x){ return std::isspace(x); }
        ),
        text_to_clean.end()
    );

    return text_to_clean;
}

}
