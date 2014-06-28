
CC=gcc
CFLAGS=-Wall -g 
CLEANFILES=*.out *.tmp *.swp *.o *.core

progs=a b c d e f g

all:${progs}
a:a.o
	${CC} ${CFLAGS} -o $@ a.c

b:b.o
	${CC} ${CFLAGS} -o $@ b.c

.PHONY :clean
clean:
	rm -rf ${progs} ${CLEANFILES}
