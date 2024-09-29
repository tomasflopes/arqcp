# A Makefile with variables and suffix rules

# Variables
INCLUDES = sum_multiples_x.h
SOURCES = main.c sum_multiples_x.c
OBJFILES = main.o sum_multiples_x.o
EXEC = prog

# Suffix rules
.SUFFIXES : .c .o

.c.o:
	gcc -Wall -g -c $<

${EXEC}: ${OBJFILES}
	gcc -Wall -g -o ${EXEC} ${OBJFILES}

${OBJFILES}: ${SOURCES} ${INCLUDES}

run: ${EXEC}
	./${EXEC}

clean:
	rm -f ${OBJFILES} ${EXEC}
