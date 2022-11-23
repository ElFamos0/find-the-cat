#ifndef TOKEN_H
#define TOKEN_H

#define TOKEN_MAX_SIZE 0xFF // Max size of a token

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef enum _Token{
    TOKEN_TEST,
    TOKEN_UNKNOWN,
} token_t;

typedef struct _tokenl {
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