#include <iostream>
#include "matrix.h"
#include <ctime>
using std::endl;
using std::cout;

/**************************
Given a 2D array A mxn and a 2D array B nxk:
• Compute the matrix product AxB
**************************/



int main() {
  Matrix<double> mat1{{
    {1,0,0},
    {0,1,0},
    {0,0,1}
  }};
  Matrix<double> mat2{3,3,1};
  mat2.random(1,time(NULL),0);
  mat1.print();
  mat2.print();
  cout << "mat1 -= mat2 \n";
  mat1 -= mat2;
  mat1.print();
  cout << "mat1 += mat2 \n";
  mat1 += mat2;
  mat1.print();
  cout << "mat1 *= mat2 \n";
  mat1 *= mat2;
  mat1.print();
  cout << "mat1 + mat2 = \n";
  (mat1 + mat2).print();
  cout << "mat1 - mat2 = \n";
  (mat1 - mat2).print();
  cout << "mat1 * mat2 = \n";
  (mat1 * mat2).print();
  cout << "mat1 * 2 = \n";
  (mat1 * 2).print();
  cout << "mat1 *= 2 \n";
  mat1 *= 2;
  mat1.print();
  cout << "2 * mat1 = \n";
  (mat1 * 2).print();
  system("pause");
  return 0;
}









//
