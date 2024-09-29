main: string_to_int.o main.o
	gcc string_to_int.o main.o -o main -lm
string_to_int.o: string_to_int.c
	gcc -g -Wall -c string_to_int.c -o string_to_int.o
main.o: main.c
	gcc -g -Wall -c main.c -o main.o
clean:
	rm -f *.o main
run: main
	./main
