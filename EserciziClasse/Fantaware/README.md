# Esercizi II-settimana Giugno 2021

L’azienda Fantaware vuole gestire le informazioni relative ai progetti software in corso su cui lavori i dipendenti dell’azienda.  
L’insieme dei progetti e dei programmatori sono mantenuti in dei vettori. Manterremo i progetti in ordine di scadenza crescente. Per ogni programmatore vengono mantenute le informazioni con: id_geek, hour_salary, list_of_projects. Per ogni progetto manteniamo: id_project, project_name, total_amount, delivery_date, list_of_geeks. Le due liste list_of_project e list_of_geeks contengono dei puntatori agli oggetti nei due vettori. Ma vogliamo anche poter memorizzare per ciascun programmatore quante ore ha dedicato ad un progetto, ad esempio con una struttura che contiene il puntatore al record del programmatore e il numero di ore dedicate al progetto nella list_of_geeks.


* Definire le strutture dati necessarie a memorizzare le informazioni descritte.
* Implementare la funzione assign_geek del progetto assegna un programmatore a quel progetto
* Implementare la funzione weekly_worked_hours che aggiunge un certo numero di ore che un programmatore ha svolto su un dato progetto
* Opzionale: calcolare lo stipendio totale di un programmatore e azzerare il numero di ore che quel programmatore ha svolto su ogni progetto.
