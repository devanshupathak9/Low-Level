CC     := gcc
CFLAGS := -Wall -Wextra -std=c11 -g
TARGET := mycp

.PHONY: all test clean

all: $(TARGET)

$(TARGET): mycp.c
	$(CC) $(CFLAGS) $< -o $@

test: $(TARGET)
	./$(TARGET) src.txt dest.txt
	@diff src.txt dest.txt && echo "PASS: dest.txt matches src.txt"

clean:
	rm -f $(TARGET)
