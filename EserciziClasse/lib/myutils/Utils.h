//
// Created by Salvatore Bramante on 10/06/21.
//

#ifndef UTILS_H
#define UTILS_H
#include <fstream>
#include <utility>
#include <vector>
#include "Helpers.h"

namespace myutils {
    using std::ostream;
    using std::string;
    using std::ofstream;
    using std::ifstream;
    using std::ios;
    using std::vector;



    template <typename T>
    void seq_write(const T& data, const string& path){
        ofstream file(path, std::ios::out);
        if (file.is_open()) {
            file << data <<"\n";
        } else {
            throw std::invalid_argument("Cannot open file");
        }
        file.close();
    }


    template <typename T>
    void bin_init(T blank, int numberOfElements, const string& path){
        ofstream file(path, std::ios::binary | std::ios::out | std::ios::app);
        if (file.is_open()) {
            for (int i=0; i<numberOfElements; i++){
                file.write(reinterpret_cast<const char*>(blank), sizeof(T));
            }
        } else {
            throw std::invalid_argument("Cannot open file");
        }
        file.close();
    }


    vector<Instance> seq_deserialize(const vector<std::pair<string,Types>>& arguments){
        ifstream file("filename.txt", std::ios::in);
        vector<Instance> result;
        if (file.is_open()) {
            while (!file.eof()) {
                for (auto arg: arguments) {
                    result.push_back(getCorrectType(file,arg));
                    //result.front().value->getType();
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

#endif //SORTHEAP_UTILS_H
