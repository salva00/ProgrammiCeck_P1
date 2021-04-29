#include <iostream>
#include <vector>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

int main() {
    SavingsAccount pippo(1030.3,"pippo",4.3);
    CheckingAccount paolo(99.8,"paolo");

    std::vector<Account*> accounts{&pippo,&paolo};

    std::cout << "start" << std::endl;
    std::cout << "pippo's balance: "<< accounts[0]->getBalance()<<std::endl;

    std::cout << "add 1 to pippo" << std::endl;
    accounts[0]->credit(1.0);

    std::cout << "pippo's afeter add balance: "<< accounts[0]->getBalance()<<std::endl;

    std::cout << "paolo's balance: "<< accounts[1]->getBalance()<<std::endl;

    std::cout << "add 500 to paolo" << std::endl;
    accounts[1]->credit(500);

    std::cout << "pippo's afeter add balance: "<< accounts[1]->getBalance()<<std::endl;


    return 0;
}
