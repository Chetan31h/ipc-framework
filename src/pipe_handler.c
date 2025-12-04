#include "../include/pipe_handler.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int ph_create_anon_pipe(int fds[2]) {
    return pipe(fds);
}

int ph_create_fifo(const char *path, int mode) {
    return mkfifo(path, mode);
}

int ph_open_fifo_read(const char *path) {
    return open(path, O_RDONLY);
}

int ph_open_fifo_write(const char *path) {
    return open(path, O_WRONLY);
}

int ph_read(int fd, void *buf, int size) {
    return read(fd, buf, size);
}

int ph_write(int fd, const void *buf, int size) {
    return write(fd, buf, size);
}

int ph_close(int fd) {
    return close(fd);
}
