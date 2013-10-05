include ../Make.defines

PROGS = shmcreate shmunlink shmwrite shmread test3\
		server1 client1

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

server1:	server1.o
		${CC} ${CFLAGS} -o $@ server1.o ${LIBS}

client1:	client1.o
		${CC} ${CFLAGS} -o $@ client1.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}

