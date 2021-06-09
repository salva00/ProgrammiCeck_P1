#ifndef UTILS_H
#define UTILS_H

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include "Types.h"

namespace myutils {
	using std::ostream;
	using std::string;
	using std::ofstream;
	using std::ifstream;
	using std::ios;
	using std::vector;

	struct Instance {
		std::string name;
		Type* value;
	};

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

	vector<Instance> read(vector<std::pair<string,Types>> arguments){
		ifstream file("filename.txt", std::ios::in);
		vector<Instance> result;
		if (file.is_open()) {
			while (!file.eof()) {
				for (auto arg: arguments) {
					Instance elem;
					// switch (arg.second) {
					// 	case Types::STRING:
					// 		string temp;
					// 		std::getline(file, temp);
					// 		//dynamic_cast<String>((elem.value).setValue(temp)); BOH
					// 		// VECTOR <3 :)
					// 		break;
					// 	case Types::INT:
					// 		int pippo;
					// 		file >> pippo;
					// 		elem.value->setValue(pippo);
					// 	case Types::FLOAT:
					// 		float pippo1;
					// 		file >> pippo;
					// 		elem.value->setValue(pippo);
					// 	case Types::DOUBLE:
					// 		double pippo2;
					// 		file >> pippo;
					// 		elem.value->setValue(pippo);
					// 	case Types::BOOL:
					// 		bool pippo;
					// 		file >> pippo3;
					// 		elem.value->setValue(pippo);
					// 	case Types::CHAR:
					// 		char pippo4;
					// 		file >> pippo;
					// 		elem.value->setValue(pippo);
					// 	default: throw std::invalid_argument("Sei scemo");
					// }
					// result.push_back(elem);
				}
				//file >> res;
			}
		} else {
			throw std::invalid_argument("Cannot open file");
		}
		file.close();
		return result;
	}



} /* myutils */

#endif










//
