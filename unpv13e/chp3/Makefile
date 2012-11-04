include ../Make.defines

PROGS = byteorder 

all:    ${PROGS}

byteorder:    byteorder.o
	${CC} ${CFLAGS} -o $@ byteorder.o ${LIBS}
clean:
	rm -f ${PROGS} ${CLEANFILES}
