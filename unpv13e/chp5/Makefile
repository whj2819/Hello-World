include ../Make.defines

PROGS = tcpserv01 tcpserv02 tcpserv03 tcpcli01 \
		tcpcli04
LIBS = ../libunp.a

all:    ${PROGS}

tcpserv01:    tcpserv01.o
	${CC} ${CFLAGS} -o $@ tcpserv01.o ${LIBS}
tcpserv02:    tcpserv02.o sigchldwait.o
	${CC} ${CFLAGS} -o $@ tcpserv02.o sigchldwait.o ${LIBS}
tcpserv03:    tcpserv03.o sigchldwait.o
	${CC} ${CFLAGS} -o $@ tcpserv03.o sigchldwait.o ${LIBS}
tcpcli01:    tcpcli01.o 
	${CC} ${CFLAGS} -o $@ tcpcli01.o  ${LIBS}
tcpcli04:    tcpcli04.o 
	${CC} ${CFLAGS} -o $@ tcpcli04.o  ${LIBS}
clean:
	rm -f ${PROGS} ${CLEANFILES}
