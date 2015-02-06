CC=g++
EXECUTABLE=revisit
CXXFLAGS=--std=c++11 -Wall -o $@
LDFLAGS=-lncursesw

all: $(EXECUTABLE) 
$(EXECUTABLE): main.o term.o game.o err.o keyboard.o Win.o TermWin.o
	$(CC) $(CXXFLAGS) main.o term.o game.o err.o keyboard.o Win.o TermWin.o $(LDFLAGS)
main.o: main.cpp
	$(CC) $(CXXFLAGS) -c main.cpp
term.o: term.cpp 
	$(CC) $(CXXFLAGS) -c term.cpp 
Win.o:	Win.cpp
	$(CC) $(CXXFLAGS) -c Win.cpp
TermWin.o: TermWin.cpp
	$(CC) $(CXXFLAGS) -c TermWin.cpp
game.o: game.cpp
	$(CC) $(CXXFLAGS) -c game.cpp
err.o: err.cpp
	$(CC) $(CXXFLAGS) -c err.cpp
keyboard.o: keyboard.cpp
	$(CC) $(CXXFLAGS) -c keyboard.cpp


.PHONY: clean
clean:
	rm -Rf *.o $(EXECUTABLE)