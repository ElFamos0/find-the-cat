#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../includes/validation.h"

int main(int argc, char *argv[])
{
    if (argc>=2){
        // test valid parameters
        if (verify_path(argv[1]) == 0){
            printf("Path is valid\n");
        } else {
            printf("Path is invalid\n");
        }
    }
    else{
        printf("No parameters\n");
    }
    return 0;
}
