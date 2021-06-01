
#include "container.h"

// Box //

Box::Box(int id, double wgt, double val, std::string per) {
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

std::string Box::getPerishable() const {return this->perishable;}
void Box::setPerishable(std::string per) {
	//if() //check format
	perishable = per;
	return;
}

bool Box::operator<(const Box& rhs) const {
	// rhs is greater if deteriorates later
	return this->perishable < rhs.perishable;
}

// bool Box::operator<=(const Box& rhs) const {
// 	// rhs is greater if deteriorates later
// 	return *this < rhs || *this == rhs;
// }

bool Box::operator==(const Box& rhs) const {
	return this->box_id == rhs.box_id;
}

bool Box::operator!=(const Box& rhs) const {
	return this->box_id != rhs.box_id;
}

#include <iostream>

void Box::print() const {
	std::cout << box_id << ' ' << weight << ' ' << value << ' ' << perishable << '\n';
	return;
}

// StoredBox //

StoredBox::StoredBox(int id, double wgt, double val, std::string per, int cont)
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
	elements{}, id_container{id}, state_orig{orig}, id_carrier{carrier} {}

int Container::getId() const {return id_container;}
void Container::setId(int id) {
	if(id < 0) throw std::invalid_argument("Id must be a positive integer");
	else id_container = id;
}

std::string Container::getOrigin() const {return state_orig;}
void Container::setOrigin(std::string orig) {state_orig = orig;}

std::string Container::getCarrier() const {return id_carrier;}
void Container::setCarrier(std::string carr) {id_carrier = carr;}

bool Container::operator<(const Container& rhs) const {
	// rhs is greater if deteriorates earlier
	bool res;
	std::cout << "u\n";
	this->print();
	std::cout << "-\n";
	rhs.print();
	if(rhs.elements.empty()) res = false;
	else if(this->elements.empty()) res = true;
	else res = rhs.elements.getMin() < this->elements.getMin();
	std::cout << "u!\n";
	return res;
}

void Container::print() const {
	std::cout << id_container << ' ' << state_orig << ' ' << id_carrier << '\n';
	if(elements.empty()) std::cout << "Empty cargo\n";
	else for(auto it = this->elements.begin(); it != this->elements.end(); ++it) {
		it->print();
	}
	return;
}

void Container::push(const Box& b) {
	elements.push(b);
	return;
}

typename Container::Iterator Container::begin() const {
	return elements.begin();
}

typename Container::Iterator Container::end() const {
	return elements.end();
}

typename Container::Iterator Container::rbegin() const {
	return elements.rbegin();
}

typename Container::Iterator Container::rend() const {
	return elements.rend();
}

void Container::clear() {
	elements.clear();
	return;
}






	//
