//
// Created by Salvatore Bramante on 21/04/21.
//

#ifndef COMPLEX_H
#define COMPLEX_H
#include <string>

class Complex {
private:
    double real;
    double imag;
public:
    explicit Complex(double r = 0.0, double i=0.0) : real(r),imag(i){}      //explict to avoid implict conversion
    Complex(Complex&);
    ~Complex();

    bool operator ==(Complex&);
    Complex operator+(Complex&);
    Complex operator-(Complex&);
    Complex operator/(Complex&);
    Complex operator*(Complex&);
    std::string toString();
    void setReal(double);
    void setImag(double);

};


#endif //COMPLEX_COMPLEX_H
