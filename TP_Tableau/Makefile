all: tableau

tableau: tableau.o main.o
	gcc -o tableau tableau.o main.o  -lm

tableau.o: tableau.c
	gcc -c tableau.c -W -Wall -o3 -lm -o tableau.o

main.o: main.c tableau.h
	gcc -c main.c -W -Wall -o3 -lm -o main.o

clean:
	rm -rf *.o

mrproper: clean
	rm -rf tableau
