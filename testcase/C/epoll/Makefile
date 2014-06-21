PROGS=server client

CLEANFILES=*.out *.o
CC=gcc
CFLAGS=-Wall -g


all:${PROGS}


server:server.o
	${CC} ${CFLAGS} -o $@ server.o
client:client.o
	${CC} ${CFLAGS} -o $@ client.o


.PHONY:clean
clean:
	rm -rf ${PROGS} ${CLEANFILES}
