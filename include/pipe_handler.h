#ifndef PIPE_HANDLER_H
#define PIPE_HANDLER_H

int ph_create_anon_pipe(int fds[2]);
int ph_create_fifo(const char *path, int mode);
int ph_open_fifo_read(const char *path);
int ph_open_fifo_write(const char *path);
int ph_read(int fd, void *buf, int size);
int ph_write(int fd, const void *buf, int size);
int ph_close(int fd);

#endif
