CXX = g++

CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD

EXEC = portfolio

OBJECTS = main.o

DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -lcurl -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

