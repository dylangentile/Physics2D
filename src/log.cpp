#include "log.h"

#include <SDL2/SDL.h>
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <ctime>
#include <cstring>
#include <string>

#include <mutex>
#include <thread>


FILE* fd = nullptr;
std::mutex fdMutex;




const char* severityConv[] = {
	"INFO",
	"WARN",
	"ERROR",
	"FATAL"
};


thread_local char threadName[52];



void setThreadName(const char* name)
{
	strcpy(threadName, name);
}


const char* getThreadName()
{
	return threadName;
}


void 
log(LogMessageSeverity severity, const char* category, const char* format, ...)
{
	
	va_list args;
	va_start(args, format);
	char buf[1024];
	vsprintf(buf, format, args);	
	va_end(args);
	

	const char* msg = buf;
	//time_t theTime = time(NULL);
	//char* c_time_string = ctime(&theTime);
	long long ticks = SDL_GetTicks();
	fdMutex.lock();
		if(fd == nullptr)
		{
			fd = fopen("elog.log", "w");
			if(!fd)
			{
				printf("Failed to open log file!");
				abort();
			}
			fprintf(fd, "  [seconds][thread][logcat][severity]: message\n");
		}
		if(severity == kLog_Fatal)
		{
			fprintf(fd, "[%9.3f] [%4s] [%6s] [%5s]: %s\nAborting Program...\n", ticks/1000.0f, threadName, category, severityConv[severity], msg);
			fflush(fd);
			printf("Fatal Error! Read the Log File\n");
			abort();
		}

		fprintf(fd, "[%9.3f] [%4s] [%6s] [%5s]: %s\n", ticks/1000.0f, threadName, category, severityConv[severity], msg);
		fflush(fd);
	fdMutex.unlock();


}