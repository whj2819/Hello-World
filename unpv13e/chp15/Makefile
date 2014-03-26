include ../Make.defines

PROGS =	unixbind mycat openfile

all:	${PROGS}


unixbind:	unixbind.o
		${CC} ${CFLAGS} -o $@ unixbind.o ${LIBS}

mycat:	mycat.o myopen.o read_fd.o
		${CC} ${CFLAGS} -o $@ mycat.o myopen.o read_fd.o

openfile:	openfile.o write_fd.o
		${CC} ${CFLAGS} -o $@ openfile.o  write_fd.o

clean:
		rm -f ${PROGS} ${CLEANFILES}
