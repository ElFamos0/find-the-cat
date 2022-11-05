#include "../includes/validation.h"


int verify_path(char *entry) {
    // verify if the path is valid
    // return 0 if valid
    // return 1 if invalid
    struct stat sb;
    if (stat(entry, &sb) == 0 && S_ISDIR(sb.st_mode)) {
        return 0;
    }
    return 1;
}
