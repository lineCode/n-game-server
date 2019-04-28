CC = /usr/local/gcc-6.5.0/bin/g++
CFLAGS = -std=c++0x -g -O0

COMMON_INCLUDE = ./common
WORLD_INCLUDE = ./world
PROTOBUF_INCLUDE = ../3rd/protobuf-3.7.1/include

LIB = ./lib/*.a
SERVER_SRC = $(shell find ./session ./world ./common/util ./protocol -name "*cc");

.PHONY:server
server:$(SERVER_SRC) $(UTIL_SRC)
	$(CC) $(CFLAGS) -I$(COMMON_INCLUDE) -I$(WORLD_INCLUDE) -I$(PROTOBUF_INCLUDE) -o $@ $^ main.cc $(LIB) -lpthread
