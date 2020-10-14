array:	array.o main.o
	gcc array.o main.o -o array -lm
array.o: array.c array.h
	gcc -Wall -Wextra -c array.c -lm
main.o: main.c
	gcc -Wall -Wextra -c main.c -lm
clean:
	rm -f *.o array
rebuild: clean array
