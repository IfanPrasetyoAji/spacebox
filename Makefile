CC = gcc
CFLAGS = -Wall -Wextra -I src
LDLIBS = -lraylib -lm

SRC = src/main.c
BIN = n-body.o

all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

run: all
	./$(BIN)

clean:
	rm -f $(BIN)

.PHONY: all clean
