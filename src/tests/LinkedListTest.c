#include <stdlib.h>
#include <stdio.h>

#include "../LinkedList.c"

int main(int argc, char** argv){
    char* one = "1.";
    char* two = "2.";
    char* three = "3.";

    struct linked_list list;

    list_init(&list);
    for(int i = 1; i <= 100;i++){
        char* ptr = malloc(sizeof(10));
        sprintf(ptr, "%d.", i);
        list_insert_head(&list, (void*) ptr);
    }

    printf("List Test:\nShould print 100,99,98...3,2,1\n");
    struct list_node* i = list.head->next;
    for(;i->item != NULL; i = i->next){
        printf("%s\n", (char*) i->item);
    } 

    printf("Should print 1,2,3...98,99,100\n");
    i = list.head->previous;
    for(;i != list.head; i = i->previous){
        printf("%s\n", (char*) i->item);
    } 

    printf("This equality shoud be true (%d > 0)\n", (list.head->next != list.head->previous));
}