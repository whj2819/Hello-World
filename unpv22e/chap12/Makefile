include ../Make.defines

PROGS = incr2	

all:	${PROGS}

incr2:	incr2.o
		${CC} ${CFLAGS} -o $@ incr2.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
