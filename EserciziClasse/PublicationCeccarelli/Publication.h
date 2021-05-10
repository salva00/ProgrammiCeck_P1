//
// Created by Salvatore Bramante on 10/05/21.
//

#ifndef PUBLICATIONCECCARELLI_PUBLICATION_H
#define PUBLICATIONCECCARELLI_PUBLICATION_H
#include <string>
#include <vector>
#include <sstream>
class Publication {
public:
    Publication(std::string ti, std::vector<std::string> au, int yr): title(ti),authors(au),year(yr){}
    bool operator<(const Publication& B){
        if (authors == B.authors)
            return year<B.year;
        return authors< B.authors;
    }
    virtual std::string toString(){
        std::ostringstream out;
        out<<"- \t";
        for (int i = 0; i < authors.size() ; i++) {
            out<<authors[i];
            out<< (i == authors.size()-1)? "" : ",";
        }
        out<< "(" <<year<<") "<< title;
        return out.str();
    }
private:
    std::string title;
    std::vector<std::string> authors;
    int year;
};


#endif //PUBLICATIONCECCARELLI_PUBLICATION_H
