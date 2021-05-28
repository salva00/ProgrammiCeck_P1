
#include "Account.h"
#include<iomanip>

Account::Account(const std::string& owner, double balance){
    setOwner(owner);
    setBalance(balance);
}

double Account::getBalance() const{
    return balance;
}

void Account::setBalance(double balance){
    if (balance<0){
        throw std::invalid_argument("Balance must be >=0");
    }
    this->balance=balance;
}

void Account::setOwner(std::string owner){
    if (owner.empty()){
        throw std::invalid_argument("Owner's name must not be empty");
    }
    this->owner=owner;
}

std::string Account::getOwner() const {
    return owner;
}

void Account::debit(double withdraw) {
    if(withdraw>getBalance()){
        throw std::invalid_argument("Withdraw must be <= balance");
    }
    setBalance(getBalance()-withdraw);
}

void Account::credit(double add) {
    if(add<0){
        throw std::invalid_argument("add must be >= 0");
    }
    setBalance(add+getBalance());
}

std::ostream& operator<<(std::ostream& prevstream, const Account& acc) {
  prevstream << std::setw(15) << std::left << acc.getOwner()
    << std::fixed << std::setprecision(2) << acc.getBalance()<< '$';
  return prevstream;
}
