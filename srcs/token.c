#include "../includes/token.h"

char* param_list[12] = {"-test","-name","-size","-date","-mime","-ctc","-dir","-color","-perm","-link","-threads","-ou"};


void create_token_item(token_item *t, token_t token, char * value, int position){
    t->token = token;
    t->value = malloc(sizeof(char) * TOKEN_MAX_SIZE);
    strncpy(t->value, value, TOKEN_MAX_SIZE);
    t->position = position;
}

void free_tokenl(token_list *t){
    for (int i = 0; i < t->ptr; i++){
        free(t->data[i].value);
    }
    free(t->data);    
}

void create_tokenl(token_list *l, int size){
    l->data = (token_item *)malloc(sizeof(token_item) * size);
    l->ptr = 0;
    l->size = size;
}

void print_token(token_item *t){
    printf("La valeur du flag %s est %s\n", param_list[t->token], t->value);
}

void print_token_list(token_list *l){
    //printf("Token list:\n");
    for (int i = 0; i < l->ptr; i++){
        print_token(&l->data[i]);
    }
}


void add_token(token_list *l, token_item *t){
    if (l->ptr == l->size){
        l->size += 1;
        l->data = (token_item *)realloc(l->data, sizeof(token_item) * l->size);
    }
    token_item *token;
    token = &l->data[l->ptr++];
    create_token_item(token, t->token, t->value, t->position);
}
