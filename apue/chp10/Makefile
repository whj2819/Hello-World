PROGS = demo1 demo2 demo3 demo11 suspend1 suspend2

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

demo11: demo11.o
	${CC} ${CFLAG} -o $@ demo11.c ${LIB}

suspend1: suspend1.o
	${CC} ${CFLAG} -o $@ suspend1.c ${LIB}

suspend2: suspend2.o
	${CC} ${CFLAG} -o $@ suspend2.c ${LIB}

clean:
	rm -f ${PROGS} ${CLEANFILES}
