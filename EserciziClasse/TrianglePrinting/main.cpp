
#include <iostream>

enum class Corners {bottomLeft, bottomRight, topLeft, topRight};

void printTriangle(int, int, Corners = Corners::topLeft);

int main() {

	std::cout << "topLeft:" << '\n';
	printTriangle(5,5,Corners::topLeft);
	std::cout << " - - - - - - - - - -\n";
	printTriangle(10,5,Corners::topLeft);
	std::cout << " - - - - - - - - - -\n";
	printTriangle(5,10,Corners::topLeft);

	std::cout << "bottomRight:" << '\n';
	printTriangle(5,5,Corners::bottomRight);
	std::cout << " - - - - - - - - - -\n";
	printTriangle(10,5,Corners::bottomRight);
	std::cout << " - - - - - - - - - -\n";
	printTriangle(5,10,Corners::bottomRight);

	std::cout << "topRight:" << '\n';
	printTriangle(5,5,Corners::topRight);
	std::cout << " - - - - - - - - - -\n";
	printTriangle(10,5,Corners::topRight);
	std::cout << " - - - - - - - - - -\n";
	printTriangle(5,10,Corners::topRight);

	std::cout << "bottomLeft:" << '\n';
	printTriangle(5,5,Corners::bottomLeft);
	std::cout << " - - - - - - - - - -\n";
	printTriangle(10,5,Corners::bottomLeft);
	std::cout << " - - - - - - - - - -\n";
	printTriangle(5,10,Corners::bottomLeft);


	return 0;
}

void printTriangle(int base, int height, Corners corner) {
	for(int i = 0; i < height; ++i) {
		for(int j = (corner == Corners::topLeft || corner == Corners::bottomRight)?0:base-1; j < base && j >= 0;) {
			if((height*j + base*i < height*base) && (corner == Corners::topLeft || corner == Corners::topRight)) std::cout << "* ";
			else if((height*(j+1) + base*(i+1) > height*base) && (corner == Corners::bottomRight || corner == Corners::bottomLeft)) std::cout << "* ";
			else std::cout << "  ";
			if(corner == Corners::topLeft || corner == Corners::bottomRight) ++j;
			else --j;

		}
		std::cout << '\n';
	}
	return;
}















//
