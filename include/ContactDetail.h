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
template <typename T>
class ContactDetail
{
    std::string detailName;
    T detailValue;
    std::string detailLabel;

    public:
        typedef T value_type;

        ContactDetail(const std::string& detailName,
                      const T& detailValue)
            : detailName{detailName}
            , detailValue{detailValue}
        {}

        virtual ~ContactDetail() = default;

        inline const std::string& getDetailName() const { return detailName; }

        inline void setDetailValue(const T& value) { detailValue = value; }
        inline const T& getDetailValue() const { return detailValue; }

        inline void setLabel(const std::string& label) { detailLabel = label; }
        inline const std::string& getLabel() const { return detailLabel; }

        virtual const std::string toString() const = 0;
};

}

#endif // CONTACTDETAIL_H
