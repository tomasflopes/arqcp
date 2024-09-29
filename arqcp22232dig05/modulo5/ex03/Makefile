# A Makefile with variables and suffix rules

# Variables
INCLUDES = student.h fill_student.h print_array.h
SOURCES = fill_student.c print_array.c main.c
OBJFILES = fill_student.o print_array.o main.o
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
