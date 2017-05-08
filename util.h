#ifndef UTIL_H
#define UTIL_H

#define true 1
#define false 0
#define bool int
#define OPT_CLR 0
#define OPT_FIND 1
#define OPT_INSERT_C 2
#define OPT_INSERT_LIST 3
#define OPT_UPDT 4
#define OPT_DELETE 5
#define OPT_PRINT 6 
#define OPT_EXIT 7
#define LINE_LENGTH 100

void scan_line(char* message, char* format, void* ret);

#endif
