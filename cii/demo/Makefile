VPATH= src include

PROGS = main
CFLAGS = -Wall -g -I include 
CC = gcc


all: $(PROGS)

main: main.o assert.o except.o



.PHONY:clean

clean:
	rm -rf *.o $(PROGS)
