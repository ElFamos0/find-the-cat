#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../includes/validation.h"
#include "../includes/parsing.h"
#include "../includes/token.h"
#include "../includes/dirent.h"
#include "../includes/execute.h"


int main(int argc, char *argv[])
{
    path_list pl;
    token_list tl;
    exec_parser(argc,argv,&pl,&tl);
    exec_find(&pl,&tl);
    free_all(&pl,&tl);

}
