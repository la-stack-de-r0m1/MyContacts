#ifndef CONTACTDETAIL_H
#define CONTACTDETAIL_H

#include <string>

namespace MyContacts
{

/**
* A contact detail.
*
* Each contact detail can have a label. For example, an e-mail can be 'personal' or
* 'professional'. Idem for the addresses.
*
* A contact detail has at least a name and a value; the label can be left empty.
*/
class ContactDetail
{
    std::string detailName;
    std::string detailLabel;

    public:
        ContactDetail(const std::string& detailName,
                      const std::string& detailValue);
        virtual ~ContactDetail() = default;

        inline const std::string& getDetailName() const { return detailName; }

        virtual void setDetailValue(const std::string& value) = 0;
        virtual const std::string& toString() const = 0;

        inline void setLabel(const std::string& label) { detailLabel = label; }
        inline const std::string& getLabel() const { return detailLabel; }
};

}

#endif // CONTACTDETAIL_H
