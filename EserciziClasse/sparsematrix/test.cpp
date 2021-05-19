
/*
• Una matrice sparsa e' una matrice in cui la
gran parte dei valori e’ uguale a zero e solo
poche posizioni sono occupate da valori
diversi da zero.
• Le matrici sparse sono molto comuni in diversi
ambiti scientifici
• Pittorsto che utilizzare un array
bidimensionale per una matrice sparsa, una
soluzione alternativa e’ quella di utilizzare
delle liste a puntatori per le righe e le
colonne.
• Un nodo conserva le coordinate ed il valore
corrispondente piu’ un puntatore al prossimo
elemento lungo la riga e un puntatore al
prossimo elemento lungo la colonna
• Scrivere un programma C++ per la
rappresentazione di una matrice sparsa NxM.
• Il programma legge da un file testo che
contiene nella prima riga le dimensioni
NxM. Nelle rimanenti righe contiene le tripette
(i,j,A[i,j])
• Come si potrebbe implementare la somma di
matrici sparse?
*/
#include <iostream>
#include "sparsematrix.cpp"
#include "..\lib\LinkedList.h"
#include <fstream>

template<typename T>
LinkedList<typename SparseMatrix<T>::Node*> readfile(std::string);

int main() {
	SparseMatrix<int> s, r;
	LinkedList<SparseMatrix<int>::Node*> q = readfile<int>("data.txt");
	s.load(q.begin(),q.end());
	s.print();
	std::cout << "+\n";
	r.append(5,2,0);
	r.append(3,0,2);
	r.append(1,1,1);
	r.append(8,0,0);
	r.append(2,0,1);
	r.print();
	std::cout << "=\n";
	(s+r).print();

	system("pause");
	return 0;
}


template<typename T>
LinkedList<typename SparseMatrix<T>::Node*> readfile(std::string filename) {
	std::ifstream file{filename};
	if(!file.is_open()) throw std::invalid_argument("File not found");
	size_t i,j;
	T value;
	LinkedList<typename SparseMatrix<T>::Node*> res;
	file >> i >> j >> value;
	while(!file.eof()) {
		res.push_front(new typename SparseMatrix<T>::Node(value,i,j));
		file >> i >> j >> value;
	}
	return res;
}










//
