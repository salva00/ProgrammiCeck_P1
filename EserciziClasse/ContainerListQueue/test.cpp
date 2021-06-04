#include <iostream>
#include <queue>
#include <list>

class Container {
    int y;
public:
    friend bool operator< (const Container& a, const Container& b);
    //...
};

struct Comp {
    bool operator() (const Container& a, const Container& b) {
        return a < b;
    }
};

bool operator<(const Container& a, const Container& b) {
    return a.y < b.y;
}

std::priority_queue<Container, std::list<Container>, Comp> containers;

int main()
{
    std::cout << "Hello World!\n";
}