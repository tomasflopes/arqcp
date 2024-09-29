# A Makefile with variables and suffix rules

# Variables
INCLUDES = reset_bit.h
SOURCES = main.c reset_bit.c
OBJFILES = main.o reset_bit.o
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
