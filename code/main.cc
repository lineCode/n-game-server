#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "log/log.h"
#include "util/utiltime.h"

bool g_game_loop = true;

int frame_time = 33; // 30 frame per second

int main(int argc, char** argv)
{
	// init
	Log("server init\n");
	
	long long time_stamp = GetMillionTime();
	int frame = 0;
	// run
	while(g_game_loop)
	{
		// handle msg

		// handle time event

		// frame update
		long long current_time = GetMillionTime();
		int delta_time = current_time - time_stamp;
		if (delta_time >= frame_time)
		{

			Log("update frame:%d delta time:%d\n", ++frame, delta_time);

			time_stamp = current_time;
		}

	}

	// uninit
	Log("server uninit\n");

	return 0;
}
