//
// Created by Salvatore Bramante on 28/04/21.
//

#ifndef POLYMORPHICBANKINGACCOUNT_SAVINGSACCOUNT_H
#define POLYMORPHICBANKINGACCOUNT_SAVINGSACCOUNT_H


#include "Account.h"

class SavingsAccount : public Account {
private:
    double interest;
public:
    SavingsAccount(double balance, const std::string& owner, double interest);
    void debit(double withdraw) override;
    void setInterest(double interest);
    double getInterest() const;
    double calculateInterest() const; //calculate interest
    void credit(double add) override;   //add interest to balance

};


#endif //POLYMORPHICBANKINGACCOUNT_SAVINGSACCOUNT_H
