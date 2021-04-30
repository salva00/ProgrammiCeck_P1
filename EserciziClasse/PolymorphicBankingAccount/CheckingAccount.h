
#ifndef POLYMORPHICBANKINGACCOUNT_CHECKINGACCOUNT_H
#define POLYMORPHICBANKINGACCOUNT_CHECKINGACCOUNT_H


#include "Account.h"

class CheckingAccount : public Account {
private:
    double atmFee{0.0};
    const double totalFee{0.0};
public:
    CheckingAccount(const std::string& owner, double balance = 0, double atmf = 0, double totf = 1);

    void debit(double withdraw) override;
    void credit(double add) override;   //add interest to balance

    //void setTotalFee(double amount); //made const
    double getTotalFee() const;

    void setAtmFee(double amount);
    double getAtmFee() const;

};


#endif //POLYMORPHICBANKINGACCOUNT_CHECKINGACCOUNT_H
