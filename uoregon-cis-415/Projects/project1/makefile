CC=gcc
CFLAGS= -W -Wall
#CFLAGS= -W -Wall -g
LDFLAGS=
#LDFLAGS= -g
PROGS= 1 2 3 4

all: $(PROGS)

1: uspsv1.o p1fxns.o 
	cc $(LDFLAGS) -o uspsv1 uspsv1.o p1fxns.o 

2: uspsv2.o p1fxns.o
	cc $(LDFLAGS) -o uspsv2 uspsv2.o p1fxns.o

3: uspsv3.o p1fxns.o
	cc $(LDFLAGS) -o uspsv3 uspsv3.o p1fxns.o

4: uspsv4.o p1fxns.o
	cc $(LDFLAGS) -o uspsv4 uspsv4.o p1fxns.o
test: test.o p1fxns.o
	cc $(LDFLAGS) -o test test.o p1fxns.o

test.o: test.c p1fxns.h
uspsv1.o: uspsv1.c p1fxns.h
uspsv2.o: uspsv2.c p1fxns.h
uspsv3.o: uspsv3.c p1fxns.h
uspsv4.o: uspsv4.c p1fxns.h
p1fxns.o: p1fxns.h p1fxns.c


clean:
	rm -f *~ *.o $(PROGS)
