include ../Make.defines

PROGS = test01 test02

all:    ${PROGS}

test01:    test01.o
	${CC} ${CFLAGS} -o $@ test01.o ${LIBS}
test02:    test02.o
	${CC} ${CFLAGS} -o $@ test02.o ${LIBS}
clean:
	rm -f ${PROGS} ${CLEANFILES}
