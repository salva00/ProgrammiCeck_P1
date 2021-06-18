
# Esame 18/06/21

La biblioteca di Fantaland vuole gestire i prestiti dei sui libri. Ogni libro
ha un identificativo: book_id, un  insieme di autori (vettore di stringhe):
authors, il titolo: title, anno di pubblicazione: year, posizione nella
libreria (stringa): position, valore del libro: value. I libri vengono
memorizzati in un vettore in ordine di autori, a parità di autori si
ordina in base all’anno. Un prestito contiene l’indicazione del libro
prestato, la data del prestito e la data di restituzione (per definizione
30 giorni a partire dalla data del  prestito). I prestiti vengono memorizzati
in una lista (mantenuta in maniera ordinata per data di  restituzione).


* Implementare le strutture dati per rappresentare le informazioni descritte
e le relative funzioni membro

* Implementare la funzione borrow che prende in ingresso un libro e la data
del prestito e aggiunge un nodo alla lista dei prestiti

* Implementare la funzione  valueExpired della lista dei prestiti prendendo
in ingresso la data odierna e  la lista per calcolare il valore complessivo
 dei libri la cui data di restituzione e’ scaduta

* Implementare un programma  driver che crea il vettore di libri e utilizza
le funzioni implementate.

* Opzionale: implementare la funzione returnBook che cerca il libro  dalla
lista dei prestiti, se presente lo rimuove e calcola l’eventuale multa
 come 1$ per ogni giorno che eccede la  data di restituzione
