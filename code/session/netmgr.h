#ifndef __NETMGR_H__
#define __NETMGR_H__

#include "singleton.h"
#include "net/net.h"
#include "net/mq.h"
#include "net/netinterface.h"
#include <map>

class Link : public ILink
{
public:
	Link() { }
	virtual ~Link() { }

	virtual void OnAccept(int fd);
	virtual void OnClose(int fd);
	virtual int OnRecv(int fd, const char* s, int len);
};

typedef bool (*Handle)(int sessionid, const char* s, int len);

class NetMgr : public Singleton<NetMgr>
{
public:
	NetMgr();
	virtual ~NetMgr();

	bool Init();
	void UnInit();

	void Run();
	
	MessageQueue& GetMq() { return m_mq; }

	void OnAccept(int fd);
	void OnClose(int fd);

	bool RegisterHandle(int id, Handle handle);

	bool HandlePacket(int fd, const char* s, int len);

private:
	Link m_link;
	Net m_net;
	MessageQueue m_mq;
	std::map<int, Handle> m_id2handle;
};

#endif
