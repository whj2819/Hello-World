PROGS = threadid exitstatus

CC = gcc
CFLAG = -Wall -g -lpthread
CLEANFILES= *.out *.o

all: ${PROGS}

threadid: threadid.o
	${CC} ${CFLAG} -o $@ threadid.c ${LIB}

exitstatus: exitstatus.o 
	${CC} ${CFLAG} -o $@ exitstatus.c ${LIB}




clean:
	rm -f ${PROGS} ${CLEANFILES}
