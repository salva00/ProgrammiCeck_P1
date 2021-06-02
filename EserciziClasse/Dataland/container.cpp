
#include "container.h"

// Box //

Box::Box(int id, double wgt, double val, bool per) {
		setBoxid(id);
		setWeight(wgt);
		setValue(val);
		setPerishable(per);
	}

int Box::getBoxid() const {return this->box_id;}
void Box::setBoxid(int id) {
	if(id < 0) throw std::invalid_argument("Box id must be greater than zero");
	else box_id = id;
	return;
}

double Box::getWeight() const {return this->weight;}
void Box::setWeight(double wgt) {
	if(wgt < 0) throw std::invalid_argument("Weight must be greater than zero");
	else weight = wgt;
	return;
}

double Box::getValue() const {return this->value;}
void Box::setValue(double val) {
	if(val < 0) throw std::invalid_argument("Value must be greater than zero");
	else value = val;

	return;
}

double Box::getPerishable() const {return this->perishable;}
void Box::setPerishable(bool per) {
	perishable = per;
	return;
}

// #include <iostream>
//
// void Box::print() const {
// 	std::cout << box_id << ' ' << weight << ' ' << value << ' ' << perishable << '\n';
// 	return;
// }

// StoredBox //

StoredBox::StoredBox(int id, double wgt, double val, bool per, int cont)
	: Box(id,wgt,val,per) {
		setId(cont);
}

StoredBox::StoredBox(const Box& b, int cont)
	: Box(b) {
		setId(cont);
}

int StoredBox::getId() const {return id_container;}

void StoredBox::setId(int id) {
	if(id < 0) throw std::invalid_argument("Id must be a positive integer");
	else id_container = id;
}

// Container //

Container::Container(int id, std::string orig, std::string carrier) :
	LinkedList(), id_container{id}, state_orig{orig}, id_carrier{carrier} {}

int Container::getId() const {return id_container;}
void Container::setId(int id) {
	if(id < 0) throw std::invalid_argument("Id must be a positive integer");
	else id_container = id;
}

std::string Container::getOrigin() const {return state_orig;}
void Container::setOrigin(std::string orig) {state_orig = orig;}

std::string Container::getCarrier() const {return id_carrier;}
void Container::setCarrier(std::string carr) {id_carrier = carr;}

// void Container::print() const {
// 	std::cout << id_container << ' ' << state_orig << ' ' << id_carrier << '\n';
// 	for(auto it = this->begin(); it != this->end(); ++it) {
// 		it->print();
// 	}
// 	return;
// }













	//
