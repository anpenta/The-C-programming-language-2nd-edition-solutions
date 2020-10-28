CC = gcc
CFLAGS = -g -std=c89
LIBS = -lm
SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))

.PHONY: all clean

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)
clean:
	rm -f $(PROGS)
