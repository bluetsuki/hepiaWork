fraction:	fraction.o main.o
	gcc fraction.o main.o -o fraction -lm
fraction.o: fraction.c fraction.h
	gcc -Wall -Wextra -c fraction.c -lm
main.o: main.c
	gcc -Wall -Wextra -c main.c -lm
clean:
	rm -f *.o fraction
rebuild: clean fraction
