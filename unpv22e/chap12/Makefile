include ../Make.defines

PROGS = incr1 incr2 incr3 incr_map_anon incr_dev_zero

all:	${PROGS}

incr1:	incr1.o
		${CC} ${CFLAGS} -o $@ incr1.o ${LIBS}

incr2:	incr2.o
		${CC} ${CFLAGS} -o $@ incr2.o ${LIBS}

incr3:	incr3.o
		${CC} ${CFLAGS} -o $@ incr3.o ${LIBS}

incr_map_anon: incr_map_anon.o
		${CC} ${CFLAGS} -o $@ incr_map_anon.o ${LIBS}

incr_dev_zero:	incr_dev_zero.o
		${CC} ${CFLAGS} -o $@ incr_dev_zero.o ${LIBS}
clean:
		rm -f ${PROGS} ${CLEANFILES}
