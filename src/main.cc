#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "log/log.h"
#include "util/utiltime.h"
#include "net/netmgr.h"
#include "session/sessionmgr.h"

bool g_game_loop = true;

int frame_time = 33; // 30 frame per second

bool Init()
{
	Log("server init\n");

	if (!NetMgr::Instance()->Init())
	{
		return false;
	}
	if (!SessionMgr::Instance()->Init())
	{
		return false;
	}

	return true;
}
void UnInit()
{
	Log("server uninit\n");

	NetMgr::Instance()->UnInit();	
}

int main(int argc, char** argv)
{
	// init
	if (!Init())
	{
		return -1;
	}
	
	long long time_stamp = GetMillionTime();
	int frame = 0;
	// run
	while(g_game_loop)
	{
		// handle msg
		NetMgr::Instance()->Run();

		// handle time event

		// frame update
		long long current_time = GetMillionTime();
		int delta_time = current_time - time_stamp;
		if (delta_time >= frame_time)
		{

			//Log("update frame:%d delta time:%d\n", ++frame, delta_time);

			time_stamp = current_time;
		}
		usleep(20);
	}

	// uninit
	UnInit();

	return 0;
}
