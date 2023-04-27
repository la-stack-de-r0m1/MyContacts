#ifndef ADDRESSCONTACTDETAIL_H
#define ADDRESSCONTACTDETAIL_H

#include <ContactDetail.h>

#include "ContactAddress.h"

namespace MyContacts
{

template <class AddressFormatter>
class AddressContactDetail final : public ContactDetail<ContactAddress>
{
    public:
        AddressContactDetail(const std::string& addressName, const ContactAddress& address)
            : ContactDetail(addressName, address)
        {}

            AddressContactDetail(const std::string& addressName)
            : ContactDetail(addressName)
        {}

        const std::string toString() const override
        {
            return AddressFormatter::format(getDetailValue());
        }
};

}

#endif // ADDRESSCONTACTDETAIL_H
