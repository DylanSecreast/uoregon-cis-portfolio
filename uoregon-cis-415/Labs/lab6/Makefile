CC=gcc
CFLAGS= -W -Wall

all: bbcat

bbcat: BoundedBuffer.o bbcat.o
	$(CC) $(CFLAGS) -o bbcat BoundedBuffer.o bbcat.o -lpthread

bbcat.o: bbcat.c BoundedBuffer.h

BoundedBuffer.o: BoundedBuffer.c BoundedBuffer.h

clean:
	rm -f *.o bbcat
