#include "GreenThreads.h"

#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>

static struct gtThread* current;
static struct gtThread* main;
int maxTid = -1;

/*!
Init and turn the running process into a thread
*/
void green_thread_init(void){
    current = malloc(sizeof(struct gtThread));
    snprintf(current->name, sizeof(current->name), "main");
    current->tid = ++maxTid;
    main = current;
    setjmp(current->thread_context);
}

static void gt_context_switch(struct gtThread* next, struct gtThread* cur){
    if(setjmp(cur->thread_context) == 0){
        // Set context
        current = next;
        longjmp(current->thread_context, 1);
    }
}

/*!
    Create a new thread bassed of func
    It is run whenever
*/
void create_thread(thread_func* t){
    struct gtThread* new = malloc(sizeof(struct gtThread));
    new->tid = ++maxTid;
    snprintf(new->name, sizeof(current->name), "hi-%d", new->tid);

    if(setjmp(current->thread_context) == 0){
        struct gtThread* pre = current;
        current = new;
        setjmp(new->thread_context);
        t(0, (char**) NULL);        
    }else{
        // Current was long-jumped
    }
}
