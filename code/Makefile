CC = g++
CFLAGS = -std=c++0x -g -O0

SERVER_INCLUDE = ./common

UTIL_SRC = $(shell find ./common/util -name "*cc");
SERVER_SRC = main.cc 

.PHONY:server
server:$(SERVER_SRC) $(UTIL_SRC)
	$(CC) $(CFLAGS) -I$(SERVER_INCLUDE) -o $@ $^
