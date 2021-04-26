#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::cin;

int main(){
    float  value{0};
    float ris;
    char scale{};

    while (scale !='C' && scale != 'F'){
        cout<< "Inserire una scala da convertire :"<< endl;
        cin >> scale;
        if(scale !='C' && scale != 'F')
            cout<< "Inserire o F o C"<< endl;
    }
    
    cout<< "Inserire una valore da convertire :"<< endl;
    cin >> value;
    if(scale=='C'){
        ris = value*(9/5) +32;
        cout<< ris <<endl;
    }else if(scale=='F'){
        ris = (value - 32) * 5/9;
        cout<<"RIS: " <<ris <<endl;
    }
    
    return 0;
}