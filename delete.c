#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int key;
    double value;
    struct node* next;
    struct node* prev;
} node_t;

typedef struct list{
    node_t* head;
    node_t* tail;
} list_t;

void free_list(list_t* list){
    node_t* current = list->head;
    while(current != NULL){
        node_t* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

//Y'avais d'autre fonctions pré-écrites mais j'ai oublie de les copier

int delete(list_t* list, int key){
    int n = 0;
    node_t* current = list->head;
    if(current->key == key){
        n = current->value;
        if(current->next==NULL){
            free_list(list);
            return n;
        }
        else{
            list->head = current->next;
            current->next->prev = NULL;
            free(current);
            return n;
        }
    }
    current = current->next;
    while (current->next->key != list->tail->key)
    {
        if(current->key == key){
            n = current->value;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            return n;
        }
        current = current->next;
    }
    current = list->tail;
    if(current->key == key){
        n = current->value;
        list->tail = current->prev;
        current->prev->next = NULL;
        free(current);
        return n;
    }
    return n;
}