#pragma once


typedef enum {
	kLog_Info = 0,
	kLog_Warn = 1,
	kLog_Error = 2,
	kLog_Fatal = 3
} LogMessageSeverity;


void log(LogMessageSeverity severity, const char* category, const char* format, ...);
void setThreadName(const char* name);
const char* getThreadName();