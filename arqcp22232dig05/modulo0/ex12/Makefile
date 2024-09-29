program: main.o size_string.o
	gcc -o program main.o size_string.o

main.o: main.c
	gcc -Wall -c main.c -o main.o

size_string.o: size_string.c
	gcc -Wall -c size_string.c -o size_string.o

clean:
	rm -f *.o program

run: program
	./program
