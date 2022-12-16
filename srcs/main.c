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
    // remove trailing slash from argv[1]
    if (argc > 1) {
        if (argv[1][strlen(argv[1])-1] == '/') {
            argv[1][strlen(argv[1])-1] = '\0';
        }
    }

    test = exec_parser(argc, argv, &pl, &tl);
    if (test == 1){

        //printf("Early interruption.\n");
        free_all(&pl,&tl);
        return 1;
    }
    if (test == -1 && test == 2) {
        free_all(&pl,&tl);
        if (test == 2) {
            //printf("No file found.\n");
            return 0;
        }

        return 0;
    }
    
    if (exec_find(&pl,&tl) == 1) {

        //printf("Early interruption.\n");
        free_all(&pl,&tl);
        return 1;
    }

    else if (exec_find(&pl,&tl) == 2) {

        //printf("No file found.\n");
        free_all(&pl,&tl);
        return 0;
    }

    else {
        print_path_list(&pl);
        free_all(&pl,&tl);
        return 0;
    }

    
}
