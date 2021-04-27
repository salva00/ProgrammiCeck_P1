
#include"eggtimer.h"
#include<iostream>

/*
max = 3 | progress = 1
#########  => max+2 #
#\     /#  => 1 + i + 1 + (2(max-i)-1) + 1 + i + 1
# \ooo/ #  => progress filled lines
#  \o/  #
#  / \  #
# /   \ #
#/ooooo\#
#########


*/
#define BORDER_CHAR '#'
#define SIDE_CHAR1 '\\'
#define SIDE_CHAR2 '/'
#define FILL_CHAR '*'

void repeatChar(char c, int amount) {
  for(int i{0}; i < amount; i++) std::cout << c;
  return;
}

Eggtimer::Eggtimer(int i) : max{i}, progress{0} {}

void Eggtimer::next(int i) {this->progress += i;}

void Eggtimer::reset() {this->progress = 0;}

void Eggtimer::printProgress() const {
  repeatChar(BORDER_CHAR, 2*this->max + 3);
  std::cout << '\n';
  for(int j{0}; j < this->max; j++) { //prints upper part
    std::cout << BORDER_CHAR;
    repeatChar(' ', j);
    std::cout << SIDE_CHAR1;
    if(j < this->progress) repeatChar(' ', 2*(this->max - j) - 1);
    else repeatChar(FILL_CHAR, 2*(this->max - j) - 1);
    std::cout << SIDE_CHAR2;
    repeatChar(' ', j);
    std::cout << BORDER_CHAR << '\n';
  }
  // lower part: same but swapped SIDE_CHAR 1 and 2, ' ' and FILLCHAR
  for(int j{0}; j < this->max; j++) {
    std::cout << BORDER_CHAR;
    repeatChar(' ', this->max-j-1);
    std::cout << SIDE_CHAR2;
    if(j < this->max - this->progress) repeatChar(' ', 2*j + 1);
    else repeatChar(FILL_CHAR, 2*j + 1);
    std::cout << SIDE_CHAR1;
    repeatChar(' ', this->max-j-1);
    std::cout << BORDER_CHAR << '\n';
  }
  repeatChar(BORDER_CHAR, 2*this->max + 3);
  std::cout << '\n';
  return;
}

bool Eggtimer::isCompleted() {
  if(this->max == this->progress) return true;
  else return false;
}















//
