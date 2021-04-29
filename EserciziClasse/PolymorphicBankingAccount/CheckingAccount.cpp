//
// Created by Salvatore Bramante on 28/04/21.
//

#include "CheckingAccount.h"

void CheckingAccount::debit(double withdraw) {
    if(withdraw>getBalance()){
        throw std::invalid_argument("Withdraw must be <= balance");
    }
    setBalance(getBalance()-withdraw);
}

void CheckingAccount::credit(double add) {
    if(add<=0){
        throw std::invalid_argument("add must be <= 0");
    }
    setBalance(add+getBalance());
}

CheckingAccount::CheckingAccount(double balance, const std::string &owner) :Account(owner,balance) {}
