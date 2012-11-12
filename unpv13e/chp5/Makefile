include ../Make.defines

PROGS = tcpserv01 tcpcli01 str_echo str_cli 

all:    ${PROGS}

tcpserv01:    tcpserv01.o
	${CC} ${CFLAGS} -o $@ tcpserv01.o ${LIBS}
tcpcli01:    tcpcli01.o
	${CC} ${CFLAGS} -o $@ tcpcli01.o ${LIBS}
str_echo:    str_echo.o
	${CC} ${CFLAGS} -o $@ str_echo.o ${LIBS}
str_cli:    str_cli.o
	${CC} ${CFLAGS} -o $@ str_cli.o ${LIBS}
clean:
	rm -f ${PROGS} ${CLEANFILES}
