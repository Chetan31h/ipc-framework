#include "../include/ipc_framework.h"
#include "../include/pipe_handler.h"
#include "../include/security_manager.h"
#include "../include/message_encoder.h"
#include "../include/logger.h"

#include <string.h>

static const char *AUTH_TOKEN = "SECRET123";
static int ENC_KEY = 3;

int ipc_init_anon(IpcConnection *conn, int read_fd, int write_fd, const char *auth_token, int use_encryption) {
    if (!sm_check_auth_token(auth_token, AUTH_TOKEN))
        return IPC_ERR_AUTH;

    conn->read_fd = read_fd;
    conn->write_fd = write_fd;
    conn->use_encryption = use_encryption;
    strcpy(conn->auth_token, auth_token);

    return IPC_OK;
}

void ipc_close(IpcConnection *conn) {
    if (conn->read_fd != -1) ph_close(conn->read_fd);
    if (conn->write_fd != -1) ph_close(conn->write_fd);
}

int ipc_send(IpcConnection *conn, const char *msg, size_t len) {
    char buffer[1024];
    memcpy(buffer, msg, len);

    if (conn->use_encryption)
        me_encrypt(buffer, len, ENC_KEY);

    return ph_write(conn->write_fd, buffer, len);
}

int ipc_send_str(IpcConnection *conn, const char *msg) {
    return ipc_send(conn, msg, strlen(msg));
}

int ipc_receive(IpcConnection *conn, char *buffer, size_t size) {
    int n = ph_read(conn->read_fd, buffer, size);

    if (n > 0 && conn->use_encryption)
        me_decrypt(buffer, n, ENC_KEY);

    return n;
}

int ipc_receive_str(IpcConnection *conn, char *buffer, size_t size) {
    int n = ipc_receive(conn, buffer, size - 1);
    if (n >= 0)
        buffer[n] = '\0';
    return n;
}
