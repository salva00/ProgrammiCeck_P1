
#ifndef CONTAINER_H
#define CONTAINER_H

#include "..\lib\mystl\LinkedList.h"

class Box {
private:
	int box_id;
	double weight;
	double value;
	bool perishable;
public:
	Box(int = 0, double = 0, double = 0, bool = 0);
	int getBoxid() const;
	void setBoxid(int);
	double getWeight() const;
	void setWeight(double);
	double getValue() const;
	void setValue(double);
	bool getPerishable() const;
	void setPerishable(bool);
	// void print() const;
};

class StoredBox : public Box {
private:
	int id_container;
public:
	StoredBox(int = 0, double = 0, double = 0, bool = 0, int = 0);
	StoredBox(const Box&, int);
	int getId() const;
	void setId(int);
};

class Container : public mystl::LinkedList<Box> {
private:
	int id_container;
	std::string state_orig;
	std::string id_carrier;
public:
	Container(int = 0, std::string = "-", std::string = "-");

	int getId() const;
	void setId(int);
	std::string getOrigin() const;
	void setOrigin(std::string);
	std::string getCarrier() const;
	void setCarrier(std::string);

	// void print() const;
};

#endif









//
