CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

####################
### USER SECTION ###
####################

# SRCS is a standard name for the source files. 
SRCS = Main.cpp Menu.cpp Ant.cpp Matrix.cpp

# HEADERS is a standard name for the header files. 
HEADERS = Menu.h Matrix.h Ant.h

# executable name 
PROG = assignment1

OBJS = Main.o Menu.o Ant.o Matrix.o

# This is the name of your compressed file. 
# Edit name as needed. Keep the format.
TAR = cs162_assignment1_tucker_walker.tar.bz2

#####################
### BUILD SECTION ###
#####################

# Typing 'make' in terminal calls the first build availible.
# In this case, default.
lab1: ${SRCS} ${HEADERS} 
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG}

# Typing 'make all' in terminal calls this build.
all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG}

# Typing 'make tar' in terminal calls this build.
# This creates a compressed file for submission.
tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} ${DOC} makefile

# Typing 'make clean' calls this build.
# It's designed to clean up the folder.
# Be careful with this, edit as needed.
clean: 
	rm -f ${PROGS} *.o *~

