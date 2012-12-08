PROGS = test rename_t dir_recursion copy_recursion
CC = gcc
CFLAGS = -Wall -g
CLEANFILES = *.o *.out

all: ${PROGS}

test: test.o
	${CC} ${CFLAGS} -o $@ test.o ${LIBS}
rename_t: rename_t.o
	${CC} ${CFLAGS} -o $@ rename_t.o ${LIBS}
dir_recursion: dir_recursion.o
	${CC} ${CFLAGS} -o $@ dir_recursion.o ${LIBS}
copy_recursion: copy_recursion.o
	${CC} ${CFLAGS} -o $@ copy_recursion.o ${LIBS}
clean:
	rm -f ${PROGS} ${CLEANFILES}
