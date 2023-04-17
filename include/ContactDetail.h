#ifndef CONTACTDETAIL_H
#define CONTACTDETAIL_H

#include <string>

namespace MyContacts
{

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
