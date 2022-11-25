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
    if (exec_parser(argc,argv,&pl,&tl) == 1) {

        printf("Early interruption.\n");
        free_all(&pl,&tl);
        return 1;
    }
    
    if (exec_find(&pl,&tl) == 1) {

        printf("Early interruption.\n");
        free_all(&pl,&tl);
        return 1;
    }
    print_path_list(&pl);
    free_all(&pl,&tl);

}
