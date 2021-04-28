
#ifndef ACCOUNTCLASS_ACCOUNT_H
#define ACCOUNTCLASS_ACCOUNT_H

#include <string>

class Account{
public:
    explicit Account(std::string accountName)
        : name{ accountName } { //memeber initializer
            //empty body
    }
    void setName(std::string accountName){
        name = accountName;
    }
    std::string getName() const{
        return name;
    }
private:
    std::string name;
};

#endif //ACCOUNTCLASS_ACCOUNT_H
