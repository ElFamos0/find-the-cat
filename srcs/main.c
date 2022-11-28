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
    int test = 0;
    path_list pl;
    token_list tl;
    test = exec_parser(argc, argv, &pl, &tl);
    if (test == 1){

        printf("Early interruption.\n");
        free_all(&pl,&tl);
        return 1;
    }
    if (test == -1) {
        free_all(&pl,&tl);
        return 0;
    }
    
    if (exec_find(&pl,&tl) == 1) {

        printf("Early interruption.\n");
        free_all(&pl,&tl);
        return 1;
    }
    print_path_list(&pl);
    free_all(&pl,&tl);
    return 0;
}
