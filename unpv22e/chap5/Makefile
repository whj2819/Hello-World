include ../Make.defines

PROGS = mqcreatel mqcreate mqunlink mqgetattr mqsend mqreceive \
		mqsysconf

all:	${PROGS}

mqcreatel:	mqcreatel.o
		${CC} ${CFLAGS} -o $@ mqcreatel.o ${LIBS}

mqcreate:	mqcreate.o
		${CC} ${CFLAGS} -o $@ mqcreate.o ${LIBS}

mqunlink:   mqunlink.o
		${CC} ${CFLAGS} -o $@ mqunlink.o ${LIBS}

mqgetattr:	mqgetattr.o
		${CC} ${CFLAGS} -o $@ mqgetattr.o ${LIBS}

mqsend:	mqsend.o
		${CC} ${CFLAGS} -o $@ mqsend.o ${LIBS}

mqreceive:	mqreceive.o
		${CC} ${CFLAGS} -o $@ mqreceive.o ${LIBS}

mqsysconf:	mqsysconf.o
		${CC} ${CFLAGS} -o $@ mqsysconf.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
