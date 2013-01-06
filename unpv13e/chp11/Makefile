include ../Make.defines

PROGS = hostent daytimetcpcli1 tmp 

all:    ${PROGS}

hostent:    hostent.o
	${CC} ${CFLAGS} -o $@ hostent.o ${LIBS}
daytimetcpcli1:    daytimetcpcli1.o
	${CC} ${CFLAGS} -o $@ daytimetcpcli1.o ${LIBS}
tmp:    tmp.o
	${CC} ${CFLAGS} -o $@ tmp.o ${LIBS}
clean:
	rm -f ${PROGS} ${CLEANFILES}
