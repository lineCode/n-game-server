#include "netmgr.h"
#include "stdio.h"
#include "string.h"

void Link::OnAccept(int fd)
{
	Event* event = new Event;
	event->fd = fd;
	event->type = 1;
	NetMgr::Instance()->GetMq().Push(event);
}

void Link::OnClose(int fd)
{
	Event* event = new Event;
	event->fd = fd;
	event->type = 2;
	NetMgr::Instance()->GetMq().Push(event);
}

#define BUFF_SIZE 10
int Link::OnRecv(int fd, const char* s, int len)
{
	int recv_len = 0;
	while (len >= BUFF_SIZE)
	{
		Event* event = new Event;
		event->fd = fd;
		event->type = 3;
		
		event->s = (char*)malloc(BUFF_SIZE + 1);
		memset(event->s, 0, BUFF_SIZE + 1);
		memcpy(event->s, s + recv_len, BUFF_SIZE);
		
		NetMgr::Instance()->GetMq().Push(event);
		
		recv_len += BUFF_SIZE;
		len -= BUFF_SIZE;
	}
	return recv_len;
}

//////////////////////////////////////////////////////////////////////

NetMgr::NetMgr()
{
}

NetMgr::~NetMgr()
{
}

bool NetMgr::Init()
{
	if (!m_net.Init())
	{
		printf("net init failed\n");
		return false;
	}
	if (!m_net.Listen("0.0.0.0", 8888, &m_link))
	{
		printf("net listen failed\n");
		return false;
	}
	return true;
}

void NetMgr::UnInit()
{
	
}

void NetMgr::Run()
{
	Event* event = m_mq.Pop();
	while (NULL != event)
	{
		switch(event->type)
		{
		case 1:
		{
			printf("socket:%d accpet\n", event->fd);
			break;
		}
		case 2:
		{
			printf("socket:%d close\n", event->fd);
			break;
		}
		case 3:
		{
			printf("socket:%d receive:%s\n", event->fd, event->s);
			break;
		}
		default:
			break;
		}
		delete event;
		event = m_mq.Pop();
	}
}

