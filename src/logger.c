#include "../include/logger.h"
#include <stdio.h>
#include <time.h>

static const char *LOG_FILE = "logs/ipc.log";

void write_log(const char *level, const char *msg) {
    FILE *f = fopen(LOG_FILE, "a");
    if (!f) return;

    time_t t = time(NULL);
    fprintf(f, "[%ld] [%s] %s\n", t, level, msg);
    fclose(f);
}

void log_info(const char *msg) { write_log("INFO", msg); }
void log_error(const char *msg) { write_log("ERROR", msg); }
