#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::vector;
using std::out_of_range;

void outputVector(const vector<int>&);  //display the vector
void inputVector(vector<int>&);  //input value into the vector

int main() {
    vector<int> integers1(7);
    vector<int> integers2(10);

    //print size vector1
    cout << "size vector integers1: "<< integers1.size() << endl;
    cout << "    vector after initialization: "<< endl;
    outputVector(integers1);

    //print size vector2
    cout << "size vector integers2: "<< integers2.size() << endl;
    cout << "    vector after initialization: "<< endl;
    outputVector(integers2);

    cout<< "enter 17 integers"<<endl;
    inputVector(integers1);
    inputVector(integers2);

    cout << "    vector1: "<< endl;
    outputVector(integers1);
    cout << "    vector2: "<< endl;
    outputVector(integers2);

    try {
        cout<<"\n Attempt to display element with index 15"<<endl;
        cout<< integers1.at(15)<< endl;
    }catch (out_of_range& ex){
        cerr<< "an exception occurred "<< ex.what()<< endl;
    }

    return 0;
}

void outputVector (const vector<int>& items){
    for (int item : items){
        cout << item <<" ";
    }
    cout<<endl;
}

void inputVector (vector<int>& items){
    for (int& item : items){
        cin >> item;
    }
}