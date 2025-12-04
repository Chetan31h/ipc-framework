#ifndef MESSAGE_ENCODER_H
#define MESSAGE_ENCODER_H

#include <stddef.h>

void me_encrypt(char *data, size_t len, int key);
void me_decrypt(char *data, size_t len, int key);

#endif
