CC := gcc
CFLAGS = -Wall -g
# CFLAGS := -Iinclude
SRCDIR := src
BINDIR := bin
SRCEXT := c
SOURCES := $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/**/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%,$(BINDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
TARGET := test

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $(BINDIR)/$@

$(BINDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean run

clean:
	rm -r $(BINDIR)/*

run: $(TARGET)
	./$(BINDIR)/$(TARGET)
