#include <iostream>
#include <queue>
int main() {
    std::priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(5);
    pq.push(3);
    std::cout << "pq size:"<<pq.size() << std::endl;
    std::cout << "pq top:"<<pq.top() << std::endl;
    std::cout << "We can use a priority queue to sort: -->" << std::endl;
    while (!pq.empty()){
        std::cout << "pq top:"<<pq.top() << std::endl;
        pq.pop();
    }

    return 0;
}
