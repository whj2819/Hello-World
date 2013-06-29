include ../Make.defines

PROGS = mainpipe mainfifo server_main client_main

all:	${PROGS}

mainpipe:	mainpipe.o server.o client.o
		${CC} ${CFLAGS} -o $@ mainpipe.o server.o client.o ${LIBS}

mainfifo:	mainfifo.o server.o client.o
		${CC} ${CFLAGS} -o $@ mainfifo.o server.o client.o ${LIBS}

server_main:	server_main.o server.o
		${CC} ${CFLAGS} -o $@ server_main.o server.o ${LIBS}

client_main:	client_main.o client.o
		${CC} ${CFLAGS} -o $@ client_main.o client.o ${LIBS}
clean:
		rm -f ${PROGS} ${CLEANFILES}
