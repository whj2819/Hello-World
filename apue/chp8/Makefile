PROGS = demo1 demo2 demo5 demo8 echoall identify
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
demo8: demo8.o
	${CC} ${CFLAG} -o $@ demo8.c ${LIB}
echoall: echoall.o
	${CC} ${CFLAG} -o $@ echoall.c ${LIB}
tmp: tmp.o
	${CC} ${CFLAG} -o $@ tmp.c ${LIB}
identify: identify.o
	${CC} ${CFLAG} -o $@ identify.c ${LIB}



clean:
	rm -f ${PROGS} ${CLEANFILES}
