include ../Make.defines

PROGS = mqcreatel

all:	${PROGS}

mqcreatel:	mqcreatel.o
		${CC} ${CFLAGS} -o $@ mqcreatel.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
