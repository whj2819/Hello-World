include ../Make.defines

PROGS = mqcreatel mqcreate mqunlink mqgetattr

all:	${PROGS}

mqcreatel:	mqcreatel.o
		${CC} ${CFLAGS} -o $@ mqcreatel.o ${LIBS}

mqcreate:	mqcreate.o
		${CC} ${CFLAGS} -o $@ mqcreate.o ${LIBS}

mqunlink:   mqunlink.o
		${CC} ${CFLAGS} -o $@ mqunlink.o ${LIBS}

mqgetattr:	mqgetattr.o
		${CC} ${CFLAGS} -o $@ mqgetattr.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
