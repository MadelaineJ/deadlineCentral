CXX = g++
CXXFLAGS = -Wall -std=c++11

all: main

main: main.o StateMachine.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp StateMachine.h
	$(CXX) $(CXXFLAGS) -c $<

StateMachine.o: StateMachine.cpp StateMachine.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f main *.o