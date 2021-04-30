#include <iostream>
#include <vector>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
/*
• Develop a polymorphic banking program. Create a vector of
Account pointers to SavingsAccount and CheckingAccount objects.
For each Account in the vector, allow the user to specify an
amount of money to withdraw from the Account using member
function debit and an amount of money to deposit into the
Account using member function credit. As you process each
Account, determine its type. If an Account is a SavingsAccount,
calculate the amount of interest owed to the Account using
member function calculateInterest, then add the interest to the
account balance using member function credit. After processing
an Account, print the up-dated account balance obtained by
invoking base-class member function getBalance.
• Write the three header files: Account.h,
SavingsAccount.h,CheckingAccount.h and the relative .cpp implementation
files
• Write the driver program that istantiate an array of accounts and
process it
*/

//TODO: rendere CheckingAccount::totalFee statico

int main() {

    std::vector<Account*> myAccounts;

    myAccounts.push_back(new CheckingAccount{"pippo",100,1});
    myAccounts.push_back(new CheckingAccount{"pluto",50,0.5});
    myAccounts.push_back(new SavingsAccount{"paperino",30,0.01});
    myAccounts.push_back(new SavingsAccount{"minnie",0,0.02});

    int accNum{-1};
    bool choice{0};
    int amount{0};

    while(true) {

      for(size_t i = 0; i < myAccounts.size(); i++)
          std::cout << i << ": " << *myAccounts[i] << '\n';

      std::cout << "\nInsert account number to modify: ";
      std::cin >> accNum;

      if(accNum < 0 || accNum >= myAccounts.size()) {
        std::cout << "Invalid number. Try again.\n";
        continue;
      }

      std::cout << "Credit (1) or Debit (0) ? ";
      std::cin >> choice;

      std::cout << "Amount: ";
      std::cin >> amount;

      if(choice == true) myAccounts[accNum]->credit(amount);
      if(choice == false) myAccounts[accNum]->debit(amount);

    }

    return 0;
}
