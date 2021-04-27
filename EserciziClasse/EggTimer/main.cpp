/*
• (Egg-timer Program) Write an application that prints the
following egg-timer shape. You may use output statements
that print a single asterisk (*), a single hash (#) a
single space or a single newline character. Maximize your
use of iteration (with nested for statements), and minimize
the number of output statement
*/

#include "eggtimer.h"
#include<iostream>

int main() {
  Eggtimer timer1(5);
  while(timer1.isCompleted() != true) {
    timer1.printProgress();
    system("pause");
    timer1.next();
  }
  timer1.printProgress();
  std::cout << "Completed!!\n";
  system("pause");
  return 0;
}
