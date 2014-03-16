include ../Make.defines

PROGS = semcreate semunlink semwait sempost semgetvalue \
		prodcons2 prodcons3

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

prodcons2:	prodcons2.o
		${CC} ${CFLAGS} -o $@ prodcons2.o ${LIBS}

prodcons3:	prodcons3.o
		${CC} ${CFLAGS} -o $@ prodcons3.o ${LIBS}
clean:
		rm -f ${PROGS} ${CLEANFILES}
