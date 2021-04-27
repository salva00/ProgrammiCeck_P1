#include<vector>
#include<iostream>

#ifndef POLYNOMIALS_H
#define POLYNOMIALS_H

typedef int coefftype;

void formatVector(std::vector<coefftype>&);

class Polynomial {
public:
  Polynomial(coefftype);
  Polynomial(std::vector<coefftype>);
  unsigned int getDegree() const;
  //coefftype getCoeff(size_t) const;
  void print() const;
  void format();
  Polynomial operator+(const Polynomial&) const;
  Polynomial operator*(const Polynomial&) const;
  Polynomial operator*(coefftype) const;
  bool operator==(const Polynomial&) const;
  coefftype operator[](size_t) const;
private:
  std::vector<coefftype> coeff;
};

Polynomial operator*(coefftype, const Polynomial&);

std::ostream& operator<<(std::ostream&, const Polynomial&);


#endif
