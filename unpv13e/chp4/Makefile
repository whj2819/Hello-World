include ../Make.defines

PROGS = daytimetcpsrv1 

all:    ${PROGS}

byteorder:    daytimetcpsrv1.o
	${CC} ${CFLAGS} -o $@ daytimetcpsrv1.o ${LIBS}
clean:
	rm -f ${PROGS} ${CLEANFILES}
