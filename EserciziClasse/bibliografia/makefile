bibliografia: main.o Pubblicazioni.o ArticoliRiviste.o Libri.o ArticoliConvegni.o
	  g++ -o bibliografia main.o Pubblicazioni.o ArticoliRiviste.o Libri.o ArticoliConvegni.o
main.o: main.cpp Pubblicazioni.h ArticoliRiviste.h Libri.h ArticoliConvegni.h
	  g++ -c main.cpp -std=c++11 -Wall -pedantic
Pubblicazioni.o: Pubblicazioni.h Pubblicazioni.cpp
	  g++ -c Pubblicazioni.cpp -std=c++11 -Wall -pedantic
ArticoliRiviste.o: ArticoliRiviste.h ArticoliRiviste.cpp
	  g++ -c ArticoliRiviste.cpp -std=c++11 -Wall -pedantic
ArticoliConvegni.o: ArticoliConvegni.h ArticoliConvegni.cpp
	  g++ -c ArticoliConvegni.cpp -std=c++11 -Wall -pedantic