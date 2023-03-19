#
# Makefile to build a Deadline Central (and a hello world database connection file)
# Required so that deadline cental uses the latest version of oracle for compilation
#

.EXPORT_ALL_VARIABLES:
	export ORACLE_BASE=/srv/export/CSCI375a/oracle-libraries
	export ORACLE_HOME=/srv/export/CSCI375a/oracle-libraries/instantclient_21_9
	export LD_LIBRARY_PATH=$ORACLE_HOME
	export PATH=$ORACLE_HOME:/usr/local/bin:/bin:/usr/bin:/usr/X11R6/bin:~/bin
	export ORALIB=$ORACLE_HOME/lib

# Basic Compilation Flags
WFLAG = -Wall
CFLAG = -c
OFLAG = -o
IFLAG = -I
DFLAG = -ggdb -gstabs+ -gcoff

# Directories
SOURCE = src
DATALAYER = datalayer
CONTROL = controllers
MODEL = models
VIEW = viewlayer
INCLUDE = include
BINARY = bin
TESTS = test
BUILDS = build

CC = g++ -ggdb
#Specifies the locations of occi.h headers
CFLAGS = -I $(ORACLE_HOME)/sdk/include
#Specifies the location of oracle programs needed to connect
LFLAGS = -L $(ORACLE_HOME) -locci -lclntsh
#Resolves "invalid password" bug
AUTH = -D_GLIBCXX_USE_CXX11_ABI=0
TFLAG = -lboost_unit_test_framework -Wl,--no-as-needed -lboost_system

# If you want to add an new file to deadline central, add the .o to ${BINARY}/deadlineCentral: , run: , and the .hpp to ${BUILDS}/main.o:
# Add it as a dependency for all 3 and in the compilation command for ${BINARY}/deadlineCentral. Follow the pre-established pattern

# MAKE COMMANDS

all: ${BINARY}/exampleProg ${BINARY}/deadlineCentral


run: ${BINARY}/deadlineCentral ${BUILDS}/main.o ${BUILDS}/controllerDb.o ${BUILDS}/mainDb.o ${BUILDS}/subscriptionDb.o \
${BUILDS}/commandHandler.o ${BUILDS}/aggregateDeadlinesController.o ${BUILDS}/courseController.o ${BUILDS}/filterTaskController.o \
${BUILDS}/subscriptionController.o ${BUILDS}/taskController.o ${BUILDS}/userController.o ${BUILDS}/course.o ${BUILDS}/instructor.o \
${BUILDS}/student.o ${BUILDS}/task.o ${BUILDS}/user.o
	${BINARY}/deadlineCentral

test: ${BINARY}/deadlineCentral ${TESTS}/${BINARY}/deadlineCentralTest
	${TESTS}/${BINARY}/deadlineCentralTest --log_level=all \
	--run_test=math \
	--run_test=controllerDB \
		-- bin/test

run-example: ${BINARY}/exampleProg ${SOURCE}/databaseTest.cpp
	${BINARY}/exampleProg

# DEADLINE CENTRAL 

# deadline central
${BINARY}/deadlineCentral: ${BUILDS}/main.o ${BUILDS}/controllerDb.o ${BUILDS}/mainDb.o ${BUILDS}/subscriptionDb.o \
${BUILDS}/commandHandler.o ${BUILDS}/aggregateDeadlinesController.o ${BUILDS}/courseController.o \
${BUILDS}/filterTaskController.o ${BUILDS}/subscriptionController.o ${BUILDS}/taskController.o \
${BUILDS}/userController.o ${BUILDS}/course.o ${BUILDS}/instructor.o ${BUILDS}/user.o \
${BUILDS}/student.o ${BUILDS}/task.o ${BUILDS}/sqrt.o
	${CC} ${WFLAG} ${OFLAG} ${BINARY}/deadlineCentral ${BUILDS}/controllerDb.o ${BUILDS}/subscriptionDb.o \
	${BUILDS}/mainDb.o ${BUILDS}/main.o ${BUILDS}/commandHandler.o ${BUILDS}/aggregateDeadlinesController.o \
	${BUILDS}/courseController.o ${BUILDS}/filterTaskController.o ${BUILDS}/subscriptionController.o \
	${BUILDS}/taskController.o ${BUILDS}/userController.o ${BUILDS}/course.o ${BUILDS}/instructor.o \
	${BUILDS}/user.o ${BUILDS}/student.o ${BUILDS}/task.o \
	$(LFLAGS) $(CFLAGS)


# Data Layer
${BUILDS}/controllerDb.o: ${SOURCE}/${DATALAYER}/controllerDb.cpp ${INCLUDE}/${DATALAYER}/controllerDb.hpp
	${CC} ${CFLAG} $(AUTH) ${CFLAG} ${IFLAG} ${INCLUDE}/${DATALAYER} ${OFLAG} ${BUILDS}/controllerDb.o \
	${SOURCE}/${DATALAYER}/controllerDb.cpp \
	$(CFLAGS)

${BUILDS}/mainDb.o: ${SOURCE}/${DATALAYER}/mainDb.cpp ${INCLUDE}/${DATALAYER}/mainDb.hpp
	${CC} ${CFLAG} $(AUTH) ${CFLAG} ${IFLAG} ${INCLUDE}/${DATALAYER} ${OFLAG} ${BUILDS}/mainDb.o \
	${SOURCE}/${DATALAYER}/mainDb.cpp \
	$(CFLAGS)

${BUILDS}/subscriptionDb.o: ${SOURCE}/${DATALAYER}/subscriptionDb.cpp ${INCLUDE}/${DATALAYER}/subscriptionDb.hpp
	${CC} ${CFLAG} $(AUTH) ${CFLAG} ${IFLAG} ${INCLUDE}/${DATALAYER} ${OFLAG} ${BUILDS}/subscriptionDb.o \
	${SOURCE}/${DATALAYER}/subscriptionDb.cpp \
	$(CFLAGS)

# View layer compilation
${BUILDS}/commandHandler.o: ${SOURCE}/${VIEW}/commandHandler.cpp ${INCLUDE}/${VIEW}/commandHandler.hpp
	${CC} ${CFLAG} $(AUTH) ${CFLAG} ${IFLAG} ${INCLUDE}/${VIEW} ${OFLAG} ${BUILDS}/commandHandler.o \
	${SOURCE}/${VIEW}/commandHandler.cpp

# Controllers compilation
${BUILDS}/aggregateDeadlinesController.o: ${SOURCE}/${CONTROL}/aggregateDeadlinesController.cpp \
${INCLUDE}/${CONTROL}/aggregateDeadlinesController.hpp
	${CC} ${CFLAG} ${CFLAG} ${IFLAG} ${INCLUDE}/${CONTROL} ${OFLAG} ${BUILDS}/aggregateDeadlinesController.o \
	${SOURCE}/${CONTROL}/aggregateDeadlinesController.cpp

${BUILDS}/courseController.o: ${SOURCE}/${CONTROL}/courseController.cpp ${INCLUDE}/${CONTROL}/courseController.hpp
	${CC} ${CFLAG} ${CFLAG} ${IFLAG} ${INCLUDE}/${CONTROL} ${OFLAG} ${BUILDS}/courseController.o \
	${SOURCE}/${CONTROL}/courseController.cpp

${BUILDS}/filterTaskController.o: ${SOURCE}/${CONTROL}/filterTaskController.cpp ${INCLUDE}/${CONTROL}/filterTaskController.hpp
	${CC} ${CFLAG} ${CFLAG} ${IFLAG} ${INCLUDE}/${CONTROL} ${OFLAG} ${BUILDS}/filterTaskController.o \
	${SOURCE}/${CONTROL}/filterTaskController.cpp

${BUILDS}/subscriptionController.o: ${SOURCE}/${CONTROL}/subscriptionController.cpp ${INCLUDE}/${CONTROL}/subscriptionController.hpp
	${CC} ${CFLAG} ${CFLAG} ${IFLAG} ${INCLUDE}/${CONTROL} ${OFLAG} ${BUILDS}/subscriptionController.o \
	${SOURCE}/${CONTROL}/subscriptionController.cpp

${BUILDS}/taskController.o: ${SOURCE}/${CONTROL}/taskController.cpp ${INCLUDE}/${CONTROL}/taskController.hpp
	${CC} ${CFLAG} ${CFLAG} ${IFLAG} ${INCLUDE}/${CONTROL} ${OFLAG} ${BUILDS}/taskController.o \
	${SOURCE}/${CONTROL}/taskController.cpp

${BUILDS}/userController.o: ${SOURCE}/${CONTROL}/userController.cpp ${INCLUDE}/${CONTROL}/userController.hpp
	${CC} ${CFLAG} ${CFLAG} ${IFLAG} ${INCLUDE}/${CONTROL} ${OFLAG} ${BUILDS}/userController.o \
	${SOURCE}/${CONTROL}/userController.cpp

# Models compilation
${BUILDS}/course.o: ${SOURCE}/${MODEL}/course.cpp ${INCLUDE}/${MODEL}/course.hpp
	${CC} ${CFLAG} ${CFLAG} ${IFLAG} ${INCLUDE}/${MODEL} ${OFLAG} ${BUILDS}/course.o \
	${SOURCE}/${MODEL}/course.cpp

${BUILDS}/instructor.o: ${SOURCE}/${MODEL}/instructor.cpp ${INCLUDE}/${MODEL}/instructor.hpp
	${CC} ${CFLAG} ${CFLAG} ${IFLAG} ${INCLUDE}/${MODEL} ${OFLAG} ${BUILDS}/instructor.o \
	${SOURCE}/${MODEL}/instructor.cpp

${BUILDS}/student.o: ${SOURCE}/${MODEL}/student.cpp ${INCLUDE}/${MODEL}/student.hpp
	${CC} ${CFLAG} ${CFLAG} ${IFLAG} ${INCLUDE}/${MODEL} ${OFLAG} ${BUILDS}/student.o \
	${SOURCE}/${MODEL}/student.cpp

${BUILDS}/task.o: ${SOURCE}/${MODEL}/task.cpp ${INCLUDE}/${MODEL}/task.hpp
	${CC} ${CFLAG} ${CFLAG} ${IFLAG} ${INCLUDE}/${MODEL} ${OFLAG} ${BUILDS}/task.o \
	${SOURCE}/${MODEL}/task.cpp

${BUILDS}/user.o: ${SOURCE}/${MODEL}/user.cpp ${INCLUDE}/${MODEL}/user.hpp
	${CC} ${CFLAG} ${CFLAG} ${IFLAG} ${INCLUDE}/${MODEL} ${OFLAG} ${BUILDS}/user.o \
	${SOURCE}/${MODEL}/user.cpp

# Main
${BUILDS}/main.o: ${SOURCE}/main.cpp ${INCLUDE}/${DATALAYER}/controllerDb.hpp \
${INCLUDE}/${DATALAYER}/mainDb.hpp ${INCLUDE}/${DATALAYER}/subscriptionDb.hpp \
${INCLUDE}/${VIEW}/commandHandler.hpp ${INCLUDE}/${CONTROL}/aggregateDeadlinesController.hpp \
${INCLUDE}/${CONTROL}/courseController.hpp ${INCLUDE}/${CONTROL}/subscriptionController.hpp \
${INCLUDE}/${CONTROL}/taskController.hpp ${INCLUDE}/${CONTROL}/userController.hpp \
${INCLUDE}/${CONTROL}/taskController.hpp ${INCLUDE}/${MODEL}/course.hpp \
${INCLUDE}/${MODEL}/instructor.hpp ${INCLUDE}/${MODEL}/student.hpp ${INCLUDE}/${MODEL}/task.hpp \
${INCLUDE}/${MODEL}/user.hpp ${INCLUDE}/sqrt.hpp
	${CC} ${CFLAG} $(AUTH) ${WFLAG} ${IFLAG} ${INCLUDE}/${DATALAYER} ${IFLAG} ${INCmLUDE}/${VIEW} \
	${IFLAG} ${INCLUDE}/${MODEL} ${IFLAG} ${INCLUDE}/${CONTROL} ${IFLAG} ${INCLUDE} \
	${OFLAG} ${BUILDS}/main.o ${SOURCE}/main.cpp \
	$(CFLAGS)

# TESTING
# note, To add a testing file simply duplicated this line for the "${TESTS}/${BINARY}/deadlineCentralTest:" target
# ${TESTS}/${SOURCE}/${DATALAYER}/controllerDbTest.cpp ${SOURCE}/${DATALAYER}/controllerDb.cpp \
# and then change the file locations and names.

# TODO: remove this, it was for testing purposes
${BUILDS}/sqrt.o: ${SOURCE}/sqrt.cpp ${INCLUDE}/sqrt.hpp
	${CC} ${WFLAG} ${CFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${BUILDS}/sqrt.o ${SOURCE}/sqrt.cpp

# TODO remove the sqrtTest compilation
# Testing executable
${TESTS}/${BINARY}/deadlineCentralTest: ${BINARY}/deadlineCentral \
${INCLUDE}/${DATALAYER}/mainDb.hpp ${INCLUDE}/${DATALAYER}/subscriptionDb.hpp \
${INCLUDE}/${VIEW}/commandHandler.hpp ${INCLUDE}/${CONTROL}/aggregateDeadlinesController.hpp \
${INCLUDE}/${CONTROL}/courseController.hpp ${INCLUDE}/${CONTROL}/subscriptionController.hpp \
${INCLUDE}/${CONTROL}/taskController.hpp ${INCLUDE}/${CONTROL}/userController.hpp \
${INCLUDE}/${CONTROL}/taskController.hpp ${INCLUDE}/${MODEL}/course.hpp \
${INCLUDE}/${MODEL}/instructor.hpp ${INCLUDE}/${MODEL}/student.hpp ${INCLUDE}/${MODEL}/task.hpp \
${INCLUDE}/${MODEL}/user.hpp ${INCLUDE}/sqrt.hpp
	${CC} ${WFLAG} ${AUTH} ${TFLAG} -o ${TESTS}/${BINARY}/deadlineCentralTest \
	${IFLAG} ${INCLUDE}/${DATALAYER} ${IFLAG} ${TESTS}/${INCLUDE}/${DATALAYER} \
	${IFLAG} ${INCLUDE} ${IFLAG} ${TESTS}/${INCLUDE} \
	${TESTS}/${SOURCE}/sqrtTest.cpp ${SOURCE}/sqrt.cpp \
	${TESTS}/${SOURCE}/${DATALAYER}/controllerDbTest.cpp ${SOURCE}/${DATALAYER}/controllerDb.cpp \
	${TESTS}/${SOURCE}/main.cpp \
	$(CFLAGS) $(LFLAGS)

.PHONY: clean

clean:
	rm -rf ${BINARY}/* 
	rm -rf ${BUILDS}/*
	rm -rf ${TESTS}/${BINARY}/*

# DATABASE HELLO WORLD EXAMPLE
# example database exe
${BINARY}/exampleProg: ${BUILDS}/databaseTest.o
	${CC} ${WFLAG} ${OFLAG} ${BINARY}/exampleProg ${BUILDS}/databaseTest.o \
	$(LFLAGS) $(CFLAGS)

${BUILDS}/databaseTest.o: ${SOURCE}/databaseTest.cpp ${INCLUDE}/databaseTest.hpp
	${CC} ${CFLAG} $(AUTH) ${CFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${BUILDS}/databaseTest.o ${SOURCE}/databaseTest.cpp \
	$(CFLAGS)
