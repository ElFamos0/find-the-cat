// list recursively one directory

#include "../includes/dirent.h"

void ft_fetch_path(path_list *pl, const char *path) {
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
        add_path(pl, new_path);

        if (entry->d_type == DT_DIR){
            ft_fetch_path(pl, new_path);
        }
        
    }
    closedir(dir);
}

void create_path_list(path_list *l, int size){
    l->path_data = (char **)malloc(sizeof(char *) * size);
    l->ptr = 0;
    l->size = size;
}

void free_path_list(path_list *l){
    for (int i = 0; i < l->ptr; i++){
        free(l->path_data[i]);
    }
    free(l->path_data);    
}

void add_path(path_list *l, char *path){
    if (l->ptr == l->size){
        l->size += 1;
        l->path_data = (char **)realloc(l->path_data, sizeof(char *) * l->size);
    }
    l->path_data[l->ptr++] = path;
}


void delete_path(path_list *l, char *path){
    for (int i = 0; i < l->ptr; i++){
        if(l->path_data[i] == NULL){
            continue;
        }
        if (strcmp(l->path_data[i], path) == 0){
            l->path_data[i] = NULL;        
        }
    }
}


void print_path_list(path_list *l){
    for (int i = 0; i < l->ptr; i++){
        if (l->path_data[i] != NULL){
            printf("%s\n", l->path_data[i]);
    }
}
}