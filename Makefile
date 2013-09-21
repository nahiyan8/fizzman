CC=g++
CPPFLAGS=-Wall -std=c++98 -g #-m64 -std=c++11 -pedantic -Wall -Wshadow -Wpointer-arith -Wcast-qual -Wno-switch -g -pg
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

SRC=$(wildcard src/*.cpp)
OBJ=$(patsubst src/%.cpp,obj/%.o,$(wildcard src/*.cpp))

all: $(OBJ)
	mkdir -p bin/
	$(CC) $(LDFLAGS) $(OBJ) -o bin/fizzman.bin

obj/%.o: src/%.cpp
	mkdir -p obj/
	$(CC) $(CPPFLAGS) -c $< -o $@

test:
	echo -e "\nCC=$(CC)\nLDFLAGS=$(LDFLAGS)\nCFLAGS=$(CFLAGS)\nSRC=$(SRC)\nOBJ=$(OBJ)\n"

clean:
	rm -rfv bin/* obj/*
