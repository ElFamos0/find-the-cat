#include "../includes/parsing.h"



int make_parser(parser_t *p,token_list *l,int argc, char *argv[]) {
    int i = 2;
    int incr = 0;
    p->test_mode = 0;
    p->error_tok = 0;

    while (i < argc) {
        if (!argv[i]) {
            p->error_nb = i;
            return 1;
        }
        if (argv[i][0] == '-') {
            // there is a parameter here
            token_t tok = detect_token(argv[i]);
            incr = set_token_opt(p,l, tok, argc, argv, i);
            if(incr == -1) 
            {return 1;}

            // to ignore all parameter values
            i += incr;
        }
        i++;
    }
    return 0;
}


int detect_token(char* token){
    if (strcmp(token, "-test") == 0){
        return TOKEN_TEST;
    }
    else if (strcmp(token, "-name") == 0){
        return TOKEN_NAME;
    }
    else if (strcmp(token, "-size") == 0){
        return TOKEN_SIZE;
    }
    else if (strcmp(token,"-date") == 0){
        return TOKEN_DATE;
    }
    else if (strcmp(token,"-ctc") == 0){
        return TOKEN_CTC;
    }
    else if (strcmp(token,"-mime") == 0){
        return TOKEN_MIME;
    }
    else if (strcmp(token,"-dir") == 0){
        return TOKEN_DIR;
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
    case TOKEN_NAME :
        if (i+1 == argc || detect_token(argv[i+1]) != TOKEN_UNKNOWN) {
            printf("Error : Option -name was not provided with a value.\n");
            p->error_tok = 1;
            return -1;
        }
        else {
        create_token_item(&t, tok, argv[i+1], i);
        add_token(l,&t);
        free(t.value);
        incr = 1;
        }
        break;
    case TOKEN_SIZE :
        if (i+1 == argc || detect_token(argv[i+1]) != TOKEN_UNKNOWN) {
            printf("Error : Option -size was not provided with a value.\n");
            p->error_tok = 1;
            return -1;
        }
        else {
        create_token_item(&t, tok, argv[i+1], i);
        add_token(l,&t);
        free(t.value);
        incr = 1;
        }
        break;
    case TOKEN_DATE :
        if (i+1 == argc || detect_token(argv[i+1]) != TOKEN_UNKNOWN) {
            printf("Error : Option -date was not provided with a value.\n");
            p->error_tok = 1;
            return -1;
        }
        else {
        create_token_item(&t, tok, argv[i+1], i);
        add_token(l,&t);
        free(t.value);
        incr = 1;
        }
        break;
    case TOKEN_MIME :
        if (i+1 == argc || detect_token(argv[i+1]) != TOKEN_UNKNOWN) {
            printf("Error : Option -date was not provided with a value.\n");
            p->error_tok = 1;
            return -1;
        }
        else {
        create_token_item(&t, tok, argv[i+1], i);
        add_token(l,&t);
        free(t.value);
        incr = 1;
        }
        break;
    case TOKEN_CTC :
        if (i+1 == argc || detect_token(argv[i+1]) != TOKEN_UNKNOWN) {
            printf("Error : Option -date was not provided with a value.\n");
            p->error_tok = 1;
            return -1;
        }
        else {
        create_token_item(&t, tok, argv[i+1], i);
        add_token(l,&t);
        free(t.value);
        incr = 1;
        }
        break;
    case TOKEN_DIR :
        if (i+1 == argc || detect_token(argv[i+1]) != TOKEN_UNKNOWN) {
            printf("Error : Option -date was not provided with a value.\n");
            p->error_tok = 1;
            return -1;
        }
        else {
        create_token_item(&t, tok, argv[i+1], i);
        add_token(l,&t);
        free(t.value);
        incr = 1;
        }
        break;
    case TOKEN_UNKNOWN:
        p->error_tok = 1;
        if (i+1 == argc) {
            printf("Error : An unknown option '%s' was provided.\n",argv[i]);
            p->error_tok = 1;
            return -1;
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