#include "../includes/parsing.h"
#include "../includes/execute.h"
#include "../includes/validation.h"
#include "../includes/parsing.h"
#include "../includes/token.h"
#include "../includes/dirent.h"

int exec_parser(int argc, char *argv[],path_list *p_list, token_list * l){

    if (verify_path(argv[1]) == 0){
            printf("Path is valid\n");
            parser_t parser;

            create_tokenl(l, 1);
            
            make_parser(&parser,l,argc,argv);
            
            if (parser.test_mode == 1){
                printf("Test mode is on\n");
                print_token_list(&l);
            }
            else{
                printf("Test mode is off\n");
            }
            free_tokenl(&l);

            return 1;
            
        } else {       
            printf("Path is invalid\n");
            return 0;
        }
}



