#include <iostream>
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;

int main(int argc, char * argv[]) {
    if (argc!=3){
        std::cerr<<"Usage: "<<argv[0]<<" file1 file 2\n";
        exit(EXIT_FAILURE);
    }
    char *buffer = NULL;
    int length = 0;
    {
        ifstream is(argv[1]);
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
        ofstream os(argv[2]);
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



