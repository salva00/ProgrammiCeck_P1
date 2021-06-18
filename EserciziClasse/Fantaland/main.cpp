
#include <iostream>

/*
La biblioteca di Fantaland vuole gestire i prestiti dei suo libri. Ogni libro
ha un identificativo: book_id, un  insieme di autori (vettore di stringhe):
authors, il titolo: title, anno di pubblicazione: year, posizione nella
libreria (stringa): position, valore del libro: value. I libri vengono
memorizzati in un vettore in ordine di autori, a parità di autori si
ordina in base all’anno. Un prestito contiene l’indicazione del libro
prestato, la data del prestito e la data di restituzione (per definizione
30 giorni a partire dalla data del  prestito). I prestiti vengono memorizzati
in una lista (mantenuta in maniera ordinata per data di  restituzione).


Implementare le strutture dati per rappresentare le informazioni descritte
e le relative funzioni membro

Implementare la funzione borrow che prende in ingresso un libro e la data
del prestito e aggiunge un nodo alla lista dei prestiti

Implementare la funzione  valueExpired della lista dei prestiti prendendo
in ingresso la data odierna e  la lista per calcolare il valore complessivo
 dei libri la cui data di restituzione e’ scaduta

Implementare un programma  driver che crea il vettore di libri e utilizza
le funzioni implementate.

Opzionale: implementare la funzione returnBook che cerca il libro  dalla
lista dei prestiti, se presente lo rimuove e calcola l’eventuale multa
 come 1$ per ogni giorno che eccede la  data di restituzione

Nota: consegnare uno zip file che contiene una  cartella CognomeNome
in cui si trovano il codice sorgente  e il makefile per la compilazione.
 Il codice  deve essere opportunamente  commentato.*/

#include "Library.h"

int main() {

	const Date today{"2021/06/18"};
	Book pippo{0, "libro di pippo", 2021, "000A", 10.0, {"pluto","paperino"}};
	Book pluto{1, "PLUTOlibro", 2019, "000B", 10.0, {"pippo","paperino"}};
	Book paperino{2, "libropaperino", 1999, "000C", 15.0, {"pippo", "paperino"}};

	// pippo.print();
	// Borrow bpippo(pippo,Date("2021/12/12"));
	// bpippo.print();

	std::cout << "\n1.\n";
	// adding pippo pluto e paperino in library
	Library lib;
	lib.addBook(pippo);
	lib.addBook(pluto);
	lib.addBook(paperino);
	lib.print();

	std::cout << "\n2.\n";
	// borrowing pluto
	lib.borrowBook(1, Date("2021/04/18"));
	lib.print();

	std::cout << "\n3.\n";
	std::cout << "value of lent books on August 1st\n" << lib.valueExpired(Date("2021/08/18")) << "$\n";

	std::cout << "\n4.\n";
	// borrowing pippo
	lib.borrowBook(0, Date("2021/06/18"));
	lib.print();

	std::cout << "\n5.\n";
	std::cout << "returning pluto\n";
	std::cout << "Need to pay " << lib.returnBook(1,today) << "$\n\n";
	lib.print();

	std::cout << "end\n";
	getchar();
	return 0;
}
