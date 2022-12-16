#ifndef PARSING_H
#define PARSING_H

#include "token.h"
#include <string.h>

typedef struct _parsing_t {
    int test_mode;
    int error_nb;
    int error_tok;
    int file_mod;
    int color_mod;
} parser_t;


int make_parser(parser_t *p, token_list *l, int argc, char *argv[]);
int detect_token(char* token);
int set_token_opt(parser_t *p, token_list *l, token_t tok, int argc, char *argv[], int i);

#endif // PARSING_H