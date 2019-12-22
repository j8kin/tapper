CC=gcc
CFLAGS=-c -Wall
LDFLAGS=-lwiringPi

SOURCES=tapper.c morse.c morseConverters.c readTapper.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=tapper

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@.out

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE).out