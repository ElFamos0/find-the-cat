#ifndef EXECUTE_H
#define EXECUTE_H

#include "token.h"
#include "parsing.h"
#include <string.h>
#include "dirent.h"

int exec_parser(int argc, char *argv[],path_list *p_list, token_list * l);
int exec_find(path_list *p_list,token_list * tl);

#endif