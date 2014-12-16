LDFLAGS=-lncurses
CC=g++
CXXFLAGS=--std=c++11 -Wall
EXECUTABLE=revisit

all: $(EXECUTABLE) 
$(EXECUTABLE): main.o term.o
	$(CC) $(CXXFLAGS) main.o term.o $(LDFLAGS)
main.o: main.cpp
	$(CC) $(CXXFLAGS) -c main.cpp
term.o: term.cpp term.h
	$(CC) $(CXXFLAGS) -c term.cpp term.h

