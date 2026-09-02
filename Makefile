.PHONY: build clean install uninstall

CC=cc
CFLAGS=-Wall -Wextra -Wpedantic
SOURCES=*.c
OBJECTS=*.o

build: $(SOURCES)
	$(CC) -c $(CFLAGS) $(SOURCES)
	$(CC) $(OBJECTS) $(CFLAGS) -o sifetch

clean:
	rm -f *.o

install: build
	cp -f sifetch /usr/local/bin

uninstall:
	rm -f /usr/local/bin/sifetch
