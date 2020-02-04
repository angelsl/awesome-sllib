CFLAGS=-O2 -fPIC -Wall -Wextra
LDFLAGS=-shared -lxcb -lxcb-screensaver

all: sllib.so

sllib.so: sllib.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
