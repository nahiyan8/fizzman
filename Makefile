CC=g++
CPPFLAGS=-m64 -std=c++98 -Wpedantic -Wall -Wextra -g -pg
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

SRC=$(wildcard src/*.cpp)
OBJ=$(patsubst src/%.cpp,obj/%.o,$(SRC))

all: $(OBJ)
	mkdir -p bin/
	$(CC) $(LDFLAGS) $(OBJ) -o bin/fizzman

obj/%.o: src/%.cpp
	mkdir -p obj/
	$(CC) $(CPPFLAGS) -c $< -o $@

test:
	echo -e "\nCC=$(CC)\nCPPFLAGS=$(CPPFLAGS)\nLDFLAGS=$(LDFLAGS)\nSRC=$(SRC)\nOBJ=$(OBJ)\n"

clean:
	rm -rfv bin/* obj/*
