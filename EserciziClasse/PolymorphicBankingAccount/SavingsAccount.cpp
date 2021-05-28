
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const std::string& owner, double balance, double interest) :Account(owner,balance) {
    setInterest(interest);
}

// void SavingsAccount::debit(double withdraw) {
//     if(withdraw>getBalance()){
//         throw std::invalid_argument("Withdraw must be <= balance");
//     }
//     setBalance(getBalance()-withdraw);
// }

double SavingsAccount::calculateInterest() const {
    return this->getInterest()*this->getBalance();
}

void SavingsAccount::credit(double add) {
    if(add<0){
        throw std::invalid_argument("add must be >= 0");
    }
    setBalance(this->getBalance()+ this->calculateInterest() +add);
    return;
}

void SavingsAccount::setInterest(double interest) {
    if (interest<0){
        throw std::invalid_argument("interest must be >=0");
    }
    this->interest=interest;
}

double SavingsAccount::getInterest() const {
    return interest;
}
