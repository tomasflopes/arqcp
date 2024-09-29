# A Makefile with variables and suffix rules

# Variables
INCLUDES = group.h count_bits_one.h approved_semester.h
SOURCES = approved_semester.s count_bits_one.s main.c
OBJFILES = approved_semester.o count_bits_one.o main.o
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
