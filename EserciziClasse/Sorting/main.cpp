#include <iostream>
#include <vector>
using std::vector;

void merge(vector<int>& A,int p, int r, int q){
    int i = p;
    int j = q+1;
    int k = p;
    static vector<int> c(A.size());

    while(i<=q && j<=r){

        if(A[i] <= A[j]){
            c[k] = A[i];
            i++;
        }
        else{
            c[k] = A[j];
            j++;
        }

        k++;

    }

    while(i<=q){
        c[k] = A[i];
        i++;
        k++;
    }

    while(j<=r){
        c[k] = A[j];
        j+=1;
        k+=1;
    }

    for(i=p; i<k;i++){
        A[i]=c[i];
    }

}

void mergeSort(vector<int>& A, int p, int r){
    int q;
    if(p<r){
        q=(p+r)/2;
        mergeSort(A,p,q);
        mergeSort(A,q + 1,r);
        merge(A,p,r,q);
    }
}

void swap(vector<int>& A,int x, int y){
    int temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}

int partition (vector<int> &A, int p, int r){
    int x = A[p];
    int i = p-1;
    int j = r+1;
    while (true){
        do {
            j--;
        } while (A[j]>x);

        do {
            i++;
        }while (A[j]<x);

        if(i<j){
            swap(A,i,j);
        }else{
            return j;
        }
    }
}

void quickSort(vector<int>& A, int p, int r){
    if(p<r){
        int q = partition(A,p,r);
        quickSort(A,p,q);
        quickSort(A,q+1,r);
    }
}

void selectionSort(vector<int>& A){
    for (int j= 1; j<A.size(); j++){
        int key = A[j];
        int i = j;
        while (i>0 && A[j-1]>key){
            A[i]=A[i-1];
            i--;
        }
        A[i]=key;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
