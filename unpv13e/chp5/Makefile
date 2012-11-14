include ../Make.defines

PROGS = tcpserv01 tcpcli01 
LIBS = ../libunp.a

all:    ${PROGS}

tcpserv01:    tcpserv01.o
	${CC} ${CFLAGS} -o $@ tcpserv01.o ${LIBS}
tcpserv02:    tcpserv02.o sigchildwait.o
	${CC} ${CFLAGS} -o $@ tcpserv01.o sigchildwait.o ${LIBS}
tcpcli01:    tcpcli01.o 
	${CC} ${CFLAGS} -o $@ tcpcli01.o  ${LIBS}
clean:
	rm -f ${PROGS} ${CLEANFILES}
