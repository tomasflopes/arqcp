# A Makefile with variables and suffix rules

# Variables
INCLUDES = sort_without_reps.h
SOURCES = main.c sort_without_reps.c ../ex07/print_array.c
OBJFILES = main.o sort_without_reps.o ../ex07/print_array.o
EXEC = main

# Suffix rules
.SUFFIXES : .c .o

# How to build an object .o from a code file .c ; $< -- file name
.c.o:
	gcc -Wall -g -c $<

${EXEC}: ${OBJFILES}
	gcc -Wall -g -o ${EXEC} ${OBJFILES}

${OBJFILES}: ${SOURCES} ${INCLUDES}

run: ${EXEC}
	./${EXEC}

clean:
	rm -f ${OBJFILES} ${EXEC}
