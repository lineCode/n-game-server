#include "session.h"

Session::Session()
{
	m_fd = -1;
	m_state = Session_Init;
}

Session::~Session()
{
}

bool Session::Init(int fd)
{
	m_fd = fd;
	m_state = Session_Init;
	return true;
}

void Session::Send(int id, const char* s, int len)
{

}
