# A Makefile with variables and suffix rules

# Variables
INCLUDES = fill_student.h student.h update_address.h update_grades.h print_array.h
SOURCES = update_address.s fill_student.c update_grades.s print_array.c main.c
OBJFILES = update_address.o fill_student.o update_grades.o print_array.o main.o
EXEC = prog

# Suffix rules
.SUFFIXES : .c .o

.s.o:
	gcc -Wall -g -c $<

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
