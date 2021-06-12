
#ifndef DATA_H
#define DATA_H

#include "..\lib\mystl\LinkedList.h"
#include <string>

class Project;

class Geek {
	friend class Storage;
private:
	int id_geek;
	double hour_salary;
	mystl::LinkedList<Project*> list_of_projects;
public:
	Geek(int = 0, double = 0);
	bool operator<(const Geek&) const;
	int getId() const;
	void addProject(Project*);
	void print() const;
};

class Project {
	friend class Storage;
private:
	int id_project;
	std::string project_name;
	int total_amount;
	std::string delivery_date;
	mystl::LinkedList<Geek*> list_of_geeks;
public:
	Project(int = 0, std::string = "", int = 0, std::string = "2099/12/12");
	bool operator<(const Project&) const;
	void addGeek(Geek*);
	std::string getName() const;
	void print() const;
};

#endif
