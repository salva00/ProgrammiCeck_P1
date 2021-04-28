
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using std::ifstream;
using std::ios;

void outputLine(int, const std::string&, double);

int main() {
    ifstream inClientFile("clients.txt",ios::out);

    //ofstream outClientFile{"clients.txt",ios::out};

    if(!inClientFile){
        std::cerr<<"File could not be opended"<<std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout<<std::left<< std::setw(10)<<"Account" <<std::setw(13)<< "Name" <<"Balance\n"
        <<std::fixed<< std::showpoint;
    int account;
    std::string name;
    double balance;

    while(inClientFile >>account>>name>>balance){
        outputLine(account,name,balance);
        std::cout<<"? ";
    }
    inClientFile.close();
    return 0;
}

void outputLine(int account, const std::string& name, double balance){
    std::cout<<std::left<< std::setw(10)<<"Account"<<account <<std::setw(13)<< "Name"<< name <<"Balance\n"<<balance
             <<std::fixed<< std::showpoint;
}

