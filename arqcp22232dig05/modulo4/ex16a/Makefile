# A Makefile with variables and suffix rules

# Variables
INCLUDES = join_bits.h
SOURCES = main.c join_bits.c
OBJFILES = main.o join_bits.o
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
