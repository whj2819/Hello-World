include ../Make.defines

PROGS = tcpserv01 tcpcli01 

all:    ${PROGS}

tcpserv01:    tcpserv01.o str_echo.o
	${CC} ${CFLAGS} -o $@ tcpserv01.o str_echo.o ${LIBS}
tcpcli01:    tcpcli01.o str_cli.o
	${CC} ${CFLAGS} -o $@ tcpcli01.o str_cli.o ${LIBS}
clean:
	rm -f ${PROGS} ${CLEANFILES}
