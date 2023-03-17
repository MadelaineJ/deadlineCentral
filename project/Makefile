#
# Makefile to build a Deadline Central (and a hello world database connection file)

# Required so that deadline cental uses the latest version of oracle for compilation
.EXPORT_ALL_VARIABLES:
	export ORACLE_BASE=/srv/export/CSCI375a/oracle-libraries/
	export ORACLE_HOME=/srv/export/CSCI375a/oracle-libraries/instantclient_21_9/
	export LD_LIBRARY_PATH=$ORACLE_HOME
	export PATH=$ORACLE_HOME:/usr/local/bin:/bin:/usr/bin:/usr/X11R6/bin:~/bin

# Flags
WFLAG = -Wall
CFLAG = -c
OFLAG = -o
IFLAG = -I
DFLAG = -ggdb


# folders
SOURCE = src
DATALAYER = datalayer
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


all: ${BINARY}/exampleProg ${BINARY}/deadlineCentral


# deadline central
${BINARY}/deadlineCentral: ${BUILDS}/main.o ${BUILDS}/controllerDb.o ${BUILDS}/mainDb.o ${BUILDS}/subscriptionDb.o
	${CC} ${WFLAG} ${OFLAG} ${BINARY}/deadlineCentral ${BUILDS}/controllerDb.o ${BUILDS}/subscriptionDb.o ${BUILDS}/mainDb.o ${BUILDS}/main.o $(LFLAGS)



# Data Layer
${BUILDS}/controllerDb.o: ${SOURCE}/${DATALAYER}/controllerDb.cpp ${INCLUDE}/${DATALAYER}/controllerDb.hpp
	${CC} ${CFLAG} $(AUTH) ${CFLAG} ${IFLAG} ${INCLUDE}/${DATALAYER} ${OFLAG} ${BUILDS}/controllerDb.o ${SOURCE}/${DATALAYER}/controllerDb.cpp $(CFLAGS)

${BUILDS}/mainDb.o: ${SOURCE}/${DATALAYER}/mainDb.cpp ${INCLUDE}/${DATALAYER}/mainDb.hpp
	${CC} ${CFLAG} $(AUTH) ${CFLAG} ${IFLAG} ${INCLUDE}/${DATALAYER} ${OFLAG} ${BUILDS}/mainDb.o ${SOURCE}/${DATALAYER}/mainDb.cpp $(CFLAGS)

${BUILDS}/subscriptionDb.o: ${SOURCE}/${DATALAYER}/subscriptionDb.cpp ${INCLUDE}/${DATALAYER}/subscriptionDb.hpp
	${CC} ${CFLAG} $(AUTH) ${CFLAG} ${IFLAG} ${INCLUDE}/${DATALAYER} ${OFLAG} ${BUILDS}/subscriptionDb.o ${SOURCE}/${DATALAYER}/subscriptionDb.cpp $(CFLAGS)

#TODO add view layer compilation

#TODO add model layer compilation


# Main
${BUILDS}/main.o: ${SOURCE}/main.cpp ${INCLUDE}/${DATALAYER}/controllerDb.hpp ${INCLUDE}/${DATALAYER}/mainDb.hpp ${INCLUDE}/${DATALAYER}/subscriptionDb.hpp
	${CC} ${CFLAG} $(AUTH) ${WFLAG} ${IFLAG} ${INCLUDE}/${DATALAYER} ${OFLAG} ${BUILDS}/main.o ${SOURCE}/main.cpp ${CFLAGS}


run: ${BINARY}/deadlineCentral ${BUILDS}/main.o ${BUILDS}/controllerDb.o ${BUILDS}/mainDb.o ${BUILDS}/subscriptionDb.o
	${BINARY}/deadlineCentral


# compile the tests
${TESTS}/${BUILDS}/databaseTest.o: ${TESTS}/${SOURCE}/databaseTest.cpp ${INCLUDE}/sqrt.hpp
	${CC} ${WFLAG} ${CFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${TESTS}/${BUILDS}/sqrt_test.o ${TESTS}/${SOURCE}/sqrt_test.cpp



# run the unit tests
test: ${BINARY}/exampleProg ${TESTS}/${BINARY}/deadlineCentralTests ${TESTS}/${BUILDS}/sqrt_test.o
	${TESTS}/${BINARY}/sqrtTest --log_level=all --run_test=first_test \
		-- bin/test

.PHONY: clean

clean:
	rm -rf ${BINARY}/* 
	rm -rf ${BUILDS}/*


# DATABASE HELLO WORLD EXAMPLE

# example database exe
${BINARY}/exampleProg: ${BUILDS}/databaseTest.o
	${CC} ${WFLAG} ${OFLAG} ${BINARY}/exampleProg ${BUILDS}/databaseTest.o $(LFLAGS)

${BUILDS}/databaseTest.o: ${SOURCE}/databaseTest.cpp ${INCLUDE}/databaseTest.hpp
	${CC} ${CFLAG} $(AUTH) ${CFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${BUILDS}/databaseTest.o ${SOURCE}/databaseTest.cpp $(CFLAGS)

run-example: ${BINARY}/exampleProg ${SOURCE}/databaseTest.cpp ${SOURCE}/main.cpp
	${BINARY}/exampleProg