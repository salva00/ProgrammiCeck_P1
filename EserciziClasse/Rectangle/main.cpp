/*
• Create a Rectangle class that
represents each rectangle with four
points
• 0<= x,y<=20
• Write a function to draw the rectangle
on a quadrant 25x25 using a blank
character “.”, anf a perimeter
character and fill character
• Ex. for a rectangle with points
p1(6,0), p2(18,0), p3(18,20), p4(6,20),
with fill character “-”
*/

#include<iostream>
#include"rectangle.cpp"
using std::cout;
using std::cin;

int main() {
  int x1,x2,y1,y2;
  cout << "Insert first point coordinates: ";
  cin >> x1;
  cin >> y1;
  cout << "Insert second point coordinates: ";
  cin >> x2;
  cin >> y2;
  Rectangle rect1{{x1,y1},{x2,y2}};
  plot(rect1);
  rect1.specs();
  system("pause");
  return 0;
}
