#ifndef ___SESSION_H__
#define ___SESSION_H__

enum SessionState
{
	Session_Init,
	Session_Verified,
	Session_Login,
	Session_Logout,
};

class Session
{
public:
	Session();
	~Session();

	void Send();
	void Close();

private:
	int m_fd;
	SessionState m_state;
};

#endif
