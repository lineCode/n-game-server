#include "utiltime.h"
#include "sys/time.h"
#include "define.h"

long long GetMillionTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);	
	long long time_stamp = tv.tv_sec*1000 + tv.tv_usec/1000;	
	return time_stamp;
}
