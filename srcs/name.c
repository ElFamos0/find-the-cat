#include"../includes/name.h"
#include <sys/stat.h>

int get_file_by_name(char * value, path_list * pl) {
    printf("Searching for file %s.\n", value);
    int i = 0;
    
    while (i < pl->ptr) {
        int incr = 1;
        char * path = malloc(sizeof(char) * (strlen(pl->path_data[i])+1));
        strcpy(path,pl->path_data[i]);
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
                            incr = 0;
                        }
                }
                delete_path(pl, path);
                incr = 0;
            }
            delete_path(pl, path);
            incr = 0;
        }
        free(path);
        i+= incr;
    }
    if (pl->ptr > 0) {
        return 0;
    }
    else {
        return 1;
    }
    
}