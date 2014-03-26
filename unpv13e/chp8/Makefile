include ../Make.defines

PROGS =	udpcli01 udpcli02 udpserv01 

all:	${PROGS}

udpcli01:	udpcli01.o
		${CC} ${CFLAGS} -o $@ udpcli01.o ${LIBS}

udpcli02:	udpcli02.o
		${CC} ${CFLAGS} -o $@ udpcli02.o ${LIBS}

udpserv01:	udpserv01.o
		${CC} ${CFLAGS} -o $@ udpserv01.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
