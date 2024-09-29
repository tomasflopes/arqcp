# A Makefile with variables and suffix rules

# Variables
INCLUDES = find_all_words.h find_word.c str_len.h compare_ignore_case.h 
SOURCES = find_all_words.c find_word.c str_len.c compare_ignore_case.c main.c
OBJFILES = find_all_words.o find_word.o str_len.o compare_ignore_case.o main.o
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
