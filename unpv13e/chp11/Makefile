include ../Make.defines

PROGS = hostent tmp 

all:    ${PROGS}

hostent:    hostent.o
	${CC} ${CFLAGS} -o $@ hostent.o ${LIBS}
tmp:    tmp.o
	${CC} ${CFLAGS} -o $@ tmp.o ${LIBS}
clean:
	rm -f ${PROGS} ${CLEANFILES}
