# Generic build helper for single-file exercises.
#
#   make FILE=01-c-fundamentals/pointers/pointers.c
#   make FILE=01-c-fundamentals/pointers/pointers.c run
#   make FILE=... debug
#   make FILE=... valgrind
#   make clean
#
# Multi-file projects keep their own Makefile in projects/<name>/.

CC      := gcc
CFLAGS  := -Wall -Wextra -std=c11 -g
LDFLAGS :=
BUILD   := build

# Extra libraries some modules need, e.g. make FILE=... LDFLAGS=-lpthread

BIN := $(BUILD)/$(basename $(notdir $(FILE)))

.PHONY: all run debug valgrind clean help

all: check $(BIN)

check:
ifndef FILE
	$(error Set FILE=path/to/file.c — e.g. make FILE=01-c-fundamentals/basics/hello-world.c run)
endif

$(BIN): $(FILE) | $(BUILD)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)
	@echo "built $@"

$(BUILD):
	@mkdir -p $(BUILD)

run: all
	@echo "--- running $(BIN) ---"
	@./$(BIN) $(ARGS)

debug: all
	gdb ./$(BIN)

valgrind: all
	valgrind --leak-check=full --track-origins=yes ./$(BIN) $(ARGS)

clean:
	rm -rf $(BUILD)

help:
	@echo "make FILE=<path.c>            build"
	@echo "make FILE=<path.c> run        build and run   (pass args with ARGS=\"a b\")"
	@echo "make FILE=<path.c> debug      build and open gdb"
	@echo "make FILE=<path.c> valgrind   build and run under valgrind"
	@echo "make clean                    remove build/"
