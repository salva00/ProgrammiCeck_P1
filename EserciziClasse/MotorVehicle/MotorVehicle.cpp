#include "MotorVehicle.h"
#include <iostream>

MotorVehicle::MotorVehicle(std::string make, std::string fuelType, int yearOfManufacture, std::string color, int engineCapacity) {
	this->make = make;
	this->fuelType = fuelType;
	this->yearOfManufacture = yearOfManufacture;
	this->color = color;
	this->engineCapacity = engineCapacity;
}
	
void MotorVehicle::setMake(std::string make) {
	this->make = make;
}
void MotorVehicle::setFuelType(std::string fueltype) {
	this->fuelType = fuelType;
}
void MotorVehicle::setYearOfManufacture(int yearOfManufacture) {
	this->yearOfManufacture = yearOfManufacture;
}

void MotorVehicle::setColor(std::string color) {
	this->color = color;
}

void MotorVehicle::setEngineCapacity(int engineCapacity) {
	this->engineCapacity = engineCapacity;
}

std::string MotorVehicle::getMake() {
	return make;
}

std::string MotorVehicle::getFuelType() {
	return fuelType;
}

int MotorVehicle::getYearOfManufacture() {
	return yearOfManufacture;
}

std::string MotorVehicle::getColor(){
	return color;
}

int MotorVehicle::getEngineCapacity() {
	return engineCapacity;
}

void MotorVehicle::displayCarDetails() {
	std::cout << "make: " << make
		<< "\nfuelType: " << fuelType
		<< "\nyearOfManufacture: " << yearOfManufacture
		<< "\ncolor: " << color
		<< "\nengineCapacity: " << engineCapacity
		<< "\n\n";
}