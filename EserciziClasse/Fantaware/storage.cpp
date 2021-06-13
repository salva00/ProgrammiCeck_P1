
#include "storage.h"
#include <algorithm>
#include <iostream>

template<typename P>
bool ptrMinus(P x, P y) {return *x < *y;}

template<typename P>
bool ptrEq(P x, P y) {return *x == *y;}

Storage::GeekTime::GeekTime(const Geek* g, const Project* p, int h) :
	geek{g}, project{p}, hours{h} {}

bool Storage::GeekTime::operator<(const GeekTime& rhs) const {
	return this->geek != rhs.geek? this->geek < rhs.geek : this->project < rhs.project;
}

Storage::Storage() : geeks{}, projects{}, gtime{} {}

void Storage::push(Geek& gk) {
	auto it = std::upper_bound(geeks.begin(),geeks.end(), &gk, ptrMinus<Geek*>);
	if(it == geeks.end()) geeks.push_back(&gk);
	else geeks.insert(it, &gk);
	return;
}

void Storage::push(Project& proj) {
	auto it = std::upper_bound(projects.begin(),projects.end(), &proj, ptrMinus<Project*>);
	if(it == projects.end()) projects.push_back(&proj);
	else projects.insert(it, &proj);
	return;
}

void Storage::print() const {
	std::cout << "-\nBy geeks:\n";
	for(auto gk : geeks) gk->print();
	std::cout << "-\nBy projects:\n";
	for(auto proj : projects) proj->print();
	std::cout << "-\n";
	return;
}

void Storage::progress(Geek* gk, Project* proj, int h) {
	for(auto it = gk->list_of_projects.begin();
		it != gk->list_of_projects.end(); ++it) {
			//for every project geek is working on
			if(*it == proj) {
				//if he was already working on proj
				//find that proj in gtime
				auto gt_it = std::find_if(gtime.begin(), gtime.end(),
					[&](GeekTime gt){return (gt.geek == gk && gt.project == proj);});
				gt_it->hours += h;
				return;
			}
	}// he wasn't working on proj
	//link geek to project
	std::cout << "1\n";
	gk->list_of_projects.insert_in_order(proj);
	std::cout << "2\n";
	// link project to geek
	proj->list_of_geeks.insert_in_order(gk);
	GeekTime temp{gk,proj,h};
	auto gt_it = std::upper_bound(gtime.begin(),gtime.end(), temp);
	if(gt_it == gtime.end()) gtime.push_back(temp);
	else gtime.insert(gt_it, temp);
	gk->print();
	return;
}

void Storage::progress(int id, std::string projname, int h) {
	progress(	*std::find_if(geeks.begin(), geeks.end(),
							[&](Geek* gk){return gk->id_geek == id;}),
						*std::find_if(projects.begin(), projects.end(),
							[&](Project* proj){return proj->project_name == projname;}),
						h );
	return;
}

void Storage::printProgress() const {
	std::cout << "Work progress:\n";
	for(GeekTime gt : gtime) {
		std::cout << gt.geek->id_geek << " on " <<
		gt.project->project_name << " : " << gt.hours << "h\n";
	}
}

double Storage::getSalary(Geek* gk) {
	double res{0};
	for(auto it = gtime.begin(); it != gtime.end(); ++it) {
		if(it->geek == gk) {
			res += it->hours * gk->hour_salary;
			it->hours = 0;
		}
	}
	return res;
}

double Storage::getSalary(int id) {
	return getSalary(*std::find_if(geeks.begin(), geeks.end(),
		[&](Geek* gk){return gk->id_geek == id;}));
}







//
