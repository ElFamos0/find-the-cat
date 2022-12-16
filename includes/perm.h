#ifndef PERM_H
#define PERM_H

#include "../includes/token.h"
#include "../includes/dirent.h"
#include <libgen.h>


int get_file_by_perm(char * value, path_list * pl);


#endif // PERM_H