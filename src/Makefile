CC = /usr/local/gcc-6.5.0/bin/g++
CXXFLAGS = -std=c++0x -g -O0

COMMON_INCLUDE = ../common
WORLD_INCLUDE = ./world
PROTOBUF_INCLUDE = ../3rd/protobuf-3.7.1/include

LIB = ../lib/*.a
SERVER_SRC = $(shell find -name "*cc");

.PHONY:server
server:$(SERVER_SRC)
	$(CC) $(CXXFLAGS) -I. -I$(COMMON_INCLUDE) -I$(WORLD_INCLUDE) -I$(PROTOBUF_INCLUDE) -o $@ $^ $(LIB) -lpthread
