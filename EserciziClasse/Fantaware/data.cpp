
#include "data.h"
#include <iostream>

// Geek //

Geek::Geek(int id, double hsal) : id_geek{id}, hour_salary{hsal}, list_of_projects{} {}

void Geek::addProject(Project* prj) {
	list_of_projects.push_front(prj);
	return;
}

bool Geek::operator<(const Geek& rhs) const {
	return this->id_geek < rhs.id_geek;
}

int Geek::getId() const {return this->id_geek;}

void Geek::print() const {
	std::cout << id_geek << " " << hour_salary << "$/h\n  Works on: ";
	std::cout << (list_of_projects.empty()? "None" : "");
	for(Project* proj : list_of_projects) std::cout << proj->getName() << ", ";
	std::cout << '\n';
	return;
}

// Project //

Project::Project(int id, std::string pname, int amt, std::string date) :
	id_project{id}, project_name{pname}, total_amount{amt}, delivery_date{date} {}

void Project::addGeek(Geek* gk) {
	list_of_geeks.push_front(gk);
	return;
}

bool Project::operator<(const Project& rhs) const {
	return this->delivery_date < rhs.delivery_date;
}

std::string Project::getName() const {return this->project_name;}

void Project::print() const {
	std::cout << id_project << " " << project_name << " x" << total_amount << " dues " << delivery_date << "\n  Contributors: ";
	std::cout << (list_of_geeks.empty()? "None" : "");
	for(Geek* gk : list_of_geeks) std::cout << gk->getId() << ", ";
	std::cout << '\n';
	return;
}















//
