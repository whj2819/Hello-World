PROGS = tmp demo1 demo2 demo5
CC = gcc
CFLAG = -Wall -g
CLEANFILES= *.out *.o

all: ${PROGS}

demo1: demo1.o
	${CC} ${CFLAG} -o $@ demo1.c ${LIB}
demo2: demo2.o
	${CC} ${CFLAG} -o $@ demo2.c ${LIB}
demo5: demo5.o
	${CC} ${CFLAG} -o $@ demo5.c ${LIB}
tmp: tmp.o
	${CC} ${CFLAG} -o $@ tmp.c ${LIB}



clean:
	rm -f ${PROGS} ${CLEANFILES}
