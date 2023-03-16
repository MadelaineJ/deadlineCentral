LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

OPTIONS = -Wall

TARGETS = main main.o statemachine.o

all: main

main: main.o statemachine.o
	@echo "building executable files"
	g++ $(OPTIONS) $^ -o $@ $(LINKER_FLAGS)

main.o: main.cpp statemachine.cpp
	@echo "building main object"
	g++ -c $(OPTIONS) $< -o $@ $(LINKER_FLAGS)

statemachine.o: statemachine.cpp globals.h
	@echo "Building statemachine"
	g++ -c $(OPTIONS) $< -o $@ $(LINKER_FLAGS)

clean:
	rm -f $(TARGETS)
