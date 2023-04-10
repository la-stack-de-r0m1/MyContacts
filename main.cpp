#include <iostream>
#include "Contact.h"

using namespace std;

int main()
{
    MyContacts::Contact c{"Romain"};

    cout << c.get_firstname() << endl;

    return 0;
}
