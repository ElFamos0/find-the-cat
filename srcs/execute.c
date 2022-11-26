#include "../includes/parsing.h"
#include "../includes/execute.h"
#include "../includes/validation.h"
#include "../includes/token.h"
#include "../includes/dirent.h"
#include "../includes/name.h"
#include "../includes/size.h"


int exec_parser(int argc, char *argv[],path_list *p_list, token_list * l){

    create_path_list(p_list, 1);
    create_tokenl(l, 1);
    if (argc >2) {
        // Most common cases
        if (verify_path(argv[1]) == 0){
                //printf("Path is valid.\n");
                parser_t parser;
                make_parser(&parser,l,argc,argv);
                ft_fetch_path(p_list, argv[1]);
                if (parser.error_tok == 1) {
                    return 1;
                }
                if (parser.test_mode == 1){
                    printf("Test mode is on\n");
                    print_token_list(l);
                }
                else{
                    printf("Test mode is off\n");
                }                

            } else {       
                printf("Path is invalid.\n");
                return 1;
            }
        }
    if (argc==2){
        if (verify_path(argv[1]) == 0){
            ft_fetch_path(p_list, argv[1]);
        } else {       
            printf("Path is invalid.\n");
            return 1;
        }
    }
    return 0;

}

int exec_find(path_list *p_list,token_list * tl) {

    token_item token;
    token_t tok;
    for (int i = 0; i < tl->ptr; i++){
        token = tl->data[i];
        tok = token.token;

        switch (tok)
        {
        case TOKEN_NAME:
            get_file_by_name(token.value,p_list);
            break;
        
        case TOKEN_SIZE:
            get_file_by_size(token.value,p_list);
            break;

        default :
            break;
        }
    
    }
    return 0;
}

void free_all(path_list * pl, token_list * tl) { 
    free_tokenl(tl);
    free_path_list(pl);
}






