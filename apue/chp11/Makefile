PROGS = threadid exitstatus cleanup

CC = gcc
CFLAG = -Wall -g -lpthread
CLEANFILES= *.out *.o

all: ${PROGS}

threadid: threadid.o
	${CC} ${CFLAG} -o $@ threadid.c ${LIB}

exitstatus: exitstatus.o 
	${CC} ${CFLAG} -o $@ exitstatus.c ${LIB}

cleanup: cleanup.o 
	${CC} ${CFLAG} -o $@ cleanup.c ${LIB}




clean:
	rm -f ${PROGS} ${CLEANFILES}
