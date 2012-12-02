PREFIX=/usr/local

CCC=gcc
CFLAGS=-std=gnu99 -Wall
LIBS=-lpulse -lgnustep-base -lobjc -lcurses
OFLAGS=-fconstant-string-class=NSConstantString
SOURCES=$(wildcard src/*.m) $(wildcard src/widgets/*.m)
OBJECTS=$(SOURCES:.m=.o)
CSOURCES=src/backend.c
COBJECTS=$(CSOURCES:.c=.o)
EXEC=pacmixer

all: CFLAGS += -O2
all: $(CSOURCES) $(SOURCES) $(EXEC)
debug: CFLAGS += -g -O0 -D DEBUG=1
debug: LIBS += -lrt
debug: $(OBJECTS) $(COBJECTS)
	$(CCC) $(CFLAGS) -c -o src/debug.o src/debug.c
	$(CCC) -o $(EXEC) $(OBJECTS) $(COBJECTS) src/debug.o $(LIBS)

$(EXEC): $(OBJECTS) $(COBJECTS)
	$(CCC) -o $@ $(OBJECTS) $(COBJECTS) $(LIBS)

clean:
	rm -rf $(OBJECTS) $(COBJECTS) src/debug.o $(EXEC)

%.o: %.m
	$(CCC) $(CFLAGS) $(OFLAGS) -c -o $@ $^

%.o: %.c
	$(CCC) $(CFLAGS) -c -o $@ $^

install:
	@echo "installing executable file into $(DESTDIR)$(PREFIX)/bin"
	@mkdir -p $(DESTDIR)$(PREFIX)/bin
	@cp -f pacmixer $(DESTDIR)$(PREFIX)/bin/
	@chmod 755 $(DESTDIR)$(PREFIX)/bin/pacmixer
