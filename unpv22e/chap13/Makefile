include ../Make.defines

PROGS = shmcreate	

all:	${PROGS}

shmcreate:	shmcreate.o
		${CC} ${CFLAGS} -o $@ shmcreate.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
