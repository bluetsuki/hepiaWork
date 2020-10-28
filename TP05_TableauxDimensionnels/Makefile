all: tableau

fractions: tableau.o main.o
	gcc -o tableau tableau.o main.o  -lm -fsanitize=address -fsanitize=leak

fractions.o: tableau.c
	gcc -c tableau.c -W -Wall -O3 -lm -o tableau.o

main.o: main.c tableau.h
	gcc -c main.c -W -Wall -O3 -lm -o main.o

clean:
	rm -rf *.o

mrproper: clean
	rm -rf tableau
