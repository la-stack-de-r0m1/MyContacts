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
    std::string detailValue;
    std::string detailLabel;

    public:
        ContactDetail(const std::string& detailName,
                      const std::string& detailValue);

        inline const std::string& getDetailName() const { return detailName; }
        inline void setDetailValue(const std::string& value) { detailValue = value; }
        inline const std::string& getDetailValue() const { return detailValue; }
        inline void setLabel(const std::string& label) { detailLabel = label; }
        inline const std::string& getLabel() const { return detailLabel; }
};

}

#endif // CONTACTDETAIL_H
