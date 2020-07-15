#Makefile
sources = *.c
target = lib
ccflags = -Wall -g -fsanitize=address
CC = gcc

all:
	$(CC) $(sources) $(ccflags) -o $(target)
