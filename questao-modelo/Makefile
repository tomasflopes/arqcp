# A Makefile with variables and suffix rules

# Variables
INCLUDES = decifra_chars.h decifra_string.h
SOURCES = decifra_chars.s decifra_string.s main.c
OBJFILES = decifra_chars.o decifra_string.o main.o
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
