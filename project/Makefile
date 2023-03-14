#
## Makefile to test oracle connection CSCI 375 TeamWon
## Taken from: CSCI 370: Sample Makefile for OCCI compilation
#

WFLAG = -Wall
CFLAG = -c
OFLAG = -o
IFLAG = -I
DFLAG = -ggdb

SOURCE = src
INCLUDE = include
BINARY = bin
TESTS = test
BUILDS = build

G = g++-4.9
CFLAGS = -I/usr/local/lib/Oracle/instantclient_11_2/sdk/include
LFLAGS = -L/usr/local/lib/Oracle/instantclient_11_2 -locci -lociei


all: ${BINARY}/exampleProg

${BINARY}/exampleProg: ${BUILDS}/databaseTest.o ${BUILDS}/main.o
	$(G) ${WFLAG} $(LFLAGS) ${BUILDS}/databaseTest.o ${BUILDS}/main.o ${OFLAG} ${BINARY}/exampleProg

${BUILDS}/databaseTest.o: ${SOURCE}/databaseTest.cpp ${INCLUDE}/databaseTest.hpp
	$(G) ${CFLAG} $(CFLAGS) ${IFLAG} ${INCLUDE} ${OFLAG} ${BUILDS}/databaseTest.o ${SOURCE}/databaseTest.cpp

${BUILDS}/main.o: ${SOURCE}/main.cpp ${INCLUDE}/databaseTest.hpp
	${CC} ${WFLAG} ${CFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${BUILDS}/main.o ${SOURCE}/main.cpp


run: ${BINARY}/exampleProg
	${BINARY}/exampleProg

.PHONY: clean

clean:
	rm -r ${BUILDS}/* ${BINARY}/*