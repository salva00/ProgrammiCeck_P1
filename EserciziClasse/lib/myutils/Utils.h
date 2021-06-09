#ifndef UTILS_H
#define UTILS_H

#include <fstream>
#include <string>
#include <iostream>
namespace myutils {
	using std::ostream;
	using std::string;
	using std::fstream;
	using std::ios;

	// fstream openFile(string path){
	// 	fstream file
	// }

	template <typename T>
	void seq_write(const T& data, string path){
		ofstream file("filename.txt", std::ios::out);
		if (file.is_open()) {
			file << data <<"\n";
		} else {
			throw std::invalid_argument("Cannot open file");
		}
		file.close();
	}
	// VECTOR = BAD
	// VECTOR = BAD
	// VECTOR = BAD
	// VECTOR = BAD
	// VECTOR = BAD
	// VECTOR = BAD
	// VECTOR = BAD
	// VECTOR = BAD
	// VECTOR = BAD
	// VECTOR = BAD
	// VECTOR = BAD
	// VECTOR = BAD
	vector read(){
		ifstream file("filename.txt", std::ios::in);
		ostream res;
		if (file.is_open()) {
			while (!file.eof()) {
				file >> res;
			}
		} else {
			throw std::invalid_argument("Cannot open file");
		}
		file.close();
	}



} /* myutils */

#endif










//
