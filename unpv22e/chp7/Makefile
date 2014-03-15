include ../Make.defines

PROGS =  prodcons2 prodcons3 prodcons6

all:	${PROGS}

prodcons2:	prodcons2.o
		${CC} ${CFLAGS} -o $@ prodcons2.o ${LIBS}

prodcons3:	prodcons3.o
		${CC} ${CFLAGS} -o $@ prodcons3.o ${LIBS}

prodcons6:	prodcons6.o
		${CC} ${CFLAGS} -o $@ prodcons6.o ${LIBS}



clean:
		rm -f ${PROGS} ${CLEANFILES}
