export LD_LIBRARY_PATH=/usr/local/gcc-6.5.0/lib64
./protoc project.proto --cpp_out=.
cp *.h *.cc ../../code/protocol
cp *.h *.cc ../client

