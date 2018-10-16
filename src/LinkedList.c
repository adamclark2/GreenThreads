#include <stdlib.h>
#include <stdio.h>

struct list_node {
    struct list_node* next;
    struct list_node* previous;
    void* item;
};

struct linked_list {
    struct list_node* head;
};

void list_init(struct linked_list* l){
    struct list_node* n = malloc(sizeof(struct list_node));
    n->item = NULL;
    n->next = n;
    n->previous = n;

    l->head = n;
}

void list_insert_head(struct linked_list* l, void* itm){
    struct list_node* old = l->head->next;
    struct list_node* n = malloc(sizeof(struct list_node));
    n->item = itm;

    n->previous = l->head;
    l->head->next = n;

    n->next = old;
    old->previous = n;
}

char* list_char_to_char(void* itm){
    return (char*) itm;
}

void list_print(char* voidToString(void*)){

}