include ../Make.defines

PROGS = semcreate semunlink semwait sempost semgetvalue

all:	${PROGS}


semcreate:	semcreate.o
		${CC} ${CFLAGS} -o $@ semcreate.o ${LIBS}

semunlink:	semunlink.o
		${CC} ${CFLAGS} -o $@ semunlink.o ${LIBS}

semwait:	semwait.o
		${CC} ${CFLAGS} -o $@ semwait.o ${LIBS}

sempost:	sempost.o
		${CC} ${CFLAGS} -o $@ sempost.o ${LIBS}

semgetvalue:	semgetvalue.o
		${CC} ${CFLAGS} -o $@ semgetvalue.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
