#ifndef IPC_FRAMEWORK_H
#define IPC_FRAMEWORK_H

#include <stddef.h>

#define IPC_OK          0
#define IPC_ERR        -1
#define IPC_ERR_AUTH   -2

typedef struct {
    int read_fd;
    int write_fd;
    int use_encryption;
    char auth_token[64];
} IpcConnection;

int ipc_init_anon(IpcConnection *conn, int read_fd, int write_fd, const char *auth_token, int use_encryption);
int ipc_init_fifo_client(IpcConnection *conn, const char *fifo_path, const char *auth_token, int use_encryption);
int ipc_init_fifo_server(IpcConnection *conn, const char *fifo_path, const char *auth_token, int use_encryption);

void ipc_close(IpcConnection *conn);

int ipc_send(IpcConnection *conn, const char *msg, size_t len);
int ipc_receive(IpcConnection *conn, char *buffer, size_t buffer_size);

int ipc_send_str(IpcConnection *conn, const char *msg);
int ipc_receive_str(IpcConnection *conn, char *buffer, size_t buffer_size);

#endif
