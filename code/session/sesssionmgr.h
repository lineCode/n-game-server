#ifndef __SESSIONMGR_H__
#define __SESSIONMGR_H__

#include "singleton.h"

class SessionMgr : public Singleton<SessionMgr>
{
public:
	SessionMgr();
	virtual ~SessionMgr();
	
	void Add(Session* session);
	void Del(Session* session);

private:
	std::map<int, Session*> m_id2session;
};

#endif
