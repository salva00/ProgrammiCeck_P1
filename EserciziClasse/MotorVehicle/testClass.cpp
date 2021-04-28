#include <iostream>
#include "MotorVehicle.h"

int main() {
	MotorVehicle testVehicle("Fiat", "Diesel", 1980, "red", 35);
	std::cout << "Calling displayCarDetails method.\n";
	testVehicle.displayCarDetails();
	std::cout << "Setting color to green with setColor method.\n";
	testVehicle.setColor("green");
	std::cout << "Calling getColor method.\n";
	std::cout << testVehicle.getColor();
	return 0;
}