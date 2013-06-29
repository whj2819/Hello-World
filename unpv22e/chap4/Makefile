include ../Make.defines

PROGS = mainpipe mainfifo

all:	${PROGS}

mainpipe:	mainpipe.o server.o client.o
		${CC} ${CFLAGS} -o $@ mainpipe.o server.o client.o ${LIBS}

mainfifo:	mainfifo.o server.o client.o
		${CC} ${CFLAGS} -o $@ mainfifo.o server.o client.o ${LIBS}
clean:
		rm -f ${PROGS} ${CLEANFILES}
