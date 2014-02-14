CC=g++
CPPFLAGS=-std=c++98 -Wall -Wextra -m64 -O3 -g -pg
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

SRCS=$(wildcard src/*.cpp)
OBJS=$(patsubst src/%.cpp,obj/%.o,$(SRCS))

all: $(OBJS)       | bin/
	$(CC) $(LDFLAGS) $(OBJS) -o bin/fizzman

obj/%.o: src/%.cpp | obj/
	$(CC) $(CPPFLAGS) -c $< -o $@

bin/ obj/:
	mkdir -p "$@"

clean:
	rm -fv bin/* obj/*
