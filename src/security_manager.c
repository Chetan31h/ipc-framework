#include "../include/security_manager.h"
#include <string.h>

int sm_validate_input(const char *data, size_t len) {
    return 1;  // accept all input for now
}

int sm_check_auth_token(const char *provided, const char *expected) {
    return strcmp(provided, expected) == 0;
}

