#include "netmgr.h"
#include "stdio.h"
#include "string.h"
#include "arpa/inet.h"
#include "session.h"
#include "sessionmgr.h"

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

//#define BUFF_SIZE 10
//int Link::OnRecv(int fd, const char* s, int len)
//{
//	int recv_len = 0;
//	while (len >= BUFF_SIZE)
//	{
//		Event* event = new Event;
//		event->fd = fd;
//		event->type = 3;
//		
//		event->s = (char*)malloc(BUFF_SIZE + 1);
//		memset(event->s, 0, BUFF_SIZE + 1);
//		memcpy(event->s, s + recv_len, BUFF_SIZE);
//		
//		NetMgr::Instance()->GetMq().Push(event);
//		
//		recv_len += BUFF_SIZE;
//		len -= BUFF_SIZE;
//	}
//	return recv_len;
//}

int Link::OnRecv(int fd, const char* s, int len)
{
	int recv_len = 0;
	while (len < 4)
	{
		int size = 0;
		memcpy(&size, s, 4);
		size = ntohl(size);
		if (len - 4 < size)
		{
			break;
		}
		else
		{
			Event* event = new Event;
			event->fd = fd;
			event->type = 3;
			
			event->s = (char*)malloc(size + 1);
			memset(event->s, 0, size + 1);
			memcpy(event->s, s + recv_len + 4, size);
			
			NetMgr::Instance()->GetMq().Push(event);

			recv_len += (size + 4);	
			len -= (size + 4);
		}
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

			HandlePacket(event->fd, event->s, strlen(event->s));

			break;
		}
		default:
			break;
		}
		delete event;
		event = m_mq.Pop();
	}
}

void NetMgr::OnAccept(int fd)
{
	SessionMgr::Instance()->Add(fd);	
}

void NetMgr::OnClose(int fd)
{
	SessionMgr::Instance()->Del(fd);	
}

bool NetMgr::RegisterHandle(int id, Handle handle)
{
	m_id2handle[id] = handle;
	return true;
}

bool NetMgr::HandlePacket(int fd, const char* s, int len)
{
	Session* session = SessionMgr::Instance()->Get(fd);
	if (NULL == session)
	{
		return false;
	}

	int id = 0;
	memcpy(&id, s, 4);
	id = ntohl(id);

	auto i = m_id2handle.find(id);
	if (i == m_id2handle.end())
	{
		return false;
	}
	else
	{
		i->second(session->GetId(), s, len);
	}
}
