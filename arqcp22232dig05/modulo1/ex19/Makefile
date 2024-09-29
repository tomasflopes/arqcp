# A Makefile with variables and suffix rules

# Variables
INCLUDES = find_word.h compare_ignore_case.h str_len.h 
SOURCES = find_word.c compare_ignore_case.c str_len.c main.c
OBJFILES = find_word.o compare_ignore_case.o str_len.o main.o
EXEC = main

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
