PROGS = demo2 
CC = gcc
CFLAG = -Wall -g
CLEANFILES= *.out *.o

all: ${PROGS}

demo2: demo2.o
	${CC} ${CFLAG} -o $@ demo2.c ${LIB}

clean:
	rm -f ${PROGS} ${CLEANFILES}
