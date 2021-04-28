#include <iostream>
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;

int main() {
    char *buffer = NULL;
    int length = 0;
    {
        ifstream is("hello.txt");
        if(!is){
            std::cout<<"Error opening file"<<std::endl;
            return 1;
        }
        is.seekg(0,ios::end);
        length = is.tellg();
        is.seekg(0, ios::beg);
        buffer = new char[length];
        is.read(buffer,length);
    }
    {
        ofstream os("hello2.txt");
        if (!os){
            std::cout<<"Error opening file"<<std::endl;
            delete[]buffer;
            return 1;
        }
        os.write(buffer,length);
        delete[] buffer;
    }
    return 0;
}



