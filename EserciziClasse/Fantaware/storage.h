
#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include "data.h"

class Storage {
private:
	class GeekTime {
		friend class Storage;
	private:
		const Geek* geek;
		const Project* project;
		int hours;
		GeekTime(const Geek*, const Project*, int = 0);
	public:
		bool operator<(const GeekTime&) const;
	};
private:
	std::vector<Geek*> geeks;
	std::vector<Project*> projects;
	std::vector<GeekTime> gtime;
protected:
	void progress(Geek*, Project*, int = 0);
	double getSalary(Geek*);
public:
	Storage();
	// Storage(std::vector<Geek*>, std::vector<Project*>);
	void push(Geek&);
	void push(Project&);
	void progress(int, std::string, int = 0);
	void print() const;
	void printProgress() const;
	double getSalary(int);
};


#endif
