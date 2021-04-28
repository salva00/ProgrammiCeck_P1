//
// Created by Salvatore Bramante on 28/04/21.
//

#ifndef POLYMORPHICBANKINGACCOUNT_CHECKINGACCOUNT_H
#define POLYMORPHICBANKINGACCOUNT_CHECKINGACCOUNT_H


#include "Account.h"

class CheckingAccount : public Account {
private:
public:
    CheckingAccount(double balance, const std::string& owner);
    void debit(double withdraw) override;
    void credit(double add) override;   //add interest to balance


};


#endif //POLYMORPHICBANKINGACCOUNT_CHECKINGACCOUNT_H
