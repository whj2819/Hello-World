include ../Make.defines

PROGS = mainpipe	

all:	${PROGS}

mainpipe:	mainpipe.o server.o client.o
		${CC} ${CFLAGS} -o $@ mainpipe.o server.o client.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
