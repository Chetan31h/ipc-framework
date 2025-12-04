#include "../include/message_encoder.h"

void me_encrypt(char *data, size_t len, int key) {
    for (size_t i = 0; i < len; i++)
        data[i] += key;
}

void me_decrypt(char *data, size_t len, int key) {
    for (size_t i = 0; i < len; i++)
        data[i] -= key;
}
