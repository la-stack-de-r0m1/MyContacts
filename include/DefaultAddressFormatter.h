#ifndef DEFAULTADDRESSFORMATTER_H
#define DEFAULTADDRESSFORMATTER_H


namespace MyContacts
{

class ContactAddress;

class DefaultAddressFormatter
{
    public:
        static std::string format(const ContactAddress& address);

};

}

#endif // DEFAULTADDRESSFORMATTER_H
