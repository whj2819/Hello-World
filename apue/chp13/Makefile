

CC = gcc
CFLAG = -g -O2 -Wall
CLEANFILES = *.o *.out
PROGS = main

all: ${PROGS}

main:daemonize.o main.o
	${CC} ${CFLAGS} -o $@ daemonize.o main.o

clean:
	rm -rf ${PROGS} ${CLEANFILES}


