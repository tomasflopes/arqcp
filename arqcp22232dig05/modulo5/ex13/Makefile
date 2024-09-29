# A Makefile with variables and suffix rules

# Variables
INCLUDES = asm.h matrix_utils.h
SOURCES = main.c asm.s matrix_utils.c
OBJFILES = main.o asm.o matrix_utils.o
EXEC = prog

# Suffix rules
.SUFFIXES : .c .o .s

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
