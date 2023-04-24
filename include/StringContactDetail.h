#ifndef STRINGCONTACTDETAIL_H
#define STRINGCONTACTDETAIL_H

#include <string>

#include <ContactDetail.h>

namespace MyContacts
{

class StringContactDetail final
    : public ContactDetail<std::string>
{
    public:
        //typedef std::string value_type;

        StringContactDetail(const std::string& name, const std::string& value);

        virtual const std::string toString() const override;
};

}

#endif // STRINGCONTACTDETAIL_H
