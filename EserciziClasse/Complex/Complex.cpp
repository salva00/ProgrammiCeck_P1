
#include <stdexcept>
#include <sstream>
#include "Complex.h"

Complex::Complex(Complex &compNum) {
    real=compNum.real;
    imag=compNum.imag;
}

Complex::~Complex() {

}

bool Complex::operator==(Complex &compNum) {
    return real==compNum.real &&  real==compNum.real? true: false;
}

Complex Complex::operator+(Complex &compNum) {
    Complex temp;
    temp.real= real + compNum.real;
    temp.imag= imag + compNum.imag;
    return temp;
}

Complex Complex::operator-(Complex &compNum) {
    Complex temp;
    temp.real = real- compNum.real;
    temp.imag= imag - compNum.imag;
    return temp;
}

Complex Complex::operator/(Complex &compNum) {
    if (compNum.real==0 && compNum.imag==0){
        throw std::invalid_argument("Cannot divide by 0");
    }
    Complex temp;
    temp.real= (real*compNum.real + imag * compNum.imag)/(compNum.real*compNum.real + compNum.imag* compNum.imag);
    temp.imag= (imag*compNum.real - real * compNum.imag)/(compNum.real*compNum.real + compNum.imag* compNum.imag);
    return temp;
}

Complex Complex::operator*(Complex &compNum) {
    if (compNum.real==0 && compNum.imag==0){
        real=0;
        imag=0;
        return *this;
    } else{
        Complex temp;
        temp.real = (real*compNum.real - imag * compNum.imag);
        temp.imag= (real*compNum.imag + imag * compNum.real);
        return temp;
    }
}

std::string Complex::toString() {
    std::ostringstream output;
    if (imag < 0.0){
        output << real << " - i " << imag;
    }else{
        output << real << " + i " << imag;
    }

    return output.str();
}

void Complex::setReal(double r) {
    real=r;
}

void Complex::setImag(double i) {
    imag=i;
}
