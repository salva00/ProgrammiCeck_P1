//
// Created by Salvatore Bramante on 09/05/21.
//

#ifndef MATHEXCEPTION_MATHEXCEPTION_H
#define MATHEXCEPTION_MATHEXCEPTION_H
#include <string>
#include <iostream>
class MathException {               //generic Mth exception
private:
    std::string errMsg;                                         //error message
public:
    MathException( const std::string& err): errMsg(err){}       //constructor
    std::string getError(){return errMsg;}                      //access error message
};


class ZeroDivide : public MathException{
public:
    ZeroDivide(const std::string& err) : MathException(err){}
};

class NegativeRoot : public MathException{
public:
    NegativeRoot(const std::string& err) : MathException(err){}
};

#endif //MATHEXCEPTION_MATHEXCEPTION_H
