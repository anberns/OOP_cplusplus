### Final Project, Aaron Berns

CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = 

OBJS = space.o timesSquare.o main.o catwalk.o yard.o tunnel.o cell.o prisoner.o game.o utilities.o validate.o

SRCS = space.cpp timesSquare.cpp main.cpp catwalk.cpp yard.cpp tunnel.cpp cell.cpp prisoner.cpp game.cpp utilities.cpp validate.cpp

HEADERS = space.hpp timesSquare.hpp catwalk.hpp yard.hpp tunnel.hpp cell.hpp prisoner.hpp game.hpp utilities.hpp validate.hpp

assignment1: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o Attica

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

.PHONY: clean
clean:
	rm Attica space.o timesSquare.o main.o catwalk.o yard.o tunnel.o cell.o prisoner.o game.o utilities.o validate.o
