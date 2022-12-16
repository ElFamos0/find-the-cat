#include"../includes/dir.h"
#include <sys/stat.h>
#include <ctype.h> 
#include <stdio.h>
#include <stdlib.h>

int get_file_by_mode(path_list * pl, int mode) {

    int i = 0;

    while (i < pl->ptr) {
        int incr = 1;
        char * path = malloc(sizeof(char) * (strlen(pl->path_data[i])+1));
        strcpy(path,pl->path_data[i]);
        struct stat st;

        if (stat(path, &st) == 0) {

            if(mode == 0) {
                if (!(S_ISREG(st.st_mode))) {
                    delete_path(pl, path);
                    incr = 0;
                }

            }
            else {
                if (!(S_ISDIR(st.st_mode))) {
                    delete_path(pl, path);
                    incr = 0;
                }

            }
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

