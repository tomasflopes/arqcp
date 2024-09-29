# A Makefile with variables and suffix rules

# Variables
INCLUDES = matrix_utils.h add_matrixes.h
SOURCES = matrix_utils.c add_matrixes.c main.c
OBJFILES = matrix_utils.o add_matrixes.o main.o
EXEC = prog

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
