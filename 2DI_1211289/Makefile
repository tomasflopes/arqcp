# A Makefile with variables and suffix rules

# Variables
INCLUDES = device_max.h global_max.h device_info.h
SOURCES = main.c global_max.s device_max.s
OBJFILES = main.o global_max.o device_max.o
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
