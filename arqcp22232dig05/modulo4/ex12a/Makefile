# A Makefile with variables and suffix rules

# Variables
INCLUDES = count_bits_one.h
SOURCES = main.c count_bits_one.c
OBJFILES = main.o count_bits_one.o
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
