CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC = $(wildcard *.c)
OUT = apc

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
