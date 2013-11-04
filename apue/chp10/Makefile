PROGS = demo1 demo2 demo3
CC = gcc
CFLAG = -Wall -g
CLEANFILES= *.out *.o

all: ${PROGS}

demo1: demo1.o
	${CC} ${CFLAG} -o $@ demo1.c ${LIB}

demo2: demo2.o
	${CC} ${CFLAG} -o $@ demo2.c ${LIB}

demo3: demo3.o
	${CC} ${CFLAG} -o $@ demo3.c ${LIB}

clean:
	rm -f ${PROGS} ${CLEANFILES}
