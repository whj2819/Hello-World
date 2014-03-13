include ../Make.defines

PROGS = mqcreate

all:	${PROGS}

mqcreate:	mqcreate.o
		${CC} ${CFLAGS} -o $@ mqcreate.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
