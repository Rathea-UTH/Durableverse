
CC=gcc
CFLAGS= -W -Wall -ansi -std=c11
LDFLAGS=
EXEC=main


all : $(EXEC)

main : main.o plateau.o carte.o interface.o structures.o
	$(CC) -o $@ $^ $(LDFLAGS)

main.o : bin/main.c obj/plateau.h headers/interface.h obj/carte.h obj/structures.h
	$(CC) -o $@ -c $< $(CFLAGS)

plateau.o : obj/plateau.c obj/plateau.h obj/structures.h obj/carte.h
	$(CC) -o $@ -c $< $(CFLAGS)

carte.o : obj/carte.c obj/carte.h
	$(CC) -o $@ -c $< $(CFLAGS)

interface.o: headers/interface.c headers/interface.h obj/plateau.h obj/carte.h
	$(CC) -o $@ -c $< $(CFLAGS)

structures.o: obj/structures.c obj/structures.h
	$(CC) -o $@ -c $< $(CFLAGS)


clean:
	rm -rf *.o

mrproper : clean
	rm -rf $(EXEC)
