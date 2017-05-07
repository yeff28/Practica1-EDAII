#include <stdio.h>
#include <string.h>
#include "util.h"

// Prints a message, reads a line from standard input and, if format != NULL, parses it as if using scanf(format, &ret);
// Otherwise returns the line without the final newline character.
void scan_line(char* message, char* format, void* ret) {
    printf("%s", message);
    fflush(stdout);

    char line[LINE_LENGTH];
    fgets(line, sizeof(line), stdin);
    line[strcspn(line, "\n")] = 0;

    if (format) sscanf(line, format, ret);
    else strcpy(ret, line);
}
