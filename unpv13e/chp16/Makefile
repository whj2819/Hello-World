include ../Make.defines

PROGS =	tcpcli02 

all:	${PROGS}


tcpcli02:	tcpcli02.o strclinonb.o
		${CC} ${CFLAGS} -o $@ tcpcli02.o strclinonb.o ${LIBS} 

#tcpcli02:	tcpcli02.o strclinonb.o gf_time.o
#		${CC} ${CFLAGS} -o $@ tcpcli02.o strclinonb.o gf_time.o

clean:
		rm -f ${PROGS} ${CLEANFILES}
