SOURCES=test.cpp SPI_api.cpp
TARGET=main
LIBRARIES=

# Decide target
ifeq ($(ARCH), target)
	OBJDIR=target
	CXX=arm-angstrom-linux-gnueabi-g++
else
	OBJDIR=host
	CXX=g++
endif

ifeq ($(DEBUG), y)
	CXXFLAGS=-g ${LIBRARIES}
else
	CXXFLAGS= ${LIBRARIES}
endif

OBJECTS=${addprefix ${OBJDIR}/,${SOURCES:.cpp=.o}}
DEPS=${addprefix ${OBJDIR}/,${SOURCES:.cpp=.d}}
EXECUTABLE=${OBJDIR}/${TARGET}

${OBJDIR}/%.d: %.cpp | ${OBJDIR}
	${CXX} -MT${@:.d=.o} -MM ${CXXFLAGS} $^ > $@

${OBJDIR}/%.o: %.cpp | ${OBJDIR}
	${CXX} -c -o $@ $^ ${CXXFLAGS}

.PHONY: all
all:  ${EXECUTABLE}	
${EXECUTABLE}: ${OBJECTS} ${DEPS}
	${CXX} -o $@ ${OBJECTS} ${CXXFLAGS}

${OBJDIR}:
	mkdir -p ${OBJDIR}

.PHONY: clean
clean: 
	rm -f ${EXECUTABLE} ${DEPS} ${OBJECTS}
	
.PHONY: help
help:
	@echo "Make targets\n - ARCH\n  - host(default)\n  - target\n - DEBUG\n  - no (default)\n  - yes\n - clean\n - help"
 
