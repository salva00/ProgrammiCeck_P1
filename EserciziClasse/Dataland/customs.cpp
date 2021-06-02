
#include "customs.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <exception>

class unfinished_load: public std::exception {
  virtual const char* what() const throw() {
    return "Cannot load all data";
  }
};

template<typename T>
T readLine(std::ifstream& file) {
	std::string line;
	if(file.eof()) throw unfinished_load();
	std::getline(file,line);
	return line;
}
template<>
int readLine<int>(std::ifstream& file) {
	std::string line;
	if(file.eof()) throw unfinished_load();
	std::getline(file,line);
	if(line.empty()) return 0;
	else return std::stoi(line);
}
template<>
double readLine<double>(std::ifstream& file) {
	std::string line;
	if(file.eof()) throw unfinished_load();
	std::getline(file,line);
	if(line.empty()) return 0;
	else return std::stod(line);
}
template<>
bool readLine<bool>(std::ifstream& file) {
	std::string line;
	if(file.eof()) throw unfinished_load();
	std::getline(file,line);
	if(line == "true" || line == "1") return true;
	else return false;
}

double getTotalWeight(const Container& cont) {
	double res{0};
	for(Box b : cont) res += b.getWeight();
	return res;
}

double getTotalValue(const Container& cont) {
	double res{0};
	for(Box b : cont) res += b.getValue();
	return res;
}

Customs::Customs() : LinkedQueue(), storage() {}

void Customs::print() const {
	std::cout << std::left << std::setw(8) << front().getId()
						<< std::left << std::setw(25) << front().getOrigin()
						<< std::left << std::setw(35) << front().getCarrier()
						<< " ~ Weight: " << std::right << std::setw(6) << getTotalWeight(front()) << " kg, "
						<< "Value: $" << getTotalValue(front()) << '\n';
	return;
}

void Customs::printStorage() const {
	if(storage.empty()) std::cout << "Storage is empty\n";
	else for(StoredBox b : storage) {
		std::cout << std::left << std::setw(8) << "From " << b.getId() << " ~ "
							<< std::setw(8) << b.getBoxid()
							<< std::right << std::setw(6) << b.getWeight() << "kg "
							<< std::setw(8) << b.getValue() << "$\n";
	}
	return;
}

void Customs::clearance() {
	print();
	dequeue();
	return;
}

void Customs::append_from(std::string filename) {
	std::ifstream file{filename};
	if(!file) {
		throw std::invalid_argument("File cannot be opened");
	}
	std::string line;
	Container cont;
	Box box;
	int repeat{0};
	double contVal;
	while(!file.eof()) {
		try{
			cont.setId(readLine<int>(file)); // id_container
			cont.setOrigin(readLine<std::string>(file)); // state_orig
			cont.setCarrier(readLine<std::string>(file)); // id_carrier
			repeat = readLine<int>(file); // n_box
			while(repeat > 0) {
				box.setBoxid(readLine<int>(file)); // box_id
				box.setWeight(readLine<double>(file)); // weight
				box.setValue(readLine<double>(file)); // value
				box.setPerishable(readLine<bool>(file)); // perishable
				cont.push_front(box);
				--repeat;
			}
		} catch(unfinished_load& exc) {
			break;
		}
		contVal = getTotalValue(cont);
		while((contVal > max_value) && (cont.begin()->getPerishable() == 0) && (!cont.empty())) {
			contVal -= cont.begin()->getValue();
			storage.push_front(StoredBox(*cont.begin(),cont.getId()));
			cont.pop_front();
		}
		if(!cont.empty()) for(Container::Iterator prev = cont.begin(), it = prev+1;
				contVal > 0 && it != cont.end();) {

			if(it->getPerishable() == false) {
				contVal -= it->getValue();
				storage.push_front(StoredBox(*it,cont.getId()));
				cont.erase_after(prev);
				it = prev + 1;
				if(it == cont.end()) break;
			} else {
				++prev, ++it;
			}
		}

		this->enqueue(cont);
		cont.clear();
	}
}

void Customs::load_from(std::string filename) {
	clear();
	append_from(filename);
	return;
}

void Customs::clearence_excess(int idCont) {

	while((!storage.empty()) && storage.begin()->getId() == idCont) {
		storage.pop_front();
	}
	if(!storage.empty()) for(auto prev = storage.begin(), it = prev+1;
			it != storage.end();) {

		if(it->getId() == idCont) {
			storage.erase_after(prev);
			it = prev + 1;
			if(it == storage.end()) break;
		} else {
			++it, ++prev;
		}
	}
}











//
