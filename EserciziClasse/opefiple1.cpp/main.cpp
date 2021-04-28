
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using std::ofstream;
using std::ios;

int main() {
    ofstream outClientFile("clients.txt",ios::out);

    //ofstream outClientFile{"clients.txt",ios::out};

    if(!outClientFile){
        std::cerr<<"File could not be opended"<<std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout<<"Enter the account, name, and balance\n"
        <<"enter e-o-f to end input.txt ";
    int account;
    std::string name;
    double balance;

    while(std::cin >>account>>name>>balance){
        outClientFile<<account<<" "<< name <<" " << balance <<std::endl;
        std::cout<<"? ";
    }
    outClientFile.close();
    return 0;
}
