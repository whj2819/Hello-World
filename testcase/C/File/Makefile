PROGS = rename_t 
CC = gcc
CFLAGS = -Wall -g
CLEANFILES = *.o *.out

all: ${PROGS}

byteorder: rename_t.o
	${CC} ${CFLAGS}-o $@ rename_t.o ${LIBS}
clean:
	rm -f ${PROGS} ${CLEANFILES}
