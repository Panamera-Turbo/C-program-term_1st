sources = library.c welcome.c code.c land.c student.c borrow.c return.c manager.c stdcode.c
target = lib
ccflags = -Wall -g -fsanitize=address
CC = gcc

all:
	$(CC) $(sources) $(ccflags) -o $(target)