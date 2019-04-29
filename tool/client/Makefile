CC = g++

CXXFLAGS = --std=c++0x -I../../code/common/net -g -O0

LIBS = libnet.a

.PHONY:client 
client:
	$(CC) $(CXXFLAGS) -o $@ client.cc $(LIBS)
