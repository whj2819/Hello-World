include ../Make.defines

PROGS = incr1 incr2 incr3

all:	${PROGS}

incr1:	incr1.o
		${CC} ${CFLAGS} -o $@ incr1.o ${LIBS}

incr2:	incr2.o
		${CC} ${CFLAGS} -o $@ incr2.o ${LIBS}

incr3:	incr3.o
		${CC} ${CFLAGS} -o $@ incr3.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
