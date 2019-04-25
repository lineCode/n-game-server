CC = g++
CFLAGS = -std=c++0x -g -O0

COMMON_INCLUDE = ./common
WORLD_INCLUDE = ./world

UTIL_SRC = $(shell find ./common/util -name "*cc");
SERVER_SRC = main.cc 

.PHONY:server
server:$(SERVER_SRC) $(UTIL_SRC)
	$(CC) $(CFLAGS) -I$(COMMON_INCLUDE) -I$(WORLD_INCLUDE) -o $@ $^
