#include "../includes/perm.h"
#include <sys/stat.h>
#include <ctype.h> 

int get_file_from_perm(char * value, path_list * pl){
    // find the path with the given permission
    int i = 0;
    while (i < pl->ptr) {
        int incr = 1;
        char * path = malloc(sizeof(char) * (strlen(pl->path_data[i])+1));
        strcpy(path,pl->path_data[i]);
        struct stat st;
        if (stat(path, &st) == 0) {
            if (S_ISREG(st.st_mode) || 1) {
                int perm = atoi(value);
                // find the permission of the file
                int file_perm = 0;
                if (st.st_mode & S_IRUSR) {
                    file_perm += 4 * 100;
                }
                if (st.st_mode & S_IWUSR) {
                    file_perm += 2 * 100;
                }
                if (st.st_mode & S_IXUSR) {
                    file_perm += 1 * 100;
                }
                if (st.st_mode & S_IRGRP) {
                    file_perm += 4 * 10;
                }
                if (st.st_mode & S_IWGRP) {
                    file_perm += 2 * 10;
                }
                if (st.st_mode & S_IXGRP) {
                    file_perm += 1 * 10;
                }
                if (st.st_mode & S_IROTH) {
                    file_perm += 4;
                }
                if (st.st_mode & S_IWOTH) {
                    file_perm += 2;
                }
                if (st.st_mode & S_IXOTH) {
                    file_perm += 1;
                }
                if (file_perm != perm) {
                    delete_path(pl, path);
                    incr = 0;
                }
            }
        }
        free(path);
        i+= incr;
    }
    return 0;
}
