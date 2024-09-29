prog: main.o
	gcc -Wall -g main.o -o prog

main.o: main.c
	gcc -Wall -g -c main.c -o main.o

run: prog
	./prog

clean:
	rm -f *.o prog

