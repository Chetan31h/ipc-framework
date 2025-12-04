#ifndef SECURITY_MANAGER_H
#define SECURITY_MANAGER_H

#include <stddef.h>

int sm_validate_input(const char *data, size_t len);
int sm_check_auth_token(const char *provided, const char *expected);

#endif
