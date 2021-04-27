#include"polynomials.h"
#include<iostream>

using std::cout;


int main() {
  Polynomial p1{{1,-2,0}};
  cout << p1 << '\n';
  Polynomial p2{{1,2,0}};
  cout << p2 << '\n';
  cout << "sum is " << p1+p2 << '\n';
  cout << "product is " << p1*p2 << '\n';
  cout << "product 2*p1 is " << 2*p1 << '\n';
  return 0;
}
