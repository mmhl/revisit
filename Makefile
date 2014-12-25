CC=g++
EXECUTABLE=revisit
CXXFLAGS=--std=c++11 -Wall -o $@
LDFLAGS=-lncursesw

all: $(EXECUTABLE) 
$(EXECUTABLE): main.o term.o world.o entity.o
	$(CC) $(CXXFLAGS) main.o term.o world.o entity.o $(LDFLAGS)
main.o: main.cpp
	$(CC) $(CXXFLAGS) -c main.cpp
term.o: term.cpp 
	$(CC) $(CXXFLAGS) -c term.cpp 
world.o: world.cpp
	$(CC) $(CXXFLAGS) -c world.cpp
entity.o: entity.cpp
	$(CC) $(CXXFLAGS) -c entity.cpp
