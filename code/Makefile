CC = g++
CFLAGS = -std=c++0x -g -O0

COMMON_INCLUDE = ./common
WORLD_INCLUDE = ./world

LIB = ./lib/*.a
SERVER_SRC = $(shell find ./session ./world ./common/util -name "*cc");

.PHONY:server
server:$(SERVER_SRC) $(UTIL_SRC)
	$(CC) $(CFLAGS) -I$(COMMON_INCLUDE) -I$(WORLD_INCLUDE) -o $@ $^ main.cc $(LIB) -lpthread
