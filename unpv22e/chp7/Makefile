include ../Make.defines

PROGS =  producons2

all:	${PROGS}

prodcons2:	prodcons2.o
		${CC} ${CFLAGS} -o $@ prodcons2.o ${LIBS}




clean:
		rm -f ${PROGS} ${CLEANFILES}
