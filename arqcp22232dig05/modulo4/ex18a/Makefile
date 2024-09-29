# A Makefile with variables and suffix rules

# Variables
INCLUDES = changes.h
SOURCES = main.c changes.c
OBJFILES = main.o changes.o
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
