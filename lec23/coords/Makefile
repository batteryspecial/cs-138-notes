# This is a file named "Makefile", usually stored in the source code directory
# We'll explain what happens as we go

CXX = g++ # which C++ compiler to use
CXXFLAGS = -std=c++14 -Wall -MMD # which C++ compiler flags to use
OBJECTS = main.o Coords.o # list all of the object files
DEPENDS = ${OBJECTS:.o=.d} # for each foo.o, there's a dep file foo.d
EXEC = coords-main # name of the final executable you picked

# Note that make needs a TAB (not spaces!) to indent a sub-target

# if you just call "make", this will be the target
${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

.PHONY: clean # "clean" is a task, but not a file name
clean:
	rm -f ${OBJECTS} ${EXEC} ${DEPENDS}

# absorbs in all of the generated .d files;
# they are generated but not used in the first build
-include ${DEPENDS} 
