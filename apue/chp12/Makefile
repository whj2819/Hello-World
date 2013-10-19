PROGS = makethread 
CC = gcc
CFLAG = -Wall -g -lpthread
CLEANFILES= *.out *.o

all: ${PROGS}

makethread: makethread.o
	${CC} ${CFLAG} -o $@ makethread.c ${LIB}

clean:
	rm -f ${PROGS} ${CLEANFILES}
