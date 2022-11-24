#include "../includes/parsing.h"



void make_parser(parser_t *p,token_list *l,int argc, char *argv[]) {
    int i = 2;
    int incr = 0;
    p->test_mode = 0;

    while (i < argc) {
        if (!argv[i]) {
            p->error_nb = i;
            return;
        }
        if (argv[i][0] == '-') {
            // there is a parameter here
            token_t tok = detect_token(argv[i]);
            incr = set_token_opt(p,l, tok, argc, argv, i);
        
            // to ignore all parameter values
            i += incr;
        }
        i++;
    }
    return;
}


int detect_token(char* token){
    if (strcmp(token, "-test") == 0){
        return TOKEN_TEST;
    }
    else{
        return TOKEN_UNKNOWN;
    }
}

int set_token_opt(parser_t *p, token_list *l, token_t tok, int argc, char *argv[], int i){
    token_item t;
    int incr = 0;
    switch (tok)
    {
    case TOKEN_TEST:
        p->test_mode = 1;
        break;
    case TOKEN_UNKNOWN:
        /* p->test_mode = 1; */
        if (i+1 == argc) {
            printf("Error : token %s was not provided with a value.\n",argv[i]);
        }
        else {
        create_token_item(&t, tok, argv[i+1], i);
        add_token(l,&t);
        free(t.value);
        incr = 1;
        }
        break;
    default:
        break;
    }
    return incr;
}