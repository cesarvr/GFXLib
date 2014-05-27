
CC=g++
CFLAGS=-c -Wall

all: gfxlib

gfxlib: main.o Vector.o Matrix3.o Quaternion.o
	$(CC) main.o Vector.o Matrix3.o Quaternion.o -o gfxlib


main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Vector.o: Vector.cpp
	$(CC) $(CFLAGS) Vector.cpp

Matrix3.o: Matrix3.cpp
	$(CC) $(CFLAGS) Matrix3.cpp

Quaternion.o: Quaternion.cpp
	$(CC) $(CFLAGS) Quaternion.cpp

clean:
	rm -rf *o gfxlib
