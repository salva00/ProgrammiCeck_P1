//
// Created by Salvatore Bramante on 28/04/21.
//

#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(const std::string& owner, double balance, double atmf, double totf) :
  Account(owner,balance), atmFee{atmf}, totalFee{totf} {
  }

void CheckingAccount::debit(double withdraw) {
    if(withdraw>getBalance()){
        throw std::invalid_argument("Withdraw must be <= balance");
    }
    setBalance(getBalance()-withdraw);
}

void CheckingAccount::credit(double add) {
    if(add < this->atmFee+this->totalFee) {
        throw std::invalid_argument("add must be >= Fees amount");
    }
    setBalance(getBalance() + add - this->atmFee - this->totalFee);
}

// void CheckingAccount::setTotalFee(double amount) {
//   this->totalFee = amount;
// }
double CheckingAccount::getTotalFee() const {
  return this->totalFee;
}

void CheckingAccount::setAtmFee(double amount) {
  this->atmFee = amount;
}
double CheckingAccount::getAtmFee() const {
  return this->atmFee;
}
