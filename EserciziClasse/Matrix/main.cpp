#include<iostream>
#include"matrix.h"
#include<ctime>
using std::endl;
using std::cout;

/**************************
Given a 2D array A mxn and a 2D array B nxk:
• Compute the matrix product AxB
• Implement a Matrix class that stores a nxm matrix of double
• Overload sum (+), difference(-) and product(*) operators;
**************************/



int main() {
  Matrix<double> mat1{{{1,0,0},
                      {0,1,0},
                      {0,0,1}}};

  cout << "top left is " << mat1.at(0,0);
  cout << "performing \n";
  mat1.print();
  cout << "+\n";
  Matrix<double> mat2{3,3,1};
  mat2.print();
  cout << "=\n";
  Matrix<double> m3 = mat1+mat2;
  m3.print();




  system("pause");
  return 0;
}
