PROGS = length_of_type
CC = gcc
CFLAG = -Wall -g
CLEANFILES= *.out *.o

all: ${PROGS}

length_of_type: length_of_type.o
	${CC} ${CFLAG} -o $@ length_of_type.c ${LIB}



clean:
	rm -f ${PROGS} ${CLEANFILES}
