#include <iostream>
#include <string>

int main() {
    std::string word,smallest;
    while (std::cin >> word){
        if(smallest.empty() || word<smallest){
            smallest = word;
        }
    }
    std::cout << smallest << std::endl;
    return 0;
}
