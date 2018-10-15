cc=gcc
all: build build/GreenThreads.o

build:
	mkdir build
	mkdir build/tests

build/GreenThreads.o: src/GreenThreads.c
	$(cc) -c -o build/GreenThreads.o src/GreenThreads.c

clean:
	rm -rf ./build

include all-tests.mk