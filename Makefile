CC      = gcc
CFLAGS  = -Wall
LDFLAGS = -I./include/
SCRS = $(wildcard src/*.c)
OBJS = $(patsubst src/%.c, build/%.o, $(SCRS))

all: build/main 

build/main: $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

$(OBJS): build/%.o: src/%.c
	$(CC) -c $^ -o $@ $(CFLAGS) $(LDFLAGS)

.PHONY: clean
clean:
	rm build/*

run:
	build/main