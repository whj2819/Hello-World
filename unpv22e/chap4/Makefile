include ../Make.defines

PROGS = mainpipe	

all:	${PROGS}

mainpipe:	mainpipe.o
		${CC} ${CFLAGS} -o $@ mainpipe.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
