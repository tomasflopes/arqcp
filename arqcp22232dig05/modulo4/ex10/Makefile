# A Makefile with variables and suffix rules

# Variables
INCLUDES = asm.h call_incr.h
SOURCES = main.c asm.s call_incr.s
OBJFILES = main.o asm.o call_incr.o
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
