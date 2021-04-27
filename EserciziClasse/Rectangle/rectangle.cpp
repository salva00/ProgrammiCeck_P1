#include<iostream>
#include<iomanip>

struct point {
  point(int xx, int yy) : x(xx), y(yy) {};
  int x;
  int y;
};


class Rectangle {
public:
  Rectangle(point A, point B) {
      if(A.x < B.x) { this->x1 = A.x; this->x2 = B.x;}
                else { this->x1 = B.x; this->x2 = A.x;}
      if(A.y < B.y) { this->y1 = A.y; this->y2 = B.y;}
                else { this->y1 = B.y; this->y2 = A.y;}
  }
  Rectangle(point A, int width, int height) {
    if(width >= 0) {this->x1 = A.x; this->x2 = (A.x + width);}
              else {this->x1 = (A.x + width); this->x2 = A.x;}
    if(height >= 0) {this->y1 = A.y; this->y2 = (A.y + height);}
                else {this->y1 = (A.y + height); this->y2 = A.y;}
  }
  int getPerimeter() {
    return ((this->x2 - this->x1) * 2 + (this->y2 - this->y1) * 2);
  }
  int getArea() {
    return ((this->x2 - this->x1) * (this->y2 - this->y1));
  }
  void specs() {
    std::cout << "Rectangle (" << this->x1 << ',' << this->y1 <<") (" << this->x2 << ',' << this->y2 << ")\n"
              << "Width: " << (this->x2 - this->x1) << "\tHeight: " << (this->y2 - this->y1) << '\n'
              << "Perimeter: " << this->getPerimeter() << "\tArea: " << this->getArea() << '\n';
  }
  int getXmin() const {return this->x1;}
  int getXmax() const {return this->x2;}
  int getYmin() const {return this->y1;}
  int getYmax() const {return this->y2;}
private:
  int x1{0}; // x min
  int x2{0}; // x max // x1 < x2
  int y1{0}; // y min
  int y2{0}; // y max // y1 < y2
};


template<unsigned short W = 25, unsigned short H = 25, char OUTFILL = '.', char PERIMETER = '*', char INFILL = '-'>
void plot(Rectangle R) {
  if(R.getXmin() < 0 || R.getYmin() < 0 || R.getXmax() >= (int) W || R.getYmax() >= (int) H) {
      std::cout << "Couldn't plot rectangle\n";
      return;
  }
  for(int j = H-1; j >= 0; j--) {
    for(int i = 0; i < (int) H; i++) {
      if(j > R.getYmax() || j < R.getYmin() || i < R.getXmin() || i > R.getXmax())
        std::cout << std::setw(2) << OUTFILL;
      else if(j == R.getYmax() || j == R.getYmin() || i == R.getXmin() || i == R.getXmax())
        std::cout << std::setw(2) << PERIMETER;
      else if((R.getYmin() < j && j < R.getYmax()) && (R.getXmin() < i && i < R.getXmax()))
        std::cout << std::setw(2) << INFILL;
      else continue;
    }
    std::cout << '\n';
  }
  std::cout << '\n';
  return;
}










//
