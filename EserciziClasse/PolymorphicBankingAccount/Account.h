//
// Created by Salvatore Bramante on 28/04/21.
//

#ifndef POLYMORPHICBANKINGACCOUNT_ACCOUNT_H
#define POLYMORPHICBANKINGACCOUNT_ACCOUNT_H

#include <stdexcept>
#include <string>
class Account {
private:
    std::string owner{" "};
    double balance{0.0};

public:
    explicit Account(const std::string& owner, double balance);
    virtual ~Account()=default;
    virtual void debit(double withdraw) = 0;
    virtual void credit(double add)=0;
    virtual double getBalance()const;
    virtual void setBalance(double balance);
    virtual void setOwner(const std::string& owner);
    virtual std::string getOwner() const;
};


#endif //POLYMORPHICBANKINGACCOUNT_ACCOUNT_H
