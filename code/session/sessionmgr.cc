#include "sessionmgr.h"
#include "session.h"
#include "netmgr.h"
#include "protocol/project.pb.h"

SessionMgr::SessionMgr()
{
}

SessionMgr::~SessionMgr()
{
}

bool SessionMgr::Init()
{
	NetMgr::Instance()->RegisterHandle(1, SessionMgr::Handle_Login);
	return true;
}

void SessionMgr::Add(int fd)
{
	Session* session = new Session();
	session->Init(fd);
	m_id2session[fd] = session;
}

void SessionMgr::Del(int fd)
{
	auto i = m_id2session.find(fd);
	if (i != m_id2session.end())
	{
		delete i->second;
		m_id2session.erase(i);
	}
}

Session* SessionMgr::Get(int fd)
{
	auto i = m_id2session.find(fd);
	if (i == m_id2session.end())
	{
		return NULL;
	}
	else
	{
		return i->second;
	}
}

bool SessionMgr::Handle_Login(int sessionid, const char* s, int len)
{
	Session* session = SessionMgr::Instance()->Get(sessionid);
	if (NULL == session)
	{
		return true;
	}
	LoginReq req;
	if (!req.ParseFromArray(s, len))
	{
		assert(false);
	}
	printf("handle login, account:%s, password:%s\n", req.account().c_str(), req.password().c_str());
		
	return true;
}

