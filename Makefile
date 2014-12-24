CC=g++
EXECUTABLE=revisit
CXXFLAGS=--std=c++11 -Wall -o $(EXECUTABLE)
LDFLAGS=-lncurses

all: $(EXECUTABLE) 
$(EXECUTABLE): main.o term.o level.o
	$(CC) $(CXXFLAGS) main.o term.o level.o $(LDFLAGS)
main.o: main.cpp
	$(CC) $(CXXFLAGS) -c main.cpp
term.o: term.cpp term.h
	$(CC) $(CXXFLAGS) -c term.cpp term.h
level.o: level.cpp level.h
	$(CC) $(CXXFLAGS) -c level.cpp level.h

