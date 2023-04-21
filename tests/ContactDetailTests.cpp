#include <boost/test/unit_test.hpp>

#include "ContactDetail.h"

using namespace MyContacts;

class FakeDetail final : public ContactDetail<std::string>
{
std::string value;

public:
    FakeDetail(const std::string& detailName) : ContactDetail(detailName , "") {}
    const std::string toString() const override { return value; }
};

BOOST_AUTO_TEST_SUITE ( ContactDetailTests )

BOOST_AUTO_TEST_CASE( testDetailName )
{
    FakeDetail cd{"E-mail"};

    BOOST_TEST("E-mail" == cd.getDetailName());
}

BOOST_AUTO_TEST_CASE( testDetailLabel )
{
    FakeDetail cd{"E-mail"};

    cd.setLabel("Domicile");

    BOOST_TEST("Domicile" == cd.getLabel());
}

BOOST_AUTO_TEST_SUITE_END( )
