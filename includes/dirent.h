#ifndef DIRENT_H
#define DIRENT_H


#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

typedef struct _path_list {
    char **path_data;
    int ptr;
    int size;
} path_list;

void create_path_list(path_list *l, int size);
void free_path_list(path_list *l);
void add_path(path_list *l, char *path);
void print_path_list(path_list *l);



void ft_fetch_path(const char *path);


#endif // DIRENT_H