SOURCES=main.o VideoTest.o Test.o EdgeTest.o

BIN=OpencvTest
CC=gcc
CPP=g++
CFLAGS=`pkg-config --cflags opencv` 
LIBS=`pkg-config --libs opencv` 

all: $(SOURCES) link

.cpp.o:
	$(CPP) -c $< -o $@ $(CFLAGS)
link:
	$(CPP) $(SOURCES) -o $(BIN) $(LIBS)
clean:
	rm $(SOURCES) $(BIN)

