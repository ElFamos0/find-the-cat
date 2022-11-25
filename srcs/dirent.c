// list recursively one directory

#include "../includes/dirent.h"

void ft_fetch_path(const char *path){
    DIR *dir; // permet de garder en mémoire le dossier
    struct dirent *entry;
    
    if (!(dir = opendir(path))){
        return;
    }

    while((entry = readdir(dir)) != NULL) {
        char *new_path;

        if(strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,"..") == 0){
            // on ignore les dossiers . et .. car non voulu 
            continue;
        }

        new_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(new_path, "%s/%s", path, entry->d_name);
        printf("%s\n", new_path);

        if (entry->d_type == DT_DIR){
            ft_fetch_path(new_path);
        }

        free(new_path);
        
    }
    closedir(dir);
}