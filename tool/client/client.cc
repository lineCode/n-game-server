#include "socket.h"
#include "stdio.h"
#include "unistd.h"
#include "string.h"

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

	//char sendbuf[1024] = { 0 };
	//char recvbuf[1024] = { 0 };
	while (1)
	{
		memset(sendbuf, 1024, 0);
		scanf("%s", sendbuf);
		client_sock.SendRaw(sendbuf, strlen(sendbuf));	

		//memset(recvbuf, 1024, 0);
		//client_sock.Recv(recvbuf, 1024);
		//printf("recv:%s\n", recvbuf);

		usleep(10000);
	}
	return 0;
}
