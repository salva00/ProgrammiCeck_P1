
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

Customs::Customs() : VPriorityQueue(), storage() {}

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
							<< std::setw(8) << b.getValue() << "$ "
							<< std::setw(12) << b.getPerishable() << '\n';
}
	return;
}

void Customs::clearance() {
	print();
	pop();
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
				box.setPerishable(readLine<std::string>(file)); // perishable
				// std::cout << "adding box:\n";
				// box.print();
				cont.push(box);
				--repeat;
			}
		} catch(unfinished_load& exc) {
			break;
		}
		contVal = getTotalValue(cont);
		while((contVal > max_value) && (!cont.empty())) {
			contVal -= cont.begin()->getValue();
			// std::cout << "removing:\n";
			// cont.begin()->print();
			storage.push_front(StoredBox(*cont.begin(),cont.getId()));
			cont.remove(cont.begin());
		}

		// std::cout << "\nPushing this container:\n";
		// cont.print();
		// std::cout << "contains " << cont.size() << '\n';
		this->push(cont);
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
