#
# Makefile to build a Deadline Central (and a hello world database connection file)
# Required so that deadline cental uses the latest version of oracle for compilation
#

.EXPORT_ALL_VARIABLES:
	ORACLE_BASE=/srv/export/CSCI375a/oracle-libraries
	ORACLE_HOME=/srv/export/CSCI375a/oracle-libraries/instantclient_21_9
	LD_LIBRARY_PATH=$ORACLE_HOME
	PATH=$ORACLE_HOME:/usr/local/bin:/bin:/usr/bin:/usr/X11R6/bin:~/bin
	ORALIB=$ORACLE_HOME/lib

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
VFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
CRYPTO = -L /usr/include/openss -lcrypto


# If you want to add an new file to deadline central, add the .o to ${BINARY}/deadlineCentral: , run: , and the .hpp to ${BUILDS}/main.o:
# Add it as a dependency for all 3 and in the compilation command for ${BINARY}/deadlineCentral. Follow the pre-established pattern

# MAKE COMMANDS

all: ${BINARY}/deadlineCentral directories

run: directories ${BINARY}/deadlineCentral ${BUILDS}/main.o ${BUILDS}/controllerDb.o ${BUILDS}/userDb.o ${BUILDS}/courseDb.o ${BUILDS}/taskDb.o ${BUILDS}/subscriptionDb.o \
${BUILDS}/commandHandler.o ${BUILDS}/courseController.o ${BUILDS}/filterTaskController.o \
${BUILDS}/subscriptionController.o ${BUILDS}/taskController.o ${BUILDS}/userController.o ${BUILDS}/course.o ${BUILDS}/instructor.o \
${BUILDS}/student.o ${BUILDS}/task.o ${BUILDS}/user.o ${BUILDS}/commands.o 
	${BINARY}/deadlineCentral


# if you want to add a test you have to duplicate this line:
# 	--run_test=taskDatabase \
# and change the name
test: directories ${BINARY}/deadlineCentral ${TESTS}/${BINARY}/deadlineCentralTest
	${TESTS}/${BINARY}/deadlineCentralTest --log_level=all \
	--run_test=controllerDB \
	--run_test=taskDatabase \
	--run_test=courseDB \
	--run_test=userDatabase \
	--run_test=subscriptionDatabase \
	--run_test=filterTaskController \
	--run_test=userControllerTest \
		-- bin/test

run-example: directories ${BINARY}/exampleProg ${SOURCE}/databaseTest.cpp
	${BINARY}/exampleProg

# DEADLINE CENTRAL 

# deadline central
${BINARY}/deadlineCentral: ${BUILDS}/main.o ${BUILDS}/controllerDb.o ${BUILDS}/userDb.o ${BUILDS}/courseDb.o ${BUILDS}/taskDb.o ${BUILDS}/subscriptionDb.o \
${BUILDS}/commandHandler.o ${BUILDS}/courseController.o ${BUILDS}/commands.o \
${BUILDS}/filterTaskController.o ${BUILDS}/subscriptionController.o ${BUILDS}/taskController.o \
${BUILDS}/userController.o ${BUILDS}/course.o ${BUILDS}/instructor.o ${BUILDS}/user.o \
${BUILDS}/student.o ${BUILDS}/task.o
	${CC} ${WFLAG} ${OFLAG} ${BINARY}/deadlineCentral ${BUILDS}/controllerDb.o ${BUILDS}/subscriptionDb.o \
	${BUILDS}/userDb.o ${BUILDS}/courseDb.o ${BUILDS}/taskDb.o ${BUILDS}/main.o ${BUILDS}/commandHandler.o \
	${BUILDS}/courseController.o ${BUILDS}/filterTaskController.o ${BUILDS}/subscriptionController.o \
	${BUILDS}/taskController.o ${BUILDS}/userController.o ${BUILDS}/course.o ${BUILDS}/instructor.o \
	${BUILDS}/user.o ${BUILDS}/student.o ${BUILDS}/task.o \
	${BUILDS}/commands.o \
	$(LFLAGS) $(CFLAGS) $(CRYPTO) $(VFLAGS)


# Data Layer
${BUILDS}/controllerDb.o: ${SOURCE}/${DATALAYER}/controllerDb.cpp ${INCLUDE}/${DATALAYER}/controllerDb.hpp
	${CC} ${CFLAG} $(AUTH) ${CFLAG} ${IFLAG} ${INCLUDE}/${DATALAYER} ${OFLAG} ${BUILDS}/controllerDb.o \
	${SOURCE}/${DATALAYER}/controllerDb.cpp \
	$(CFLAGS) $(CRYPTO)

${BUILDS}/taskDb.o: ${SOURCE}/${DATALAYER}/taskDb.cpp ${INCLUDE}/${DATALAYER}/taskDb.hpp
	${CC} ${CFLAG} $(AUTH) ${CFLAG} ${IFLAG} ${INCLUDE}/${DATALAYER} ${IFLAG} ${INCLUDE}/${MODEL} \
	${OFLAG} ${BUILDS}/taskDb.o \
	${SOURCE}/${DATALAYER}/taskDb.cpp \
	$(CFLAGS) $(CRYPTO)

${BUILDS}/userDb.o: ${SOURCE}/${DATALAYER}/userDb.cpp ${INCLUDE}/${DATALAYER}/userDb.hpp
	${CC} ${CFLAG} $(AUTH) ${CFLAG} ${IFLAG} ${INCLUDE}/${DATALAYER} ${IFLAG} ${INCLUDE}/${MODEL} \
	${OFLAG} ${BUILDS}/userDb.o \
	${SOURCE}/${DATALAYER}/userDb.cpp \
	$(CFLAGS) $(CRYPTO)

${BUILDS}/courseDb.o: ${SOURCE}/${DATALAYER}/courseDb.cpp ${INCLUDE}/${DATALAYER}/courseDb.hpp
	${CC} ${CFLAG} $(AUTH) ${CFLAG} ${IFLAG} ${INCLUDE}/${DATALAYER} ${IFLAG} ${INCLUDE}/${MODEL} \
	${OFLAG} ${BUILDS}/courseDb.o \
	${SOURCE}/${DATALAYER}/courseDb.cpp \
	$(CFLAGS) $(CRYPTO)

${BUILDS}/subscriptionDb.o: ${SOURCE}/${DATALAYER}/subscriptionDb.cpp ${INCLUDE}/${DATALAYER}/subscriptionDb.hpp
	${CC} ${CFLAG} $(AUTH) ${CFLAG} ${IFLAG} ${INCLUDE}/${DATALAYER} ${IFLAG} ${INCLUDE}/${MODEL} \
	${OFLAG} ${BUILDS}/subscriptionDb.o \
	${SOURCE}/${DATALAYER}/subscriptionDb.cpp \
	$(CFLAGS) $(CRYPTO)

# View layer compilation
${BUILDS}/commandHandler.o: ${SOURCE}/${VIEW}/commandHandler.cpp ${INCLUDE}/${VIEW}/commandHandler.hpp ${INCLUDE}/${VIEW}/commands.hpp
	${CC} ${CFLAG} $(AUTH) ${IFLAG} ${INCLUDE}/${DATALAYER} ${IFLAG} ${INCLUDE}/${VIEW} \
	${IFLAG} ${INCLUDE}/${MODEL} ${IFLAG} ${INCLUDE}/${CONTROL} ${IFLAG} ${INCLUDE} \
	${SOURCE}/${VIEW}/commandHandler.cpp \
	${OFLAG} ${BUILDS}/commandHandler.o \
	$(CFLAGS) $(CRYPTO)

${BUILDS}/commands.o: ${SOURCE}/${VIEW}/commands.cpp ${INCLUDE}/${VIEW}/commands.hpp ${INCLUDE}/${VIEW}/commands.hpp
	${CC} ${CFLAG} $(AUTH) ${IFLAG} ${INCLUDE}/${DATALAYER} ${IFLAG} ${INCLUDE}/${VIEW} \
	${IFLAG} ${INCLUDE}/${MODEL} ${IFLAG} ${INCLUDE}/${CONTROL} ${IFLAG} ${INCLUDE} \
	${SOURCE}/${VIEW}/commands.cpp \
	${OFLAG} ${BUILDS}/commands.o \
	$(CFLAGS) $(CRYPTO)

# Controllers compilation

${BUILDS}/courseController.o: ${SOURCE}/${CONTROL}/courseController.cpp ${INCLUDE}/${CONTROL}/courseController.hpp
	${CC} ${CFLAG} $(AUTH) ${CFLAG} ${IFLAG} ${INCLUDE}/${CONTROL} ${IFLAG} ${INCLUDE}/${DATALAYER} \
	 ${IFLAG} ${INCLUDE}/${MODEL} \
	${OFLAG} ${BUILDS}/courseController.o \
	${SOURCE}/${CONTROL}/courseController.cpp \
	$(CFLAGS) $(CRYPTO)

${BUILDS}/filterTaskController.o: ${SOURCE}/${CONTROL}/filterTaskController.cpp ${INCLUDE}/${CONTROL}/filterTaskController.hpp
	${CC} ${CFLAG} $(AUTH) ${CFLAG} ${IFLAG} ${INCLUDE}/${CONTROL} ${IFLAG} ${INCLUDE}/${DATALAYER} \
	${IFLAG} ${INCLUDE}/${MODEL} \
	${OFLAG} ${BUILDS}/filterTaskController.o \
	${SOURCE}/${CONTROL}/filterTaskController.cpp \
	$(CFLAGS) $(CRYPTO)

${BUILDS}/subscriptionController.o: ${SOURCE}/${CONTROL}/subscriptionController.cpp ${INCLUDE}/${CONTROL}/subscriptionController.hpp
	${CC} ${CFLAG} $(AUTH) ${CFLAG} ${IFLAG} ${INCLUDE}/${CONTROL} ${IFLAG} ${INCLUDE}/${DATALAYER}  \
	${IFLAG} ${INCLUDE}/${MODEL} \
	${OFLAG} ${BUILDS}/subscriptionController.o \
	${SOURCE}/${CONTROL}/subscriptionController.cpp \
	$(CFLAGS) $(CRYPTO)

${BUILDS}/taskController.o: ${SOURCE}/${CONTROL}/taskController.cpp ${INCLUDE}/${CONTROL}/taskController.hpp
	${CC} ${CFLAG} $(AUTH) ${CFLAG} ${IFLAG} ${INCLUDE}/${CONTROL} ${IFLAG} ${INCLUDE}/${DATALAYER}  \
	${IFLAG} ${INCLUDE}/${MODEL} \
	${OFLAG} ${BUILDS}/taskController.o \
	${SOURCE}/${CONTROL}/taskController.cpp \
	$(CFLAGS) $(CRYPTO)

${BUILDS}/userController.o: ${SOURCE}/${CONTROL}/userController.cpp ${INCLUDE}/${CONTROL}/userController.hpp
	${CC} ${CFLAG} $(AUTH) ${CFLAG} ${IFLAG} ${INCLUDE}/${CONTROL} ${IFLAG} ${INCLUDE}/${DATALAYER} ${IFLAG} ${INCLUDE}/${MODEL} \
	${OFLAG} ${BUILDS}/userController.o \
	${SOURCE}/${CONTROL}/userController.cpp \
	$(CFLAGS) $(CRYPTO)

# Models compilation
${BUILDS}/course.o: ${SOURCE}/${MODEL}/course.cpp ${INCLUDE}/${MODEL}/course.hpp
	${CC} ${CFLAG} $(AUTH) ${IFLAG} ${INCLUDE}/${MODEL} ${OFLAG} ${BUILDS}/course.o \
	${SOURCE}/${MODEL}/course.cpp

${BUILDS}/instructor.o: ${SOURCE}/${MODEL}/instructor.cpp ${INCLUDE}/${MODEL}/instructor.hpp
	${CC} ${CFLAG} $(AUTH) ${IFLAG} ${INCLUDE}/${MODEL} ${OFLAG} ${BUILDS}/instructor.o \
	${SOURCE}/${MODEL}/instructor.cpp

${BUILDS}/student.o: ${SOURCE}/${MODEL}/student.cpp ${INCLUDE}/${MODEL}/student.hpp
	${CC} ${CFLAG} $(AUTH) ${IFLAG} ${INCLUDE}/${MODEL} ${OFLAG} ${BUILDS}/student.o \
	${SOURCE}/${MODEL}/student.cpp

${BUILDS}/task.o: ${SOURCE}/${MODEL}/task.cpp ${INCLUDE}/${MODEL}/task.hpp
	${CC} ${CFLAG} $(AUTH) ${IFLAG} ${INCLUDE}/${MODEL} ${OFLAG} ${BUILDS}/task.o \
	${SOURCE}/${MODEL}/task.cpp

${BUILDS}/user.o: ${SOURCE}/${MODEL}/user.cpp ${INCLUDE}/${MODEL}/user.hpp
	${CC} ${CFLAG} $(AUTH) ${IFLAG} ${INCLUDE}/${MODEL} ${OFLAG} ${BUILDS}/user.o \
	${SOURCE}/${MODEL}/user.cpp

# Main
${BUILDS}/main.o: ${SOURCE}/main.cpp ${INCLUDE}/${DATALAYER}/controllerDb.hpp \
${INCLUDE}/${DATALAYER}/userDb.hpp ${INCLUDE}/${DATALAYER}/courseDb.hpp ${INCLUDE}/${DATALAYER}/taskDb.hpp ${INCLUDE}/${DATALAYER}/subscriptionDb.hpp \
${INCLUDE}/${VIEW}/commandHandler.hpp ${INCLUDE}/${VIEW}/commands.hpp \
${INCLUDE}/${CONTROL}/courseController.hpp ${INCLUDE}/${CONTROL}/subscriptionController.hpp \
${INCLUDE}/${CONTROL}/taskController.hpp ${INCLUDE}/${CONTROL}/userController.hpp \
${INCLUDE}/${CONTROL}/taskController.hpp ${INCLUDE}/${MODEL}/course.hpp \
${INCLUDE}/${MODEL}/instructor.hpp ${INCLUDE}/${MODEL}/student.hpp ${INCLUDE}/${MODEL}/task.hpp \
${INCLUDE}/${MODEL}/user.hpp
	${CC} ${CFLAG} $(AUTH) ${WFLAG} ${IFLAG} ${INCLUDE}/${DATALAYER} ${IFLAG} ${INCLUDE}/${VIEW} \
	${IFLAG} ${INCLUDE}/${MODEL} ${IFLAG} ${INCLUDE}/${CONTROL} ${IFLAG} ${INCLUDE} \
	${OFLAG} ${BUILDS}/main.o ${SOURCE}/main.cpp \
	$(CFLAGS) $(CRYPTO)

# TESTING
# note, To add a testing file simply duplicated this line for the "${TESTS}/${BINARY}/deadlineCentralTest:" target
# ${TESTS}/${SOURCE}/${DATALAYER}/taskDbTest.cpp ${SOURCE}/${DATALAYER}/taskDb.cpp ${SOURCE}/${MODEL}/task.cpp \
# and then change the file locations and names.

# Testing executable
${TESTS}/${BINARY}/deadlineCentralTest: ${BINARY}/deadlineCentral \
${INCLUDE}/${DATALAYER}/userDb.hpp ${INCLUDE}/${DATALAYER}/courseDb.hpp ${INCLUDE}/${DATALAYER}/taskDb.hpp ${INCLUDE}/${DATALAYER}/subscriptionDb.hpp \
${INCLUDE}/${VIEW}/commandHandler.hpp ${INCLUDE}/${VIEW}/commands.hpp \
${INCLUDE}/${CONTROL}/courseController.hpp ${INCLUDE}/${CONTROL}/subscriptionController.hpp \
${INCLUDE}/${CONTROL}/taskController.hpp ${INCLUDE}/${CONTROL}/userController.hpp \
${INCLUDE}/${CONTROL}/filterTaskController.hpp ${INCLUDE}/${MODEL}/course.hpp \
${INCLUDE}/${MODEL}/instructor.hpp ${INCLUDE}/${MODEL}/student.hpp ${INCLUDE}/${MODEL}/task.hpp \
${INCLUDE}/${MODEL}/user.hpp
	${CC} ${WFLAG} ${AUTH} ${TFLAG} -o ${TESTS}/${BINARY}/deadlineCentralTest \
	${IFLAG} ${INCLUDE}/${DATALAYER} ${IFLAG} ${TESTS}/${INCLUDE}/${DATALAYER} \
	${IFLAG} ${INCLUDE} ${IFLAG} ${TESTS}/${INCLUDE} \
	${IFLAG} ${INCLUDE}/${DATALAYER} ${IFLAG} ${INCLUDE}/${VIEW} \
	${IFLAG} ${INCLUDE}/${MODEL} ${IFLAG} ${INCLUDE}/${CONTROL} ${IFLAG} ${INCLUDE} \
	${TESTS}/${SOURCE}/${DATALAYER}/controllerDbTest.cpp ${SOURCE}/${DATALAYER}/controllerDb.cpp \
	${TESTS}/${SOURCE}/${DATALAYER}/taskDbTest.cpp ${SOURCE}/${DATALAYER}/taskDb.cpp ${SOURCE}/${MODEL}/task.cpp \
	${TESTS}/${SOURCE}/${DATALAYER}/courseDbTest.cpp ${SOURCE}/${DATALAYER}/courseDb.cpp ${SOURCE}/${MODEL}/course.cpp  \
    ${TESTS}/${SOURCE}/${DATALAYER}/userDbTest.cpp ${SOURCE}/${DATALAYER}/userDb.cpp ${SOURCE}/${MODEL}/user.cpp ${SOURCE}/${MODEL}/student.cpp ${SOURCE}/${MODEL}/instructor.cpp \
	${TESTS}/${SOURCE}/${DATALAYER}/subscriptionDbTest.cpp ${SOURCE}/${DATALAYER}/subscriptionDb.cpp \
	${TESTS}/${SOURCE}/${CONTROL}/filterTaskControllerTest.cpp ${SOURCE}/${CONTROL}/filterTaskController.cpp \
	${TESTS}/${SOURCE}/${CONTROL}/userControllerTest.cpp ${SOURCE}/${CONTROL}/userController.cpp \
	${SOURCE}/${CONTROL}/courseController.cpp ${SOURCE}/${CONTROL}/subscriptionController.cpp \
	${SOURCE}/${CONTROL}/taskController.cpp \
	${TESTS}/${SOURCE}/main.cpp \
	$(CFLAGS) $(CRYPTO) $(LFLAGS)

.PHONY: directories clean
# ${SOURCE}/${CONTROL}/filterTaskController.cpp
clean: directories
	rm -rf ${BINARY}/* 
	rm -rf ${BUILDS}/*
	rm -rf ${TESTS}/${BINARY}/*


# Creating directories that are ignored by git
MKDIR_P = mkdir -p
directories:
	${MKDIR_P} ${BINARY} ${BUILDS} ${TESTS}/${BINARY} ${TESTS}/${BUILDS}


