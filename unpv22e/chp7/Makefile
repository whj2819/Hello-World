include ../Make.defines

PROGS =  prodcons2 prodcons3

all:	${PROGS}

prodcons2:	prodcons2.o
		${CC} ${CFLAGS} -o $@ prodcons2.o ${LIBS}

prodcons3:	prodcons3.o
		${CC} ${CFLAGS} -o $@ prodcons3.o ${LIBS}




clean:
		rm -f ${PROGS} ${CLEANFILES}
