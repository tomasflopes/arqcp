# A Makefile with variables and suffix rules

# Variables
INCLUDES = f.h f2.h f3.h f4.h
SOURCES = main.c f.s f2.s f3.s f4.s
OBJFILES = main.o f.o f2.o f3.o f4.o 
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
