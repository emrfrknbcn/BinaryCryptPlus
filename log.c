#include <stdio.h>
#include "log.h"

void logOperation(const char *type, const char *in, const char *out, int key) {
    FILE *log = fopen("log.txt", "a");
    if (!log) return;

    fprintf(log, "[%s] input: %s, output: %s, key: %d\n", type, in, out, key);
    fclose(log);
}

