#include"../includes/name.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <regex.h>
#include <libgen.h>
#include <stdio.h>


int regex_check(char * path, char * value) {
    regex_t regex;
    int reti;
    int result;
    
    reti = regcomp(&regex, value, 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex");
        exit(1);
    }

    result = regexec(&regex, path, 0, NULL, 0);
    regfree(&regex);
    return result;
}


int get_file_by_name(char * value, path_list * pl) {
    //printf("Searching for file %s.\n", value);
    int i = 0;
    
    while (i < pl->ptr) {
        int incr = 1;
        char * path = malloc(sizeof(char) * (strlen(pl->path_data[i])+1));
        strcpy(path,pl->path_data[i]);

        char * path_cpy = malloc(sizeof(char) * (strlen(pl->path_data[i])+1));
        strcpy(path_cpy,path);
        char *filename = basename(path_cpy);
        struct stat st;
        if (stat(path, &st) == 0) {
            if (S_ISREG(st.st_mode)||1) {
                if (regex_check(filename, value) == 0) {
                    //printf("Found file %s.\n", path);
                }
                else{
                    delete_path(pl, path);
                    incr = 0;
                }
            }
            else {
                delete_path(pl, path);
                incr = 0;
            }
            
        }
        free(path);
        i+= incr;
        free(path_cpy);
    }
    if (pl->ptr > 0) {
        return 0;
    }
    else {
        return 2;
    }
    
}

