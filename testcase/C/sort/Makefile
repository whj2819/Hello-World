PROGS = main
CC = gcc
CFLAG = -Wall -g
CLEANFILES= *.out *.o

all: ${PROGS}

main: main.o
	${CC} ${CFLAG} -o $@ main.c ${LIB}



clean:
	rm -f ${PROGS} ${CLEANFILES}
