CC=gcc
CFLAGS=-I.

all:
	$(CC) jiggler.c -o nickjiggler $(CFLAGS) 
