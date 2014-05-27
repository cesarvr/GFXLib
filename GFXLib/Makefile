
CC=g++
CFLAGS=-c -Wall

LDFLAGS=
SOURCES=main.cpp Gfxlib.h base/Vector.cpp base/Matrix3.cpp base/Quaternion.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=gfxtest


all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *o gfxtest 
