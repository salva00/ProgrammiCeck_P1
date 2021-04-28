//MotorVehicle.h
#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H

#include <string>

class MotorVehicle {
	std::string make;
	std::string fuelType;
	int yearOfManufacture;
	std::string color;
	int engineCapacity;
public:
	MotorVehicle(std::string make, std::string fuelType,int yearOfManufacture,std::string color,int engineCapacity);
	void setMake(std::string make);
	void setFuelType(std::string fuelType);
	void setYearOfManufacture(int yearOfManufacture);
	void setColor(std::string color);
	void setEngineCapacity(int engineCapacity);
	std::string getMake();
	std::string getFuelType();
	int getYearOfManufacture();
	std::string getColor();
	int getEngineCapacity();
	void displayCarDetails();
};

#endif // !MOTORVEHICLE_H
