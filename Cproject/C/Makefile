#Makefile
sources = library_main.c linked_list.c read.c code.c land.c
target = lib
ccflags = -Wall -g -fsanitize=address
CC = gcc

all:
	$(CC) $(sources) $(ccflags) -o $(target)
