#include "../includes/parsing.h"
#include "../includes/exec_parser.h"
#include "../includes/validation.h"
#include "../includes/parsing.h"
#include "../includes/token.h"
#include "../includes/dirent.h"

void exec_parser(int argc, char *argv[],path_list *p_list){

    if (verify_path(argv[1]) == 0){
            printf("Path is valid\n");
            parser_t parser;
            token_list l;

            create_tokenl(&l, 1);
            
            make_parser(&parser,&l,argc,argv);
            
            if (parser.test_mode == 1){
                printf("Test mode is on\n");
                print_token_list(&l);
            }
            else{
                printf("Test mode is off\n");
            }
            free_tokenl(&l);






            
        } else {       
            printf("Path is invalid\n");
        }
}



