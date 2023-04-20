#ifndef STRINGCONTACTDETAIL_H
#define STRINGCONTACTDETAIL_H

#include <string>

#include <ContactDetail.h>

namespace MyContacts
{

class StringContactDetail final : public ContactDetail
{
    std::string value;

    public:
        StringContactDetail(const std::string& name, const std::string& value);

        virtual void setDetailValue(const std::string& value) override;
        virtual const std::string& toString() const override;
};

}

#endif // STRINGCONTACTDETAIL_H
