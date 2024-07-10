CC= gcc
CFLAGS= -g -Wall -std=gnu99 
LD= gcc
LDFLAGS = -L.
AR= ar
ARFLAGS= rcs

all: greet.dyn greet.stc

library.o: library.c 
	$(CC) $(CFLAGS) -c -o library.o library.c

main.o: main.c 
	$(CC) $(CFLAGS) -c -o main.o main.c

libgreet.so: library.o
	$(LD) -shared -o libgreet.so library.o

libgreet.a : library.o
	$(AR) $(ARFLAGS) libgreet.a library.o

greet.dyn: main.o libgreet.so
	$(LD) $(LDFLAGS) -o greet.dyn main.o -lgreet

greet.stc: main.o libgreet.a
	$(LD) $(LDFLAGS) -static -o greet.stc main.o -lgreet