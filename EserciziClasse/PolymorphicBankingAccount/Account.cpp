//
// Created by Salvatore Bramante on 28/04/21.
//

#include "Account.h"

Account::Account(const std::string& owner, double balance){
    setOwner(owner);
    setBalance(balance);
}

double Account::getBalance() const{
    return balance;
}

void Account::setBalance(double balance){
    if (balance<=0){
        throw std::invalid_argument("Balance must be >0");
    }
    this->balance=balance;
}

void Account::setOwner(const std::string &owner){
    if (owner.empty()){
        throw std::invalid_argument("Owner's name must not be empty");
    }
    this->owner=owner;
}

std::string Account::getOwner() const {
    return owner;
}
