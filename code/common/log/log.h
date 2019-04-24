#include "stdarg.h"

//void Log(const char* s, ...);
//#define Log(format, ...) fprintf(stdout, format, ##__VA_ARGS__);
#define Log(format, ...) printf(format, ##__VA_ARGS__);
