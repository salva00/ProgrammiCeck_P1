#include <iostream>
#include "matrix.cpp"
#include <ctime>
using std::endl;
using std::cout;

/**************************
Given a 2D array A mxn and a 2D array B nxk:
• Compute the matrix product AxB
**************************/



int main() {
  Matrix<double> mat1{{{0,0,-1,1},
                    {0,0,1,3},
                    {0,0,5,4},
                    {0,1,1,1}}};
  // Matrix<double> mat1(8,8);
  // mat1.random(1,time(0),-1);
  mat1.print();
  cout << "\n";
  Matrix<double> mat2 = mat1.gauss();
  cout << "\n";
  mat2.print();
  cout << "\nDeterminant is " << mat2.diag() << "\n\n";

  system("pause");
  return 0;
}
