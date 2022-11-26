#include"../includes/name.h"
#include <sys/stat.h>

int get_file_by_name(char * value, path_list * pl) {
    printf("Searching for file %s\n", value);
    for (int i = 0; i < pl->ptr; i++) {
        char * path = pl->path_data[i];
        //printf("Searching in %s\n", path);
        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir(path)) != NULL) {
            while ((ent = readdir(dir)) != NULL) {
                if (strcmp(ent->d_name, value) == 0) {
                    char * newpath = malloc(sizeof(char) * (strlen(path) + strlen(ent->d_name) + 2));
                    strcpy(newpath, path);
                    strcat(newpath, "/");
                    strcat(newpath, ent->d_name);
                    printf("Found file %s in %s\n", value, newpath);
                    free(newpath);
                }
            }
            closedir(dir);
        }
        else {
            //printf("Could not open directory %s\n", path);
        }
    }
    
    return 0;
}