
#ifndef EMPLOYEE_H
#define EMPLOYEE_H


#include <string>

class Employee {
private:
    std::string firstName;
    std::string lastName;
    std::string socialSecurityNumber;//codice fiscale
    //double salary;
public:
    Employee( const std::string &,const std::string &,const std::string &);
    virtual ~Employee()=default;        //compilatore genera il distruttore di default
                                        //virtuale perchè abbiamo funzioni virtuali

    void setFirstName(const std::string &);
    void setLastName(const std::string &);
    void setSocialSecurityNumber(const std::string &);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getSocialSecurityNumber() const;


    virtual double earnings() const = 0;    //pure virtual

    virtual std::string toString() const;   //virtual




};


#endif //EMPLOYEESALARY_EMPLOUYEE_H
