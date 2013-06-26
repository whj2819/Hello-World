include ../Make.defines

PROGS = shmcreate shmunlink shmwrite shmread test3	

all:	${PROGS}

shmcreate:	shmcreate.o
		${CC} ${CFLAGS} -o $@ shmcreate.o ${LIBS}

shmunlink:	shmunlink.o
		${CC} ${CFLAGS} -o $@ shmunlink.o ${LIBS}

shmwrite:	shmwrite.o
		${CC} ${CFLAGS} -o $@ shmwrite.o ${LIBS}

shmread:	shmread.o
		${CC} ${CFLAGS} -o $@ shmread.o ${LIBS}
test3:	test3.o
		${CC} ${CFLAGS} -o $@ test3.o ${LIBS}
clean:
		rm -f ${PROGS} ${CLEANFILES}
