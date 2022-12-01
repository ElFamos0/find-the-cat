#ifndef TOKEN_H
#define TOKEN_H

#define TOKEN_MAX_SIZE 0xFF // Max size of a token

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum _Token{
    TOKEN_TEST,
    TOKEN_NAME,
    TOKEN_SIZE,
    TOKEN_DATE,
    TOKEN_MIME,
    TOKEN_CTC,
    TOKEN_DIR,
    TOKEN_COLOR,
    TOKEN_PERM,
    TOKEN_LINK,
    TOKEN_THREADS,
    TOKEN_OU,
    TOKEN_TYPE,
    TOKEN_UNKNOWN,
} token_t;

typedef struct _token_item {
    token_t token;
    char * value;
    int position;
} token_item;

typedef struct _token_list {
    token_item *data;
    int ptr;
    int size;
} token_list;

void create_token_item(token_item *t, token_t token, char * value, int position);
void free_tokenl(token_list *t);
void create_tokenl(token_list *l, int size);
void print_token_list(token_list *l);
void print_token(token_item *t);

void add_token(token_list *l, token_item *t);

#endif // TOKEN_H
