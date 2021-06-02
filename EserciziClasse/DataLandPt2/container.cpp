
#include "container.h"

// Box //

Box::Box(int id, double wgt, double val, std::string per) {
		setBoxid(id);
		setWeight(wgt);
		setValue(val);
		setPerishable(per);
	}

Box::Box(const Box& b) : box_id{b.box_id}, weight{b.weight}, value{b.value},
	perishable{b.perishable} {}

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
	BinarySearchTree(), id_container{id}, state_orig{orig}, id_carrier{carrier} {}

Container::Container(const Container& c) : BinarySearchTree{c},
	id_container{c.id_container}, state_orig{c.state_orig}, id_carrier{c.id_carrier} {}

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
	if(rhs.empty()) res = false;
	else if(this->empty()) res = true;
	else res = rhs.getMin() < this->getMin();
	return res;
}

void Container::print() const {
	std::cout << id_container << ' ' << state_orig << ' ' << id_carrier << '\n';
	if(empty()) std::cout << "Empty cargo\n";
	else for(auto it = this->begin(); it != this->end(); ++it) {
		it->print();
	}
	return;
}





	//
