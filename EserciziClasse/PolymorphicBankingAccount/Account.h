
#ifndef POLYMORPHICBANKINGACCOUNT_ACCOUNT_H
#define POLYMORPHICBANKINGACCOUNT_ACCOUNT_H

#include <stdexcept>
#include <string>
#include <iostream>

class Account {
private:
    std::string owner{" "};
    double balance{0.0};

public:
    Account(const std::string& owner, double balance = 0);
    virtual ~Account()=default;

    virtual void debit(double withdraw);
    virtual void credit(double add);

    virtual double getBalance()const;
    virtual void setBalance(double balance);

    void setOwner(std::string owner);
    std::string getOwner() const;

};

std::ostream& operator<<(std::ostream&, const Account&);

#endif //POLYMORPHICBANKINGACCOUNT_ACCOUNT_H
