#include "polynomials.h"
#include<iostream>


Polynomial::Polynomial(int val) : coeff(1,val) {}

Polynomial::Polynomial(std::vector<coefftype> cf) : coeff{cf} {}

unsigned int Polynomial::getDegree() const {return (this->coeff.size()-1);}

// coefftype Polynomial::getCoeff(size_t pos) const {
//   if(pos > 0 && pos < this->coeff.size()) return this->coeff[pos];
//   else return 0;
// }

void formatVector(std::vector<coefftype>& vect) {
  size_t i{vect.size()-1};
  while(vect[i] == 0) i--;
  vect.resize(i+1);
  return;
}

void Polynomial::format() { // 1,2,0,0 / size = 4
  formatVector(this->coeff);
  return;
}

coefftype Polynomial::operator[](size_t pos) const {
  if(pos >= 0 && pos < this->coeff.size()) return this->coeff[pos];
  else return 0;
}

Polynomial Polynomial::operator+(const Polynomial& rhs) const {
  //supposing deg this > deg rhs
  if(this->getDegree() < rhs.getDegree()) return rhs+(*this);
  std::vector<coefftype> newcoeff = this->coeff;
  size_t i{0};
  while(i < (rhs.coeff).size()) {
    newcoeff[i] += rhs[i];
    i++;
  }

  // size_t i{maxLen};
  // while(this->coeff[i] == 0) i--;
  // this->coeff.resize(i+1);
  formatVector(newcoeff);
  Polynomial res{newcoeff};
  return res;
}

Polynomial Polynomial::operator*(const Polynomial& rhs) const {
  std::vector<coefftype> newcoeff(this->getDegree()+rhs.getDegree()+1,0);
  for(size_t i = 0; i <= this->getDegree(); i++) {
    for(size_t j = 0; j <= rhs.getDegree(); j++) {
        newcoeff[i+j] += (*this)[i] * rhs[j];
    }
  }
  formatVector(newcoeff);
  Polynomial res(newcoeff);
  return res;
}

bool Polynomial::operator==(const Polynomial& rhs) const {
  if(this->coeff == rhs.coeff) return true;
  else return false;
}

Polynomial Polynomial::operator*(coefftype rhs) const {
  Polynomial res = *this;
  for(unsigned int i = 0; i <= this->getDegree(); i++) {
    res.coeff[i] *= rhs;
  }
  return res;
}

Polynomial operator*(coefftype lhs, const Polynomial& rhs) {
  return rhs*lhs;
}

std::ostream& operator<<(std::ostream& input, const Polynomial& rhs) {
  bool begin{false};
  coefftype k;
  for(size_t i = 0; i <= rhs.getDegree(); i++) {
    k = rhs[i];
    if(rhs.getDegree() > 0 && k == 0) continue;
    //skips if val = 0 but val is not the only element
    if(begin) input << (k >= 0 ? " + " : " - ");
    //write +- before every number except the first one
    if((k != 1 && k != -1 ) || i == 0) input << (k > 0 ? k : -k);
    //write value except for ones, but not the first 1
    if(i > 0) input << "x";
    if(i > 1) input << '^' << i;
    begin = true;
  }
  return input;
}


void Polynomial::print() const {
  std::cout << *this << '\n';
  return;
}

/*
        1   2x   3x2
  1     1   2x   3x2
 2x    2x  4x2   6x3
3x2   3x2  6x3   9x4




*/













//
