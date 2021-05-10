#include <iostream>
#include "Publication.h"
#include "Book.h"
template<typename T>
void swap(std::vector<T>& A,int x, int y){
    T temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}

template<typename T>
int partition (std::vector<T> &A, int p, int r){
    T x = A[p];
    int i = p-1;
    int j = r+1;
    while (true){
        do {
            j--;
        } while (*x<*A[j]);

        do {
            i++;
        }while (*x<*A[j]);

        if(i<j){
            swap(A,i,j);
        }else{
            return j;
        }
    }
}

template<typename T>
void quickSort(std::vector<T>& A, int p, int r){
    if(p<r){
        int q = partition(A,p,r);
        quickSort(A,p,q);
        quickSort(A,q+1,r);
    }
}


int main() {
    Book::nBooks=0;
    Publication b1("A great book",{"Rossi M.","Verdi C,", "Bianchi P."},2001);
    Publication b2("Another great book",{"Esposito M.", "Bianchi P."},2002);
    Book b3("The Art of computer programming",{"Knuth B."},1968, "PP","9999999999");
    std::vector<Publication*> bib;
    bib.push_back(&b1);
    bib.push_back(&b2);
    quickSort(bib,0,bib.size()-1);
    for (int i = 0; i < bib.size(); ++i) {
        std::cout << bib[i]->toString() << std::endl;

    }
    return 0;
}
