include ../Make.defines

PROGS = incr1 incr2

all:	${PROGS}

incr2:	incr2.o
		${CC} ${CFLAGS} -o $@ incr2.o ${LIBS}

incr1:	incr1.o
		${CC} ${CFLAGS} -o $@ incr1.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
