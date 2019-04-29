CC = /usr/local/gcc-6.5.0/bin/g++
CXXFLAGS = --std=c++0x -I../../common/net -g -O0

PROTOBUF_INCLUDE = ../../3rd/protobuf-3.7.1/include

LIBS = ../../lib/*.a

.PHONY:client 
client:client.cc project.pb.cc
	$(CC) $(CXXFLAGS) -I$(PROTOBUF_INCLUDE) -o $@ $^ $(LIBS)
