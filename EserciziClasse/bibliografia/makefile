CC=g++
CFLAGS=-std=c++11 -pedantic -Wall
DEPS= ListaPubblicazioni.h Pubblicazioni.h ArticoliConvegni.h ArticoliRiviste.h Libri.h
OBJ= main.o ListaPubblicazioni.o Pubblicazioni.o ArticoliConvegni.o ArticoliRiviste.h Libri.o
EXEC_NAME= bibliografia

 %.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
 $(EXEC_NAME): $(OBJ)
	$(CC) -o $@ $^
	$(RM) $(OBJ)
