#include <iostream>
#include <vector>

int vectorSum1 (std::vector<int> V){
    std::vector<int>::iterator p;   //iteretor
    int sum = 0;
    for (p=V.begin(); p != V.end(); p++)
        sum += *p;
    return sum;
}

int vectorSum2 (const std::vector<int>& V){
    std::vector<int>::const_iterator p;   //iteretor
    int sum = 0;
    for (p=V.begin(); p != V.end(); p++)
        sum += *p;
    return sum;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
