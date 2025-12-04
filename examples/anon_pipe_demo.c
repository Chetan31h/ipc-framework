#include "../include/ipc_framework.h"
#include "../include/pipe_handler.h"

#include <unistd.h>
#include <stdio.h>

int main() {
    int fds[2];
    ph_create_anon_pipe(fds);

    int pid = fork();

    if (pid == 0) {
        // Child
        close(fds[1]);
        IpcConnection conn;
        ipc_init_anon(&conn, fds[0], -1, "SECRET123", 1);

        char buffer[256];
        ipc_receive_str(&conn, buffer, sizeof(buffer));

        printf("Child received: %s\n", buffer);
    }
    else {
        // Parent
        close(fds[0]);
        IpcConnection conn;
        ipc_init_anon(&conn, -1, fds[1], "SECRET123", 1);

        ipc_send_str(&conn, "Hello from parent!");
    }

    return 0;
}
