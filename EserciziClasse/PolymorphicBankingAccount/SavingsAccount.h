
#ifndef POLYMORPHICBANKINGACCOUNT_SAVINGSACCOUNT_H
#define POLYMORPHICBANKINGACCOUNT_SAVINGSACCOUNT_H


#include "Account.h"

class SavingsAccount : public Account {
private:
    double interest{0.0}; // in %
public:
    SavingsAccount(const std::string& owner, double balance = 0, double interset = 0);

    // void debit(double withdraw) override;
    void credit(double add) override;   //add interest to balance

    void setInterest(double interest);
    double getInterest() const;

    double calculateInterest() const; //calculate interest

};


#endif //POLYMORPHICBANKINGACCOUNT_SAVINGSACCOUNT_H
