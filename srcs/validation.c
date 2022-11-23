#include "../includes/validation.h"


int verify_path(char *entry) {
    struct stat sb;
    if (stat(entry, &sb) == 0 && S_ISDIR(sb.st_mode)) {
        return 0;
    }
    return 1;
}
