## Esercizio 1

La dogana dell’isola di Dataland deve gestire il flusso dei container in ingresso in ordine di arrivo con una coda. Ogni container contiene uno specifico identificativo: id_container, il paese di provenienza: state_orig, e lo spedizionere: id_carrier. Inoltre ogni container contiene  un certo numero di pacchi (memorizzati in una lista): n_box. Ogni pacco ha un identificativo: box_id, il peso: weight, il valore:  value, e un flag per materiale deteriorabile: perishable.  
Queste informazioni sono memorizzate in un file sequenziale containers.txt, ad esempio:

10101 						← id_container\
United States					← state_orig\
International Shipping Company		← id_carrier\
2							← n_box\
1212							← box_id\
13.2							← weigh\
1245.8						← value\
1							← perishable\
1213							←- box_id\
...	\
...\
10134							← id_container\
...

* 1.1 Implementare  un programma C++ che legge il file  containers.txt e memorizza i dati nelle strutture dati opportune. Implementare la funzione clearance che estrae il prossimo container dalla coda, calcola il peso totale e il valore totale.

* 1.2 Se il valore totale supera un certo valore soglia allora la funzione deve creare la lista dei pacchi  in giacenza togliendo dalla lista originale quei pacchi identificati non deteriorabili. La nuova  lista deve aggiungere il numero del container alle informazioni sui pacchi in giacenza.
Implementare infine la funzione clearence_excess che, preso come parametro l’id_container elimini dalla lista eccedenze tutti i pacchi relativi a quello specifico container.
