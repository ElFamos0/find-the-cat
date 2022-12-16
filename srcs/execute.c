#include "../includes/parsing.h"
#include "../includes/execute.h"
#include "../includes/validation.h"
#include "../includes/token.h"
#include "../includes/dirent.h"
#include "../includes/name.h"
#include "../includes/size.h"
#include "../includes/date.h"
#include "../includes/mime.h"
#include "../includes/ctc.h"
#include "../includes/dir.h"


int exec_parser(int argc, char *argv[],path_list *p_list, token_list * l){

    create_path_list(p_list, 1);
    create_tokenl(l, 1);
    if (argc >2) {
        // Most common cases
        if (verify_path(argv[1]) == 0){
                //printf("Path is valid.\n");
                parser_t parser;
                make_parser(&parser,l,argc,argv);
                ft_fetch_path(p_list, argv[1],1);
                if (parser.error_tok == 1) {
                    return 1;
                }
                if (parser.test_mode == 1){
                    //printf("Test mode is on\n");
                    print_token_list(l);
                    return -1;
                }
                else{
                    //printf("Test mode is off\n");
                }                
                if (get_file_by_mode(p_list,parser.file_mod)) {
                    return 2;
                }

            } else {

		parser_t parser;
    	make_parser(&parser,l,argc,argv);
		if(parser.test_mode == 1){
		    print_token_list(l);
		}
                //printf("Path is invalid.\n");
                return 1;
            }
        }
    if (argc==2){
        if (verify_path(argv[1]) == 0){
            ft_fetch_path(p_list, argv[1],1);
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
        int error = 0;
        switch (tok)
        {
        case TOKEN_NAME:
            error = get_file_by_name(token.value,p_list);
            if (error == 1) {
                //printf("Error : No file found with name '%s'\n",token.value);
                return 1;
            }
            else if (error == 2) {
                return 2;
            }
            break;
        
        case TOKEN_SIZE:
            error = get_file_by_size(token.value,p_list);
            if (error == 1) {
                //printf("Error : No file found with size '%s'\n",token.value);
                return 1;
            }
            else if (error == 2) {
                return 2;
            }
            break;

        case TOKEN_DATE :
            error = get_file_by_date(token.value,p_list);
            if (error == 1) {
                //printf("Error : No file found with last activity of '%s'\n",token.value);
                return 1;
            }
            else if (error == 2) {
                return 2;
            }
            break;
        case TOKEN_DIR :
            error = get_file_by_name(token.value,p_list);
            if (error == 1) {
                //printf("Error : No file found with last activity of '%s'\n",token.value);
                return 1;
            }
            else if (error == 2) {
                return 2;
            }
            break;
        case TOKEN_MIME:
            error = get_file_by_mime(token.value,p_list);
            if (error == 1) {
                //printf("Error : No file found with mime type '%s'\n",token.value);
                return 1;
            }
            else if (error == 2) {
                return 2;
            }
            break;
        case TOKEN_CTC:
            error = get_file_by_ctc(token.value,p_list);
            if (error == 1) {
                //printf("Error : No file found with ctc '%s'\n",token.value);
                return 1;
            }
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






