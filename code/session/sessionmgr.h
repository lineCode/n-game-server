#ifndef __SESSIONMGR_H__
#define __SESSIONMGR_H__

#include "singleton.h"
#include <map>

class Session;
class SessionMgr : public Singleton<SessionMgr>
{
public:
	SessionMgr();
	virtual ~SessionMgr();
	
	bool Init();

	void Add(int fd);
	void Del(int fd);

	Session* Get(int fd);

	static bool Handle_Login(int sessionid, const char* s, int len);

private:
	std::map<int, Session*> m_id2session;
};

#endif
