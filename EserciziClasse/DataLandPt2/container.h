
#ifndef CONTAINER_H
#define CONTAINER_H

#include "..\lib\mystl\BinarySearchTree.h"

class Box {
private:
	int box_id;
	double weight;
	double value;
	std::string perishable;
public:
	Box(int = 0, double = 0, double = 0, std::string = "2121/12/31");
	Box(const Box&);
	int getBoxid() const;
	void setBoxid(int);
	double getWeight() const;
	void setWeight(double);
	double getValue() const;
	void setValue(double);
	std::string getPerishable() const;
	void setPerishable(std::string);
	bool operator<(const Box&) const;
	// bool operator<=(const Box&) const;
	bool operator==(const Box&) const;
	bool operator!=(const Box&) const;
	void print() const; // DEBUG
};

class StoredBox : public Box {
private:
	int id_container;
public:
	StoredBox(int = 0, double = 0, double = 0, std::string = "2121/12/31", int = 0);
	StoredBox(const Box&, int);
	int getId() const;
	void setId(int);
};

class Container : public mystl::BinarySearchTree<Box> {
private:
	int id_container;
	std::string state_orig;
	std::string id_carrier;
public:
	using Iterator = mystl::BinarySearchTree<Box>::Iterator;
	Container(int = 0, std::string = "-", std::string = "-");
	Container(const Container&);
	int getId() const;
	void setId(int);
	std::string getOrigin() const;
	void setOrigin(std::string);
	std::string getCarrier() const;
	void setCarrier(std::string);
	bool operator<(const Container&) const;
	void print() const; //DEBUG
};

#endif









//
