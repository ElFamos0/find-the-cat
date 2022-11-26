#ifndef NAME_H
#define NAME_H

#include "../includes/token.h"
#include "../includes/dirent.h"

int get_file_by_name(char * value, path_list * pl);
int regex_check(char * path, char * value);

#endif