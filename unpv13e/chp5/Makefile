include ../Make.defines

PROGS = tcpserv01 tcpserv02 tcpcli01 
LIBS = ../libunp.a

all:    ${PROGS}

tcpserv01:    tcpserv01.o
	${CC} ${CFLAGS} -o $@ tcpserv01.o ${LIBS}
tcpserv02:    tcpserv02.o sigchldwait.o
	${CC} ${CFLAGS} -o $@ tcpserv02.o sigchldwait.o ${LIBS}
tcpcli01:    tcpcli01.o 
	${CC} ${CFLAGS} -o $@ tcpcli01.o  ${LIBS}
clean:
	rm -f ${PROGS} ${CLEANFILES}
