#include <boost/test/unit_test.hpp>

#include "ContactDetail.h"
#include <fakeit.hpp>

using namespace MyContacts;
using namespace fakeit;

class FakeDetail : public ContactDetail
{
std::string value;

public:
    FakeDetail(const std::string& detailName) : ContactDetail(detailName , "") {}
     void  setDetailValue(const std::string& value) override { this->value = value; }
     virtual const std::string& toString() const override { return value; }
};

BOOST_AUTO_TEST_SUITE ( ContactDetailTests )

BOOST_AUTO_TEST_CASE( testDetailName )
{
    FakeDetail cd{"E-mail"};

    BOOST_TEST("E-mail" == cd.getDetailName());
}

/*BOOST_AUTO_TEST_CASE( testDetailValue )
{
    ContactDetail cd{"E-mail", "mail@example.com"};

    BOOST_TEST("mail@example.com" == cd.getDetailValue());
}

BOOST_AUTO_TEST_CASE( testDetailValueUpdate )
{
    ContactDetail cd{"E-mail", "mail@example.com"};
    cd.setDetailValue("r0m1@example.me");

    BOOST_TEST("r0m1@example.me" == cd.getDetailValue());
}*/

BOOST_AUTO_TEST_CASE( testDetailLabel )
{
    FakeDetail cd{"E-mail"};

    cd.setLabel("Domicile");

    BOOST_TEST("Domicile" == cd.getLabel());
}

BOOST_AUTO_TEST_SUITE_END( )
