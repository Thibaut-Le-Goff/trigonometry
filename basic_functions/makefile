CC = gcc
CFLAGS = -Wall -g

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)
EXE = test

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(EXE)

run: $(EXE)
	./$(EXE)

.PHONY: all clean run
