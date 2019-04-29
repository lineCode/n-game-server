#ifndef __ROLE_H__
#define __ROLE_H__

#include <string>

class Role : public Unit
{
public:
	Role();
	virtual ~Role();

	bool Init();

	void OnLogin();
	void OnLogout();
	
	void OnEnterScene();
	void OnLeaveScene();

private:
	std::string m_rolename;
	int m_sessionid;			
};

#endif
