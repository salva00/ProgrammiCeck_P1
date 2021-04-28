#include <iostream>
#include "Account.h"

using std::endl;
using std::endl;

int main() {
    // create two Account objects
    Account account1{ "Jane Green" };
    Account account2{ "John Blue" };

    // display initial value of name for each Account
    cout << "account1 name is: " << account1.getName() << endl;
    cout << "account2 name is: " << account2.getName() << endl;
    return 0;
}
