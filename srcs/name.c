#include"../includes/name.h"
#include <sys/stat.h>

int get_file_by_name(char * value, path_list * pl) {
    printf("Searching for file %s\n", value);
    for (int i = 0; i < pl->ptr; i++) {
        char * path = pl->path_data[i];
        struct stat st;
        if (stat(path, &st) == 0) {
            if (S_ISREG(st.st_mode)) {
                size_t lenstr = strlen(path);
                size_t lensuffix = strlen(value);
                if (lenstr >= lensuffix) {
                    if (strncmp(path + lenstr - lensuffix, value, lensuffix) == 0) {
                        printf("Found file %s\n", path);}
                        else{
                            delete_path(pl, path);
                        }
                }
                delete_path(pl, path);
            }
            delete_path(pl, path);
        }
    }
    return 0;
}