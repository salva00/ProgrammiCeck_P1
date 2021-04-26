#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;

int main() {
    //set floating-point number format
    cout << fixed << setprecision(2) << endl;

    double principal{1000.00};          //initial amount before interest
    double rate{0.05};                  //interest rate

    cout << "Initial principal: " << principal << endl;
    cout << "   Interest rate: " << rate << endl;

    //dispay headers
    cout << "\nYear" <<setw(20) <<"Amount on deposit: " << rate << endl;

    //calculate amount on deposit for aech of ten years
    for (unsigned int year{1}; year <= 10; year++){
        // calculate amount on deposit at the end of the specified year
        double amout = principal * pow(1.0 + rate, year);

        //display the year and the amount
        cout << setw(4) << year << setw(20) << amout << endl;
    }

    return 0;
}
