include ../Make.defines

PROGS =	unixbind 

all:	${PROGS}


unixbind:	unixbind.o
		${CC} ${CFLAGS} -o $@ unixbind.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
