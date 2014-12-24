CC=g++
EXECUTABLE=revisit
CXXFLAGS=--std=c++11 -Wall -o $@
LDFLAGS=-lncurses

all: $(EXECUTABLE) 
$(EXECUTABLE): main.o term.o level.o
	$(CC) $(CXXFLAGS) main.o term.o level.o $(LDFLAGS)
main.o: main.cpp
	$(CC) $(CXXFLAGS) -c main.cpp
term.o: term.cpp 
	$(CC) $(CXXFLAGS) -c term.cpp 
level.o: level.cpp 
	$(CC) $(CXXFLAGS) -c level.cpp 

