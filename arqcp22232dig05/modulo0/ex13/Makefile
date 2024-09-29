# A Makefile with variables and suffix rules

# Variables
INCLUDES = line.h multiplication_table.h multiplication_table_n.h
SOURCES = line.c multiplication_table.c multiplication_table_n.c main.c
OBJFILES = line.o multiplication_table.o multiplication_table_n.o main.o
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
