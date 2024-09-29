# A Makefile with variables and suffix rules

# Variables
INCLUDES = asm.h vec_diff.h
SOURCES = main.c asm.s vec_diff.s
OBJFILES = main.o asm.o vec_diff.o
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
