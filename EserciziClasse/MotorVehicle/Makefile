test: MotorVehicle.o testClass.o
	g++ -o test MotorVehicle.o testClass.o
MotorVehicle.o: MotorVehicle.h MotorVehicle.cpp
	g++ -c MotorVehicle.cpp -std=c++11 -Wall -pedantic
testClass.o: MotorVehicle.h testClass.cpp
	g++ -c testClass.cpp -std=c++11 -Wall -pedantic
