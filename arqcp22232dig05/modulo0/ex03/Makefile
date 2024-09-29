main: fill_array.o main.o
	gcc fill_array.o main.o -o main
fill_array.o: fill_array.c
	gcc -g -Wall -c fill_array.c -o fill_array.o
main.o: main.c
	gcc -g -Wall -c main.c -o main.o
clean:
	rm -f *.o main
run: main
	./main
