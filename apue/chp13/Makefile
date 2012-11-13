

CC = gcc
CFLAG = -g -O2 -Wall
CLEANFILES = *.o *.out
PROGS = main01 main02

all: ${PROGS}

main01:daemonize.o main.o
	${CC} ${CFLAGS} -o $@ daemonize.o main01.o
main02: main.o daemonize.o already_running.o
	${CC} ${CFLAGS} -o $@ daemonize.o already_runnig.o main02.o 

clean:
	rm -rf ${PROGS} ${CLEANFILES}


