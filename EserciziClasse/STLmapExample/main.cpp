#include <iostream>
#include <map>

using std::map;
using std::string;

int main() {
    map<string ,double> myConst;
    myConst["PI"] = 3.14;
    myConst["e"] = 2.78;
    myConst["Erdos"] = 1.6066;
    //use of insert
    myConst.insert(std::pair<string,double>("Gauss",0.83462));
    return 0;
}
