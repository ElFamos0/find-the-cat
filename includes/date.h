#ifndef DATE_H
#define DATE_H

#include "../includes/token.h"
#include "../includes/dirent.h"

int get_file_by_date(char * value, path_list * pl);
int get_date(char * value, int * is_special);

#endif