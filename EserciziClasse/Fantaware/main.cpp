/*
Esercizio.

L’azienda Fantaware vuole gestire le informazioni relative ai progetti
software in corso su cui lavorino i dipendenti dell’azienda.
L’insieme dei progetti e dei programmatori sono mantenuti in dei vettori.
Manterremo i progetti in ordine di scadenza crescente. Per ogni
programmatore vengono mantenute le informazioni con: id_geek, hour_salary,
list_of_projects. Per ogni progetto manteniamo: id_project, project_name,
total_amount, delivery_date, list_of_geeks. Le due liste list_of_project
e list_of_geeks contengono dei puntatori agli oggetti nei due vettori.
Ma vogliamo anche poter memorizzare per ciascun programmatore quante ore ha
dedicato ad un progetto, ad esempio con una struttura che contiene il
puntatore al record del programmatore e il numero di ore dedicate al progetto
nella list_of_geeks.

* Definire le strutture dati necessarie a memorizzare le informazioni descritte.
* Implementare la funzione assign_geek del progetto assegna un programmatore
a quel progetto
* Implementare la funzione weekly_worked_hours che aggiunge un certo numero di
ore che un programmatore ha svolto su un dato progetto
* Opzionale: calcolare lo stipendio totale di un programmatore e azzerare il
numero di ore che quel programmatore ha svolto su ogni progetto.
*/

#include "storage.h"
// #include "..\lib\mystl\LinkedList.h"
// #include <cstdlib>
// #include <ctime>
#include <iostream>


int main() {
	Geek pippo{0, 40}, pluto{1, 40}, paperino{2,30};
	Project p1{1, "proj1", 1, "2021/10/05"}, p2{2, "proj2", 1, "2022/01/20"};
	Storage fanta;
	fanta.push(pluto);
	fanta.push(paperino);
	fanta.push(pippo);
	fanta.push(p1);
	fanta.push(p2);
	fanta.progress(0, "proj1", 50);
	fanta.print();
	fanta.printProgress();
	std::cout << "geek 0 is paid " << fanta.getSalary(0) << "$\n";
	fanta.printProgress();

	system("pause");
	return 0;
}

// mystl::LinkedList<int> q;
// std::srand(time(0));
// int r;
// for(int j = 0; j < 4; ++j) {
	// 	r = std::rand() % 10;
	// 	q.insert_in_order(r);
	// }
	// for(auto x : q) std::cout << x << ' ';
	// std::cout << '\n';
	//
	// q.remove_if([](int i){return 0;});
	//
	// for(auto x : q) std::cout << x << ' ';
	// std::cout << '\n';

















//
