#include"../includes/date.h"
#include"../includes/name.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <regex.h>

int get_file_by_ctc(char * value, path_list * pl) {
    // for every path make a grep
    int i = 0;
    while(i < pl->ptr){
        int incr = 1;
        char * path = malloc(sizeof(char) * (strlen(pl->path_data[i])+1));
        strcpy(path,pl->path_data[i]);
        struct stat st;
        if (stat(path, &st) == 0) {
            if (S_ISREG(st.st_mode)) {
                // put the ascii caracter in a buffer
                
                FILE * file = fopen(path, "r");
                char * buffer = malloc(sizeof(char) * (st.st_size+1));
                fread(buffer, sizeof(char), st.st_size, file);
                fclose(file);
                buffer[st.st_size] = '\0';
                
                if (regex_check(buffer, value) == 0) {
                    //printf("Found file %s.\n", path);
                }
                else{
                    delete_path(pl, path);
                    incr = 0;
                }                
            free(buffer);
            }
            else {
                delete_path(pl, path);
                incr = 0;
            }  
        }
        free(path);
        i+= incr;
    }
    return 0;
}