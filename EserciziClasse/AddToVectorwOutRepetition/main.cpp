/*
• Write a program that reads integers from the keyboard until
EOF and stores the values in a vector
• Before adding an element to the vector it check if the value is
already in the vector, if it is present than the value is not
added
• At the end the program outputs the number of values stored in the
vector and the values
• If you have entered n numbers m of which are different, can you
compute the worst case analysis?
• What is the computational complexity if you mantain the vector ordered?
(assume the insert operation to be constant, even it is not!)
*/

#include<iostream>
#include<vector>
using std::cout;
using std::vector;

template<class T>
int search(T what, vector<T> where) {
  int n = where.size();
  for(int i{0}; i < n; i++) {
    if(where[i] == what) return i;
  }
  return -1;
}

template<class T>
void read(vector<T> input) {
  for(T i : input) cout << i << " ";
  cout << "\n";
  return;
}

template<class T>
void sortedinsert(T what, vector<T>& where) {
  if(where.size() == 0 || what > where.back()) {
    where.push_back(what);
    return;
  }
  size_t i = {where.size() - 1};
  while(i > 0 && !(where[i-1] < what && what < where[i])) i--; //decrease i until in good position
  where.insert(where.begin() + i, what);
  return;
}

int main() {
  vector<int> data;
  int in;
  cout << "Insert numbers to add to vector (Ctrl+Z to end):\n";
  while(std::cin >> in) {
    if(search(in,data) < 0) sortedinsert(in,data);
    cout << "Current elements:\n";
    read(data);
  }
  cout << "Your vector has " << data.size() << " elements:\n";
  read(data);
  system("pause");
  return 0;
}
