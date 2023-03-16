#
## Makefile to test oracle connection CSCI 375 TeamWon
## Taken from: CSCI 370: Sample Makefile for OCCI compilation
#
.EXPORT_ALL_VARIABLES:
	export ORACLE_BASE=/.jonesme/oracle-libraries
	export ORACLE_HOME=/.jonesme/oracle-libraries/instantclient_21_9
	export LD_LIBRARY_PATH=$ORACLE_HOME
	export PATH=$ORACLE_HOME:/usr/local/bin:/bin:/usr/bin:/usr/X11R6/bin:~/bin

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

CC = g++
#Specifies the locations of occi.h headers
CFLAGS = -I $(ORACLE_HOME)/sdk/include
#Specifies the location of oracle programs needed to connect
LFLAGS = -L $(ORACLE_HOME) -locci -m64 -lclntsh
#Resolves "invalid password" bug
AUTH = -D_GLIBCXX_USE_CXX11_ABI=0


all: ${BINARY}/exampleProg

${BINARY}/exampleProg: ${BUILDS}/databaseTest.o ${BUILDS}/main.o
	${CC} ${WFLAG} ${OFLAG} ${BINARY}/exampleProg ${BUILDS}/databaseTest.o ${BUILDS}/main.o $(LFLAGS)

${BUILDS}/databaseTest.o: ${SOURCE}/databaseTest.cpp ${INCLUDE}/databaseTest.hpp
	${CC} ${CFLAG} $(AUTH) ${CFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${BUILDS}/databaseTest.o ${SOURCE}/databaseTest.cpp $(CFLAGS)

${BUILDS}/main.o: ${SOURCE}/main.cpp ${INCLUDE}/databaseTest.hpp
	${CC} ${CFLAG} $(AUTH) ${WFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${BUILDS}/main.o ${SOURCE}/main.cpp ${CFLAG} 


run: ${BINARY}/exampleProg ${SOURCE}/databaseTest.cpp ${SOURCE}/main.cpp
	${BINARY}/exampleProg

.PHONY: clean

clean:
	rm -rf ${BINARY}/* 
	rm -rf ${BUILDS}/*