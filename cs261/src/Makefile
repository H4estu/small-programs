IDIR = ../hdr
ODIR = ./obj
CC = gcc
CFLAGS = -g -Wall -I$(IDIR)


DEPS = main.h
_DEPS = $(patsubst %,$(IDIR)/%,$(DEPS))

SRCS = main.c Q0.c Q1.c Q2.c Q3.c Q4.c Q5.c

OBJS = $(SRCS:.c=.o)
_OBJS = $(patsubst %,$(ODIR)/%,$(OBJS))

MAIN = main

all: $(MAIN) 
	
$(MAIN): $(_OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(_OBJS)

# place object files into obj directory	
$(ODIR)/%.o: %.c $(_DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# test.out: test.h test.c test.o
# 	gcc -o test test.c test.o $(CFLAGS)
# 	echo "test.c:" >> test.out
# 	./test >> test.out
# 	gcov test.c >> test.out

.PHONY: clean

clean:
	rm -rf *.o $(MAIN) $(_OBJS)