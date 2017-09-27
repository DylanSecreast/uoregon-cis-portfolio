#include <iostream>
#include "names.h"

using namespace std;

int main()
{
    Names group(4);

    cout << " before starting group has " << group.howMany() << " names " << endl;

    group.addName("mary");
    group.addName("bill");
    group.addName("ET");

    cout << " after adding names group has " << group.howMany() << " names " << endl;
    cout << " and they are: " << group.listNames() << endl;
    return 0;
}
