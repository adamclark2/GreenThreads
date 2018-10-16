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
    gt_context_switch(current);
}

static void gt_context_switch(struct gtThread* next){
    if(setjmp(current->thread_context) == 0){
        // Set context
        current = next;
        longjmp(current->thread_context, 1);
    }else{
        // Long-jumped
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

    struct gtThread* pre = current;
    gt_context_switch(current);

    current = new;
    t(0, (char**) NULL);

    // t is done, go back to pre
    gt_context_switch(pre); 
}
