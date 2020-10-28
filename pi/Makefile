
all: fractions

fractions: fractions.o main.o
	gcc -o fractions fractions.o main.o  -lm -fsanitize=address -fsanitize=leak

fractions.o: fractions.c
	gcc -c fractions.c -W -Wall -O3 -lm -o fractions.o

main.o: main.c fractions.h
	gcc -c main.c -W -Wall -O3 -lm -o main.o

clean:
	rm -rf *.o

mrproper: clean
	rm -rf fractions
				