CC = g++
CXXFLAGS = --std=c++0x -g -I.
ARFLAGS = rcs

SRC_DIR := .

SRCS := $(shell find timer util -name "*.cc")
OBJS := $(SRCS:.cc=.o)

.PHONY:libcommon.a

libcommon.a:$(OBJS)
	ar $(ARFLAGS) $@ $^
	cp $@ ../lib

clean:
	rm *.o
	rm *.a
