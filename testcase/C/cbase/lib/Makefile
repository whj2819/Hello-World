PROGS = strings
CC = gcc
CFLAG = -Wall -g
CLEANFILES= *.out *.o

all: ${PROGS}

strings: strings.o
	${CC} ${CFLAG} -o $@ main.c strings.c ${LIB}



clean:
	rm -f ${PROGS} ${CLEANFILES}
