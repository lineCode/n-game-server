#include "socket.h"
#include "stdio.h"
#include "unistd.h"
#include "string.h"
#include <string>
#include "arpa/inet.h"
#include "project.pb.h"

int Pack(char* dest, int id, const char* s, int len)
{
	int temp = 4 + len;
	temp = htonl(temp);
	memcpy(dest, &temp, 4);

	id = htonl(id);
	memcpy(dest + 4, &id, 4);

	memcpy(dest + 8, s, len);
	return len + 4 + 4;
}

int main(int argc, char** argv)
{
	Socket client_sock;
	client_sock.Init();

	if (!client_sock.Connect("127.0.0.1", 8888))
	{
		printf("connect failed\n");
		return -1;
	}
	printf("connect succeed\n");

	char sendbuf[1024] = { 0 };
	//char recvbuf[1024] = { 0 };
	char cmd[16] = { 0 };
	while (1)
	{
		memset(cmd, 0, 16);
		scanf("%s", cmd);
		if (strcmp(cmd, "login") == 0)
		{
			memset(sendbuf, 0, 1024);

			LoginReq req;
			req.set_account("nomad");
			req.set_password("123456");

			std::string ss;
			req.SerializeToString(&ss);
			int size = Pack(sendbuf, 1, ss.c_str(), ss.length());	

			printf("size:%d\n", size);
			client_sock.SendRaw(sendbuf, size);	

			req.ParseFromArray(ss.c_str(), ss.length());
			printf("account:%s password:%s\n", req.account().c_str(), req.password().c_str());
		}
		else
		{
			printf("invalid cmd\n");
		}
		//usleep(10000);
	}
	return 0;
}
